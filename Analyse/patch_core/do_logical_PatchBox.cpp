int do_logical_PatchBox(int XChan, int YChan, float scroll_chan)
{

if(mouse_x>=XChan+340 && mouse_x<=XChan+430 && mouse_y>YChan+50 && mouse_y<YChan+250)
{
scroller_patch=mouse_y-(YChan+50);
}


for (int o=0;o<9;o++)
{

 if(mouse_x>XChan+345 && mouse_x<XChan+435 && mouse_y>YChan+290+(o*30) &&  mouse_y<YChan+310+(o*30)  )
 {
switch(o)
{
 case 0:
 patch_unselect_all_dimmers();
 break;
 case 1:
 index_affect_patch=toggle(index_affect_patch);
 break;
 case 2:
 patch_select_all_dimmers();
 break;
 case 3:
 index_do_clear_patch=1;
 index_ask_confirm=1;
 break;
 case 4:
 index_do_default_patch=1;
 index_ask_confirm=1;
 break;
 case 5:
 index_menu_curve=toggle(index_menu_curve);
 break;
 case 6:
 index_patch_overide=toggle(index_patch_overide);
 reset_check_grada_overide_dimmers();
 break;
 case 7:
 index_build_patch_from_plot=toggle(index_build_patch_from_plot);
 break;
 case 8:
 index_show_first_dim=toggle(index_show_first_dim);
 break;
 default:
 break;
}
 mouse_released=1;
}

}


int maxchan_per_ligne=7;
int grad=0;
for (int l=0;l<86;l++)
{
if(l==85){maxchan_per_ligne=3;} //derniere ligne à 512

for (int c=1; c<maxchan_per_ligne;c++)
{
if(mouse_x>(XChan + (45*c)-10) && mouse_x<(XChan + (45*c)+35) && mouse_y>YChan+50 && mouse_y>(YChan+90+(l*60) - (int)(scroller_patch* scroll_chan)) && mouse_y<(YChan+90+(l*60)+40 - (int)(scroller_patch* scroll_chan)))
{
grad=c+(l*6);
if(Dimmers_selected[grad]==0)
{
Dimmers_selected[grad]=1;
}
else if(Dimmers_selected[grad]==1)
{
Dimmers_selected[grad]=0;
}
if(index_affect_patch==1)//affectation manuelle à la souris
{
Patch[grad]=last_ch_selected;
sprintf(string_Last_Order,">> Dimmer %d affected to Channel %d",grad, last_ch_selected);
sprintf(string_monitor_patch,">> Dimmer %d affected to Channel %d",grad, last_ch_selected);
patch_unselect_all_dimmers();
for (int ci=1;ci<514;ci++)
{Selected_Channel[ci]=0;}
index_type=0;index_level_attribue=0;
index_affect_patch=0;
}
generate_channel_view_list_from_patched_circuits();
mouse_released=1;
}


}
}

return(0);
}
