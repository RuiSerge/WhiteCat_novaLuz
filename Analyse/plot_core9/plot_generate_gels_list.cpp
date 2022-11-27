int plot_generate_gels_list()
{

    plot_reset_list_gelat();
    for(int c=0; c<4; c++)
    {
        if( show_calc_number[c]==1)
        {
            for(int s=1; s<=nbre_symbols_on_plot[c]; s++)
            {
                for(int g=0; g<3; g++) //3 slots de gelat par symbol
                {
                    if( gelat[c][s][g]!=0 && gelat_family[c][s][g]<5) //si une gelat non zero et inférieure à la marque 0 à 4 pour ne pas déborder du tableau
                    {
                        tmp_gel_list[gelat_family[c][s][g]][(gelat[c][s][g])][(symbol_type[c][s])]++;
                    }
                }
            }
        }
    }


    char GelTyp[12];
    nbre_ligne_pour_gelats=0;
    int index_geo=0;

    for(int g=0; g<nbre_gelats_manufact; g++)
    {
        for(int t=1; t<1000; t++) //3 slots de gelat par symbol
        {
            for(int s=0; s<127; s++)
            {
                if(tmp_gel_list[g][t][s]!=0)
                {
                    switch(g)
                    {
                    case 0:
                        sprintf(GelTyp,"Lee");
                        break;
                    case 1:
                        sprintf(GelTyp,"Rosco");
                        break;
                    case 2:
                        sprintf(GelTyp,"GamColor");
                        break;
                    case 3:
                        sprintf(GelTyp,"Apollo");
                        break;
                    default:
                        sprintf(GelTyp," ");
                        break;
                    }
                    sprintf(Geo[index_geo]," %s %d x %d %s",GelTyp, t, tmp_gel_list[g][t][s],symbol_nickname[s]);
                    index_geo++;
                }
            }

        }

    }

    nbre_ligne_pour_gelats=index_geo;
    return(0);
}
