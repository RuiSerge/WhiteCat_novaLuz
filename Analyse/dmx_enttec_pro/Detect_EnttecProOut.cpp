int Detect_EnttecProOut()
{
com_handle_ = NULL;
	// Search in Windows Registry for serial COM
	{
		HKEY        hKey;
        DWORD       DeviceNameLen, KeyNameLen;
        char		KeyName[256];
		intptr_t idmx ;//modification 2 aout était int idmx; pb de pointeur 32 vers 64
        if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\SERIALCOMM", 0, KEY_QUERY_VALUE, &hKey) != ERROR_SUCCESS)
        {
			 sprintf(string_display_dmx_params,"No VCOM drivers installed !");
             return(0);
        }
        idmx = 0;
        while(idmx < 50) {
            DeviceNameLen = 80;
            KeyNameLen = 100;
            if (RegEnumValue(hKey,idmx,KeyName,&KeyNameLen,NULL,NULL,DeviceName,&DeviceNameLen) != ERROR_SUCCESS) break;

			if ((!strncmp(KeyName,"\\Device\\VCP",11)) && idmx!=arduino_com0)
			{
                index_init_dmx_ok[3]=1;
                istheresomeone_in_enttecpro=idmx;
                break;
				// we found a serial COM device, COM port "idmx"
			}

			DeviceName[0] = 0;

            idmx++;
		}



		RegCloseKey(hKey);

		if (idmx == 50)
		{
			 sprintf(string_display_dmx_params,"No ENTTEC PRO detected. ");
             return(0);
		}
	sprintf(string_display_dmx_params,"ENTTEC PRO Out is on : %s",DeviceName);
	}

return(0);
}
