int ventilation_niveaux_mover()
{
 inversion_of_axes();//X et Y

buffer_moving_head[irisadress]=mover_params[2][0];
buffer_moving_head[focusadress]=mover_params[3][0];
buffer_moving_head[zoomadress]=mover_params[4][0];



 return(0);
}
