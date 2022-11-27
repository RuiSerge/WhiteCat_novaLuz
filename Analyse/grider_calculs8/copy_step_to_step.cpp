int copy_step_to_step(int from_grid_number, int from_num_step, int dest_grid_number, int dest_num_step)
{
for(int chg=0;chg<513;chg++)
{
 grid_levels[dest_grid_number][dest_num_step][chg]=grid_levels[from_grid_number][from_num_step][chg];
}
for(int tt=0;tt<4;tt++)
{
grid_times[dest_grid_number][dest_num_step][tt]=grid_times[from_grid_number][from_num_step][tt];
}
grid_goto[dest_grid_number][dest_num_step][0]=grid_goto[from_grid_number][from_num_step][0];
grid_goto[dest_grid_number][dest_num_step][1]=grid_goto[from_grid_number][from_num_step][1];
grid_seekpos[dest_grid_number][dest_num_step]=grid_seekpos[from_grid_number][from_num_step];
grid_stoplay[dest_grid_number][dest_num_step]=grid_stoplay[from_grid_number][from_num_step];
grid_count[dest_grid_number][dest_num_step]=grid_count[from_grid_number][from_num_step];
grid_counted_times[dest_grid_number][dest_num_step]=0;
 return(0);
}
