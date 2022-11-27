void do_logical_deroule_repertoire_classical_save(int xrep, int yrep, const std::string label)
{
const std::string name_of_rep = label.substr(0,24);

for (int y=0;y<8;y++)
{


if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+155 && mouse_y>(yrep+175+(y*20)) && mouse_y<(yrep+190+(y*20)))
{

if(mouse_button==1 && mouse_released==0)
{
savefile_selected=(y+line_save);
sprintf(savefile_name,list_save_files[savefile_selected]);
mouse_released=1;
}
}

}

if(window_focus_id==W_SAVE && mouse_x>xrep+5 && mouse_x<xrep+245 && mouse_y>yrep+347 && mouse_y<yrep+377)
{

if(mouse_button==1 && mouse_released==0 && index_type==1)
{

for (int tt=0;tt<24;tt++)
{
savefile_name[tt]=numeric[tt];
}
reset_numeric_entry();
index_type=0;
mouse_released=1;
}
}

if(window_focus_id==W_SAVE && mouse_x>xrep+208 && mouse_x<xrep+232)
{
if(mouse_y>yrep+188 && mouse_y<yrep+212)
{

if(mouse_button==1)
{

if(line_save>0){line_save--;}
mouse_released=1;
}
}
else if(mouse_y>yrep+298 && mouse_y<yrep+322)
{

if(mouse_button==1)
{

if(line_save<127){line_save++;}
mouse_released=1;
}
}
}
if(window_focus_id==W_SAVE && mouse_x>xrep+40 && mouse_x<xrep+110 && mouse_y>yrep+390 && mouse_y<yrep+420)
{

if(mouse_button==1 && mouse_released==0)
{

if(strlen(savefile_name)==0){sprintf(savefile_name,"unnamed");}
index_do_saveshow=1;
index_ask_confirm=1;
mouse_released=1;
}
}

if(window_focus_id==W_SAVE && mouse_x>xrep+140 && mouse_x<xrep+210 && mouse_y>yrep+390 && mouse_y<yrep+420)
{
if(mouse_button==1 && mouse_released==0)
{

if(strcmp(savefile_name,"")!=0)
{
index_do_loadshow=1;
index_ask_confirm=1;
}
mouse_released=1;
}
}


if(window_focus_id==W_SAVE && mouse_x>xrep+280 && mouse_x<xrep+350 && mouse_y>yrep+390 && mouse_y<yrep+420)
{

if(mouse_button==1 && mouse_released==0)
{
index_do_resetshow=1;
index_ask_confirm=1;
mouse_released=1;
}
}
}
