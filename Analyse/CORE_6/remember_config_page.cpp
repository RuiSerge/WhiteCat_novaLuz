int remember_config_page()
{
    if(index_config_dmx==1)
    {
        config_page_is=1;
    }
    else if(index_config_midi==1)
    {
        config_page_is=2;
    }
    else if(index_config_network==1)
    {
        config_page_is=3;
    }
    else if(index_setup_gfx==1)
    {
        config_page_is=4;
    }
    else if(index_config_arduino==1)
    {
        config_page_is=5;
    }
    else if(index_config_general==1)
    {
        config_page_is=6;
    }
    else if(index_config_core==1)
    {
        config_page_is=7;
    }
    /// sab 12/08/2016 - Onglet des Hot Keys ////////////////////////////////////////////
    else if(index_config_tab_hotkeys==1)
    {
        config_page_is=8;
    }
    return(0);
}
