int clear_part_of_a_grid(int grid_number, int num_stepfrom, int num_stepto)
{
for(int num_step=num_stepfrom;num_step<=num_stepto;num_step++)
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
}
return(0);
}
