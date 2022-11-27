int write_curve()
{
index_writing_curve=1;
 int points[MAX_curve_nodeS ];// etait [8] le 24 aout


 curve_curviness = ftofix(curve_spline_level);
 curve_calc_tangents();

 for(int nio=1;nio<(curve_node_count-1);nio++)
 {
 curve_get_control_points(curve_nodes[nio],curve_nodes[nio+1],points);

 int resolu= (curve_nodes[nio+1].x) - (curve_nodes[nio].x);
 int temp_curve_x[resolu];
 int temp_curve_y[resolu];
 calc_spline(points,resolu,  temp_curve_x, temp_curve_y);

 int index_sp=0;

 for(int cuv=0;cuv<resolu;cuv++)
 {
 index_sp=(curve_nodes[nio].x+cuv)-(xpatch_window+30+455);

 if(index_sp>255){index_sp=255;}
 if(index_sp<0){index_sp=0;}

 curve_report[curve_selected][index_sp]=temp_curve_y[cuv]-(ypatch_window+50);

 if(curve_report[curve_selected][index_sp]<0){curve_report[curve_selected][index_sp]=0;}
 if(curve_report[curve_selected][index_sp]>255){curve_report[curve_selected][index_sp]=255;}

 }
 }
index_writing_curve=0;
 return(0);
}
