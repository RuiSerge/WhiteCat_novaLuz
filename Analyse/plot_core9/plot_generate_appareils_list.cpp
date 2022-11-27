int plot_generate_appareils_list()
{
plot_reset_list_appareils();
for(int l=0;l<4;l++)
{
if(show_calc_number[l]==1)
{
for (int i=0;i<=nbre_symbols_on_plot[l];i++)
{
plot_show_typ_appareil[(symbol_type[l][i])]=1;
plot_list_appareils[(symbol_type[l][i])]++;
}
}
}

int addx=0;
for (int i=0;i<127;i++)
{
if( plot_show_typ_appareil[i]==1)
{
index_list_appareils_pour_la_legende[addx]=i;
addx++;
nbre_symbols_differents_sur_plot++;
}
}


plot_generate_gels_list();
 return(0);
}
