int check_nbre_opened_windows()
{

int nbre_windows=0;
for(int i=0;i<63;i++)
{
/*Christoph 11/04/14 Begin replace */
if(window_opened[i]>=900 && window_opened[i]<=max_window_identity_is)
{
nbre_windows++;
}
}
 return(nbre_windows);
}
