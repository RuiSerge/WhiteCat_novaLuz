int do_loop_bang(int banger_is)
{
ticker_loop_banger[banger_is]++;
if(do_loop_banger[banger_is]==1 && time_loop_banger[banger_is]>0.0 && ticker_loop_banger[banger_is]>time_loop_banger[banger_is]*10000)
{
  for (int y=0;y<6;y++){event_sended[banger_is][y]=0;}
  bang_is_sended[banger_is]=0;
  start_time_for_banger[banger_is]=actual_time;
  ticker_loop_banger[banger_is]=0;
}
 return(0);
}
