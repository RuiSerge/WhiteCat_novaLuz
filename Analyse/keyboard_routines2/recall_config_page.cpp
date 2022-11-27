int recall_config_page()
{
    switch(config_page_is)
    {
    case 0:
        break;
    case 1:
        index_config_dmx=1;
        break;
    case 2:
        index_config_midi=1;
        break;
    case 3:
        index_config_network=1;
        break;
    case 4:
        index_setup_gfx=1;
        break;
    case 5:
        index_config_arduino=1;
        break;
    case 6:
        index_config_general=1;
        break;
    default: break;
    }
    return(0);
}
