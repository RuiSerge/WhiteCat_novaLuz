int all_at_zero_panel_core(int xf, int yf)
{


for (int u=0;u<8;u++)
{

if(mouse_x>xf && mouse_x<xf+50 && mouse_y>yf+10+(25*u) && mouse_y<yf+10+(25*u)+20 && mouse_released==0)
{


if( Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(548+u, 2);
}
 else
 {

  switch(u)
  {
           case 0://faders off
           do_stock_fadersstate(1,0,0,0,0);
           for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           fader_set_level(p,0);
           /*Fader[p]=0;
           midi_levels[p]=0;
           index_send_midi_out[p]=1;*/
           }
           }
           break;
           case 1://speed at zero
           do_stock_fadersstate(0,1,0,0,0);
           for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           lfo_speed[p]=64;
           midi_levels[196+p]=64;
           index_send_midi_out[196+p]=1;
           }
           }
           break;
           case 2://lock off
           do_stock_fadersstate(0,0,1,0,0);
           for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           FaderLocked[p]=0;
           }
           }
           break;
           case 3://lfo off
           do_stock_fadersstate(0,0,0,1,0);
           for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           lfo_mode_is[p]=0;//no lfo
           lfo_cycle_is_on[p]=0;//saw
           lfo_cycle_steps[p]=0;
           lfo_do_next_step[p][0]=0;
           lfo_do_next_step[p][1]=0;
           }
           }
           break;
           case 4://loop off
           do_stock_fadersstate(0,0,0,0,1);
           for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           for(int d=0;d<6;d++)
           {
           is_dock_for_lfo_selected[p][d]=0;
           }
           }
           }
           break;
           case 5://ALL
           do_stock_fadersstate(1,1,1,1,1);
            for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           /*Fader[p]=0;
           midi_levels[p]=0;
           index_send_midi_out[p]=1;*/
           fader_set_level(p,0);
           lfo_speed[p]=64;
           midi_levels[196+p]=64;
           index_send_midi_out[196+p]=1;
           FaderLocked[p]=0;
           lfo_mode_is[p]=0;//no lfo
           lfo_cycle_is_on[p]=0;//saw
           lfo_cycle_steps[p]=0;
           lfo_do_next_step[p][0]=0;
           lfo_do_next_step[p][1]=0;
           for(int d=0;d<6;d++)
           {
           is_dock_for_lfo_selected[p][d]=0;
           }
           }
           }
           break;
           case 6://midi out
           for (int p=0;p<core_user_define_nb_faders;p++)
           {
           if(minifaders_selected[p]==1)
           {
           midi_send_out[p]=0;//faders
           }
           }
           break;
           case 7://recall
           do_recall_fadersstate( stockage_all_at_zero_state[0],stockage_all_at_zero_state[1],
           stockage_all_at_zero_state[2],stockage_all_at_zero_state[3],stockage_all_at_zero_state[4]);
           break;
           default: break;
  }

 }
 mouse_released=1;
 }

}

return(0);
}
