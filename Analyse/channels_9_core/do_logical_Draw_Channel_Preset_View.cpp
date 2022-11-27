int do_logical_Draw_Channel_Preset_View( int xchan, int ychan,   int prst_v)
{

int maxchan_per_ligne=12;
int nbre_lignes=channel_number_of_lines[prst_v];
int num_circ=0;
int ypos_ch=0;



for (int l=0;l<nbre_lignes+1;l++)
{
for (int c=1; c<=maxchan_per_ligne;c++)
{
ypos_ch=ychan+(l*70);
num_circ=Channel_View_ROUTING[prst_v][c+(l*12)-1];
if (index_over_A_window==0 && index_over_faderspace==0 && mouse_x>   ((xchan-10) + (45*c)) && mouse_x< ((xchan+30) + (45*c))
&& mouse_y> ypos_ch && mouse_y< ypos_ch+65
&&  num_circ!=0 && num_circ<513)
{

if(index_level_attribue==1)//pour déselection lors prochain circuit piqué dominique guesdon 10aout 2010
{
for(int y=1;y<512;y++)
{
Selected_Channel[y]=0;
last_ch_selected=0;
if(index_plot_window==1){substract_channel_selection_to_layers_plot();}
}
index_level_attribue=0;
}

if (index_ch_thruth==0)//selection normale
 {
 Selected_Channel[num_circ]=1-(Temp_Selected_Channel[num_circ]); //chainage mouse released sorti
 last_ch_selected=num_circ;
 if(index_plot_window==1){add_channel_selection_to_layers_plot();substract_channel_selection_to_layers_plot();}
 }
 else if (index_ch_thruth==1)//selection thruth
 {
 Channel_select_thruth(last_ch_selected,num_circ);
 index_ch_thruth=0;
 mouse_released=1;
 if(index_plot_window==1){add_channel_selection_to_layers_plot();substract_channel_selection_to_layers_plot();}
 }
 //
}
}

}

return(0);
}
