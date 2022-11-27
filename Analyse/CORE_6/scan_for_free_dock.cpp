int scan_for_free_dock()
{
    bool someone_inside=0;
    for (int f=0; f<core_user_define_nb_faders; f++)
    {
        for (int d=0; d<core_user_define_nb_docks; d++)
        {
            someone_inside=0;
            for(int c=0; c<513; c++)
            {
                if (FaderDockContains[f][d][c]>0)
                {
                    someone_inside=1;
                    break;
                }
            }
            if(someone_inside==0)
            {
                DockTypeIs[f][d]=9;
            }
            else if(someone_inside==1)
            {
                DockTypeIs[f][d]=0;
            }
        }

    }
    return(0);
}
