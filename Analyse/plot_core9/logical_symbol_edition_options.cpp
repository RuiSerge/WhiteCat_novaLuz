int logical_symbol_edition_options(int plotx, int ploty)
{
if(window_focus_id==W_PLOT && index_edit_light_plot==1 && mouse_button==1 && mouse_released==0)
{
if(  index_click_inside_relativ_xy==0)
{
for (int l=0;l<8;l++)
{
if(mouse_x>plotx+5 && mouse_x<plotx+5+10 && mouse_y>ploty+70+(20*l) && mouse_y<ploty+70+(20*l)+10)
{
plot_show_options[l]=toggle(plot_show_options[l]);
mouse_released=1;
}
switch(l)
{
case 0: //"CHANNEL");
if(mouse_x>plotx+100 && mouse_x<plotx+100+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
int tnum=atoi(numeric);
if(tnum>=0 && tnum<=512)
{
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
Selected_Channel[(symbol_channel_is[view_plot_calc_number_is][i])]=0;
symbol_channel_is[view_plot_calc_number_is][i]= tnum;
Selected_Channel[tnum]=1;
last_ch_selected=tnum;
if(symbol_dimmer_is[view_plot_calc_number_is][i]==0)
{
search_affect_first_dimmer_to_symbole(view_plot_calc_number_is,i);
}
if(index_build_patch_from_plot==1 && symbol_dimmer_is[view_plot_calc_number_is][i]>0)
{
Patch[(symbol_dimmer_is[view_plot_calc_number_is][i])]=(symbol_channel_is[view_plot_calc_number_is][i]);
}
}
}
}
generate_channel_view_list_from_patched_circuits();
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}
break;
case 1: //"LIST:");plotx+20,ploty+65+(20*l)));
if(index_type==1 && mouse_x>plotx+20 && mouse_x<plotx+20+175 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
int tnum=0;
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
tnum=i;
for(int tt=0;tt<24;tt++)
{
descriptif_projecteurs[(symbol_channel_is[view_plot_calc_number_is][tnum])][tt]=numeric[tt];
}
descriptif_projecteurs[(symbol_channel_is[view_plot_calc_number_is][tnum])][24]='\0';
}
}
reset_numeric_entry();
if(index_text_auto_close==1){index_type=0;}
mouse_released=1;
}
break;
case 2://"GEL 1:");
if(mouse_x>plotx+70 && mouse_x<plotx+70+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
int tnum=atoi(numeric);
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
gelat[view_plot_calc_number_is][i][0]= tnum;
}
}
reset_numeric_entry();
numeric_postext=0;
mouse_released=1;
}
else if(mouse_x>plotx+130 && mouse_x<plotx+130+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
gelat_family[view_plot_calc_number_is][i][0]++;
if(gelat_family[view_plot_calc_number_is][i][0]>nbre_gelats_manufact){gelat_family[view_plot_calc_number_is][i][0]=0;}

}
}
plot_generate_appareils_list();
mouse_released=1;
}
break;
case 3: //"GEL 2:");
if(mouse_x>plotx+70 && mouse_x<plotx+70+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
int tnum=atoi(numeric);
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
gelat[view_plot_calc_number_is][i][1]= tnum;
}
reset_numeric_entry();
numeric_postext=0;
}
plot_generate_appareils_list();
mouse_released=1;
}
else if(mouse_x>plotx+130 && mouse_x<plotx+130+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
gelat_family[view_plot_calc_number_is][i][1]++;
if(gelat_family[view_plot_calc_number_is][i][1]>nbre_gelats_manufact){gelat_family[view_plot_calc_number_is][i][1]=0;}
}
}
plot_generate_appareils_list();
mouse_released=1;
}
break;
case 4: //"GEL 3:");
if(mouse_x>plotx+70 && mouse_x<plotx+70+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
int tnum=atoi(numeric);
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
gelat[view_plot_calc_number_is][i][2]= tnum;
}
reset_numeric_entry();
numeric_postext=0;
}
mouse_released=1;
}
else if(mouse_x>plotx+130 && mouse_x<plotx+130+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
gelat_family[view_plot_calc_number_is][i][2]++;
if(gelat_family[view_plot_calc_number_is][i][2]>nbre_gelats_manufact){gelat_family[view_plot_calc_number_is][i][2]=0;}
}
}
plot_generate_appareils_list();
mouse_released=1;
}
break;
case 5: //"DIMMER:");
if(mouse_x>plotx+100 && mouse_x<plotx+100+50 && mouse_y>ploty+65+(20*l) && mouse_y<ploty+65+(20*l)+18)
{
int tnum=atoi(numeric);

if(tnum>=0 && tnum<=512)
{
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1)
{
int olddim=symbol_dimmer_is[view_plot_calc_number_is][i];
int the_symb=i;

if(index_build_patch_from_plot==1 )
{Patch[olddim]=0;} //depatch

for (int l=0;l<4;l++)
{
for(int u=1;u<=nbre_symbols_on_plot[l];u++)
{
if  (symbol_dimmer_is[l][u]== tnum && (symbol_channel_is[l][u] != symbol_channel_is[view_plot_calc_number_is][the_symb]) ) {symbol_dimmer_is[l][u]=0;}
}
}
symbol_dimmer_is[view_plot_calc_number_is][the_symb]= tnum;
}
}
}
reset_numeric_entry();
numeric_postext=0;


if(index_build_patch_from_plot==1)
{
if(tnum>=0) {repatch_from_plot(view_plot_calc_number_is);    }
}
mouse_released=1;
}
break;
default:
break;
}
}

if(mouse_x>plotx+5 && mouse_x<plotx+5+195 && index_type==1)
{
for(int n=0;n<4;n++)
{
if(mouse_y>ploty+225+(n*20) && mouse_y<ploty+225+(n*20)+18)
{
   for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
   {
   if(symbol_is_selected[view_plot_calc_number_is][i]==1)
   {
   sprintf(symbol_note[view_plot_calc_number_is][i][n],numeric);
   }
   }
sprintf(symbol_note[view_plot_calc_number_is][last_selected_symbol_is][n],numeric);
reset_numeric_entry();
numeric_postext=0;
if(index_text_auto_close==1){index_type=0;}
mouse_released=1;
break;
}
}
}

if(mouse_x>plotx+150 && mouse_x<plotx+150+30 && mouse_y>ploty+210 && mouse_y<ploty+220 )
{
plot_name_text_size=toggle(plot_name_text_size);
mouse_released=1;
}
for(int i=0;i<5;i++)
{
if(index_click_inside_relativ_xy==0 && mouse_x>plotx+5 && mouse_x<plotx+5+10 && mouse_y>ploty+320+(20*i) &&  mouse_y<ploty+320+(20*i)+10)
{
if(  Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_solo_affectation(1610+i,Midi_Faders_Affectation_Mode);
}
else
{
switch(mode_relatif_xy_solo)
{
case 0:
adjust_xy_type[i]=toggle(adjust_xy_type[i]);
break;
case 1:
for(int j=0;j<5;j++)
{adjust_xy_type[j]=0;}
adjust_xy_type[i]=1;
break;
default: break;
}
}
mouse_released=1;

}
}

if(index_click_inside_relativ_xy==0 && mouse_x>plotx+75 && mouse_x<plotx+75+10 && mouse_y>ploty+350 &&  mouse_y<ploty+350+10)
{
mode_relatif_xy_solo=toggle(mode_relatif_xy_solo);
mouse_released=1;
}


for(int pr=0;pr<8;pr++)
{
if( mouse_x>plotx+30+(20*pr) && mouse_x<plotx+30+(20*pr)+10 && mouse_y>ploty+430 && mouse_y<ploty+430+10)
{
xyrelativ_preset=pr;

if(  Midi_Faders_Affectation_Type!=0)
{
 attribute_midi_to_control(1615+pr,Midi_Faders_Affectation_Type,Midi_Faders_Affectation_Mode);
}
else
{
if(index_main_clear==0)
{

if(index_do_dock==0 )
{affect_preset_xy_to_symbols(pr);}

else if(index_do_dock==1 )
{
record_preset_xy_from_symbol(pr);
reset_symbols_selected(view_plot_calc_number_is);
index_do_dock=0;
}
}
else
{
index_ask_clear_preset_relativ=1;
index_ask_confirm=1;
}
plot_light_preset_on_click[pr]=1.0;
last_xyrelativ_preset=pr;
}
xyrelativ_preset=999;

mouse_released=1;
break;
}
}
if( mouse_y>ploty+450 && mouse_y<ploty+450+18)
{
if(mouse_x>plotx+20 && mouse_x<plotx+20+100 )//rebuild on off
{
index_build_patch_from_plot=toggle(index_build_patch_from_plot);
}
else if(mouse_x>plotx+110 && mouse_x<plotx+110+85 )//reset patch
{
index_do_clear_all_the_patch=1;
index_ask_confirm=1;
}
mouse_released=1;
}
}


if( mouse_x > plotx+110 && mouse_x<plotx+110+70 && mouse_y>ploty+310 && mouse_y<ploty+310+70)
{

if(index_main_clear==1)
{
for(int i=1;i<=nbre_symbols_on_plot[view_plot_calc_number_is];i++)
{
if(symbol_is_selected[view_plot_calc_number_is][i]==1 )
{
for(int t=0;t<5;t++)
{
if(adjust_xy_type[t]==1)
{
 relatif_plot_xy[view_plot_calc_number_is][i][t][0]=0;
 relatif_plot_xy[view_plot_calc_number_is][i][t][1]=0;
}
}
}
}
index_main_clear=0;
}

else
{
if(index_click_inside_relativ_xy==0 && mouse_released==0 )
{
index_click_inside_relativ_xy=1;
store_relativ_xy_position_of_activ_calc(view_plot_calc_number_is);
}

}
}

}
 return(0);
}
