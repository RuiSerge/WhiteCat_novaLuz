int rafraichissement_padwheel()
{
angle_snap_pad=(((PIknob*2)+angle_correction_wheel) / 128)*midi_levels[664];
   pad_vx = cos(angle_snap_pad)* rayon_wheel_level;
   pad_vy = sin(angle_snap_pad)* rayon_wheel_level;
   position_curseur_pad_x= xnum_window+10+260+pad_vx;
   position_curseur_pad_y=ynum_window+35+pad_vy ;
return(0);
}
