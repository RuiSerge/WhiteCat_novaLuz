int Move_DelStep(int move_selected)
{
if(dock_moves_contains_steps[move_selected]>0)
{
for (int mv=dock_move_actual_step[move_selected]; mv<dock_moves_contains_steps[move_selected];mv++)
{
dock_move_xy[move_selected][mv][0]=dock_move_xy[move_selected][mv+1][0];
dock_move_xy[move_selected][mv][1]=dock_move_xy[move_selected][mv+1][1];
dock_move_xy_16b[move_selected][mv][0]=dock_move_xy_16b[move_selected][mv+1][0];
dock_move_xy_16b[move_selected][mv][1]=dock_move_xy_16b[move_selected][mv+1][1];
dock_asservis[move_selected][mv][0]=dock_asservis[move_selected][mv+1][0];  //iris
dock_asservis[move_selected][mv][1]=dock_asservis[move_selected][mv+1][1];  //focus
dock_asservis[move_selected][mv][2]=dock_asservis[move_selected][mv+1][2]; //zoom
dock_time[move_selected][mv]=dock_time[move_selected][mv+1];
move_auto_stop[move_selected][mv]=move_auto_stop[move_selected][mv+1];
}
dock_moves_contains_steps[move_selected]-=1;
if (dock_move_actual_step[move_selected]>1 ){dock_move_actual_step[move_selected]-=1;}
else if( dock_move_actual_step[move_selected]==1){dock_move_actual_step[move_selected]=dock_moves_contains_steps[move_selected];}
}
Move_refresh_xy(move_selected);
return(0);
}
