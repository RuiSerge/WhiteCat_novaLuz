int inversion_of_axes()
{
if(invX_on==1)
{
buffer_moving_head[xadress]=255-mover_params[0][0];
if(tracker_mode==1){buffer_moving_head[xadress+1]=255-mover_params[0][1];   }
}
else if(invX_on==0)
{
buffer_moving_head[xadress]=mover_params[0][0];
if(tracker_mode==1){buffer_moving_head[xadress+1]=mover_params[0][1];   }
}
if(invY_on==1)
{
buffer_moving_head[yadress]=255-mover_params[1][0];
if(tracker_mode==1){buffer_moving_head[yadress+1]=255-mover_params[1][1];   }
}
else if(invY_on==0)
{
buffer_moving_head[yadress]=mover_params[1][0];
if(tracker_mode==1){buffer_moving_head[yadress+1]=mover_params[1][1];   }
}
 return(0);
}
