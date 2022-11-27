int refresh_step_in_player(int grid_number, int num_step, int grider_player)
{
for(int chg=0;chg<513;chg++)
{
 buffer_gridder[grider_player][chg]=grid_levels[grid_number][num_step][chg];
}
return(0);
}
