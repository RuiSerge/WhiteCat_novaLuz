typedef int (CALLBACK * DasUsbCommand)(int command, int param, unsigned char *bloc );
{
  hLibSunlite = LoadLibrary("DasHard2006.dll");
 if (hLibSunlite == NULL)
 {
     sprintf(string_display_dmx_params,"Impossible to load sunlite DLL");
 }

 dasusbcommand = (DasUsbCommand) GetProcAddress(hLibSunlite, "DasUsbCommand");
 if (dasusbcommand == NULL)
 {
    sprintf(string_display_dmx_params,"Impossible to Get ProcAdress DASHARD");
  }

   int iReto=dasusbcommand(DHC_INIT,0,NULL);//init
   if( iReto>0){	sprintf(string_display_dmx_params,"Init Sunlite DLL version %d=Ok", iReto);}

   iReto = dasusbcommand(DHC_OPEN,0,NULL);
  		 	    if (iReto == 0)
    	    	{
    	    	sprintf(string_display_dmx_params,"Impossible to to open interface, is it PLUGGED ? Error: %d", iReto);
                }
                else if(iReto==1)
                {
                sprintf(string_display_dmx_params,"Sunlite open=Ok");
                }
   sunlite_version_number=dasusbcommand(DHC_VERSION,0,NULL);
   sunlite_serial_number=dasusbcommand(DHC_SERIAL,0,NULL);
   if (sunlite_serial_number>150001 && sunlite_serial_number<150001+100000)
   {
   sprintf(string_sunlite_is,"SIDUI-8C interface");
   index_is_siudi_8C=1;
   }
   else if (sunlite_serial_number>562173952 && sunlite_serial_number<562173952+100000){sprintf(string_sunlite_is,"SIDUI-5C interface");}
   else  if (sunlite_serial_number>61865984 && sunlite_serial_number<61865984+100000){sprintf(string_sunlite_is,"SIDUI-6C interface");}


 return(0);
}
