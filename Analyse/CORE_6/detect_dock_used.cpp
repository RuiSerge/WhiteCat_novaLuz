int detect_dock_used(int numfad)
{
    int thedockused=0;
    for (int tt=0; tt<core_user_define_nb_docks; tt++)
    {
        if ( DockIsSelected[numfad][tt]==1)
        {
            thedockused=tt;
            break;
        }
    }
    return(thedockused);
}
