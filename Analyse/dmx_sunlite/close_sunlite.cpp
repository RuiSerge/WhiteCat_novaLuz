int close_sunlite()
{
 //fermeture device
 if (dasusbcommand != NULL)
         {
              int iReto=dasusbcommand(DHC_CLOSE,0,0);
              switch(iReto)
              {
              case 1:
              sprintf(string_display_dmx_params,"Sunlite close=Ok");
              break;
              case -2:
              sprintf(string_display_dmx_params,"Sunlite close=No / Device not open");
              break;
              case -1:
              sprintf(string_display_dmx_params,"Sunlite close=No / Error Command");
              break;
              default: break;
              }

              dasusbcommand(DHC_EXIT,0,NULL);
              sprintf(string_display_dmx_params,"Sunlite close dll access=Ok");
         }

 //déchargement dll
 if (hLibSunlite != NULL)
     {     FreeLibrary(hLibSunlite);
        hLibSunlite = NULL;
     }

sprintf(string_display_dmx_params,">>Sunlite closed");
 return(0);
}
