int Clear_the_Move(int move_selected)
{
for(int i=0;i<48;i++)
{
dock_move_xy[move_selected][i][0]=127;
dock_move_xy[move_selected][i][1]=127;
dock_move_xy_16b[move_selected][i][0]=127;
dock_move_xy_16b[move_selected][i][1]=127;
dock_time[move_selected][i]=0;
move_auto_stop[move_selected][i]=0;
dock_time[dock_move_selected][i]=1000;
GotoMoves[move_selected][i]=0;
for(int dd=0;dd<16;dd++)
{
dock_asservis[move_selected][(dock_move_actual_step[move_selected])][dd]=0;
}
}
x_val_at_beg[move_selected]=0.0;
y_val_at_beg[move_selected]=0.0;
x_val_at_end[move_selected]=0.0;
y_val_at_end[move_selected]=0.0;
x_fract[move_selected]=0.0;
y_fract[move_selected]=0.0;
spline_ratio[move_selected]=0.0;
dock_move_actual_step[move_selected]=1;
dock_moves_contains_steps[move_selected]=1;
Moves_Inpoint[move_selected]=1;

index_main_clear=0;
return(0);
}
