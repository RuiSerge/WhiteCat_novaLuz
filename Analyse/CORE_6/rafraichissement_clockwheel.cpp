int rafraichissement_clockwheel()
{

   clock_vx = cos(angle_snap_clock)* rayon_wheel_level;
   clock_vy = sin(angle_snap_clock)* rayon_wheel_level;
   position_curseur_clock_x= window_cfgX+770+clock_vx;
   position_curseur_clock_y=window_cfgY+115+clock_vy ;


return(0);
}
