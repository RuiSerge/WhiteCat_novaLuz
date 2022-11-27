int affect_audio_control_to_dock(int faa, int docc)
{
    DockHasAudioVolume[faa][docc]=0;
    DockHasAudioPan[faa][docc]=0;
    DockHasAudioPitch[faa][docc]=0;
    ClearDock(faa,docc);
    switch(audio_type_for_dock_affectation_is)
    {
    case 0:
        DockTypeIs[faa][docc]=6;//volume
        DockHasAudioVolume[faa][docc]=player_to_affect_to_dock+1;
        break;
    case 1:
        DockTypeIs[faa][docc]=7;//pan
        DockHasAudioPan[faa][docc]=player_to_affect_to_dock+1;
        break;
    case 2:
        DockTypeIs[faa][docc]=8;//picth
        DockHasAudioPitch[faa][docc]=player_to_affect_to_dock+1;
        break;
    default:
        break;
    }
    player_to_affect_to_dock=999;
    audio_type_for_dock_affectation_is=999;

    return(0);
}
