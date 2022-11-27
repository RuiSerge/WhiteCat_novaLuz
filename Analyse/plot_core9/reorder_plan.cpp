int reorder_plan(int the_calc)
{
    for(int s=1; s<=nbre_symbols_on_plot[the_calc]; s++)
    {
        if(symbol_type[the_calc][s]==999)
        {
            for(int yu=s; yu<=nbre_symbols_on_plot[the_calc]; yu++)
            {
                if(symbol_type[the_calc][yu]!=999)
                {
                    copy_symbol_to_emply_slot(the_calc,s,yu);//(int calc, int empty, int filled)
                    clear_symbol_slot(the_calc,yu);
                    break;
                }

            }
        }

    }

    return(0);
}
