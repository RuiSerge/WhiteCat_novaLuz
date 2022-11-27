int plot_print_neutral_symbol(int s, int plotx, int ploty)
{

switch(s)
{
case 0:     //PC 500 ou 650
plot_draw_symbol_pc(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 1:     //PC 1kw
plot_draw_symbol_pc(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 2:     //PC2kw
plot_draw_symbol_pc(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 3:    //fresnel 1kw
plot_draw_symbol_fresnel(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 4:    //fresnel 2kw
plot_draw_symbol_fresnel(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 5:    //fresnel 5kw
plot_draw_symbol_fresnel(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 6: //dec 30°
plot_draw_symbol_decoupe_etc_1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 7: //dec 40°
plot_draw_symbol_decoupe_etc_2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 8: //dec 50°
plot_draw_symbol_decoupe_etc_3(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 9: //dec 1kw longue
plot_draw_symbol_decoupe_1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 10: //dec 1kw mid
plot_draw_symbol_decoupe_2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 11: //dec 1kw wide
plot_draw_symbol_decoupe_3(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 12: //dec 2kw
plot_draw_symbol_decoupe_1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 13: //dec 2kw
plot_draw_symbol_decoupe_2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 14: //dec 2kw
plot_draw_symbol_decoupe_3(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 15: //PAR CP60
plot_draw_symbol_Par_1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 16: //PAR CP61
plot_draw_symbol_Par_2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 17: //PAR CP62
plot_draw_symbol_Par_3(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 18: //PAR CP95
plot_draw_symbol_Par_4(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 19://par 56 CP60
plot_draw_symbol_Par_1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 20://par 56 CP61
plot_draw_symbol_Par_2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 21://par 56 CP62
 plot_draw_symbol_Par_3(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 22://Par 36
plot_draw_symbol_Par_4(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 23://par 20
plot_draw_symbol_Par_3(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 24://par 16
plot_draw_symbol_Par_1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 25://horiziode assymetrique
plot_draw_symbol_Horiziode_assym(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 26://horiziode symetrique
plot_draw_symbol_Horiziode_sym(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 27://hallogene de chantier
plot_draw_symbol_Horiziode_sym(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 28://BT250w
plot_draw_symbol_BT(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 29://BT500W
plot_draw_symbol_BT(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 30://rampe brabo
plot_draw_symbol_T8(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 31://blinder
plot_draw_symbol_Blinder(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 32://Svob
plot_draw_symbol_Svoboda(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 33://ACL
plot_draw_symbol_ACL(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 34://FLUO
plot_draw_symbol_fluo_little(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 35://FLUO
plot_draw_symbol_fluo_big(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 36://Follow Spot
plot_draw_symbol_FollowSpot1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 37://Follow Spot
plot_draw_symbol_FollowSpot2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 38://VP1
plot_draw_symbol_VP1(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 39://VP2
plot_draw_symbol_VP2(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 40://Proj diapo
plot_draw_symbol_slideprojector(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 41://Rétro Proj
plot_draw_symbol_retroprojector(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 42://volets
plot_draw_symbol_barndoors(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 43://tophat
plot_draw_symbol_top_hat(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 44://color extender
plot_draw_symbol_color_extender(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 45://color changer
plot_draw_symbol_colorchanger(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 46://jalousie
plot_draw_symbol_jalousie(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 47://iris
plot_draw_symbol_iris(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 48://gobo
plot_draw_symbol_goboholder(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 49://shutter
plot_draw_symbol_shutter(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 50://MOTORIZED MIRROR
plot_draw_symbol_motorized_mirror(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 51://smoke machine
plot_draw_symbol_smokemachine(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 52://fog machine
plot_draw_symbol_fogmachine(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 53:
plot_draw_symbol_dimmerline(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 54://direct
plot_draw_symbol_direct(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 55://service
plot_draw_symbol_serviceligth(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 56://platine
plot_draw_symbol_platine_de_sol(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 57://pied
plot_draw_symbol_littlestand(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 58://grand pied
plot_draw_symbol_bigstand(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 59://barre de couplage
plot_draw_symbol_barre_de_couplage(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 60://Echelle
plot_draw_symbol_echelle(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 61://pont 50 1m
plot_draw_symbol_pont50_1m(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 62://pont 50 3m
plot_draw_symbol_pont50_3m(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 63://pont 50 jonction
plot_draw_symbol_pont50_jonction(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 64://pont 30 1m
plot_draw_symbol_pont30_1m(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 65://pont 30 3m
plot_draw_symbol_pont30_3m(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
case 66://pont 30 jonction
plot_draw_symbol_pont30_jonction(plotx, ploty , size_symbol[s], 0, 0, 0);
break;
default:
break;
}

 return(0);
}
