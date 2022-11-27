int back_up_fader_if_a_fader_inside(int banger_num)
{
 for (int u=0;u<6;u++)
 {
     if(bangers_type[banger_num][u]==1)
     {
     store_state_of_fader_before_bang((bangers_params[banger_num][u][0]-1));
     }

 }
 return(0);
}
