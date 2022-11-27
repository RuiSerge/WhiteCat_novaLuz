int plot_ventilate_y(int calc)
{


    int the_highest_value=0;
    int the_lowest_value=0;
    int the_value=0;
    int the_count=0;
    int index_low_value=0;
    int index_high_value=0;

    for(int i=1; i<= nbre_symbols_on_plot[calc]; i++)
    {
        if(symbol_is_selected[calc][i]==1)
        {
            if(the_count==0)
            {
                the_highest_value=pos_symbol[calc][1][1];
                the_lowest_value=pos_symbol[calc][1][1];
            }
            the_count++;
            the_value=pos_symbol[calc][i][1];

            if(the_value>= the_highest_value)
            {
                the_highest_value=the_value;
                index_high_value=i;
            }
            else if(the_value<=the_lowest_value)
            {
                the_lowest_value=the_value;
                index_low_value=i;
            }
        }
    }

    if(the_lowest_value>the_highest_value)
    {
        the_lowest_value=return_lowest(the_lowest_value,the_highest_value);
        the_highest_value=return_highest(the_lowest_value,the_highest_value);
    }

    int the_frac=(int)(((float)(the_highest_value-the_lowest_value))/(the_count));
    the_count=0;
    for(int i=0; i<=nbre_symbols_on_plot[calc]; i++)
    {
        if(symbol_is_selected[calc][i]==1 && i!=index_low_value && i!=index_high_value)
        {
            the_count++;
            pos_symbol[calc][i][1]=(the_lowest_value+(the_frac*the_count));
        }
    }


    return(0);
}
