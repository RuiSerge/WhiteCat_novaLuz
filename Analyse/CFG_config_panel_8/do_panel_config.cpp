int do_panel_config(int cfg_X,int cfg_Y)
{

Rect ConfigPanel(Vec2D(cfg_X,  cfg_Y), Vec2D( largeurCFGwindow,hauteurCFGwindow));
ConfigPanel.SetRoundness(15);
ConfigPanel.Draw(CouleurConfig);
ConfigPanel.DrawOutline(CouleurLigne);

if(index_config_dmx==1)
{
do_dmx_config(cfg_X,cfg_Y,largeurCFGwindow,hauteurCFGwindow);
petitchiffre.Print( string_title_panel_config,cfg_X+20, cfg_Y+20);
}
else if(index_config_midi==1)
{
do_midi_config(cfg_X,cfg_Y,largeurCFGwindow,hauteurCFGwindow);
}
else if(index_config_arduino==1)
{
do_arduino_config(cfg_X,cfg_Y);
sprintf(string_title_panel_config,"ARDUINO CONFIGURATION");
petitchiffre.Print( string_title_panel_config,cfg_X+20, cfg_Y+20);
}
else if(index_setup_gfx==1)
{
do_screen_config(cfg_X,cfg_Y,largeurCFGwindow,hauteurCFGwindow);
sprintf(string_title_panel_config,"SCREEN CONFIGURATION");
petitchiffre.Print( string_title_panel_config,cfg_X+20, cfg_Y+20);
}
else if(index_config_network==1)
{
do_network_config(cfg_X,cfg_Y,largeurCFGwindow,hauteurCFGwindow);
sprintf(string_title_panel_config,"NETWORK/KBD");
petitchiffre.Print( string_title_panel_config,cfg_X+20, cfg_Y+20);
}
else if (index_config_general==1)
{
do_main_config(cfg_X,cfg_Y,largeurCFGwindow,hauteurCFGwindow);
sprintf(string_title_panel_config,"MAIN CONFIGURATION");
petitchiffre.Print( string_title_panel_config,cfg_X+20, cfg_Y+20);
}

else if(index_config_core==1)
{
do_core_config(cfg_X,cfg_Y,largeurCFGwindow,hauteurCFGwindow);
sprintf(string_title_panel_config,"CORE CONFIGURATION");
petitchiffre.Print( string_title_panel_config,cfg_X+20, cfg_Y+20);
}

    else if(index_config_tab_hotkeys==true)
    {
        do_hotkey_config(cfg_X,cfg_Y);
    }

if( index_config_dmx==1 || index_config_network==1 || index_config_general==1 ||  index_config_core==1)
{
Rect SaveCFG( Vec2D((cfg_X+largeurCFGwindow-110),(cfg_Y+hauteurCFGwindow-40)),Vec2D(90,30));
SaveCFG.SetRoundness(15);
SaveCFG.Draw(CouleurFond.WithAlpha(0.5));
if( window_focus_id==920)
{
if(mouse_x>(cfg_X+largeurCFGwindow-110) && mouse_x<(cfg_X+largeurCFGwindow-20)
&& mouse_y>(cfg_Y+hauteurCFGwindow-40)&& mouse_y<(cfg_Y+hauteurCFGwindow-10) )
{
SaveCFG.DrawOutline(CouleurLevel);
if(mouse_button==1 &&  mouse_released==0  )
{
SaveCFG.Draw(CouleurLevel);
if( index_config_dmx==1)
{
Save_my_dmx_conf();
save_artnet_conf();
}
else if(index_config_network==1)
{
save_network_settings();
}
else if( index_config_general==1)
{
Save_onstart_Config();
}
else if( index_config_core==1)
{
Save_Core_Config();
}
mouse_released=1;
}
}
}
petitchiffre.Print( "SAVE CFG",(cfg_X+largeurCFGwindow-100), (cfg_Y+hauteurCFGwindow-20));
}
return(0);
}
