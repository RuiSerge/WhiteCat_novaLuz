int plot_reset_list_gelat()
{


for(int num=0;num<3;num++)//3 slots de gelat par symbol
{
for(int t=0;t<1000;t++)
{
for(int s=0;s<127;s++)
{
tmp_gel_list[num][t][s]=0;
}
strcpy(Geo[t],"");
}
}

nbre_ligne_pour_gelats=0;
 return(0);
}
