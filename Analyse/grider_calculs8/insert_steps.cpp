int insert_steps(int dest_grid_number, int from_num_step,  int dest_nbr_step)
{

unsigned char  buffer_temp_grd[1024][513];
float tmp_grid_times[1024][4];
int tmp_grid_goto[1024][2];//0 grid 1 step
int tmp_grid_seekpos[1024];//step seek pos
bool tmp_grid_stoplay[1024];//1=pause
int tmp_grid_count[1024];

for(int st=0;st<1023;st++)
{
for(int chg=0;chg<513;chg++)
{
 buffer_temp_grd[st][chg]=grid_levels[dest_grid_number][st][chg];
}
for(int tt=0;tt<4;tt++)
{
tmp_grid_times[st][tt]=grid_times[dest_grid_number][st][tt];
}
tmp_grid_goto[st][0]=grid_goto[dest_grid_number][st][0];
tmp_grid_goto[st][1]=grid_goto[dest_grid_number][st][1];
tmp_grid_seekpos[st]=grid_seekpos[dest_grid_number][st];
tmp_grid_stoplay[st]=grid_stoplay[dest_grid_number][st];
tmp_grid_count[st]=grid_count[dest_grid_number][st];
}


for(int st=from_num_step;st<1023;st++)
{
if(st+dest_nbr_step+1<1024)//protection des tableaux
{
for(int chg=0;chg<513;chg++)
{
grid_levels[dest_grid_number][st+dest_nbr_step+1][chg]=buffer_temp_grd[st][chg];
}
for(int tt=0;tt<4;tt++)
{
grid_times[dest_grid_number][st+dest_nbr_step+1][tt]=tmp_grid_times[st][tt];
}
grid_goto[dest_grid_number][st+dest_nbr_step+1][0]=tmp_grid_goto[st][0];
grid_goto[dest_grid_number][st+dest_nbr_step+1][1]=tmp_grid_goto[st][1];
grid_seekpos[dest_grid_number][st+dest_nbr_step+1]=tmp_grid_seekpos[st];
grid_stoplay[dest_grid_number][st+dest_nbr_step+1]=tmp_grid_stoplay[st];
grid_count[dest_grid_number][st+dest_nbr_step+1]=tmp_grid_count[st];
}
}

clear_part_of_a_grid(dest_grid_number, from_num_step+1,  from_num_step+dest_nbr_step+1);

 return(0);
}
