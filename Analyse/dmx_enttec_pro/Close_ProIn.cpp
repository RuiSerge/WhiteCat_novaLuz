int Close_ProIn()
{
    CloseHandle(com_handle_IN);
    com_handle_IN = NULL;
    sprintf(string_display_dmx_params,"Enttec Pro IN %s is now closed",DeviceNameIN) ;
    index_init_EnttecPROIN_ok=0;
    return(0);
}
