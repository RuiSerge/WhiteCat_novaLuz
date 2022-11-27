int check_slider( int tp)
{
int fsBx=FS_touch_point_begin[0][tp];
int fsBy=FS_touch_point_begin[1][tp];
int fsMx=FS_touch_point_move[0][tp];
int fsMy=FS_touch_point_move[1][tp];

int fsTestX2=0; int fsTestY2=0;

for(int sl=1;sl<iCat_nbre_de_sliders[iCatPageis]+1;sl++)
{
switch (iCat_orientation_slider[iCatPageis][sl])
{
case 0:
fsTestX2=(iCat_pos_slider[iCatPageis][sl][0]*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][sl]);
fsTestY2=(iCat_pos_slider[iCatPageis][sl][1]*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][sl]);
break;
case 1:
fsTestX2=(iCat_pos_slider[iCatPageis][sl][0]*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][sl]);
fsTestY2=(iCat_pos_slider[iCatPageis][sl][1]*2)+(iCatSlidersizeX*ratio_iCat_slider[iCatPageis][sl]);
break;
default: break;
}
if ( fsBx>=(iCat_pos_slider[iCatPageis][sl][0]*2)-10 && fsBx<=fsTestX2+10 && fsBy>=(iCat_pos_slider[iCatPageis][sl][1]*2)-10 && fsBy<=fsTestY2+10 )
{
slider_is_touched[iCatPageis][sl]=1;
slider_is_controlled_by_point[iCatPageis][sl]=tp;
}
if(slider_is_touched[iCatPageis][sl]==1 && slider_is_controlled_by_point[iCatPageis][sl]==tp)
{
switch (iCat_orientation_slider[iCatPageis][sl])
{
case 0://vertical
level_from_touch[iCatPageis][sl]=(iCat_pos_slider[iCatPageis][sl][1]*2)+(iCatSlidersizeY*ratio_iCat_slider[iCatPageis][sl])-fsMy;
break;
case 1://horizontal
level_from_touch[iCatPageis][sl]=fsMx-(iCat_pos_slider[iCatPageis][sl][0]*2);
break;
default: break;
}
switch(ratio_iCat_slider[iCatPageis][sl])
{
case 1:
level_from_touch[iCatPageis][sl]*=2;
break;
case 3:
level_from_touch[iCatPageis][sl]=(level_from_touch[iCatPageis][sl]/3)*2;
break;
default:
break;
}
level_from_touch[iCatPageis][sl]=constrain_data_to_dmx_range(level_from_touch[iCatPageis][sl]);

switch(iCat_affectation_slider_type_is[iCatPageis][sl])
{
case 1://niveaux faders
    fader_set_level((iCat_affectation_slider_value_is[iCatPageis][sl]-1),level_from_touch[iCatPageis][sl]);
*/
if(lfo_mode_is[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]==1 || lfo_mode_is[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]==2 || lfo_cycle_is_on[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]==1)
{
lfo_mode_is[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=0;
lfo_mode_is[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=0;
lfo_cycle_is_on[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=0;

}

break;
case 2://speed accelerometre faders
lfo_speed[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=level_from_touch[iCatPageis][sl]/2;

index_send_midi_out[196+(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=1;

if(DockTypeIs[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)][dock_used_by_fader_is[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]]==12)//enchassement Grid si slave
{
asservissement_gridplayer((iCat_affectation_slider_value_is[iCatPageis][sl]-1),dock_used_by_fader_is[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]);
}
midi_levels[196+(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=lfo_speed[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)];

break;
case 3://sequenciel 0: stage 1: preset 2: accelerometre
     switch(iCat_affectation_slider_value_is[iCatPageis][sl])
     {
     case 0://sx1
     index_go=0; index_go_back=0; index_pause=0;
     niveauX1=level_from_touch[iCatPageis][sl];
     iCat_slider_doing_X1_is=sl;
     midi_levels[491]=level_from_touch[iCatPageis][sl]/2;
     if(midi_send_out[491]==1){ index_send_midi_out[491]=1;}

     break;
     case 1://x2
     index_go=0; index_go_back=0; index_pause=0;
     niveauX2=255-level_from_touch[iCatPageis][sl];
     iCat_slider_doing_X2_is=sl;
     midi_levels[492]=127-(level_from_touch[iCatPageis][sl]/2);
     if(midi_send_out[492]==1){ index_send_midi_out[492]=1;}

     break;
     case 2:
     crossfade_speed= level_from_touch[iCatPageis][sl]/2;
     prepare_crossfade();
     if(crossfade_speed<0){crossfade_speed=0;}
     if(crossfade_speed>127){crossfade_speed=127;}
     midi_levels[493]=level_from_touch[iCatPageis][sl];
     if(midi_send_out[493]==1){ index_send_midi_out[493]=1;}

    //rafraichissement seq non uniquement en release sinon ca bloque
     break;
     default:
     break;
     }

break;
case 4://grand master
if(index_allow_grand_master==1)
{
niveauGMaster=level_from_touch[iCatPageis][sl];
if(niveauGMaster<0){niveauGMaster=0;}
if(niveauGMaster>255){niveauGMaster=255;}
midi_levels[615]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[615]==1){ index_send_midi_out[615]=1;}
}
break;
case 5://level wheel
if(wheellevel_absolutemode==1)//mode absolu
{
int levelwheelis=level_from_touch[iCatPageis][sl];
if(levelwheelis<0){levelwheelis=0;}
if(levelwheelis>255){levelwheelis=255;}
for (int tc=1;tc<514;tc++)
{
if (Selected_Channel[tc]==1 && index_blind==0)
{
bufferSaisie[tc]=levelwheelis;
}
else if (Selected_Channel[tc]==1 && index_blind==1)
{
bufferBlind[tc]=levelwheelis;
}
}
absolute_level_wheel=levelwheelis;

midi_levels[664]=levelwheelis/2;
if(midi_send_out[664]==1){index_send_midi_out[664]=1;}
}
break;

case 6://MOVER
if( tracker_16b_edit==0)
{
mover_params[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)][0]=level_from_touch[iCatPageis][sl];
}
else
{
mover_params[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)][1]=level_from_touch[iCatPageis][sl];
}
midi_levels[1700+(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1700+(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]==1){ index_send_midi_out[1700+(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=1;}
break;

case 7: //DRAW PRESSURE
draw_level_to_do[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=((float)(level_from_touch[iCatPageis][sl])/2)/127.0;
if((iCat_affectation_slider_value_is[iCatPageis][sl]-1)==draw_preset_selected)
{
midi_levels[1653]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1653]==1){ index_send_midi_out[1653]=1;}
}
break;
case 8: //DRAW decay
draw_damper_decay_factor[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=((float)(level_from_touch[iCatPageis][sl])/2)/127.0;
if((iCat_affectation_slider_value_is[iCatPageis][sl]-1)==draw_preset_selected)
{
midi_levels[1654]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1654]==1){ index_send_midi_out[1654]=1;}
}
break;
case 9: //DRAW GHOST
draw_ghost_to_do[(iCat_affectation_slider_value_is[iCatPageis][sl]-1)]=((float)(level_from_touch[iCatPageis][sl])/2)/127.0;
if((iCat_affectation_slider_value_is[iCatPageis][sl]-1)==draw_preset_selected)
{
midi_levels[1656]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1656]==1){ index_send_midi_out[1656]=1;}
}
break;
case 10: //DRAW PRESSURE SELECTED
draw_level_to_do[draw_preset_selected]=((float)(level_from_touch[iCatPageis][sl])/2)/127.0;
midi_levels[1653]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1653]==1){ index_send_midi_out[1653]=1;}
break;
case 11: //DRAW DECAY
draw_damper_decay_factor[draw_preset_selected]=((float)(level_from_touch[iCatPageis][sl])/2)/127.0;
midi_levels[1654]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1654]==1){ index_send_midi_out[1654]=1;}
break;
case 12: //DRAW GHOST
draw_ghost_to_do[draw_preset_selected]=((float)(level_from_touch[iCatPageis][sl])/2)/127.0;
midi_levels[1656]=level_from_touch[iCatPageis][sl]/2;
if(midi_send_out[1656]==1){ index_send_midi_out[1656]=1;}
break;

default:
break;
}

}


if(niveauX1==0 && niveauX2==255
   && slider_is_touched[iCatPageis][iCat_slider_doing_X1_is]==0 &&  slider_is_touched[iCatPageis][iCat_slider_doing_X2_is]==0)
{
     index_go=0; index_go_back=0; index_pause=0;
     next_mem_crossfade_finished(position_preset);
     niveauX1=255; niveauX2=0;floatX1=niveauX1; floatX2=niveauX2;
     crossfade_speed=64;
     crossfade_done_time=0;
     midi_levels[491]=127; midi_levels[492]=127;midi_levels[493]=crossfade_speed;
     if(midi_send_out[491]==1){ index_send_midi_out[491]=1;}
     if(midi_send_out[492]==1){ index_send_midi_out[492]=1;}
     if(midi_send_out[493]==1){ index_send_midi_out[493]=1;}
     index_x1_x2_together=1;
}

if(slider_is_touched[iCatPageis][sl]!=before_slider_is_touched[iCatPageis][sl])
{
switch(slider_is_touched[iCatPageis][sl])
{
case 0:
sprintf(StrOrderToiCat, "model t%d color 1.0 1.0 1.0",sl);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
case 1:
sprintf(StrOrderToiCat, "model t%d color 1.0 0.0 0.0",sl);
nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
break;
default: break;
}
}
before_slider_is_touched[iCatPageis][sl]=slider_is_touched[iCatPageis][sl];
}
return(0);
}
