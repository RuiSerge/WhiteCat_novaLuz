int  do_arduino_draw_input()
{
if( dragging_draw==0){snap_state_of_draw_grid(draw_preset_selected); dragging_draw=1;}
draw_point_is_traced[draw_preset_selected]=1;
Draw_point_and_perform_level_on_area_NEW(draw_preset_selected, draw_arduino_xy[0]+draw_arduino_xy[1],draw_arduino_xy[2]+draw_arduino_xy[3]);
return(0);
}
