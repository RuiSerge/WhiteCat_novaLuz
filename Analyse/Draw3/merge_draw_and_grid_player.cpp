int merge_draw_and_grid_player(int pr)
{
merging_gpl_in_draw=1;
     //recup des niveaux issus d'un gridplayer
if(draw_point_is_traced[pr]==1)
{
float value_grid;
int coord=0;

int rate=BPS_RATE/10;




if(draw_brush_type[pr]==0)//Point
          {
          //préparattion calculs damper decay
          damper_target_val=draw_preset_levels[pr][coord]+(draw_level_to_do[pr]/rate);
          if(damper_target_val>1.0){damper_target_val=1.0;}
          else if(damper_target_val<0.0){damper_target_val=0.0;}
          damper_val=draw_preset_levels[pr][coord];
          damper_vel= (damper_target_val-damper_val)* (1.0-draw_damper_decay_factor[pr]);

          coord=index_case[pr];
           switch(draw_mode[pr])
           {
           case 0://draw
           if(draw_damper_decay_factor[pr]==0.0){draw_preset_levels[pr][coord]+=draw_level_to_do[pr]/rate;}
           else{draw_preset_levels[pr][coord]+=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);}
           if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
           break;
           case 1://erase
           if(draw_damper_decay_factor[pr]==0.0){draw_preset_levels[pr][coord]-=draw_level_to_do[pr]/rate;}
           else {draw_preset_levels[pr][coord]-=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);}
           if(draw_preset_levels[pr][coord]<0.0){draw_preset_levels[pr][coord]=0.0;}
           break;
           case 2://solo
           for(int i=0;i<500;i++)
           {
           if(i!=coord){draw_preset_levels[pr][i]=0.0;  }
           }
           if(draw_damper_decay_factor[pr]==0.0){draw_preset_levels[pr][coord]+=draw_level_to_do[pr]/rate;}
           else {draw_preset_levels[pr][coord]+=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);}
           if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
           break;
           case 3://ghost
           if(draw_damper_decay_factor[pr]==0.0)
           {
           for(int i=0;i<(draw_preset_parameters[pr][0]*draw_preset_parameters[pr][1]);i++)
           {
           if(i!=coord && draw_preset_levels[pr][i]>0.0)
           {
           draw_preset_levels[pr][i]-=(draw_ghost_to_do[pr]/(rate))/10;
           if(draw_preset_levels[pr][i]<0.0){draw_preset_levels[pr][i]=0.0;}
           }
           }
           draw_preset_levels[pr][coord]+=draw_level_to_do[pr]/rate ;
           }
           else //decay
           {
           for(int i=0;i<(draw_preset_parameters[pr][0]*draw_preset_parameters[pr][1]);i++)
           {
           if(i!=coord && draw_preset_levels[pr][i]>0.0)
           {
           draw_preset_levels[pr][i]-=(draw_ghost_to_do[pr]/(rate))/10;
           if(draw_preset_levels[pr][i]<0.0){draw_preset_levels[pr][i]=0.0;}
           }
           }
           draw_preset_levels[pr][coord]+=(damper_vel*0.1)*(1.0-draw_damper_decay_factor[pr]);
           }
           if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          break;
          default:
          break;
          }
          }

else //GPL MODE
{
if(draw_brush_type[pr]==2)//mode solo, reset
            {
            for(int i=0;i<500;i++)
            {
            draw_preset_levels[pr][i]=0.0;
            }
            }


for(int c=-draw_preset_parameters[pr][0]/2;c<=(draw_preset_parameters[pr][0]/2) ;c++)
 {
     //for(int l=-draw_preset_parameters[pr][1]/2;l<grider_nb_row/2;l++) //christoph 21/02/15
   for(int l=-draw_preset_parameters[pr][1]/2;l<=grider_nb_row/2;l++)
    {
          coord=index_case[pr]+c+(l*draw_preset_parameters[pr][0]);
          //restriction au tableau pour éviter les débordements du motif
          if( coord>=0 && coord<=(draw_preset_parameters[pr][1]*draw_preset_parameters[pr][0]))
          {

          if (coord%draw_preset_parameters[pr][0]>=draw_centre_x[pr]-(draw_preset_parameters[pr][0]/2)
          && coord%draw_preset_parameters[pr][0]<=draw_centre_x[pr]+(draw_preset_parameters[pr][0]/2) )
          {
          value_grid=((float)(buffer_gridder[draw_get_gpl[pr]-1][draw_offset_gpl[pr]-1 + c+(l*grider_nb_col)])/255 )*draw_level_to_do[pr];

          damper_target_val=draw_preset_levels[pr][coord]+value_grid;
          if(damper_target_val>1.0){damper_target_val=1.0;}
          else if(damper_target_val<0.0){damper_target_val=0.0;}
          damper_val=draw_preset_levels[pr][coord];
          damper_vel= (damper_target_val-damper_val)* (1.0-draw_damper_decay_factor[pr]);

          switch(draw_mode[pr])
          {
          case 0://draw
          if(draw_damper_decay_factor[pr]==0.0){draw_preset_levels[pr][coord]+=value_grid;}
          else{draw_preset_levels[pr][coord]+=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);}
          if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          break;
          case 1://erase
          if(draw_damper_decay_factor[pr]==0.0){draw_preset_levels[pr][coord]-=value_grid;}
           else {draw_preset_levels[pr][coord]-=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);}
          if(draw_preset_levels[pr][coord]<0.0){draw_preset_levels[pr][coord]=0.0;}
          break;
          case 2://solo
          //faire reset de la grille draw SOUCI

          if(draw_damper_decay_factor[pr]==0.0)
          {
          if(value_grid>0.0){ draw_preset_levels[pr][coord]+=value_grid;}
          else {draw_preset_levels[pr][coord]=0;}
          }
          else
          {
          if(value_grid>0.0){draw_preset_levels[pr][coord]+=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);}
          else {draw_preset_levels[pr][coord]=0;}
          }
          if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          break;
          case 3://ghost
          /* //previous algo
          if(draw_damper_decay_factor[pr]==0.0)
           {
           for(int i=0;i<(draw_preset_parameters[pr][0]*draw_preset_parameters[pr][1]);i++)
           {
           if(i!=coord && draw_preset_levels[pr][i]>0.0)
           {
           draw_preset_levels[pr][i]-=(draw_ghost_to_do[pr]/(rate))/10;
           if(draw_preset_levels[pr][i]<0.0){draw_preset_levels[pr][i]=0.0;}
           }
           }
           draw_preset_levels[pr][coord]+=draw_level_to_do[pr]/rate ;
           }
           else //decay
           {
           for(int i=0;i<(draw_preset_parameters[pr][0]*draw_preset_parameters[pr][1]);i++)
           {
           if(i!=coord && draw_preset_levels[pr][i]>0.0)
           {
           draw_preset_levels[pr][i]-=(draw_ghost_to_do[pr]/(rate))/10;
           if(draw_preset_levels[pr][i]<0.0){draw_preset_levels[pr][i]=0.0;}
           }
           }
           draw_preset_levels[pr][coord]+=(damper_vel*0.1)*(1.0-draw_damper_decay_factor[pr]);
           }
           if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          */
          //christoph 21/02/15
          if(draw_damper_decay_factor[pr]==0.0)
          {
          if(value_grid!=0.0)//is a pattern
          {
          draw_preset_levels[pr][coord]+=value_grid;
          if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          }
          else
          {
          draw_preset_levels[pr][coord]-=(draw_ghost_to_do[pr]/(rate))/10;
          if(draw_preset_levels[pr][coord]<0.0){draw_preset_levels[pr][coord]=0.0;}
          }
          }
          else //decay
          {
          if(value_grid!=0.0)//is a pattern
          {
          draw_preset_levels[pr][coord]+=(damper_vel*0.1)* (1.0-draw_damper_decay_factor[pr]);
          if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          }
          else
          {
          draw_preset_levels[pr][coord]-=(draw_ghost_to_do[pr]/(rate))/10;
          if(draw_preset_levels[pr][coord]<0.0){draw_preset_levels[pr][coord]=0.0;}
          }
          }
          if(draw_preset_levels[pr][coord]>1.0){draw_preset_levels[pr][coord]=1.0;}
          if(draw_preset_levels[pr][coord]<0.0){draw_preset_levels[pr][coord]=0.0;}
          break;
          default:
          break;
          }

          }

          }
          }
          }



}
draw_point_is_traced[pr]=0;//pour ipad reset de l'action
}


merging_gpl_in_draw=0;
return(0);
}
