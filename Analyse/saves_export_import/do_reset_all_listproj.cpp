int do_reset_all_listproj()
{
for (int r=0;r<514;r++)
{
 strcpy(descriptif_projecteurs[r],"");
 descriptif_projecteurs[r][0]='\0';
}
 return(0);
}
