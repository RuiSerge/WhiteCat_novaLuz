int plot_draw_plan(int plotx, int ploty, int plot_calc_number_is)
{

    for(int i=1; i<=nbre_symbols_on_plot[plot_calc_number_is]; i++)
    {
        switch(symbol_type[plot_calc_number_is][i])
        {
        case 0:     //PC 500 ou 650
            plot_draw_symbol_pc(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 1:     //PC 1kw
            plot_draw_symbol_pc(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 2:     //PC2kw
            plot_draw_symbol_pc(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i],i, plot_calc_number_is);
            break;
        case 3:    //fresnel 1kw
            plot_draw_symbol_fresnel(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 4:    //fresnel 2kw
            plot_draw_symbol_fresnel(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 5:    //fresnel 5kw
            plot_draw_symbol_fresnel(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 6: //dec source four
            plot_draw_symbol_decoupe_etc_1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 7: //dec source four
            plot_draw_symbol_decoupe_etc_2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 8: //dec source four
            plot_draw_symbol_decoupe_etc_3(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 9: //dec 1kw longue
            plot_draw_symbol_decoupe_1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 10: //dec 1kw mid
            plot_draw_symbol_decoupe_2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 11: //dec 1kw wide
            plot_draw_symbol_decoupe_3(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 12: //dec 2kw
            plot_draw_symbol_decoupe_1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 13: //dec 2kw
            plot_draw_symbol_decoupe_2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 14: //dec 2kw
            plot_draw_symbol_decoupe_3(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 15: //PAR CP60
            plot_draw_symbol_Par_1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 16: //PAR CP61
            plot_draw_symbol_Par_2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 17: //PAR CP62
            plot_draw_symbol_Par_3(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 18: //PAR CP95
            plot_draw_symbol_Par_4(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 19://par 56 CP60
            plot_draw_symbol_Par_1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1],size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 20://par 56 CP61
            plot_draw_symbol_Par_2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 21://par 56 CP62
            plot_draw_symbol_Par_3(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 22://Par 36
            plot_draw_symbol_Par_4(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 23://par 20
            plot_draw_symbol_Par_3(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 24://par 16
            plot_draw_symbol_Par_1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 25://horiziode assymetrique
            plot_draw_symbol_Horiziode_assym(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 26://horiziode symetrique
            plot_draw_symbol_Horiziode_sym(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 27://hallogene de chantier
            plot_draw_symbol_Horiziode_sym(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 28://BT250w
            plot_draw_symbol_BT(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 29://BT500W
            plot_draw_symbol_BT(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 30://rampe brabo
            plot_draw_symbol_T8(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 31://blinder
            plot_draw_symbol_Blinder(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 32://Svob
            plot_draw_symbol_Svoboda(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 33://ACL
            plot_draw_symbol_ACL(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 34://FLUO
            plot_draw_symbol_fluo_little(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 35://FLUO
            plot_draw_symbol_fluo_big(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 36://Follow Spot
            plot_draw_symbol_FollowSpot1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 37://Follow Spot
            plot_draw_symbol_FollowSpot2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 38://VP1
            plot_draw_symbol_VP1(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 39://VP2
            plot_draw_symbol_VP2(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 40://slide projector
            plot_draw_symbol_slideprojector(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 41://retro projector
            plot_draw_symbol_retroprojector(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 42://volets
            plot_draw_symbol_barndoors(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 43://tophat
            plot_draw_symbol_top_hat(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 44://color extender
            plot_draw_symbol_color_extender(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 45://color changer
            plot_draw_symbol_colorchanger(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 46://jalousie
            plot_draw_symbol_jalousie(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 47://iris
            plot_draw_symbol_iris(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 48://gobo
            plot_draw_symbol_goboholder(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 49://shutter
            plot_draw_symbol_shutter(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 50://mirror
            plot_draw_symbol_motorized_mirror(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 51://smoke machine
            plot_draw_symbol_smokemachine(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 52://fog machine
            plot_draw_symbol_fogmachine(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 53://DIIMMER LINE
            plot_draw_symbol_dimmerline(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 54://direct
            plot_draw_symbol_direct(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 55://service
            plot_draw_symbol_serviceligth(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 56://platine
            plot_draw_symbol_platine_de_sol(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 57://pied
            plot_draw_symbol_littlestand(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 58://grand pied
            plot_draw_symbol_bigstand(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 59://barre de couplage
            plot_draw_symbol_barre_de_couplage(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 60://Echelle
            plot_draw_symbol_echelle(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 61://pont 50 1m
            plot_draw_symbol_pont50_1m(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 62://pont 50 3m
            plot_draw_symbol_pont50_3m(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 63://pont 50 jonction
            plot_draw_symbol_pont50_jonction(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 64://pont 30 1m
            plot_draw_symbol_pont30_1m(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 65://pont 30 3m
            plot_draw_symbol_pont30_3m(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;
        case 66://pont 30 jonction
            plot_draw_symbol_pont30_jonction(plotx+pos_symbol[plot_calc_number_is][i][0], ploty+pos_symbol[plot_calc_number_is][i][1], size_symbol[(symbol_type[plot_calc_number_is][i])]*global_symbol_size,  angle_symbol[plot_calc_number_is][i], i, plot_calc_number_is);
            break;

        default:
            break;
        }


        if( index_edit_light_plot==1 && (index_menus_lighting_plot==2 || index_menus_lighting_plot==4))//visualition du centre projo
        {
            Line(Vec2D(plotx+pos_symbol[plot_calc_number_is][i][0]-5,ploty+pos_symbol[plot_calc_number_is][i][1]-5),Vec2D(plotx+pos_symbol[plot_calc_number_is][i][0]+5,ploty+pos_symbol[plot_calc_number_is][i][1]+5)).Draw(CouleurBlind);
            Line(Vec2D(plotx+pos_symbol[plot_calc_number_is][i][0]+5,ploty+pos_symbol[plot_calc_number_is][i][1]-5),Vec2D(plotx+pos_symbol[plot_calc_number_is][i][0]-5,ploty+pos_symbol[plot_calc_number_is][i][1]+5)).Draw(CouleurBlind);
            if(plot_show_options[6]==1)
            {
                petitchiffrenoir.Print(ol::ToString(i),plotx+pos_symbol[plot_calc_number_is][i][0],ploty+pos_symbol[plot_calc_number_is][i][1]);
                if(symbol_is_linked_to[plot_calc_number_is][i]>0)
                {
                    char temp_txt_grp[16];
                    sprintf(temp_txt_grp,"Grp to %d",symbol_is_linked_to[plot_calc_number_is][i]);
                    petitchiffrenoir.Print(temp_txt_grp,plotx+pos_symbol[plot_calc_number_is][i][0],ploty+10+pos_symbol[plot_calc_number_is][i][1]);
                }

            }//show ID
            if( plot_show_options[7]==1)
            {
                switch(plot_name_text_size)
                {
                case 0:
                    for(int n=0; n<4; n++)
                    {
                        petitchiffrenoir.Print(symbol_note[plot_calc_number_is][i][n], plotx+pos_symbol[plot_calc_number_is][i][0]+relatif_plot_xy[plot_calc_number_is][i][4][0],ploty+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][4][1]+(n*10));
                    }
                    break;
                case 1:
                    for(int n=0; n<4; n++)
                    {
                        minichiffre.Print(symbol_note[plot_calc_number_is][i][n], plotx+pos_symbol[plot_calc_number_is][i][0]+relatif_plot_xy[plot_calc_number_is][i][4][0],ploty+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][4][1]+(n*10));
                    }
                    break;
                default:
                    break;
                }
            }
        }


        if( symbol_channel_is[plot_calc_number_is][i]!=0 && i>0)
        {

            bool way=0;
            if(plot_show_options[0]==1)
            {

                if(symbol_is_linked_to[plot_calc_number_is][i]==0)
                {

                    if(relatif_plot_xy[plot_calc_number_is][i][0][0]<0) way=1; //( right to left)
                    draw_line_to_channel_of_symbol(plotx+pos_symbol[plot_calc_number_is][i][0],ploty+pos_symbol[plot_calc_number_is][i][1],
                                                   plotx+pos_symbol[plot_calc_number_is][i][0]+relatif_plot_xy[plot_calc_number_is][i][0][0],
                                                   ploty+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][0][1], way);

                    draw_channel_of_symbol(plot_calc_number_is,i,
                                           plotx+pos_symbol[plot_calc_number_is][i][0]+relatif_plot_xy[plot_calc_number_is][i][0][0],
                                           ploty+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][0][1]);
                }
                else
                {
                    int dest_s=symbol_is_linked_to[plot_calc_number_is][i];
                    way=0;
                    if((plotx+pos_symbol[plot_calc_number_is][dest_s][0]+relatif_plot_xy[plot_calc_number_is][dest_s][0][0])-(plotx+pos_symbol[plot_calc_number_is][i][0])<0)
                        way=1;
                    draw_line_to_channel_of_symbol(
                        plotx+pos_symbol[plot_calc_number_is][i][0],
                        ploty+pos_symbol[plot_calc_number_is][i][1],
                        plotx+pos_symbol[plot_calc_number_is][dest_s][0]+relatif_plot_xy[plot_calc_number_is][dest_s][0][0],
                        ploty+pos_symbol[plot_calc_number_is][dest_s][1]+relatif_plot_xy[plot_calc_number_is][dest_s][0][1],
                        0);
                }


            }

            if(plot_show_options[1]==1 )
                switch( plot_name_text_size)
                {
                case 0:
                    petitchiffrenoir.Print(descriptif_projecteurs[(symbol_channel_is[plot_calc_number_is][i])],
                                           plotx+pos_symbol[plot_calc_number_is][i][0]-50+relatif_plot_xy[plot_calc_number_is][i][1][0],(ploty+50+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][1][1]));
                    break;
                case 1:
                    minichiffre.Print(descriptif_projecteurs[(symbol_channel_is[plot_calc_number_is][i])],
                                      plotx+pos_symbol[plot_calc_number_is][i][0]-50+relatif_plot_xy[plot_calc_number_is][i][1][0],(ploty+50+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][1][1]));
                    break;
                default:
                    break;
                }
        }


        if(plot_show_options[5]==1 && symbol_dimmer_is[plot_calc_number_is][i]!=0 )
        {
            sprintf(temp_plot_info,"d:%d",symbol_dimmer_is[plot_calc_number_is][i]);
            petitchiffrenoir.Print(temp_plot_info,plotx+pos_symbol[plot_calc_number_is][i][0]+10+relatif_plot_xy[plot_calc_number_is][i][3][0],ploty+pos_symbol[plot_calc_number_is][i][1]+80+relatif_plot_xy[plot_calc_number_is][i][3][1]);

        }
        draw_gels_of_a_symbol(plot_calc_number_is,i,
                              plotx+pos_symbol[plot_calc_number_is][i][0]+relatif_plot_xy[plot_calc_number_is][i][2][0],ploty+pos_symbol[plot_calc_number_is][i][1]+relatif_plot_xy[plot_calc_number_is][i][2][1]);


    }

    return(0);
}
