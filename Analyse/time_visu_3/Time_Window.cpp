int Time_Window(int xtime, int ytime, int timerayon)
{

Rect TimeWindow(Vec2D (xtime, ytime ), Vec2D ( 370,300));
TimeWindow.SetRoundness(15);
TimeWindow.SetLineWidth(triple_epaisseur_ligne_fader);
TimeWindow.Draw(CouleurFond);
if(window_focus_id==908)
{
TimeWindow.DrawOutline(CouleurFader);
}
else
{
TimeWindow.DrawOutline(CouleurLigne);
}


Rect BigChrono(Vec2D(xtime+20,ytime+280),Vec2D(10,10));
BigChrono.Draw(CouleurBlind.WithAlpha(index_show_chrono));
BigChrono.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print("Chrono foreground",xtime+40,ytime+290);
Circle monTrajetTime0( Vec2D(xtime+150, ytime+150), 115);
 monTrajetTime0.SetLineWidth(epaisseur_ligne_fader);
 monTrajetTime0.DrawOutline( CouleurBleuProcedure);

Circle monTrajetTime2( Vec2D(xtime+150, ytime+150), 85);
 monTrajetTime2.SetLineWidth(epaisseur_ligne_fader);
 monTrajetTime2.Draw(CouleurBleuProcedure.WithAlpha(0.5));

 //AFFECTATION MIDI Fader

if( Midi_Faders_Affectation_Type!=0 && window_focus_id==W_TIME)
{
 if(mouse_x>xtime+150  && mouse_x< xtime+250 && mouse_y>ytime+150 && mouse_y<ytime+250 )
 {
 monTrajetTime0.DrawOutline(CouleurBlind);
 }
}

 if(show_im_recording_a_time==1)
 {
 monTrajetTime2.Draw(CouleurFader);
 }

 //affichage du pointeur de temps
 Circle monCurseurTime( Vec2D(position_curseur_time_x-4, position_curseur_time_y-4), 8 );
 monCurseurTime.SetLineWidth(epaisseur_ligne_fader);
 monCurseurTime.DrawOutline( CouleurBlind );


neuro.Print(ol::ToString(time_minutes), xtime+85, ytime+150);
neuro.Print("..",xtime+120,ytime+150);
neuro.Print(ol::ToString(time_secondes), xtime+130, ytime+150);
neuro.Print(".",xtime+170,ytime+150);
petitchiffre.Print(ol::ToString(time_centiemes), xtime+180, ytime+150);
petitchiffre.Print("1/100",xtime+190,ytime+135);

print_time_reperes(time_wheel_datatype_is);//affichage des chiffres sur le tableau de bord

Rect SetTimeWheelMode(Vec2D(xtime+120,ytime+80),Vec2D(60,20));
SetTimeWheelMode.SetRoundness(7.5);
SetTimeWheelMode.SetLineWidth(epaisseur_ligne_fader);

SetTimeWheelMode.DrawOutline(CouleurLigne);

if(  window_focus_id==W_TIME && mouse_x>xtime+120 && mouse_x<xtime+180 && mouse_y>ytime+80 && mouse_y<ytime+100)
{
if( Midi_Faders_Affectation_Type!=0)
{SetTimeWheelMode.DrawOutline(CouleurBlind); }
else {SetTimeWheelMode.Draw(CouleurSurvol);   }
}

Line(Vec2D(xtime+150,ytime+100),Vec2D(Vec2D(xtime+150,ytime+115))).Draw(CouleurLigne);
if(time_wheel_datatype_is==0)//minutes
{
Line(Vec2D(xtime+150,ytime+115),Vec2D(Vec2D(xtime+100,ytime+115))).Draw(CouleurLigne);
Line(Vec2D(xtime+100,ytime+115),Vec2D(Vec2D(xtime+100,ytime+120))).Draw(CouleurLigne);
petitchiffrerouge.Print("min",xtime+100,ytime+135);
petitchiffre.Print("MIN.",xtime+135,ytime+95);
}
if(time_wheel_datatype_is==1)//secondes
{
Line(Vec2D(xtime+150,ytime+115),Vec2D(Vec2D(xtime+160,ytime+115))).Draw(CouleurLigne);
Line(Vec2D(xtime+160,ytime+115),Vec2D(Vec2D(xtime+160,ytime+120))).Draw(CouleurLigne);
petitchiffrerouge.Print("sec",xtime+150,ytime+135);
petitchiffre.Print("SEC.",xtime+135,ytime+95);
}
if(time_wheel_datatype_is==2)//1/10
{
Line(Vec2D(xtime+150,ytime+115),Vec2D(Vec2D(xtime+200,ytime+115))).Draw(CouleurLigne);
Line(Vec2D(xtime+200,ytime+115),Vec2D(Vec2D(xtime+200,ytime+120))).Draw(CouleurLigne);
petitchiffrerouge.Print("1/100",xtime+190,ytime+135);
petitchiffre.Print("1/100",xtime+135,ytime+95);
}



Circle DoChrono( Vec2D(xtime+140, ytime+190), 15);
DoChrono.SetLineWidth(epaisseur_ligne_fader);
DoChrono.Draw(CouleurBleuProcedure.WithAlpha(0.4));

Circle ResetChrono( Vec2D(xtime+180, ytime+200), 8);
ResetChrono.SetLineWidth(epaisseur_ligne_fader);
ResetChrono.Draw(CouleurBleuProcedure.WithAlpha(0.4));

DoChrono.DrawOutline(CouleurBleuProcedure);
ResetChrono.DrawOutline(CouleurBleuProcedure);

if (index_play_chrono==1){DoChrono.Draw(CouleurFader); }
if(window_focus_id==W_TIME && mouse_x>xtime+125 && mouse_x<xtime+155 && mouse_y>ytime+175 && mouse_y<ytime+205)
{
if(Midi_Faders_Affectation_Type!=0)
{
DoChrono.DrawOutline(CouleurBlind);
}
else
{
DoChrono.Draw(CouleurSurvol);
}
}

if(window_focus_id==W_TIME && mouse_x>xtime+172 && mouse_x<xtime+188 && mouse_y>ytime+192 && mouse_y<ytime+208)
{
if(Midi_Faders_Affectation_Type!=0)
{
ResetChrono.DrawOutline(CouleurBlind);
}
else
{
ResetChrono.Draw(CouleurSurvol);
}
}

petitpetitchiffre.Print("CHRONO",xtime+90,ytime+190);
petitpetitchiffre.Print("clear",xtime+150,ytime+210);


if (index_play_chrono==1)
{
DoChrono.DrawOutline(CouleurFader);
}
Rect SetTimeIn(Vec2D(xtime+300,ytime+20),Vec2D(50,30));
SetTimeIn.SetRoundness(7.5);
SetTimeIn.SetLineWidth(epaisseur_ligne_fader);

Rect SetTimeOut(Vec2D(xtime+300,ytime+70),Vec2D(50,30));
SetTimeOut.SetRoundness(7.5);
SetTimeOut.SetLineWidth(epaisseur_ligne_fader);

Rect SetTimeDIn(Vec2D(xtime+300,ytime+120),Vec2D(50,30));
SetTimeDIn.SetRoundness(7.5);
SetTimeDIn.SetLineWidth(epaisseur_ligne_fader);

Rect SetTimeDOut(Vec2D(xtime+300,ytime+170),Vec2D(50,30));
SetTimeDOut.SetRoundness(7.5);
SetTimeDOut.SetLineWidth(epaisseur_ligne_fader);


SetTimeIn.DrawOutline(CouleurLigne);
SetTimeOut.DrawOutline(CouleurLigne);
SetTimeDIn.DrawOutline(CouleurLigne);
SetTimeDOut.DrawOutline(CouleurLigne);


if(index_type_of_time_to_affect[0]==1)
{SetTimeDIn.Draw(CouleurFader);
SetTimeDIn.DrawOutline(CouleurFader);}
if(index_type_of_time_to_affect[1]==1)
{SetTimeIn.Draw(CouleurFader);
SetTimeIn.DrawOutline(CouleurFader);}
if(index_type_of_time_to_affect[2]==1)
{SetTimeDOut.Draw(CouleurFader);
SetTimeDOut.DrawOutline(CouleurFader);}
if(index_type_of_time_to_affect[3]==1)
{SetTimeOut.Draw(CouleurFader);
SetTimeOut.DrawOutline(CouleurFader);}


if( Midi_Faders_Affectation_Type!=0 && window_focus_id==W_TIME )
{
if(mouse_x>xtime+300 && mouse_x<xtime+350)
{
if(mouse_y>ytime+120 && mouse_y<ytime+150)
{
SetTimeDIn.DrawOutline(CouleurBlind);
}
if(mouse_y>ytime+20 && mouse_y<ytime+50)
{
SetTimeIn.DrawOutline(CouleurBlind);
}
if(mouse_y>ytime+170 && mouse_y<ytime+200)
{
SetTimeDOut.DrawOutline(CouleurBlind);
}
if(mouse_y>ytime+70 && mouse_y<ytime+100)
{
SetTimeOut.DrawOutline(CouleurBlind);
}
}
}


petitchiffre.Print("IN",xtime+320,ytime+40);
petitchiffre.Print("OUT",xtime+315,ytime+90);
petitchiffre.Print("D.IN",xtime+313,ytime+140);
petitchiffre.Print("D.OUT",xtime+305,ytime+190);

Rect TapTempo(Vec2D(xtime+310,ytime+210),Vec2D(40,30));
TapTempo.SetRoundness(7.5);
TapTempo.SetLineWidth(demi_epaisseur_ligne_fader);
if(do_light_tap_tempo==1)
{
TapTempo.Draw(CouleurFader);
do_light_tap_tempo=0;
}
TapTempo.DrawOutline(CouleurLigne);
if(window_focus_id==W_TIME && mouse_x>xtime+310 && mouse_x<xtime+350 && mouse_y>ytime+210 && mouse_y<ytime+240)
{
TapTempo.DrawOutline(CouleurBlind);
}

Rect RecTempo(Vec2D(xtime+285,ytime+210),Vec2D(15,15));
RecTempo.SetRoundness(4);
if(index_recording_tap_tempo==1)
{RecTempo.Draw(CouleurBlind);}
RecTempo.DrawOutline(CouleurLigne);
if(window_focus_id==W_TIME && mouse_x>xtime+285 && mouse_x<xtime+300 && mouse_y>ytime+210 && mouse_y<ytime+225)
{
RecTempo.DrawOutline(CouleurBlind);
}
petitpetitchiffre.Print("R",xtime+288,ytime+220);
petitpetitchiffre.Print("Tempo",xtime+310,ytime+225);
petitpetitchiffre.Print(string_tap_tempo_average,xtime+260,ytime+252);
petitpetitchiffrerouge.Print(string_actual_tap_tempo,xtime+260,ytime+240);

Rect TapSend(Vec2D(xtime+265,ytime+210),Vec2D(15,15));
TapSend.SetRoundness(4);
if(do_light_send_tap==1)
{TapSend.Draw(CouleurFader);do_light_send_tap=0;}
TapSend.DrawOutline(CouleurLigne);
if(window_focus_id==W_TIME && mouse_x>xtime+265 && mouse_x<xtime+280 && mouse_y>ytime+210 && mouse_y<ytime+225  )
{
TapSend.DrawOutline(CouleurBlind);
}
petitpetitchiffre.Print("S",xtime+268,ytime+220);

Rect TimeAffect(Vec2D(xtime+280,ytime+260),Vec2D(70,30));
TimeAffect.SetRoundness(7.5);
TimeAffect.SetLineWidth(epaisseur_ligne_fader);

if(index_affect_time==1)
{
TimeAffect.Draw(CouleurFader);
TimeAffect.DrawOutline(CouleurFader);
}


if(window_focus_id==W_TIME && Midi_Faders_Affectation_Type!=0)
{
if(mouse_x>xtime+280 && mouse_x<xtime+350 && mouse_y>ytime+260 && mouse_y<ytime+290)
{
TimeAffect.DrawOutline(CouleurBlind);
}
}
petitchiffre.Print("AFFECT",xtime+290,ytime+280);
TimeAffect.DrawOutline(CouleurLigne);



button_midi_out_visu( xtime+250, ytime+250,758);
Line (Vec2D( xtime+231,ytime+231),Vec2D( xtime+245,ytime+245)).Draw(CouleurLigne);

return(0);
}
