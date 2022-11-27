int logical_deroule_repertoire_plans(int xrep, int yrep)
{

for (int y=0;y<8;y++)
{

if( index_editing_theatre_plan==0 && mouse_x>xrep+5 && mouse_x<xrep+5+150 && mouse_y>(yrep+185+(y*20)-10) && mouse_y<(yrep+185+(y*20)+5))
{
if(mouse_button==1 && mouse_released==0)
{
importplan_selected=y+line_importplan;
mouse_released=1;
sprintf(Name_of_plane_is,list_import_plans[importplan_selected]);


load_plan_of_theatre(Name_of_plane_is, 1);


alpha_plan=1.0;

}
}

}



if(mouse_x>xrep+190-12 && mouse_x<xrep+190+12)
{
if(mouse_y>yrep+180-12 && mouse_y<yrep+200+12)
{
if(mouse_button==1 &&  index_editing_theatre_plan==0 && editing_plot_sizex==0 && editing_plot_sizey==0)
{
if(line_importplan>0){line_importplan--;}
}
}
else if(mouse_y>yrep+290-12 && mouse_y<yrep+310+12)
{
if(mouse_button==1 &&  index_editing_theatre_plan==0)
{
if(line_importplan<127){line_importplan++;}
}
}
}

if( index_editing_theatre_plan==0 && mouse_x>xrep+150 && mouse_x<xrep+150+60 && mouse_y>(yrep+345) && mouse_y<(yrep+345+20)
 && editing_plot_sizex==0 && editing_plot_sizey==0)
{
if(mouse_button==1 && mouse_released==0)
{
scan_planfolder();
 mouse_released=1;
}
}

return(0);
}
