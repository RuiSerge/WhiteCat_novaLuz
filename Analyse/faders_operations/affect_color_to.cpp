int affect_color_to(int dockC_sel,int couleur)
{
    if(index_do_dock==1)
    {
        for (int co=1; co<513; co++)
        {
            dock_color_channels[dockC_sel][couleur][co]=Selected_Channel[co];
        }
        index_do_dock=0;
    }
    else if(index_do_modify==1)
    {
        for (int co=1; co<513; co++)
        {
            if(dock_color_channels[dockC_sel][couleur][co]==1 && Selected_Channel[co]==1)
            {
                dock_color_channels[dockC_sel][couleur][co]=0;
            }
            else if(dock_color_channels[dockC_sel][couleur][co]==0 && Selected_Channel[co]==1)
            {
                dock_color_channels[dockC_sel][couleur][co]=1;
            }
        }
        index_do_modify=0;
    }

    if(index_do_report==1)
    {
        for (int co=1; co<513; co++)
        {
            if(bufferSaisie[co]>0 || bufferFaders[co]>0)
            {
                dock_color_channels[dockC_sel][couleur][co]=1;
            }
            else
            {
                dock_color_channels[dockC_sel][couleur][co]=0;
            }
        }
        index_do_report=0;
    }
    Unselect_all_channels();
    return(0);
}
