int Receive_sunlite_dmxIN()
{
if(dasusbcommand >0 && index_quit==0 && index_allow_sunlite_dmxIN==1)
{
for (int p=0;p<511;p++)//etait 512 aout 2016
{
 dmxIN[p+2]=dmxINsunlite[p];   //ok +2 fonctionne tres bien de 1 à 512 compris
}
}
return(0);
}
