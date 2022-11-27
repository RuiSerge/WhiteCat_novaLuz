int gridplayer_seek(int num_grider)
{
 if(index_grider_seek_pos[num_grider]<0){index_grider_seek_pos[num_grider]=0;}
 index_grider_step_is[num_grider]=index_grider_seek_pos[num_grider];

 else {index_grider_seek_pos[num_grider]=1;}*/
 gridder_prepare_cross(num_grider,index_grider_selected[num_grider],index_grider_step_is[num_grider]);
 grid_niveauX1[num_grider]=255;
 grid_niveauX2[num_grider]=0;
 grid_floatX1[num_grider]=grid_niveauX1[num_grider];
 grid_floatX2[num_grider]=grid_niveauX2[num_grider];
 grid_counted_times[index_grider_selected[num_grider]] [index_grider_step_is[num_grider]]=0;
 return(0);
}
