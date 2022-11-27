int check_select_deselect_symbol(int posx, int posy)
{
    int previous_calc_selection=view_plot_calc_number_is;
    int is_manipulated=0;
    int second_round=0;
    for(int calc=0; calc<4; calc++)
    {
        if(show_calc_number[calc]==1)
        {
            for(int i=nbre_symbols_on_plot[calc]+1; i>0 ; i--)
            {
                if(mouse_x>posx+pos_symbol[calc][i][0]-10 && mouse_x<posx+pos_symbol[calc][i][0]+10
                        && mouse_y>posy+pos_symbol[calc][i][1]-10 && mouse_y<posy+pos_symbol[calc][i][1]+10)
                {
                    symbol_is_selected[calc][i]=toggle(symbol_is_selected[calc][i]);
                    view_plot_calc_number_is=calc;
                    is_manipulated=i;
                    if(symbol_is_selected[calc][i]==1)
                    {
                        last_selected_symbol_is=i;
                        symbol_selected_type=symbol_type[calc][i];
                        last_ch_selected=symbol_channel_is[calc][i];
                    }

                    if((symbol_channel_is[calc][i])!=0)
                    {
                        Selected_Channel[(symbol_channel_is[calc][i])]=symbol_is_selected[calc][i];
                    }
                    for(int gr=1; gr<=nbre_symbols_on_plot[calc] ; gr++)
                    {
                        if(symbol_channel_is[calc][gr]!=0 && symbol_channel_is[calc][gr]==symbol_channel_is[calc][is_manipulated] )//ismanipulated si déselection
                        {
                            if( symbol_is_linked_to[calc][gr]==is_manipulated || symbol_is_linked_to[calc][is_manipulated ]==gr )
                            {
                                symbol_is_selected[calc][gr]=symbol_is_selected[calc][is_manipulated];
                                second_round=gr;
                            }
                            for (int g=1; g<=nbre_symbols_on_plot[calc]; g++)
                            {
                                if(symbol_channel_is[calc][g]!=0 && symbol_channel_is[calc][g]==symbol_channel_is[calc][is_manipulated] &&  symbol_is_linked_to[calc][g]!=0 && ( symbol_is_linked_to[calc][g]==is_manipulated || symbol_is_linked_to[calc][g ]==second_round ) )
                                {
                                    symbol_is_selected[calc][g]=symbol_is_selected[calc][is_manipulated];
                                }
                            }
                        }
                    }

                    mouse_released=1;
                    break;
                }
            }
        }
    }


    if(view_plot_calc_number_is!=previous_calc_selection)
    {
        reset_symbols_selected(previous_calc_selection);
    }



    return(0);
}
