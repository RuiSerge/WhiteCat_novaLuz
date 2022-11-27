int do_logical_Sequenciel_Window(int xseq, int yseq,int largeur_seq,int hauteur_seq)
{

do_logical_refresh_vision_memories(xseq,yseq);
do_logical_x1_x2(xseq,yseq-25);


if(mouse_x>xseq+180 && mouse_x<xseq+180+35 && mouse_y>yseq+50 && mouse_y<yseq+50+15)
{
if(index_link_is_on==0){index_link_is_on=1;}
else if(index_link_is_on==1){index_link_is_on=0;}
mouse_released=1;
}

if(mouse_x>xseq+223 && mouse_x<xseq+263 && mouse_y>yseq+50 && mouse_y<yseq+50+15)
{
index_banger_is_on=toggle(index_banger_is_on);
mouse_released=1;
}

if(mouse_x>xseq+275 && mouse_x<xseq+275+30 && mouse_y>yseq+50 && mouse_y<yseq+50+15 )
{
show_gridplayer_in_seq=toggle(show_gridplayer_in_seq);
mouse_released=1;
}



int rangee_y= yseq+180+(35*(nbre_memoires_visualisables_en_preset+1));
int index_atoi=0;
for (int op=0;op<7;op++)
{
if(mouse_x>xseq+20+(op*60) && mouse_x<xseq+20+(op*60)+50 && mouse_y>rangee_y && mouse_y<rangee_y+20)
{
switch(op)
{
case 0:         //create
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(768,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
reset_indexs_confirmation();
index_do_create_mem=1;
index_ask_confirm=1;
}
break;
case 1://delete mem
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(769,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
reset_indexs_confirmation();
index_do_delete_mem=1;
index_ask_confirm=1;
}
break;
case 2://stage minus
if(  Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(770,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
    if(index_go==0 && index_go_back==0 && index_pause==0)
           {
           position_onstage=mem_before_one;
           }
           else {index_go=0;index_pause=0; index_go_back=0;}

refresh_mem_onstage(position_onstage);
detect_mem_before_one();
detect_mem_preset();
refresh_mem_onpreset(position_preset);
niveauX1=255; niveauX2=0;
refresh_banger_wx();
refresh_integrated_gridplayer1();
}
break;
case 3://stage +
if(  Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(771,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{

 if(index_go==0 && index_go_back==0 && index_pause==0)
           {
           position_onstage=position_preset;
           }
            else {index_go=0;index_pause=0; index_go_back=0;}

refresh_mem_onstage(position_onstage);
detect_mem_before_one();
detect_mem_preset();
refresh_mem_onpreset(position_preset);
niveauX1=255; niveauX2=0;
refresh_banger_wx();
refresh_integrated_gridplayer1();
}
break;
case 4://preset -
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(772,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
index_go=0;index_pause=0; index_go_back=0;
detect_mem_preset_previous();
refresh_mem_onpreset(position_preset);
niveauX2=0;
}
break;
case 5://preset +
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(773,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
index_go=0;index_pause=0; index_go_back=0;
detect_next_preset();
refresh_mem_onpreset(position_preset);
niveauX2=0;
}
break;
case 6://goto
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1645,Midi_Faders_Affectation_Mode);
mouse_released=1;
}
else
{
if(numeric_postext>0)
{
index_atoi=(int)(atof(numeric)*10);
if(MemoiresExistantes[index_atoi]==1)
{
position_preset=index_atoi;
refresh_mem_onpreset(position_preset);
reset_numeric_entry();
numeric_postext=0;
}
}
}
break;

default:
break;
}//fin des switch
mouse_released=1;
}
}

if(show_gridplayer_in_seq==1)
{


if(mouse_x>xseq+880-12 && mouse_x<xseq+880+12 && mouse_y>yseq+40-12 && mouse_y<yseq+40+12)
{

if(mouse_released==0)
{
if(Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1476,Midi_Faders_Affectation_Mode);
}
else
{
if(index_grider_selected[0]>0)
{index_grider_selected[0]--;}
}
 mouse_released=1;
}
}


if( mouse_x>xseq+910-12 && mouse_x<xseq+910+12 && mouse_y>yseq+40-12 && mouse_y<yseq+40+12)
{

if( mouse_released==0)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
attribute_midi_solo_affectation(1480,Midi_Faders_Affectation_Mode);
}
else
{
if(index_grider_selected[0]<127){index_grider_selected[0]++;}
}
mouse_released=1;
}
}

do_logical_TheStepBox(xseq+660,yseq+90,0);
do_logical_ThePlayCommands(xseq+760,yseq+90,0);
do_logical_TheGrid_commands(xseq+660,yseq+130,0);//pos x, posy y, num player

if(mouse_x>xseq+690 && mouse_x<xseq+690+105 && mouse_y>yseq+295 && mouse_y<yseq+295+15 && mouse_released==0)
{
if( Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(1540,Midi_Faders_Affectation_Mode);
}

else
{
index_link_speed_crossfade_to_gpl1=toggle(index_link_speed_crossfade_to_gpl1);
if(index_link_speed_crossfade_to_gpl1==1)
{  grid_crossfade_speed[0]=crossfade_speed;
   midi_levels[1508]=crossfade_speed;
}
}
mouse_released=1;
}
}


return(0);
}
