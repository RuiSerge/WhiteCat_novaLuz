int selecteur_binary_save_solo_global(int xrep, int yrep)
{
Rect SwitchGlobal(Vec2D(xrep+170,yrep-35),Vec2D(70,20));
SwitchGlobal.SetRoundness(7.5);


if(window_focus_id==W_SAVE && mouse_x>xrep+170 && mouse_x<xrep+240 && mouse_y>yrep-35 && mouse_y<yrep-15)
{
SwitchGlobal.Draw(CouleurSurvol);
}
switch (index_save_global_is)
{
case 0:
SwitchGlobal.Draw(CouleurBlind.WithAlpha(alpha_blinker));
petitchiffre.Print("CHOICE",xrep+180,yrep-20);
break;
case 1:
SwitchGlobal.Draw(CouleurFader);
petitchiffre.Print("GLOBAL",xrep+180,yrep-20);
break;
default: break;
}
SwitchGlobal.DrawOutline(CouleurLigne);


char string_title_sav_spec[48];
for(int u=0;u<12;u++)
{
Rect SavePin(Vec2D(xrep,yrep+(u*15)),Vec2D(10,10));
if(specify_who_to_save_load[u]==1){SavePin.Draw(CouleurFader); }

switch (u)
{
case 0:
sprintf(string_title_sav_spec,"MEMORIES");
break;
case 1:
sprintf(string_title_sav_spec,"Mem.Times");
break;
case 2:
sprintf(string_title_sav_spec,"Mem.Links");
break;
case 3:
sprintf(string_title_sav_spec,"Mem.Bangers");
break;
case 4:
sprintf(string_title_sav_spec,"Mem.Man.Ratio");
break;
case 5:
sprintf(string_title_sav_spec,"Ch.List&Views");
break;
case 6:
sprintf(string_title_sav_spec,"Ch.DirectCH");
break;
case 7:
sprintf(string_title_sav_spec,"Ch.Freeze/Excl.");
break;
case 8:
sprintf(string_title_sav_spec,"Patch.Circuits");
break;
case 9:
sprintf(string_title_sav_spec,"Patch.LTP/HTP");
break;
case 10:
sprintf(string_title_sav_spec,"Patch.Curves");
break;
case 11:
sprintf(string_title_sav_spec,"BANGER");
break;
default: break;
}
petitpetitchiffre.Print(string_title_sav_spec,xrep+20,yrep+(u*15)+10);


SavePin.DrawOutline(CouleurLigne);


Rect SavePinSnd(Vec2D(xrep+110,yrep+(u*15)),Vec2D(10,10));

if(specify_who_to_save_load[u+12]==1){SavePinSnd.Draw(CouleurFader); }

switch (u)
{
case 0:
sprintf(string_title_sav_spec,"FADERS.Content");
break;
case 1:
sprintf(string_title_sav_spec,"Faders.LFO/Times");
break;
case 2:
sprintf(string_title_sav_spec,"Faders.Curves");
break;
case 3:
sprintf(string_title_sav_spec,"MINIF.Prsts/Lcks");
break;
case 4:
sprintf(string_title_sav_spec,"CHASERS");
break;
case 5:
sprintf(string_title_sav_spec,"MIDI.Affectation");
break;
case 6:
sprintf(string_title_sav_spec,"Midi.Cheat");
break;
case 7:
sprintf(string_title_sav_spec,"TRICHROMY");
break;
case 8:
sprintf(string_title_sav_spec,"VIDEO-TRACKING");
break;
case 9:
sprintf(string_title_sav_spec,"ARDUINO");
break;
case 10:
sprintf(string_title_sav_spec,"AUDIO.Conf");
break;
case 11:
sprintf(string_title_sav_spec,"iCAT");
break;
default: break;
}
petitpetitchiffre.Print(string_title_sav_spec,xrep+130,yrep+(u*15)+10);

SavePinSnd.DrawOutline(CouleurLigne);






Rect SavePinThrd(Vec2D(xrep+240,yrep+(u*15)),Vec2D(10,10));

if(specify_who_to_save_load[u+24]==1){SavePinThrd.Draw(CouleurFader); }

switch (u)
{
case 0:
sprintf(string_title_sav_spec,"Windows");
break;
case 1:
sprintf(string_title_sav_spec,"ColorProfile");
break;
case 2:
sprintf(string_title_sav_spec,"Keyboard.conf");
break;
case 3:
sprintf(string_title_sav_spec,"Indexes");
break;
case 4:
sprintf(string_title_sav_spec,"MOVER");
break;
case 5:
sprintf(string_title_sav_spec,"GRID");
break;
case 6:
sprintf(string_title_sav_spec,"GridPl1.CueList");
break;
case 7:
sprintf(string_title_sav_spec,"Light Plot");
break;
case 8:
sprintf(string_title_sav_spec,"DRAW");
break;
case 9:
sprintf(string_title_sav_spec,"ECHO");
break;
case 10:
sprintf(string_title_sav_spec,"WAVE");
break;
case 11:
sprintf(string_title_sav_spec,"Save Presets");
break;
default: break;
}
petitpetitchiffre.Print(string_title_sav_spec,xrep+260,yrep+(u*15)+10);


SavePinThrd.DrawOutline(CouleurLigne);

}

 return(0);
}
