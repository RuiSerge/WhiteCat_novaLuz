int detect_master_lock(int mo)
{


    for(int p=0; p<core_user_define_nb_faders; p++)
    {
        if(LockFader_is_FullLevel_Preset[mo][p]==1)
        {
            master_lock_preset[mo]=p+1;//l info d affichage est mise directement en + 1 pour permettre le 0
            break;
        }
    }

    return(0);
}
