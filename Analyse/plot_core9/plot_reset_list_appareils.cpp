int plot_reset_list_appareils()
{
nbre_symbols_differents_sur_plot=0;
for (int i=0;i<nbre_symbol_per_layer;i++)
{
plot_list_appareils[i]=0;
plot_show_typ_appareil[i]=0;
}

plot_reset_list_gelat();
 return(0);
}
