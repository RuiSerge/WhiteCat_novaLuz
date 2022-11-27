int match_minifaders()
{
    mf_preset_selected_is=-999;
    for(int prt=0; prt<8; prt++)
    {
        int index_presetmf=0;
        for(int cmptfader=0; cmptfader<core_user_define_nb_faders; cmptfader++)
        {
            if(minifaders_preset_selection[prt][cmptfader]==minifaders_selected[cmptfader])
            {
                index_presetmf++;
            }
            if(index_presetmf==core_user_define_nb_faders)
            {
                mf_preset_selected_is=prt;
                break;
            }
        }
    }
    for(int prt=0; prt<8; prt++)
    {
        int index_presetmf=0;
        for(int cmptfader=0; cmptfader<core_user_define_nb_faders; cmptfader++)
        {
            if(minifaders_preset_selection[prt][cmptfader]==0)
            {
                index_presetmf++;
            }
        }
        if(index_presetmf==core_user_define_nb_faders)
        {
            minifader_preset_is_empty[prt]=1;
        }
        else
        {
            minifader_preset_is_empty[prt]=0;
        }
    }
    return(0);
}
