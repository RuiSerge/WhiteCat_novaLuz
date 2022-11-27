int logical_menu_plan(int plotx, int ploty)
{

if(window_focus_id==W_PLOT && index_edit_light_plot==1 && editing_plot_sizex==0 && editing_plot_sizey==0 && mouse_button==1 && mouse_released==0 && index_click_inside_relativ_xy==0 && index_click_inside_plot==0 && plot_editing_color_background==0 && plot_editing_color_line==0)
{

if(index_editing_theatre_plan==0 )
{
if( mouse_x>plotx+40 && mouse_x<plotx+40+40 && mouse_y>ploty+195 && mouse_y<ploty+195+20)
{
plot_quadrillage_size+=25;
if(plot_quadrillage_size>200){plot_quadrillage_size=0;}
mouse_released=1;
}
if ( mouse_x>plotx+100 && mouse_x<plotx+100+40 && mouse_y>ploty+195 && mouse_y<ploty+195+20)
{
plot_grid_type=toggle(plot_grid_type);
mouse_released=1;
}
if ( mouse_x>plotx+145 && mouse_x<plotx+150+60 && mouse_y>ploty+200 && mouse_y<ploty+200+10)
{
alpha_grille=(float)(mouse_x-(plotx+150))/50;
if(alpha_grille<0.0){alpha_grille=0.0;}
if(alpha_grille>1.0){alpha_grille=1.0;}
}
}


for(int i=0;i<4;i++)
{
if(mouse_x>plotx+5+(50*i) && mouse_x<plotx+5+(50*i)+45 && mouse_y>ploty+90 && mouse_y<ploty+90+20)
{
if(numeric_postext>0)
{
float numo=atof(numeric);
switch(i)
{
case 0:
position_relative_plan_theatre[0]=int(numo);
break;
case 1:
position_relative_plan_theatre[1]=int(numo);
break;
case 2:
ratio_lock_plot_scale=(float)(taille_relative_plan_theatre[0])/(float)(taille_relative_plan_theatre[1]);
taille_relative_plan_theatre[0]=int(numo);
 if(lock_background_proportions==1)
   {
   taille_relative_plan_theatre[1]=(int)(((float)taille_relative_plan_theatre[0])/ratio_lock_plot_scale);
   }
break;
case 3:
ratio_lock_plot_scale=(float)(taille_relative_plan_theatre[0])/(float)(taille_relative_plan_theatre[1]);
taille_relative_plan_theatre[1]=int(numo);
 if(lock_background_proportions==1)
   {
   taille_relative_plan_theatre[0]=(int)(((float)taille_relative_plan_theatre[1])/ratio_lock_plot_scale);
   }
break;
default:
break;
}
editing_plan_data_type=i+1;
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}
else if(numeric_postext==0)//drag souris
{
  if( index_editing_theatre_plan==0)
  {
  index_editing_theatre_plan=1;
  editing_plan_data_type=i+1;
  old_position_relative_plan_theatre[0]=position_relative_plan_theatre[0];
  old_position_relative_plan_theatre[1]=position_relative_plan_theatre[1];
  old_taille_relative_plan_theatre[0]=taille_relative_plan_theatre[0];
  old_taille_relative_plan_theatre[1]=taille_relative_plan_theatre[1];
  ratio_lock_plot_scale=(float)(taille_relative_plan_theatre[0])/(float)(taille_relative_plan_theatre[1]);
  }
}

}

}
  if(index_edit_light_plot==1 && index_editing_theatre_plan==1 && editing_plot_sizex==0 && editing_plot_sizey==0 && index_click_inside_relativ_xy==0 && index_click_inside_plot==0 && plot_editing_color_background==0 && plot_editing_color_line==0 )
  {
   moving_plan_relativ_x=mouse_x-original_posx;
   moving_plan_relativ_y=mouse_y-original_posy;



   switch(editing_plan_data_type)//décalé de +1
   {
   case 1:
   position_relative_plan_theatre[0]=old_position_relative_plan_theatre[0]-moving_plan_relativ_y;
   break;
   case 2:
   position_relative_plan_theatre[1]=old_position_relative_plan_theatre[1]-moving_plan_relativ_y;
   break;
   case 3:
   taille_relative_plan_theatre[0]=old_taille_relative_plan_theatre[0]-moving_plan_relativ_y;
   if(lock_background_proportions==1)
   {
   taille_relative_plan_theatre[1]=(int)(((float)taille_relative_plan_theatre[0])/ratio_lock_plot_scale );
   }
   break;
   case 4:
   taille_relative_plan_theatre[1]=old_taille_relative_plan_theatre[1]-moving_plan_relativ_y;
   if(lock_background_proportions==1)
   {
   taille_relative_plan_theatre[0]=(int)(((float)taille_relative_plan_theatre[1])*ratio_lock_plot_scale);
   }
   break;
   default:
   break;
   }
}

if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && mouse_released==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0 && mouse_x>=plotx+5+141 && mouse_x<=plotx+5+141+8 && mouse_y>ploty+111 && mouse_y<ploty+111+8)
{
lock_background_proportions=toggle(lock_background_proportions);
mouse_released=1;
}
if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0 && mouse_x>=plotx+10 && mouse_x<=plotx+10+100+5 && mouse_y>ploty+140 && mouse_y<ploty+140+10)
{
orientation_plan_theatre=((float)(mouse_x-(plotx+10)))/100;
if(orientation_plan_theatre<0.0){orientation_plan_theatre=0.0;}
if (orientation_plan_theatre>1.0){orientation_plan_theatre=1.0;}
}
for(int l=0;l<3;l++)
{
for(int c=0;c<3;c++)
{
int pos2=(l*3) + c;
if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0
 &&  mouse_x>plotx+140+(c*15) && mouse_x<plotx+140+(c*15)+10 && mouse_y>ploty+125+(l*15) && mouse_y<ploty+125+(l*15)+10 )
{
switch(pos2)
{
case 0:
     orientation_plan_theatre=0.12;
break;
case 1:
     orientation_plan_theatre=0.0;
break;
case 2:
     orientation_plan_theatre=0.84;
break;
case 3:
     orientation_plan_theatre=0.24;
break;
case 4:
    //nothing
break;
case 5:
     orientation_plan_theatre=0.725;
break;
case 6:
     orientation_plan_theatre=0.36;
break;
case 7:
     orientation_plan_theatre=0.485;
break;
case 8:
     orientation_plan_theatre=0.59;
break;
default:
break;
}
mouse_released=1;
}
}
}

if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0  && mouse_x>=plotx+5 && mouse_x<=plotx+10+100+5 && mouse_y>ploty+180 && mouse_y<ploty+180+10)
{
alpha_plan=((float)(mouse_x-(plotx+10)))/100;
if(alpha_plan<0.0){alpha_plan=0.0;}
if (alpha_plan>1.0){alpha_plan=1.0;}
}



if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0  &&
mouse_x>plotx+5 && mouse_x<plotx+5+40 && mouse_y>ploty+480 && mouse_y<ploty+480+20)
{
if(numeric_postext>0)
{
plot_window_x_size=atol(numeric);
if(plot_window_x_size<840){plot_window_x_size=840;}
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}
else if(numeric_postext==0)//drag souris
{
if(editing_plot_sizex==0)
{
editing_plot_sizex=1;
old_plot_sizex=plot_window_x_size;
}
}
}

if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0  &&
mouse_x>plotx+5+50 && mouse_x<plotx+5+50+40 && mouse_y>ploty+480 && mouse_y<ploty+480+20)
{
if(numeric_postext>0)
{
plot_window_y_size=atol(numeric);
if(plot_window_y_size<plot_minimum_y_size){plot_window_y_size=plot_minimum_y_size;}
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}
else if(numeric_postext==0)//drag souris
{
if(editing_plot_sizey==0)
{
editing_plot_sizey=1;
old_plot_sizey=plot_window_y_size;
}
}
}
}

if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0
&& mouse_button==1 && mouse_x>plotx+5+100 && mouse_x<plotx+5+100+40 && mouse_y>ploty+480 && mouse_y<ploty+480+20)
{
plot_editing_color_background=1;  plot_editing_color_line=0;
}
if(index_edit_light_plot==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0 && plot_editing_color_background==0 && plot_editing_color_line==0
&& mouse_button==1 && mouse_x>plotx+5+150 && mouse_x<plotx+5+150+40 && mouse_y>ploty+480 && mouse_y<ploty+480+20)
{
plot_editing_color_line=1; plot_editing_color_background=0;
}

if(editing_plot_sizex==1)
{
moving_size_relativ_x=mouse_y-original_posy;
plot_window_x_size=old_plot_sizex-(moving_size_relativ_x*10);
if(plot_window_x_size<840){plot_window_x_size=840;}
}
else if(editing_plot_sizey==1)
{
moving_size_relativ_y=mouse_y-original_posy;
plot_window_y_size=old_plot_sizey-(moving_size_relativ_y*10);
if(plot_window_y_size<plot_minimum_y_size){plot_window_y_size=plot_minimum_y_size;}
}

else if(plot_editing_color_background==1)
{
Color_plotfill=((float)(original_posy-mouse_y))/50;
if(Color_plotfill<0.0){Color_plotfill=0.0;}
Rgba TmpPlotColor (Color_plotfill,Color_plotfill,Color_plotfill);
CouleurPlotFill=TmpPlotColor;
}
else if(plot_editing_color_line==1)
{
Color_plotline=((float)(original_posy-mouse_y))/50;
if(Color_plotline<0.0){Color_plotline=0.0;}
Rgba TmpPlotColor (Color_plotline,Color_plotline,Color_plotline);
CouleurPlotLine=TmpPlotColor;
}
 return(0);
}
