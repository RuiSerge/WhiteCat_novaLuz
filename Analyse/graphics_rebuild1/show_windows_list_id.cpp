int show_windows_list_id(int x_info, int y_info)
{
petitpetitchiffre.Print("Nb.W.:",x_info,y_info);
petitpetitchiffre.Print(ol::ToString(nbre_fenetre_actives),x_info+35,y_info);
for(int i=0;i<63;i++)
{
if(window_opened[i]>0 && window_opened[i]<max_window_identity_is){petitpetitchiffre.Print(ol::ToString(window_opened[i]),x_info,y_info+10+(i*10));}
}
 return(0);
}
