int do_artnet_affect_config(int cfgnetw_X, int cfgnetw_Y)
{


petitchiffre.Print("ArtNet IN is :",(cfgnetw_X), (cfgnetw_Y));

Rect AllowIn(Vec2D((cfgnetw_X+140), cfgnetw_Y-13),Vec2D(50,20));
AllowIn.SetRoundness(7.5);
AllowIn.Draw(CouleurFond.WithAlpha(0.5));

switch(allow_artnet_in)
{
case 0:
petitchiffre.Print("/Off",(cfgnetw_X+150), (cfgnetw_Y));
break;
case 1:
AllowIn.Draw(CouleurFader);
petitchiffre.Print("/On",(cfgnetw_X+155), (cfgnetw_Y));
break;
default: break;
}

if(mouse_x>cfgnetw_X+140 && mouse_x<cfgnetw_X+190 && mouse_y> cfgnetw_Y-13 && mouse_y< cfgnetw_Y+7  && window_focus_id==W_CFGMENU )
{
AllowIn.DrawOutline(CouleurNiveau);
if(mouse_button==1 && mouse_released==0)
{
allow_artnet_in=toggle(allow_artnet_in);
switch(allow_artnet_in)
{
case 0:
     fermeture_serveur_artnet();
break;
case 1:
     initialisation_serveur_artnet();
break;
default: break;
}
mouse_released=1;
}
}



Rect AffectToDockN(Vec2D(cfgnetw_X, cfgnetw_Y+17),Vec2D(100,15));
AffectToDockN.SetRoundness(4);
AffectToDockN.Draw(CouleurBlind.WithAlpha(alpha_blinker*index_do_affect_net_to_dock));
AffectToDockN.DrawOutline(CouleurLigne.WithAlpha(0.7));

petitchiffre.Print("Affect to dock",(cfgnetw_X+5), (cfgnetw_Y+27));

if(window_focus_id==W_CFGMENU && mouse_x>cfgnetw_X && mouse_x<cfgnetw_X+100 && mouse_y>cfgnetw_Y+17 && mouse_y<cfgnetw_Y+17+15 && mouse_button==1 && mouse_released==0)
{
index_do_affect_net_to_dock=toggle(index_do_affect_net_to_dock);
index_do_dock=index_do_affect_net_to_dock;
mouse_released=1;
}

Rect AffectD(Vec2D(cfgnetw_X+140, cfgnetw_Y+12),Vec2D(50,25));
AffectD.SetRoundness(7.5);
AffectD.Draw(CouleurFond.WithAlpha(0.5));

petitchiffre.Print(ol::ToString(select_artnet_to_listen),cfgnetw_X+160, cfgnetw_Y+27);

if(window_focus_id==W_CFGMENU && mouse_x>cfgnetw_X+140 && mouse_x<cfgnetw_X+190 && mouse_y>cfgnetw_Y+25 && mouse_y<cfgnetw_Y+47 )
{
AffectD.DrawOutline(CouleurLigne.WithAlpha(0.6));
if(mouse_button==1 && mouse_released==0   )
{
int nu=atoi(numeric);
reset_numeric_entry();
numeric_postext=0;
if(nu>=0 && nu<=15)
{
select_artnet_to_listen=nu;
}
else{sprintf(string_Last_Order,"Universe must be from 0 to 15");}
}
mouse_released=1;
}


return(0);
}
