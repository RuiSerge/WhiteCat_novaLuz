int Channel_macros_visu(int xlist, int ylist)
{

Line(Vec2D(xlist,ylist),Vec2D(xlist+300,ylist)).Draw(CouleurLigne.WithAlpha(0.5));
char titlemacro[36];
sprintf(titlemacro,"Channel Macro / CHANNEL %d",last_ch_selected );
petitchiffre.Print(titlemacro,xlist,ylist+15);
if(last_ch_selected!=0)
{
for(int i=0;i<nbre_macros_per_channel;i++)
{
Rect condition_B(Vec2D(xlist, ylist+25+(25*i)),Vec2D(80,20));
condition_B.SetRoundness(4);
condition_B.Draw(CouleurBleuProcedure.WithAlpha(0.5));
if(mouse_x>xlist && mouse_x<xlist+80 && mouse_y>ylist+25+(25*i) && mouse_y<ylist+45+(25*i) && window_focus_id==914)
{
condition_B.DrawOutline(CouleurLigne.WithAlpha(0.5));
}
switch(channel_macro_reaction[last_ch_selected][i])
{
case 0:
sprintf(titlemacro,"-");
break;
case 1:
sprintf(titlemacro,"        >=");
break;
case 2:
sprintf(titlemacro,"        > ");
break;
case 3:
sprintf(titlemacro,"        ==");
break;
case 4:
sprintf(titlemacro,"        !=");
break;
case 5:
sprintf(titlemacro,"        <=");
break;
case 6:
sprintf(titlemacro,"        <");
break;
case 7:
sprintf(titlemacro,"    Follow");
break;
case 8:
sprintf(titlemacro,"Follow Inv.");
break;
default:
break;
}
petitchiffre.Print(titlemacro,xlist+5, ylist+38+(25*i));

Rect lev_B(Vec2D(xlist+90, ylist+25+(25*i)),Vec2D(40,20));
lev_B.SetRoundness(4);
lev_B.Draw(CouleurBleuProcedure.WithAlpha(0.5));

switch (dmx_view)
{
case 0:
if(channel_macro_reaction[last_ch_selected][i]<7)
{sprintf(titlemacro,"%d", (int) (((float)(channel_macro_val[last_ch_selected][i][0]) /2.55)));}
else
{
sprintf(titlemacro,"%d",channel_macro_val[last_ch_selected][i][0]);
}
break;
case 1:
sprintf(titlemacro,"%d",channel_macro_val[last_ch_selected][i][0]);
break;
default: break;
}
petitchiffre.Print(titlemacro,xlist+95, ylist+38+(25*i));
if(mouse_x>xlist+90 && mouse_x<xlist+130 && mouse_y>ylist+25+(25*i) && mouse_y<ylist+45+(25*i) && window_focus_id==914)
{
lev_B.DrawOutline(CouleurLigne.WithAlpha(0.5));
}

Rect action_B(Vec2D(xlist+140, ylist+25+(25*i)),Vec2D(80,20));
action_B.SetRoundness(4);
action_B.Draw(CouleurBleuProcedure.WithAlpha(0.5));
if(mouse_x>xlist+140 && mouse_x<xlist+220 && mouse_y>ylist+25+(25*i) && mouse_y<ylist+45+(25*i)&& window_focus_id==914)
{
action_B.DrawOutline(CouleurLigne.WithAlpha(0.5));
}
switch(channel_macro_action[last_ch_selected][i])
{
case 0:
sprintf(titlemacro,"-");
break;
case 1:
sprintf(titlemacro,"Bang Banger");
break;
case 2:
sprintf(titlemacro,"Load Audio");
break;
case 3:
sprintf(titlemacro,"Play A.Pl");
break;
case 4:
sprintf(titlemacro,"Stop A.Pl");
break;
case 5:
sprintf(titlemacro,"Seek A.Pl");
break;
case 6:
sprintf(titlemacro,"Loop ON A.Pl");
break;
case 7:
sprintf(titlemacro,"Loop OFF A.Pl");
break;
case 8:
sprintf(titlemacro,"Volume A.Pl");
break;
case 9:
sprintf(titlemacro,"Pan A.Pl");
break;
case 10:
sprintf(titlemacro,"Pitch A.Pl");
break;
case 11:
sprintf(titlemacro, "MidiCh15 CC");
break;
case 12:
sprintf(titlemacro, "MidiCh15 KOn");
break;
case 13:
sprintf(titlemacro, "MidiCh15 KOff");
break;
case 14:
sprintf(titlemacro, "Fader Level");
break;
case 15:
sprintf(titlemacro, "FaderLFOSpeed");
break;
case 16:
sprintf(titlemacro, "Ch>Fader Num");
break;
case 17:
strcpy(titlemacro, "Ch>Stage %");
break;
default:
break;
}
petitchiffre.Print(titlemacro,xlist+145, ylist+35+(25*i));

Rect Vaction_B(Vec2D(xlist+230, ylist+25+(25*i)),Vec2D(40,20));
Vaction_B.SetRoundness(4);
Vaction_B.Draw(CouleurBleuProcedure.WithAlpha(0.5));
sprintf(titlemacro,"%d",channel_macro_val[last_ch_selected][i][1]);
petitchiffre.Print(titlemacro,xlist+235, ylist+38+(25*i));
if(mouse_x>xlist+230 && mouse_x<xlist+270 && mouse_y>ylist+25+(25*i) && mouse_y<ylist+45+(25*i) && window_focus_id==914)
{
Vaction_B.DrawOutline(CouleurLigne.WithAlpha(0.5));
}

Rect onoff_B(Vec2D(xlist+280, ylist+25+(25*i)),Vec2D(35,20));
onoff_B.SetRoundness(4);
onoff_B.Draw(CouleurBleuProcedure.WithAlpha(0.5));

switch( macro_channel_on[last_ch_selected][i])
{
case 0:
sprintf(titlemacro,"/Off");
break;
case 1:
onoff_B.Draw(CouleurBlind);
sprintf(titlemacro,"/On");
break;
default: break;
}
petitchiffre.Print(titlemacro,xlist+285, ylist+38+(25*i));
if(mouse_x>xlist+280 && mouse_x<xlist+315 && mouse_y>ylist+25+(25*i) && mouse_y<ylist+45+(25*i) && window_focus_id==914)
{
onoff_B.DrawOutline(CouleurLigne.WithAlpha(0.5));
}
}


}//fin si circuit != de 0
 return(0);
}
