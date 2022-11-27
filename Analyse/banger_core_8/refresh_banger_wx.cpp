int refresh_banger_wx()
{
           //BANGER
           if(index_banger_is_on==1)//pour navigation rapide
           {

           //back du stage precedent a fabriquer

           //stage
           if(Banger_Memoire[position_onstage]>0 && Banger_Memoire[position_onstage]<128)
           {

           //effacement des autres bangers

           for (int p=0; p<128;p++)
           {
              bang_is_sended[p]=1;
              for (int y=0;y<6;y++){event_sended[p][y]=0;}
           }

           //envoi d un coup des events concerné par le crossfade
           for (int o=0;o<6;o++)
           {  Bang_event(Banger_Memoire[position_onstage]-1, o);}
           }



           }
           //
 return(0);
}
