int echo_window(int xe, int ye)
{
Rect EchoBckgd(Vec2D(xe,  ye), Vec2D( echo_window_x_size,echo_window_y_size));
EchoBckgd.SetRoundness(15);
EchoBckgd.SetLineWidth(triple_epaisseur_ligne_fader);
EchoBckgd.Draw(CouleurFond);

if(window_focus_id==W_ECHO)
{
EchoBckgd.DrawOutline(CouleurFader);
}
else {EchoBckgd.DrawOutline(CouleurLigne); }
neuro.Print("ECHO",xe+100,ye+30);

Rect GriderEditEnable( Vec2D((xe+610),(ye+10)),Vec2D(50,20));
GriderEditEnable.SetRoundness(5);
if(index_enable_edit_echo==1)
{
GriderEditEnable.Draw(CouleurFader);
}
GriderEditEnable.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print("edit",xe+620 ,ye+22);


neuro.Print(ol::ToString(echo_over_channel+1),xe+625 ,ye+55);

char tcmp[24];

switch(dmx_view)
{
case 1:
sprintf(tcmp,"Level %.2f - %d",echo_levels[echo_selected][0][echo_over_channel],(int)( echo_levels[echo_selected][0][echo_over_channel]*255));
break;
case 0:
sprintf(tcmp,"Level %.2f - %d",echo_levels[echo_selected][0][echo_over_channel],(int)( echo_levels[echo_selected][0][echo_over_channel]*100));
break;
default: break;
}
petitchiffre.Print(tcmp,xe+500 ,ye+45);

switch(dmx_view)
{
case 1:
sprintf(tcmp,"Ground %.2f - %d",echo_levels[echo_selected][1][echo_over_channel],(int)( echo_levels[echo_selected][1][echo_over_channel]*255));
break;
case 0:
sprintf(tcmp,"Ground %.2f - %d",echo_levels[echo_selected][1][echo_over_channel],(int)( echo_levels[echo_selected][1][echo_over_channel]*100));
break;
default: break;
}
petitchiffre.Print(tcmp,xe+500 ,ye+70);

strcpy(tcmp,"");

int index_ec=0;




Rect EchoPreset(Vec2D(xe+10,ye+10),Vec2D(30,15));
EchoPreset.SetRoundness(4);
for(int le=0;le<3;le++)
{
for(int cel=0;cel<8;cel++)
{
index_ec=cel+(le*8);
EchoPreset.MoveTo(Vec2D(xe+180+(cel*40),ye+10+(le*25)));
if(echo_selected==index_ec){EchoPreset.Draw(CouleurFader);}
EchoPreset.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print(ol::ToString(index_ec+1),xe+188+(cel*40),ye+20+(le*25));


if(window_focus_id==W_ECHO && dragging_channel_in_echo==0 && mouse_x> xe+180+(40*cel) && mouse_x<xe+210+(40*cel) && mouse_y>ye+10+(le*25) && mouse_y<ye+30+(le*25))
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
sprintf(tcmp,"Echo Preset %d",index_ec+1);
show_type_midi(1663+index_ec, tcmp);
EchoPreset.DrawOutline(CouleurBlind);
}
}
}
}


 Rect SetChannpos(Vec2D(xe+615,ye+65),Vec2D(40,20));
 SetChannpos.SetRoundness(5);
 SetChannpos.Draw(Discrete2);
 SetChannpos.DrawOutline(CouleurLigne.WithAlpha(0.4));
 petitchiffre.Print(ol::ToString(echo_grid_channel_position[echo_selected]+1),xe+625,ye+78);

 if(window_focus_id==W_ECHO && mouse_x>xe+615 && mouse_x<xe+655 && mouse_y>ye+65 && mouse_y<ye+85)
 {
 SetChannpos.DrawOutline(CouleurLigne.WithAlpha(0.7));
 }

Rect Action(Vec2D(xe+10,ye+40),Vec2D(115,20));
Action.SetRoundness(4);
for (int n=0;n<5;n++)
{
Action.MoveTo(Vec2D(xe+10,ye+50+(n*30)));
Action.DrawOutline(CouleurLigne.WithAlpha(0.5));
switch(n)
{
case 0:
     Action.Draw(CouleurFader.WithAlpha(echo_is_echo_mode[echo_selected]));
     petitchiffre.Print("ECHO FADER",xe+30,ye+62+(n*30));
     sprintf(tcmp,"ECHO FADER");
break;
case 1:
     petitchiffre.Print("SNAP FADER",xe+30,ye+62+(n*30));
     sprintf(tcmp,"SNAP FADER");
break;
case 2:

     Action.Draw(CouleurFader.WithAlpha(do_bounce[echo_selected]));
     petitchiffre.Print("BOUNCE !",xe+35,ye+62+(n*30));
     sprintf(tcmp,"BOUNCE !");
break;
case 3:
     petitchiffre.Print("SNAP-KILL-BOUNCE",xe+11,ye+62+(n*30));
     sprintf(tcmp,"SNAP-KILL-BOUNCE");
break;
case 4:
     petitchiffre.Print("GET BACK FADER",xe+15,ye+62+(n*30));
     sprintf(tcmp,"GET BACK FADER");
break;
default:
break;
}

if(window_focus_id==W_ECHO && dragging_channel_in_echo==0  && mouse_x>xe+30 && mouse_x<xe+145 && mouse_y>ye+50+(n*30) && mouse_y<ye+80+(n*30))
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
show_type_midi(1686+n, tcmp);
Action.DrawOutline(CouleurBlind);
}


}
}


petitchiffre.Print("FADER",xe+10,ye+218);
Rect FBox(Vec2D(xe+70,ye+200),Vec2D(45,35));
FBox.SetRoundness(5);
FBox.DrawOutline(CouleurLigne.WithAlpha(0.5));

neuro.Print(ol::ToString(echo_pointing_fader_num[echo_selected]),xe+80,ye+220);

if(window_focus_id==W_ECHO && mouse_x>xe+70 && mouse_x<xe+115 && mouse_y>ye+200 && mouse_y<ye+235)
{
FBox.DrawOutline(CouleurLigne);

}

Rect Affecttodock(Vec2D(xe+10,ye+245), Vec2D(110,20));
Affecttodock.SetRoundness(7.5);
if(index_affect_echo_to_dock==1){Affecttodock.Draw(CouleurFader);}
Affecttodock.DrawOutline(CouleurLigne.WithAlpha(0.5));

petitchiffre.Print( "Affect To Dock",(xe+20), (ye+258));






Rect ActionTyp(Vec2D(xe+500,ye+10),Vec2D(70,20));
ActionTyp.SetRoundness(4);


switch(echo_channel_manipulate_mode[echo_selected])
{
case 0:
     ActionTyp.Draw(Discrete8);
     petitchiffre.Print("CH.LEVEL",xe+507,ye+22);
     sprintf(tcmp,"CH.LEVEL");
break;
case 1:
     ActionTyp.Draw(Discrete2);
     petitchiffre.Print("CH.GRND",xe+507,ye+22);
     sprintf(tcmp,"CH.GROUND");
break;
default: break;
}

ActionTyp.DrawOutline(CouleurLigne.WithAlpha(0.5));


if(window_focus_id==W_ECHO && mouse_x>xe+500 && mouse_x<xe+570 && mouse_y>ye+10&& mouse_y<ye+30)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
show_type_midi(1696, tcmp);
ActionTyp.DrawOutline(CouleurBlind);
}
}





Echo_Aera(xe+155,ye+95);


Rect Frame(Vec2D(xe+185,ye+255),Vec2D(127,10));
float tmp_lev=0;


Circle BMidiOut(xe+316,ye+255, 5);


char mid_lev[8];
for (int cl=0;cl<3;cl++)
{
tmp_lev=echo_global_params[echo_selected][cl];
switch(cl)
{
 case 0:
 sprintf(tcmp,"Gravity:     %.2f",tmp_lev);
 break;
 case 1:
 sprintf(tcmp,"Mass:        %.2f",tmp_lev);
 break;
 case 2:
 sprintf(tcmp,"Energy: %.2f",tmp_lev);
 break;
 default:
  //sab 02/03/2014 sprintf(tcmp,"");
  strcpy(tcmp,"");
 break;
}
sprintf(mid_lev,"%d",(int)(tmp_lev*127));
Rect LevelF(Vec2D(xe+155+(cl*180),ye+255),Vec2D(tmp_lev*127,10));
LevelF.Draw(Discrete8);
Frame.MoveTo(Vec2D(xe+155+(cl*180),ye+255));
Frame.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print(tcmp,xe+155+(cl*180),ye+248);
BMidiOut.MoveTo(Vec2D(xe+295+(cl*180),ye+265));
if(midi_send_out[1693+cl]==1)
{
BMidiOut.Draw(CouleurBlind);
}
BMidiOut.DrawOutline(CouleurGrisMoyen);
petitchiffrerouge.Print(mid_lev,xe+286+(cl*180),ye+252);

if(window_focus_id==W_ECHO && mouse_x>=xe+155+(cl*180) && mouse_x<=xe+285+(cl*180) && mouse_y>=ye+255 && mouse_y<=ye+265)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
show_type_midi(1693+cl, tcmp);
Frame.DrawOutline(CouleurBlind);
}

}


}



return(0);
}
