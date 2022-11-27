int build_square_curve(int curve)
{
 //points
 curve_ctrl_pt[curve][1][0]=0; curve_ctrl_pt[curve][1][1]=255;//point 1 en 0 0

  curve_ctrl_pt[curve][2][0]=27; curve_ctrl_pt[curve][2][1]=255-89;//point 1 en 0 0
  curve_ctrl_pt[curve][3][0]=55; curve_ctrl_pt[curve][3][1]=255-153;//point 1 en 0 0
  curve_ctrl_pt[curve][4][0]=118; curve_ctrl_pt[curve][4][1]=255-213;//point 1 en 0 0

 curve_ctrl_pt[curve][5][0]=255; curve_ctrl_pt[curve][5][1]=0;//point 5 en 255 255

 the_curve_spline_level[curve]=176;
 index_curve_spline_level=176;
 curve_spline_level=(((float)index_curve_spline_level)/127)-1;
 curve_node_count=6;
 curve_curviness = ftofix(curve_spline_level);
 curve_calc_tangents();
 curve_draw_splines();
 view_curve_after_draw();
 return(0);
}
