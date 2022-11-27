int do_logical_choose_personnal_preset_binary_save_load(int xs,int ys)
{
    for(int i=0; i<4; i++)
    {
        if(window_focus_id==W_SAVE && mouse_button==1 && mouse_released==0 && mouse_x>=xs+(20*i) && mouse_x<=xs+(20*i)+10 && mouse_y>=ys && mouse_y<=ys+10)
        {
            mouse_released=1;

            if(index_do_dock==1)
            {
                for(int p=0; p<80; p++)
                {
                    preset_specify_who_to_save_load[p][i]=specify_who_to_save_load[p];
                }
                index_do_dock=0;
                sprintf(string_Last_Order,"Recorded Personnal Save-Load Preset %d",i+1);
            }

            else if(index_main_clear==1)
            {
                for(int p=0; p<80; p++)
                {
                    preset_specify_who_to_save_load[p][i]=0;
                }
                index_main_clear=0;
                sprintf(string_Last_Order,"Cleared Personnal Save-Load Preset %d",i+1);
            }

            else
            {
                for(int p=0; p<80; p++)
                {
                    specify_who_to_save_load[p]=preset_specify_who_to_save_load[p][i];
                }
                index_save_global_is=0;
                sprintf(string_Last_Order,"Called Personnal Save-Load Preset %d",i+1);
            }

        }
    }
    return(0);
}
