int Channel_at_level()
{
 int chlevelis=0;
 if(dmx_view==0)
 {chlevelis=(int)( atof(numeric)*2.55); }
 else if (dmx_view==1)
 {chlevelis= atol(numeric);}
 if(chlevelis>255){chlevelis=255;}
 if(chlevelis<0){chlevelis=0;}

 for (int ci=1;ci<514;ci++)
 {
 if(Selected_Channel[ci]==1 && index_blind==0)    {bufferSaisie[ci]=chlevelis;}
 else if(Selected_Channel[ci]==1  && index_blind==1)    {bufferBlind[ci]=chlevelis;}
 }

 sprintf(string_Last_Order,">> Selection AT %d", chlevelis);
 return(0);
}
