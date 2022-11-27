int Init_A_specific_dmx_interface(int i)
{
switch(i)
{
            case 1:
            initialisation_client_artnet();
            ConstructArtPoll();
            ConstructArtPollReply();
            //ArtPolling message ArtPoll
            nbrbytessended=sendto(sockartnet, ArtPollBuffer,sizeof( ArtPollBuffer),0,(SOCKADDR*)&sinS,sinsize);
             //ArtNet
            ArtDmx();
            nbrbytessended=sendto(sockartnet, ArtDmxBuffer,sizeof( ArtDmxBuffer),0,(SOCKADDR*)&sinS,sinsize);
            index_init_dmx_ok[i]=1;
            break;

            case 2:
            pUsbDmx = new Open_USB_DMX();
            if (pUsbDmx == NULL)//creation class
                {  sprintf(string_display_dmx_params,"Impossible to load DLL");	return(0);}
                sprintf(string_display_dmx_params,"Pointer Created");
                rest(100);
            if (pUsbDmx != NULL)
                   {
                          int iRet;
                          iRet = pUsbDmx->open_dmx_devices();
                          sprintf(string_display_dmx_params,"Enttec Open Dmx return :%d",iRet);
                          if (iRet==0)
                          { sprintf(string_display_dmx_params,"Impossible to open interface, is it PLUGGED ?");
                            return(0);
                          }
                          index_init_dmx_ok[i]=1;
                           for(int ko=0;ko<513;ko++)
                           {
                           DmxBlockEnttecOpen[ko]=DmxBlock[ko+1];
                           }
                          pUsbDmx->send_dmx_packet(DmxBlockEnttecOpen);

                    }
                 else {
                      sprintf(string_display_dmx_params,"Interface Opened !");
                      index_init_dmx_ok[i]=1;
                  }
            break;

            case 3:
            //VCOM
            Detect_EnttecProOut();
            Open_EnttecProOut();
            break;

            case 4:
            //sunlite
            open_sunlite();
            index_init_dmx_ok[i]=1;
            break;

            default:
            break;
        }

return(0);
}
