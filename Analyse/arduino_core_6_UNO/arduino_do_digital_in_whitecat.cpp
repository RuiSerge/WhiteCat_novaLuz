int arduino_do_digital_in_whitecat()
{
int vfader=0;int num_banger=0;

for(int p=0;p<=arduino_max_digital;p++)
{

if((arduino_digital_type[p]==1||arduino_digital_type[p]==2||arduino_digital_type[p]==7)  && digital_data_from_arduino[p]!= previous_digital_data_from_arduino[p] )//si l'affectation est type INPUT
{
switch(arduino_digital_function_input[p][0])
{
case 0://desafected
break;
case 1: //fader up
if(digital_data_from_arduino[p]==1) {
vfader=(arduino_digital_function_input[p][1]-1);
start_time_for_delays[vfader]=actual_time;
if(lfo_mode_is[vfader]!=1)//up
{
lfo_mode_is[vfader]=1;
faders_in_float[vfader]=Fader[vfader];
if(index_midi_mute_on_lfo==1){is_raccrochage_midi_remote[vfader]=1;}
}
else {lfo_mode_is[vfader]=0;}
lfo_cycle_is_on[vfader]=0;
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}

break;
case 2://fader down
if(digital_data_from_arduino[p]==1)
{
vfader=(arduino_digital_function_input[p][1]-1);
start_time_for_delays[vfader]=actual_time;
if(lfo_mode_is[vfader]!=2)//down
{
lfo_mode_is[vfader]=2;
faders_in_float[vfader]=Fader[vfader];
if(index_midi_mute_on_lfo==1){is_raccrochage_midi_remote[vfader]=1;}
}
else {lfo_mode_is[vfader]=0;}
lfo_cycle_is_on[vfader]=0;
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}

break;
case 3://Fader saw
if(digital_data_from_arduino[p]==1)
{
vfader=(arduino_digital_function_input[p][1]-1);
start_time_for_delays[vfader]=actual_time;
faders_in_float[vfader]=Fader[vfader];
if(lfo_cycle_is_on[vfader]==0)//
{
lfo_cycle_is_on[vfader]=1;
lfo_mode_is[vfader]=0;
lfo_running_is_upward[vfader]=1;
if(index_midi_mute_on_lfo==1){is_raccrochage_midi_remote[vfader]=1;}
}
else if(lfo_cycle_is_on[vfader]==1)
{
lfo_cycle_is_on[vfader]=0;
}
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 4://Fader: ToPREVDock
if(digital_data_from_arduino[p]==1)
{
vfader=(arduino_digital_function_input[p][1]-1);
if (lfo_do_next_step[vfader][0]==0) {lfo_do_next_step[vfader][0]=1;lfo_do_next_step[vfader][1]=0;}
else if (lfo_do_next_step[vfader][0]==1) {lfo_do_next_step[vfader][0]=0; }
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 5://Fader: ToNEXTDock
if(digital_data_from_arduino[p]==1)
{
vfader=(arduino_digital_function_input[p][1]-1);
if (lfo_do_next_step[vfader][1]==0) {lfo_do_next_step[vfader][1]=1;lfo_do_next_step[vfader][0]=0; ;}
else if (lfo_do_next_step[vfader][1]==1) {lfo_do_next_step[vfader][1]=0; }
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 6://Fader: Up/Down
if(digital_data_from_arduino[p]==1)
{
vfader=(arduino_digital_function_input[p][1]-1);
lfo_cycle_steps[vfader]= toggle(lfo_cycle_steps[vfader]);
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 7://Fader: LOCK
if(digital_data_from_arduino[p]==1) //si appuy�
{
vfader=(arduino_digital_function_input[p][1]-1);
 switch(FaderLocked[vfader])
  {
   case 0:
   FaderLocked[vfader]=1;
   StateOfFaderBeforeLock[vfader]=Fader[vfader];
   if(StateOfFaderBeforeLock[vfader]==255){LockFader_is_FullLevel[vfader]=1;}
   else if(StateOfFaderBeforeLock[vfader]<255){LockFader_is_FullLevel[vfader]=0;}
   sprintf(string_Last_Order,">> LOCKED Fader %d",vfader+1);
   if(LockFader_is_FullLevel[vfader]==0)//quand mis en lock et pas full level rajout 0.7.6
   {
   lfo_mode_is[vfader]=0;
   lfo_cycle_is_on[vfader]=0;
   }
   break;
   case 1:
   FaderLocked[vfader]=0;
   //remise � plat du niveau
   Fader[vfader]=(unsigned char)((((float)(StateOfFaderBeforeLock[vfader]))/255)*locklevel);
   midi_levels[vfader]=(int)(((float)Fader[vfader])/2);
   sprintf(string_Last_Order,">> UNLOCKED Fader %d",vfader+1);
   break;
   default: break;
   }
   previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 8://FLASH
vfader=(arduino_digital_function_input[p][1]-1);
FaderIsFlash[vfader]=digital_data_from_arduino[p];
break;
case 9://Fader: All at 0
if(digital_data_from_arduino[p]==1) //si appuy�
{
vfader=(arduino_digital_function_input[p][1]-1);
           Fader[vfader]=0;
           midi_levels[vfader]=0;
           index_send_midi_out[vfader]=1;
           lfo_speed[vfader]=64;
           midi_levels[196+p]=64;
           index_send_midi_out[196+p]=1;
           FaderLocked[vfader]=0;
           lfo_mode_is[vfader]=0;//no lfo
           lfo_cycle_is_on[vfader]=0;//saw
           lfo_cycle_steps[vfader]=0;
           lfo_do_next_step[vfader][0]=0;
           lfo_do_next_step[vfader][1]=0;
           for(int d=0;d<6;d++)
           {
           is_dock_for_lfo_selected[vfader][d]=0;
           }
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 10://Fader: L/Unloop dock
if(digital_data_from_arduino[p]==1) //si appuy�
{
vfader=(arduino_digital_function_input[p][1]-1);
is_dock_for_lfo_selected[vfader][(dock_used_by_fader_is[vfader])]=toggle(is_dock_for_lfo_selected[vfader][(dock_used_by_fader_is[vfader])]);
}
digital_data_from_arduino[p]=toggle(digital_data_from_arduino[p]);
break;
case 11://Fader: L/Unloop all
if(digital_data_from_arduino[p]==1) //si appuy�
{
vfader=(arduino_digital_function_input[p][1]-1);
for(int d=0;d<6;d++)
           {
           is_dock_for_lfo_selected[vfader][d]=toggle(is_dock_for_lfo_selected[vfader][d]);
           }
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 12://Seq: GO
if(digital_data_from_arduino[p]==1) //si appuy�
{
do_go_function();
do_send_bang();
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);//pour ne pas faire un flicker sur le  go/pause/go
}
break;
case 13://Seq: GO BACK
if(digital_data_from_arduino[p]==1) //si appuy�
{
do_go_back_function();
int banger_back_is=Banger_Memoire[position_preset]-1;
do_go_back_bang(banger_back_is);
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);
}
break;
case 14://Seq: JUMP
if(digital_data_from_arduino[p]==1) //si appuy�
{
do_double_go_function();
do_send_bang();
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);
}
break;
case 15://Seq: SHIFT-W
if(digital_data_from_arduino[p]==1) //si appuy�
{
index_go=0;index_pause=0; index_go_back=0;
detect_mem_preset_previous();
refresh_mem_onpreset(position_preset);
niveauX2=0;
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);
someone_changed_in_sequences=1;//icat
}
break;
case 16://Seq: SHIFT-X
if(digital_data_from_arduino[p]==1) //si appuy�
{
index_go=0;index_pause=0; index_go_back=0;
detect_next_preset();
refresh_mem_onpreset(position_preset);
niveauX2=0;
previous_digital_data_from_arduino[p]=toggle(previous_digital_data_from_arduino[p]);
someone_changed_in_sequences=1;//icat
}
break;

case 17://BANGER
if(digital_data_from_arduino[p]==1) //si appuy�
{
num_banger=arduino_digital_function_input[p][1]-1;

if( num_banger>=0 && num_banger<=127  )
{
bang_is_sended[num_banger]=toggle(bang_is_sended[num_banger]);
    switch (bang_is_sended[num_banger])
    {
    case 0://reset des send events et on demarre � la souris le banger
        for (int y=0;y<6;y++){event_sended[num_banger][y]=0;}
        start_time_for_banger[num_banger]=actual_time;
        //calcul bang time de fin
        for (int y=0;y<6;y++)
        {
        if(bangers_delay[num_banger][y]> end_time_for_banger[num_banger])
            {
            end_time_for_banger[num_banger]= bangers_delay[num_banger][y];
            }
        }
        if(end_time_for_banger[num_banger]<default_time_of_the_bang)
        {end_time_for_banger[num_banger]=default_time_of_the_bang;}
        last_banger_sended_manually=num_banger;
    break;
    case 1://go back sur le banger
       for (int y=0;y<6;y++)
        {
        if(bangers_type[num_banger][y]!=0 )
            {
            Bang_event_back(num_banger, y);
            event_sended[num_banger][y]=1;
            }
        }
        bang_is_sended[num_banger]=1;//bloquage de l envoi des autres �v�nements

    break;
    }
}
}
case 18:////As Key-On CH0 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,0,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,0,arduino_digital_function_input[p][1],0);
}
break;
case 19:////As Key-On CH1 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,1,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,1,arduino_digital_function_input[p][1],0);
}
break;
case 20:////As Key-On CH2 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,2,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,3,arduino_digital_function_input[p][1],0);
}
break;
case 21:////As Key-On CH3 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,3,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,4,arduino_digital_function_input[p][1],0);
}
break;
case 22:////As Key-On CH4 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,4,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,4,arduino_digital_function_input[p][1],0);
}
break;
case 23:////As Key-On CH5 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,5,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,5,arduino_digital_function_input[p][1],0);
}
break;
case 24:////As Key-On CH6 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,6,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,6,arduino_digital_function_input[p][1],0);
}
break;
case 25:////As Key-On CH7 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,7,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,7,arduino_digital_function_input[p][1],0);
}
break;
case 26:////As Key-On CH8 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,8,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,8,arduino_digital_function_input[p][1],0);
}
break;
case 27:////As Key-On CH9 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,9,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,9,arduino_digital_function_input[p][1],0);
}
break;
case 28:////As Key-On CH10 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,10,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,10,arduino_digital_function_input[p][1],0);
}
break;
case 29:////As Key-On CH11 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,11,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,11,arduino_digital_function_input[p][1],0);
}
break;
case 30:////As Key-On CH12 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,12,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,12,arduino_digital_function_input[p][1],0);
}
break;
case 31:////As Key-On CH13 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,13,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,13,arduino_digital_function_input[p][1],0);
}
break;
case 32:////As Key-On CH14 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,14,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,14,arduino_digital_function_input[p][1],0);
}
break;
case 33:////As Key-On CH15 P:
if(digital_data_from_arduino[p]==1) //si appuy�
{
simulate_midi(1,15,arduino_digital_function_input[p][1],127);
sprintf (my_midi_string, "Arduino Chan:%-2d Pitch:%-2d Vel:%-2d Typ: %s",	ischan,ispitch,isvel, "Key-On");
simulate_midi(2,15,arduino_digital_function_input[p][1],0);
}
break;
default:
break;
}
}
}

 return(0);
}
