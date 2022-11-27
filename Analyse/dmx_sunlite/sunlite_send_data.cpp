int sunlite_send_data()
{
do_send_dmx_on_change_siudi=0;
for(int z=0;z<512;z++)
       {
       DmxBlockSunlite[z]=DmxBlock[z+1];
       //au cas ou 5C ou 6C ont besoin de tempo
       if(index_is_siudi_8C==0 && DmxBlockSunlite[z]!=dmxbackup_sunlite[z])
       {  do_send_dmx_on_change_siudi=1;}
       }

if (dasusbcommand >0)
       { dasusbcommand(DHC_DMXOUT,512,DmxBlockSunlite);  }
 return(0);
}
