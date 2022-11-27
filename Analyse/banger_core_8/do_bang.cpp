int do_bang(int banger_is)
{
if(banger_is<127 && bang_is_sended[banger_is]==0 )
{
end_time_for_banger[banger_is]=0;//reinit pour pierre groupe laps
for (int y=0;y<6;y++)
{
if(bangers_delay[banger_is][y]> end_time_for_banger[banger_is])
{
end_time_for_banger[banger_is]= bangers_delay[banger_is][y];
}
}
if(end_time_for_banger[banger_is]<default_time_of_the_bang)
{end_time_for_banger[banger_is]=default_time_of_the_bang;}


for (int y=0;y<6;y++)
{
if(bangers_type[banger_is][y]!=0)
{

if(actual_time>start_time_for_banger[banger_is]+ (bangers_delay[banger_is][y]*BPS_RATE) && event_sended[banger_is][y]==0)
{
    Bang_event(banger_is, y);
    event_sended[banger_is][y]=1;
}
}
}

if(actual_time>(start_time_for_banger[banger_is]+ (end_time_for_banger[banger_is]*BPS_RATE)))//rajout de +50 pour visualisation send dernier event
{
bang_is_sended[banger_is]=1;
}

}
return(0);
}
