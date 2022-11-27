int SetAllParams(int move_selected)
{
if (tracker_mode==1)
 {
 mover_params[0][1]=dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][0] ;
 mover_params[1][1]=dock_move_xy_16b[move_selected][(dock_move_actual_step[move_selected])][1] ;
 }

for (int o=1; o<dock_moves_contains_steps[move_selected]+1;o++)
{
for(int param=2;param<16;param++)
{
if(param_selected[param]==1)
{dock_asservis[move_selected][o][param-2]=mover_params[param][0] ;}

}
}
return(0);
}
