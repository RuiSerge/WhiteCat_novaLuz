int Close_EnttecProOut()
{
    CloseHandle(com_handle_);
    com_handle_ = NULL;
    sprintf(string_display_dmx_params,"ENTTEC PRO OUT : Closed...");
    return(0);
}
