int detect_actual_master_lock_is()
{
    for(int u=0; u<core_user_define_nb_faders; u++)
    {
        if(LockFader_is_FullLevel[u]==1)
        {
            actual_master_lock=u;
            break;
        }
    }
    return(0);
}
