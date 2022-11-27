int ClearDock(int fad, int dk)
{

    for (int dc=1; dc<514; dc++)
    {
        FaderDockContains[fad][dk][dc]=0;//nettoyage du fader
        FaderDoDmx[fad][dc]=0;//clear du buffer dmx
        show_who_is_in_FADER_DOCK[dc]=0;//debug jacques
        highest_level_comes_from_fader[dc]=0;//debug jacques
    }


    DockTypeIs[fad][dk]=9;//le type est 9 clear rien du tout / 0= circuits normaux


    if(DockTypeIs[fad][dk]==1)
    {
        for(int i=0; i<8; i++)
        {
            if(colorpreset_linked_to_dock[i][0]==fad && colorpreset_linked_to_dock[i][1]==dk)
            {
                colorpreset_linked_to_dock[i][0]=-1;
                colorpreset_linked_to_dock[i][1]=-1;
            }
        }
    }


    for(int fg=0; fg<48; fg++)
    {
        fgroup[fad][dk][fg]=0;
    }
    //remise à plat de view
    show_who_is_in_dock (fad, dk);
    time_minutes=0;
    time_secondes=0;
    time_centiemes=0;
    index_type_of_time_to_affect[0]=1;
    index_type_of_time_to_affect[2]=1;
    DoTimeToDock(fad,dk);
    index_type_of_time_to_affect[0]=0;
    index_type_of_time_to_affect[2]=0;
    index_type_of_time_to_affect[1]=1;
    index_type_of_time_to_affect[3]=1;
    time_minutes=0;
    time_secondes=3;
    time_centiemes=0;
    DoTimeToDock(fad,dk);
    index_type_of_time_to_affect[1]=0;
    index_type_of_time_to_affect[3]=0;
    strcpy(DockName[fad][dk],"");
    DockName[fad][dk][24]='\0';
    is_dock_for_lfo_selected[fad][dk]=0;
    DockHasAudioVolume[fad][dk]=999;
    DockHasAudioPan[fad][dk]=999;
    DockHasAudioPitch[fad][dk]=999;
    ChaserAffectedToDck[fad][dk]=999;
    faders_dock_grid_affectation[fad][dk]=-1;
    return(0);
}
