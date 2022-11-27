int check_tracker_zone( int tp)
{
int fsBx=FS_touch_point_begin[0][tp];
int fsBy=FS_touch_point_begin[1][tp];
int fsMx=FS_touch_point_move[0][tp];
int fsMy=FS_touch_point_move[1][tp];
int fsEx=FS_touch_point_end[0][tp];
int fsEy=FS_touch_point_end[1][tp];

int fsTestX2=0; int fsTestY2=0;

for(int sl=1;sl< iCat_nbre_de_tracking_zone[iCatPageis]+1;sl++)
{

fsTestX2=(iCat_pos_trackzone[iCatPageis][sl][0]*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
fsTestY2=(iCat_pos_trackzone[iCatPageis][sl][1]*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);


if ( fsBx>=(iCat_pos_trackzone[iCatPageis][sl][0]*2)-10 && fsBx<=fsTestX2+10 && fsBy>=(iCat_pos_trackzone[iCatPageis][sl][1]*2)-10 && fsBy<=fsTestY2+10 )
{
zone_is_touched[iCatPageis][sl]=1;
zone_is_controlled_by_point[iCatPageis][sl]=tp;
}



if((fsMx==fsEx && fsMy==fsEy) || (fsBx==fsEx && fsBy==fsEy) )//pour la relache n egale pas 0
{
zone_is_touched[iCatPageis][sl]=0;
if(dragging_draw==0 )//si pas de la souris
{
switch(iCat_trackzone_type_is[iCatPageis][sl])
{
case 2://draw activ
  draw_point_is_traced[draw_preset_selected]=0;
break;
case 3://draw specific num
 draw_point_is_traced[iCat_trackzone_affectation_is[iCatPageis][sl]-1]=0;
break;
default:
break;
}
}

}


if(zone_is_touched[iCatPageis][sl]==1 && zone_is_controlled_by_point[iCatPageis][sl]==tp)
{
int pr=0;
float ratiox=0.0;
float ratioy=0.0;

switch(iCat_trackzone_type_is[iCatPageis][sl])
{
case 1://MOVER

index_move_crossfade_is_on=0;
index_move_crossfade_is_on=0;
index_move_back=0;
index_move_forward=0;
if(lockX_on==0 )
{
pos_iCat_tracker[iCatPageis][sl][0]=(iCat_pos_trackzone[iCatPageis][sl][0]*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl])-fsMx;
switch(ratio_iCat_trackzone[iCatPageis][sl])
{
case 1: //small
pos_iCat_tracker[iCatPageis][sl][0]*=2;
break;
case 3: //big
pos_iCat_tracker[iCatPageis][sl][0]=(pos_iCat_tracker[iCatPageis][sl][0]/3)*2;
break;
case 4: //BIG
pos_iCat_tracker[iCatPageis][sl][0]=(int)(pos_iCat_tracker[iCatPageis][sl][0]/2);
break;
default:
break;
}
pos_iCat_tracker[iCatPageis][sl][0]=constrain_data_to_dmx_range(pos_iCat_tracker[iCatPageis][sl][0]);
mover_params[0][0]=255-pos_iCat_tracker[iCatPageis][sl][0];
}

if(lockY_on==0 )
{
pos_iCat_tracker[iCatPageis][sl][1]=(iCat_pos_trackzone[iCatPageis][sl][1]*2)+(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl])-fsMy;
switch(ratio_iCat_trackzone[iCatPageis][sl])
{
case 1: //small
pos_iCat_tracker[iCatPageis][sl][1]*=2;
break;
case 3:    //big
pos_iCat_tracker[iCatPageis][sl][1]=(pos_iCat_tracker[iCatPageis][sl][1]/3)*2;
break;
case 4: //BIG
pos_iCat_tracker[iCatPageis][sl][1]=(int)(pos_iCat_tracker[iCatPageis][sl][1]/2);
break;
default:
break;
}
pos_iCat_tracker[iCatPageis][sl][1]=constrain_data_to_dmx_range(pos_iCat_tracker[iCatPageis][sl][1]);
mover_params[1][0]=255-pos_iCat_tracker[iCatPageis][sl][1];
}
break;
case 2://draw activ

if(iCat_preset_orientation[iCatPageis]==0)
   {
    ratiox=((float)draw_tracking_aera_size_y)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
    ratioy=((float)draw_tracking_aera_size_x)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
   }
   else
   {
   ratiox=((float)draw_tracking_aera_size_x)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
   ratioy=((float)draw_tracking_aera_size_y)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
   }

pos_iCat_tracker[iCatPageis][sl][0]=(int)((fsMx-(iCat_pos_trackzone[iCatPageis][sl][0]*2))*ratiox);
pos_iCat_tracker[iCatPageis][sl][1]=(int)((fsMy-(iCat_pos_trackzone[iCatPageis][sl][1]*2))*ratioy);

pos_iCat_tracker[iCatPageis][sl][0]=constrain_int_data_to_this_range(pos_iCat_tracker[iCatPageis][sl][0], 0,draw_tracking_aera_size_x );
pos_iCat_tracker[iCatPageis][sl][1]=constrain_int_data_to_this_range(pos_iCat_tracker[iCatPageis][sl][1], 0,draw_tracking_aera_size_y );

pr=draw_preset_selected;

if(pos_iCat_tracker[iCatPageis][sl][0]>(draw_largeur_case[pr]*draw_preset_parameters[pr][0]))
{pos_iCat_tracker[iCatPageis][sl][0]=(draw_largeur_case[pr]*draw_preset_parameters[pr][0])-1;}
if(pos_iCat_tracker[iCatPageis][sl][1]>(draw_hauteur_case[pr]*draw_preset_parameters[pr][1]))
{pos_iCat_tracker[iCatPageis][sl][1]=(draw_hauteur_case[pr]*draw_preset_parameters[pr][1])-1;}

if( ticks_dixieme_for_icat_and_draw!=before_ticks_dixieme_for_icat_and_draw)
{
draw_point_is_traced[pr]=1;
Draw_point_and_perform_level_on_area_NEW(draw_preset_selected,pos_iCat_tracker[iCatPageis][sl][0],pos_iCat_tracker[iCatPageis][sl][1]);
before_ticks_dixieme_for_icat_and_draw=ticks_dixieme_for_icat_and_draw;
}
break;
case 3://draw num
if(iCat_preset_orientation[iCatPageis]==0)
   {
    ratiox=((float)draw_tracking_aera_size_y)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
    ratioy=((float)draw_tracking_aera_size_x)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
   }
   else
   {
   ratiox=((float)draw_tracking_aera_size_x)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
   ratioy=((float)draw_tracking_aera_size_y)/(largeur_trackzone*ratio_iCat_trackzone[iCatPageis][sl]);
   }

pos_iCat_tracker[iCatPageis][sl][0]=(int)((fsMx-(iCat_pos_trackzone[iCatPageis][sl][0]*2))*ratiox);
pos_iCat_tracker[iCatPageis][sl][1]=(int)((fsMy-(iCat_pos_trackzone[iCatPageis][sl][1]*2))*ratioy);


pos_iCat_tracker[iCatPageis][sl][0]=constrain_int_data_to_this_range(pos_iCat_tracker[iCatPageis][sl][0], 0,draw_tracking_aera_size_x);
pos_iCat_tracker[iCatPageis][sl][1]=constrain_int_data_to_this_range(pos_iCat_tracker[iCatPageis][sl][1], 0,draw_tracking_aera_size_y);

pr=iCat_trackzone_affectation_is[iCatPageis][sl]-1;

if(pos_iCat_tracker[iCatPageis][sl][0]>(draw_largeur_case[pr]*draw_preset_parameters[pr][0]))
{pos_iCat_tracker[iCatPageis][sl][0]=(draw_largeur_case[pr]*draw_preset_parameters[pr][0])-1;}
if(pos_iCat_tracker[iCatPageis][sl][1]>(draw_hauteur_case[pr]*draw_preset_parameters[pr][1]))
{pos_iCat_tracker[iCatPageis][sl][1]=(draw_hauteur_case[pr]*draw_preset_parameters[pr][1])-1;}

if( ticks_dixieme_for_icat_and_draw!=before_ticks_dixieme_for_icat_and_draw)
{
draw_point_is_traced[pr]=1;
Draw_point_and_perform_level_on_area_NEW(draw_preset_selected,pos_iCat_tracker[iCatPageis][sl][0],pos_iCat_tracker[iCatPageis][sl][1]);
before_ticks_dixieme_for_icat_and_draw=ticks_dixieme_for_icat_and_draw;
}
break;
default:
break;
}
}




}

return(0);
}
