void command_button_view( int xcom, int ycom, int isstate, const std::string desc, const std::string shortcut, int IDmidi)
{
Rect Command(Vec2D(xcom,ycom),Vec2D(65,20));
Command.SetRoundness(5);
Command.Draw(CouleurFond.WithAlpha(0.5));

switch(IDmidi)
{
case 754: //Blind
if(isstate==1)
{Command.Draw(CouleurSurvol.WithAlpha(alpha_blinker));}
Command.DrawOutline(CouleurBlind);
break;
case 1335://freeze
if(isstate==1)
{Command.Draw(CouleurBlind.WithAlpha(alpha_blinker));}
Command.DrawOutline(CouleurBlind);
break;
case 1541://exclude
if(isstate==1)
{Command.Draw(CouleurBlind.WithAlpha(alpha_blinker));}
Command.DrawOutline(CouleurBlind);
break;
case 1277: //MIdi Mute
if(isstate==1)
{Command.Draw(CouleurFader.WithAlpha(alpha_blinker));}
Command.DrawOutline(CouleurLigne);
Command.DrawOutline(CouleurBleuProcedure.WithAlpha(0.5));
break;
case 1333://direct Ch
if(isstate==1)
{Command.Draw(CouleurFader);}
if( multiple_direct_chan==1) {Command.Draw(CouleurBlind);}
Command.DrawOutline(CouleurFader);
break;
case 1334://View
if(isstate==1)
{Command.Draw(CouleurFader);}
Command.DrawOutline(CouleurFader);
break;
case 1542://hipass
if( index_do_hipass==1)
{Command.Draw(CouleurFader.WithAlpha(alpha_blinker));}
Command.DrawOutline(CouleurFader);
break;
case 1592://Fgroup
if(isstate==1)
{Command.Draw(CouleurYellowFgroup);}
Command.DrawOutline(CouleurFader);
break;
case 1625: //MIdi affect
switch(isstate)
{
case 1:
Command.Draw(CouleurLigne);
Command.Draw(CouleurBleuProcedure.WithAlpha(alpha_blinker));
break;
case 2:
Command.Draw(CouleurLigne);
Command.Draw(CouleurBlind.WithAlpha(alpha_blinker));
break;
default:
Command.DrawOutline(CouleurLigne);
Command.DrawOutline(CouleurBleuProcedure.WithAlpha(0.5));
break;
}
break;
case 1593:
if(do_light_midi_send_on_faders==1)
{ Command.Draw(CouleurFader);do_light_midi_send_on_faders=0;}
Command.DrawOutline(CouleurLigne);
Command.DrawOutline(CouleurBleuProcedure.WithAlpha(0.5));
break;
case 2047://exemple My window
if(isstate==1)
{Command.Draw(CouleurFader);}
Command.DrawOutline(CouleurLigne);
Command.DrawOutline(CouleurBleuProcedure.WithAlpha(alpha_blinker));  //animation qui est faite dans le fichier main
break;

default:
if(isstate==1)
{Command.Draw(CouleurFader);}
Command.DrawOutline(CouleurLigne.WithAlpha(0.8));
break;
}

if ( ( (window_focus_id==0 && index_over_A_window==0 )|| window_focus_id==W_MAINMENU) && mouse_x>xcom && mouse_x<xcom+60 && mouse_y>ycom && mouse_y<ycom+20)
{
if(Midi_Faders_Affectation_Type!=0 && IDmidi!=1625 )
{show_type_midi(IDmidi, desc);
Command.DrawOutline(CouleurBlind);}
}

petitpetitchiffre.Print(desc,xcom+5,ycom+12);
}
