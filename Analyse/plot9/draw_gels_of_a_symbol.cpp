int draw_gels_of_a_symbol(int calc, int symb, int plotx, int ploty)
{
for(int i=0;i<3;i++)//3 slots de gelat par symbol
{
if(plot_show_options[i+2]==1 && gelat[calc][symb][i]!=0 )
{
switch(gelat_family[calc][symb][i])
{
case 0:
sprintf(temp_plot_info,"L.%d",gelat[calc][symb][i]);
break;
case 1:
sprintf(temp_plot_info,"R.%d",gelat[calc][symb][i]);
break;
case 2:
sprintf(temp_plot_info,"G.%d",gelat[calc][symb][i]);
break;
case 3:
sprintf(temp_plot_info,"A.%d",gelat[calc][symb][i]);
break;
default:
strcpy(temp_plot_info,"");
break;
}
petitchiffrenoir.Print(temp_plot_info,plotx+10,(int)(ploty+(i*10)));
}
}
 return(0);
}
