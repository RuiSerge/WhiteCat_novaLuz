int Detect_EnttecProIn()
{
    com_handle_IN = NULL;
    // Search in Windows Registry for serial COM
    {
        HKEY        hKeyIN;
        DWORD       DeviceNameLenIN, KeyNameLenIN;
        char		KeyNameIN[256];
        intptr_t idmxIN ;//modification 2 aout était int idmx; pb de pointeur 32 vers 64
        if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\SERIALCOMM", 0, KEY_QUERY_VALUE, &hKeyIN) != ERROR_SUCCESS)
        {
            sprintf(string_display_dmx_params,"Impossible to load DLL");
            return(0);
        }
        idmxIN = istheresomeone_in_enttecpro+1;//depart après position enttec pro out
        while(idmxIN < 50)
        {
            DeviceNameLenIN = 80;
            KeyNameLenIN = 100;
            if (RegEnumValue(hKeyIN,idmxIN,KeyNameIN,&KeyNameLenIN,NULL,NULL,DeviceNameIN,&DeviceNameLenIN) != ERROR_SUCCESS) break;

            if (!strncmp(KeyNameIN,"\\Device\\VCP",11))
            {
                sprintf(string_display_dmx_params,"detected Vcom in %d!",idmxIN);
                index_init_EnttecPROIN_ok=1;
                vcom_inposition_is=idmxIN;
                // we found a serial COM device, COM port "idmx"
                break;
            }

            DeviceNameIN[0] = 0;
            idmxIN++;
        }
        RegCloseKey(hKeyIN);

        if (idmxIN == 50)
        {
            sprintf(string_display_dmx_params,"No VCOM for IN founded. ");
            return(0);
        }
        sprintf(string_display_dmx_params,"Founded Enttec Pro In :%s",DeviceNameIN);
    }
    return(0);
}
