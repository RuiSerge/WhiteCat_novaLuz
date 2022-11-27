int do_logical_Save_Menu(int xsave, int ysave)
{

if(window_focus_id==W_SAVE && mouse_x>xsave+310 && mouse_x<xsave+410 && mouse_y>ysave+15 && mouse_y<ysave+35)
{
if(mouse_button==1 && mouse_released==0)
{
index_save_mode_export_or_binary=toggle(index_save_mode_export_or_binary);
mouse_released=1;
}
}



switch(index_save_mode_export_or_binary)
{
case 0:
do_logical_selecteur_binary_save_solo_global(xsave+30, ysave+50);
do_logical_deroule_repertoire_classical_save(xsave+20, ysave+85, "saves");
do_logical_choose_personnal_preset_binary_save_load(xsave+300, ysave+270);
break;
case 1:
if(isPdf==1) {do_logical_selecteur_PDF_save_solo_global(xsave+30, ysave+50);   }
do_logical_deroule_repertoire_export_import(xsave+20, ysave+85, "import_export");
break;
default: break;
}
if(window_focus_id==W_SAVE && mouse_x>xsave+300 && mouse_x<xsave+370 && mouse_y>ysave+430 && mouse_y<ysave+455)
{
if(mouse_button==1 && mouse_released==0)
{
index_show_save_load_report=toggle(index_show_save_load_report);
mouse_released=1;
there_is_change_on_show_save_state=1;
}

}

return(0);
}
