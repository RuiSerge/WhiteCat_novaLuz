int do_logical_Draw_TrackingAera(int xw,int yw)
{
if(window_focus_id==W_DRAW && mouse_x>=xw && mouse_x<=xw+draw_tracking_aera_size_x && mouse_y>=yw && mouse_y<=yw+draw_tracking_aera_size_y && mouse_button==1)
{
if( dragging_draw==0){snap_state_of_draw_grid(draw_preset_selected); dragging_draw=1;}
draw_point_is_traced[draw_preset_selected]=1;
Draw_point_and_perform_level_on_area_NEW(draw_preset_selected,mouse_x-xw,mouse_y-yw);
}
return(0);
}
