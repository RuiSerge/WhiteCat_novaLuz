int SendData_to_interface()
{
for(int i=0;i<NB_INTERFACES;i++)
{
    if(do_DMX_out[i]==1)
    {
    if(index_init_dmx_ok[i]==1 )
        {
        switch(i)
        {
          case 1:
          ArtDmx();
          check_if_dmx_change();
          if(do_send_on_change==1)
          {
          nbrbytessended=sendto(sockartnet, ArtDmxBuffer,sizeof( ArtDmxBuffer),0,(SOCKADDR*)&sinS,sinsize);
          do_send_on_change=0;
          for(int bup=0;bup<512;bup++)
          {artnet_backup[bup]=DmxBlock[bup];}
          }
          break;
          //enttec open
          case 2:
         for(int ko=0;ko<513;ko++)
         {
         DmxBlockEnttecOpen[ko]=DmxBlock[ko+1];
         }
            if (pUsbDmx!= NULL)
                {
                pUsbDmx->send_dmx_packet(DmxBlockEnttecOpen);
                }
          break;
         //enttec pro
         case 3:
         //VCOM
          Enttec_Pro_SendData(6, DmxBlock, sizeof(DmxBlock),NULL);
         break;
         //sunlite
         case 4:
         sunlite_send_data();
         break;
         default:
         break;
         }
        }
    }
}

 return(0);
}
