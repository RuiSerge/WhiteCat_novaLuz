int do_logical_my_window_Box(int mx, int my)
{

    if(window_focus_id==W_MY_WINDOW && mouse_released==0)//si focus sur la fenetre my window et que bouton pas enclenché
    {
        if(mouse_x>mx+260 && mouse_x<mx+280 && mouse_y>my+100 && mouse_y<my+120)
        {
            mouse_released=1; //on encleche le bouton pour pas avoir de double ordre
            my_window_variable_boolean=toggle(my_window_variable_boolean);
        }
        for(int i=0; i<6; i++) //pas de mouse released, c est que pour les boutons
        {
            if(mouse_x>mx+10+(i*35) && mouse_x<mx+30+(i*35) && mouse_y>my+60 && mouse_y<my+207)//10 pixels en haut et en bas en plus
            {
                my_window_fader_value[i] = constrain_data_to_midi_range((my+70+127)-mouse_y);//dans core_6.cpp
            }
        }

    }//fin condition focus

    return(0);
}
