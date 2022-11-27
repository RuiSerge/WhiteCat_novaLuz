int copy_grid_partially(int from_grid_number, int from_num_step,int to_step_number, int dest_grid_number, int dest_num_step)
{
for(int defil=0;defil<=(to_step_number-from_num_step);defil++)
{
for(int chg=0;chg<513;chg++)
{
 grid_levels[dest_grid_number][dest_num_step+defil][chg]=grid_levels[from_grid_number][from_num_step+defil][chg];
}
for(int tt=0;tt<4;tt++)
{
grid_times[dest_grid_number][dest_num_step+defil][tt]=grid_times[from_grid_number][from_num_step+defil][tt];
}
grid_goto[dest_grid_number][dest_num_step+defil][0]=grid_goto[from_grid_number][from_num_step+defil][0];
grid_goto[dest_grid_number][dest_num_step+defil][1]=grid_goto[from_grid_number][from_num_step+defil][1];
grid_seekpos[dest_grid_number][dest_num_step+defil]=grid_seekpos[from_grid_number][from_num_step+defil];
grid_stoplay[dest_grid_number][dest_num_step+defil]=grid_stoplay[from_grid_number][from_num_step+defil];
grid_count[dest_grid_number][dest_num_step+defil]=grid_count[from_grid_number][from_num_step+defil];
grid_counted_times[dest_grid_number][dest_num_step+defil]=0;
}

return(0);
}
