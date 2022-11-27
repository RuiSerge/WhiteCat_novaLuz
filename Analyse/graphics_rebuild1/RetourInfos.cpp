int RetourInfos(int x_info,int y_info)
{

    neuro.Print(string_numeric_entry,x_info,y_info+15);//input chaine clavier numerique
    petitchiffre.Print(string_last_ch,x_info,y_info+30);//input last ch selected
    petitchiffre.Print(string_last_copy_mem,x_info+170,y_info+30);

    Rect VisuHue(Vec2D(x_info+290,y_info+15),Vec2D(30,20));
    Rgba CouleurPreviewHue(r_pick,v_pick,b_pick,255);
    VisuHue.Draw(CouleurPreviewHue);
    Rgba CouleurPreviewChroma(my_red,my_green,my_blue,255);
    Rect VisuChroma(Vec2D(x_info+325,y_info+15),Vec2D(30,20));
    VisuChroma.Draw(CouleurPreviewChroma);
    petitpetitchiffre.Print(string_dock_col_sel,x_info+293,y_info+30);

    petitchiffre.Print(string_secondary_feeback,x_info,y_info+45);//
    petitchiffrerouge.Print(string_display_dmx_params,x_info,y_info+60);
    petitchiffre.Print(">>MIDI IN:",x_info, y_info+75);//midi in
    petitchiffre.Print(my_midi_string,x_info+70, y_info+75);//midi in

    petitchiffre.Print("Time Is:",x_info,y_info+90);
    petitchiffre.Print(tmp_time,x_info+60,y_info+90);
    sprintf(visu_chrono_str,"Chrono: %d..%d.%d",time_minutes,time_secondes, time_centiemes);
    sprintf(visu_big_chrono,"%d..%d",time_minutes,time_secondes);
    petitchiffre.Print(visu_chrono_str,x_info+170,y_info+90);
    petitchiffrerouge.Print(string_Last_Order,x_info, y_info+105);//last order
    diodes_artnet(x_info,y_info+120);
    if(index_do_light_diode_artnet==1)
    {
        light_temoin_universe(incoming_universe,x_info,y_info+120);
        index_do_light_diode_artnet=0;
    }
    if((do_DMX_out[1]==1 && index_init_dmx_ok[1]==1) )
    {
        light_temoin_emission(Univers,x_info,y_info+120);
    }



    return(0);
}
