int do_bouncing_levels(int ech)
{

float gravity=echo_global_params[ech][0];
float inertie=echo_global_params[ech][1]/9.8; //( channel mass)
float acceleration=inertie/gravity;
float delta=echo_global_params[ech][2]/9.8;//velocity

if( echo_is_echo_mode[ech]==1)
{

for(int i=1;i<513;i++)
{
if(((float)(FaderDoDmx[(echo_pointing_fader_num[ech]-1)][i]))/255 > echo_levels[ech][0][i-1] )
{
echo_levels[ech][0][i-1]=((float)(FaderDoDmx[(echo_pointing_fader_num[ech]-1)][i]))/255;//((float)(FaderDockContains[f][dock_used_by_fader_is[f]][i]))/255;
tmp_echo[ech][i-1]=0.0;
tmp_falling_from_level[ech][i-1]=echo_levels[ech][0][i-1];
echo_way[ech][i-1]=0;
}
}
bounce_is_prepared[ech]=1;
do_bounce[ech]=1;
}


for(int b=0; b<512; b++)
{

switch(echo_way[ech][b])
{
case 0: //falling
echo_levels[ech][0][b]-=gravity*delta + 0.5*acceleration*(delta*delta)+tmp_echo[ech][b];
tmp_echo[ech][b]+=0.001*gravity;
if(echo_levels[ech][0][b]<=echo_levels[ech][1][b])//ground
{
echo_levels[ech][0][b]=echo_levels[ech][1][b];
tmp_echo[ech][b]=0.0;
tmp_falling_from_level[ech][b]-=inertie;
echo_way[ech][b]=1;
tmp_echo[ech][b]=0.001*gravity;
}

break;
case 1://boucing
echo_levels[ech][0][b]+=gravity*delta + 0.5*acceleration*(delta*delta)+tmp_echo[ech][b];

if(echo_levels[ech][0][b]>tmp_falling_from_level[ech][b])//ground
{
echo_levels[ech][0][b]=tmp_falling_from_level[ech][b];
echo_way[ech][b]=0;
tmp_echo[ech][b]=0.001*gravity;
}
break;
default: break;
}

if(echo_levels[ech][0][b]<echo_levels[ech][1][b])
{
echo_levels[ech][0][b]=echo_levels[ech][1][b];
if(echo_is_echo_mode[ech]==0) check_echo_bounce_done(ech);
}

}
 return(0);
}
