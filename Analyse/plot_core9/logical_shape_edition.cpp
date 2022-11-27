int logical_shape_edition(int plotx, int ploty)
{

if(window_focus_id==W_PLOT && mouse_button==1 && index_edit_light_plot==1 )
{

if(mouse_x>=plotx+10 && mouse_x<=plotx+10+100+5 && mouse_y>ploty+40 && mouse_y<ploty+40+10 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0 && index_click_inside_relativ_xy==0)
{
if(mouse_released==0 &&  Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(1601,Midi_Faders_Affectation_Mode);
 mouse_released=1;
}
else
{
angle_shape_selected=((float)(mouse_x-(plotx+10)))/100;
if(angle_shape_selected<0.0){angle_shape_selected=0.0;}
if (angle_shape_selected>1.0){angle_shape_selected=1.0;}
affect_angle_to_shapes(angle_shape_selected);
}
}

if(mouse_x>plotx+76 && mouse_x<plotx+76+60 && mouse_y>ploty+22 && mouse_y<ploty+22+15 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0 && index_click_inside_relativ_xy==0 && mouse_released==0)
{
float numof=atof(numeric);
angle_shape_selected=numof;
if(angle_shape_selected<0.0){angle_shape_selected=0.0;}
else if(angle_shape_selected>1.0){angle_shape_selected=1.0;}
affect_angle_to_shapes(angle_shape_selected);
mouse_released=1;
reset_numeric_entry();
numeric_postext=0;
}

for(int l=0;l<3;l++)
{
for(int c=0;c<3;c++)
{
int pos2=(l*3) + c;
if( mouse_x>plotx+140+(c*15) && mouse_x<plotx+140+(c*15)+10 && mouse_y>ploty+10+(l*15) && mouse_y<ploty+10+(l*15)+10 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0)
{
switch(pos2)
{
case 0:
     angle_shape_selected=0.12;
break;
case 1:
    angle_shape_selected=0.0;
break;
case 2:
    angle_shape_selected=0.84;
break;
case 3:
     angle_shape_selected=0.24;
break;
case 4:
    //nothing
break;
case 5:
     angle_shape_selected=0.725;
break;
case 6:
     angle_shape_selected=0.36;
break;
case 7:
     angle_shape_selected=0.485;
break;
case 8:
     angle_shape_selected=0.59;
break;
default:
break;
}
affect_angle_to_shapes(angle_shape_selected); mouse_released=1;
}
}
}


for(int c=0;c<3;c++)
{
for(int l=0;l<2;l++)
{
if(mouse_x>plotx+5+(c*65) && mouse_x<plotx+5+(c*65)+60 && mouse_y>ploty+60+(l*20) && mouse_y<ploty+60+18+(l*20)
&& mouse_button==1 && mouse_released==0  && index_click_inside_relativ_xy==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0 )
{
switch(c+(l*3))
{
case 0://"Dub",plotx+20+(c*65),ploty+82+(l*20));
if(  Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(1602,Midi_Faders_Affectation_Mode);
}
else
{
duplicate_selected_shapes();
}
break;
case 1://"Delete",plotx+10+(c*65),ploty+82+(l*20));
if(  Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(1603,Midi_Faders_Affectation_Mode);
}
else
{
delete_selected_shapes();
}
break;
case 2://petitchiffre.Print("UnSelect",plotx+7+(c*65),ploty+72+(l*20));
if( Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(1604,Midi_Faders_Affectation_Mode);
}
else
{
unselect_all_shapes();
}
break;
case 3://petitchiffre.Print("Down",plotx+15+(c*65),ploty+72+(l*20));
position_down_selected_shapes();
break;
case 4://petitchiffre.Print("Top",plotx+22+(c*65),ploty+72+(l*20));
position_on_top_selected_shapes();
break;
case 5://petitchiffre.Print("Grp/unGr.",plotx+7+(c*65),ploty+72+(l*20));
group_ungroup_selected_shapes();
break;
default:
break;
}
mouse_released=1;
}
}
}


for(int c=0;c<4;c++)
{
if(window_focus_id==W_PLOT && index_edit_light_plot==1 && index_click_inside_relativ_xy==0
&& index_adjusting_shape_x==0 && index_adjusting_shape_y==0
&& mouse_button==1 && mouse_released==0
&& mouse_x>plotx+10+(c*45)&&mouse_x<plotx+10+(c*45)+40 && mouse_y>ploty+110 && mouse_y<ploty+110+18)
{
switch(c)
{
case 0://align x
plot_shapes_align_x();
break;
case 1://align y
plot_shapes_align_y();
break;
case 2://ventilation x
plot_shapes_ventilate_x();
break;
case 3://ventilation y
plot_shapes_ventilate_y();
break;
default:
break;
}
mouse_released=1;
}
}

if( mouse_x>=plotx+10 && mouse_x<=plotx+10+150+5 && mouse_y>ploty+155 && mouse_y<ploty+155+10 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0)
{
general_shape_size_to_apply=((float)(mouse_x-(plotx+10)));
if(general_shape_size_to_apply<0.5){general_shape_size_to_apply=0.5;}
else if(general_shape_size_to_apply>100.0){general_shape_size_to_apply=100.0;}
affect_size_to_shape(general_shape_size_to_apply);
}

if( mouse_released==0 && mouse_x>=plotx+126 && mouse_x<=plotx+126+70 && mouse_y>ploty+136 && mouse_y<ploty+136+15 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0)
{
float numo=atof(numeric);
general_shape_size_to_apply=numo;
if(general_shape_size_to_apply<0.5){general_shape_size_to_apply=0.5;}
else if(general_shape_size_to_apply>100.0){general_shape_size_to_apply=100.0;}
affect_size_to_shape(general_shape_size_to_apply);
 reset_numeric_entry();
 numeric_postext=0;
 mouse_released=1;
}
if( ( shape_selected_type>=0 && shape_selected_type<11 ) && mouse_released==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0 &&
mouse_x>plotx+10 && mouse_x<plotx+10+45 && mouse_y>ploty+190 && mouse_y<ploty+190+20)
{
color_pattern_selected++;
if(shape_selected_type>7 && color_pattern_selected>3){color_pattern_selected=0;}
else { if(color_pattern_selected>4){color_pattern_selected=0;}}
affect_color_pattern_to_shape(color_pattern_selected);
mouse_released=1;
}

if( shape_selected_type==7 && mouse_released==0  && index_click_inside_relativ_xy==0)//rectangle
{ //rectangle: x
if (mouse_x>=plotx+10 && mouse_x<plotx+10+45 && mouse_y>ploty+230 && mouse_y<ploty+230+20)
{
 if(numeric_postext>0)
 {
 float numo=atof(numeric);
 shape_rect_size_x=numo;
 reset_numeric_entry();
 numeric_postext=0;
 affect_size_to_rect(shape_rect_size_x,shape_rect_size_y);
 mouse_released=1;
 }
 else
 {
  index_adjusting_shape_x=1;
  temp_shape_rect_size_x=shape_rect_size_x;
 }
}//rectangle y
else if(mouse_x>=plotx+100 && mouse_x<plotx+100+45 && mouse_y>ploty+230 && mouse_y<ploty+230+20)
{
 if(numeric_postext>0)
 {
 float numo=atof(numeric);
 shape_rect_size_y=numo;
 reset_numeric_entry();
 numeric_postext=0;
 affect_size_to_rect(shape_rect_size_x,shape_rect_size_y);
 mouse_released=1;
 }
 else
 {
 index_adjusting_shape_y=1;
 temp_shape_rect_size_y=shape_rect_size_y;
 }
}
}
if( shape_selected_type==9 && mouse_released==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0 &&
mouse_x>=plotx && mouse_x<plotx+5+190 && mouse_y>ploty+240 && mouse_y<ploty+240+10)
{
opening_angle_selected=((float)(mouse_x-plotx))/180;
if(opening_angle_selected<0.0){opening_angle_selected=0.001;}
else if(opening_angle_selected>1.0){opening_angle_selected=1.0;}
refresh_opening_angle(opening_angle_selected);
}



if( shape_selected_type==10 && mouse_released==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0 &&
mouse_x>=plotx+10 && mouse_x<plotx+10+45 && mouse_y>ploty+230 && mouse_y<ploty+230+20)
{
nbre_branches_polygon=atoi(numeric);
reset_numeric_entry();
numeric_postext=0;
if(nbre_branches_polygon<3){nbre_branches_polygon=3;}
else if(nbre_branches_polygon>20){nbre_branches_polygon=20;}
affect_polygon_nbr_of_corners(nbre_branches_polygon);
mouse_released=1;
}

else if( shape_selected_type==11&& mouse_released==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0 &&
mouse_x>=plotx+10 && mouse_x<plotx+10+45 && mouse_y>ploty+230 && mouse_y<ploty+230+20)
{
if(numeric_postext>0)
{
fonttype_selected=atoi(numeric);
reset_numeric_entry();
numeric_postext=0;
if(fonttype_selected<0){fonttype_selected=0;}
else if(fonttype_selected>13){fonttype_selected=10;}
}
else
{
fonttype_selected++;
if(fonttype_selected>13){fonttype_selected=0;}
}
affect_font_to_texts(fonttype_selected);
mouse_released=1;
}

if( mouse_released==0 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0  && index_click_inside_relativ_xy==0 &&
mouse_x>=plotx+5 && mouse_x<plotx+5+10 && mouse_y>ploty+260 && mouse_y<ploty+260+10)
{
index_show_shape_id=toggle(index_show_shape_id);
mouse_released=1;
}

if(index_adjusting_shape_x==1 && index_click_inside_relativ_xy==0)
{
affect_size_to_rect(shape_rect_size_x,shape_rect_size_y);
}
else if
(index_adjusting_shape_y==1  && index_click_inside_relativ_xy==0)
{
affect_size_to_rect(shape_rect_size_x,shape_rect_size_y);
}


if(index_type==1 && mouse_released==0 && index_click_inside_relativ_xy==0 && mouse_x>plotx+10 && mouse_x<plotx+10+175 && mouse_y>ploty+275 && mouse_y<ploty+275+18)
{
edit_shape_name();
mouse_released=1;
}

if( mouse_released==0 && mouse_x > plotx+110 && mouse_x<plotx+110+70 && mouse_y>ploty+300 && mouse_y<ploty+300+70 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0 && index_click_inside_relativ_xy==0 )
{

if(index_main_clear==1)
{
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1 )
{
 shape_relativ_position_legend_name[i][0]=0;
 shape_relativ_position_legend_name[i][1]=0;
}
}
index_main_clear=0;
}

else
{
if(index_click_inside_relativ_xy==0 && mouse_released==0 )
{
index_click_inside_relativ_xy=1;
store_relativ_xy_position_of_shape();
}

}
}






if(index_click_inside_relativ_xy==0 && mouse_x>plotx-5 && mouse_x<plotx+10+100 && mouse_y>ploty+380 && mouse_y<ploty+380+10 && index_adjusting_shape_x==0 && index_adjusting_shape_y==0 )
{
general_alpha_for_shape=((float)(mouse_x-plotx))/100;
if(general_alpha_for_shape<0){general_alpha_for_shape=0;}
else if(general_alpha_for_shape>1.0){general_alpha_for_shape=1.0;}
}

}



 return(0);
}
