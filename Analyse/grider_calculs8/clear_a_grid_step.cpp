int clear_a_grid_step(int grid_number, int num_step)
{
for(int chg=0;chg<513;chg++)
{
 grid_levels[grid_number][num_step][chg]=0;
}
for(int tt=0;tt<4;tt++)
{
grid_times[grid_number][num_step][tt]=0.0;
}
grid_times[grid_number][num_step][1]=default_time;
grid_times[grid_number][num_step][3]=default_time;

grid_goto[grid_number][num_step][0]=-1;
grid_goto[grid_number][num_step][1]=-1;
grid_seekpos[grid_number][num_step]=-1;
grid_stoplay[grid_number][num_step]=0;
grid_count[grid_number][num_step]=0;
grid_counted_times[grid_number][num_step]=0;

sprintf(string_Last_Order,"Cleared Step %d in Grid %d", num_step+1, grid_number+1);

return(0);
}
