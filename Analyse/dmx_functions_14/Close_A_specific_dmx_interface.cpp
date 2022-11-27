int Close_A_specific_dmx_interface(int i)
{
    switch(i)
        {
        //art-net
         case 1:
              fermeture_client_artnet();
              index_init_dmx_ok[i]=0;
         break;
         //enttec Open
         case 2:
         if (pUsbDmx != NULL)
                {
                pUsbDmx->close_dmx_devices();
                }
                sprintf(string_display_dmx_params,"Interface Closed");
                rest(100);
         if (pUsbDmx != NULL)//destruction classe
            {	delete pUsbDmx;
                pUsbDmx = NULL;
                sprintf(string_display_dmx_params,"Pointer Deleted");
            }
            index_init_dmx_ok[i]=0;
         break;
         //enttec PRO
         case 3:
         //VCOM
         Close_EnttecProOut();
         index_init_dmx_ok[i]=0;
         //FTDI_ClosePort();
         break;
         //sunlite
         case 4:
         close_sunlite();
         index_init_dmx_ok[i]=0;
         break;
         default:
         break;
         }

    return(0);
}
