int do_wizard_reload_from_disk()
{
    index_save_global_is=0;
    set_all_saves_indexes_at(0);
    specify_who_to_save_load[0]=1;//memories
    specify_who_to_save_load[1]=1;
    specify_who_to_save_load[2]=1;
    specify_who_to_save_load[3]=1;
    specify_who_to_save_load[4]=1;
    index_is_saving=1;
    Load_Show();
    timer_save_tmp=0;
    index_is_saving=0;
    set_all_saves_indexes_at(1);
    index_save_global_is=1;

    return(0);
}
