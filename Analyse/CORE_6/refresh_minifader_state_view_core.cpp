int refresh_minifader_state_view_core(int cmptfader)
{
    sprintf(str_minifader_feedback[0],"Fader %d:",cmptfader+1);
    int dokmin=dock_used_by_fader_is[cmptfader];
    sprintf(str_minifader_feedback[2],DockName[cmptfader][dokmin]);
    switch(DockTypeIs[cmptfader][dokmin])
    {
    case 0:
        sprintf(str_tmp_minidock_dock,"Channels");
        break;
    case 1://si le doc est reli� aux trichro
        sprintf(str_tmp_minidock_dock,"Color");
        break;
    case 2://si le doc est reli� � un artnet
        sprintf(str_tmp_minidock_dock, "Art-%d",DockNetIs[cmptfader][dokmin]);
        break;
    case 3://si le doc recoit le dmxIN
        sprintf(str_tmp_minidock_dock,"Dmx-In");
        break;
    case 4://si le doc recoit le tracking video
        sprintf(str_tmp_minidock_dock,"Video");
        break;
    case 5://si le doc contient une memoire
        sprintf(str_tmp_minidock_dock,"Mem.%.1f",(((float)(DockHasMem[cmptfader][dokmin]))/10));
        sprintf(str_minifader_feedback[2],descriptif_memoires[(DockHasMem[cmptfader][dokmin])]);
        break;
    case 6://audio Player Volume
        sprintf(str_tmp_minidock_dock,"Vol.%d",(DockHasAudioVolume[cmptfader][dokmin]));
        break;
    case 7://audio Player Pan
        sprintf(str_tmp_minidock_dock,"Pan.%d",(DockHasAudioPan[cmptfader][dokmin]));
        break;
    case 8:
        sprintf(str_tmp_minidock_dock,"Pitch.%d",(DockHasAudioPitch[cmptfader][dokmin]));
        break;
    case 9://no content
        sprintf(str_tmp_minidock_dock,"-no name-");
        break;
    case 10://DC
        sprintf(str_tmp_minidock_dock,"DC.%d",(FaderDirectChan[cmptfader][dokmin]));
        break;
    case 11://chaser
        sprintf(str_tmp_minidock_dock,"Chaser.%d",(ChaserAffectedToDck[cmptfader][dokmin]+1));
        break;
    case 12:
        sprintf(str_tmp_minidock_dock,"GridPl.%d",(faders_dock_grid_affectation[cmptfader][dokmin]+1));
        break;
    default:
        break;
    }
    sprintf(str_minifader_feedback[1],"Dock %d %s",(dokmin+1),str_tmp_minidock_dock);

    sprintf(str_minifader_feedback[3],"Speed: %d", lfo_speed[cmptfader]);

    switch(lfo_mode_is[cmptfader])
    {
    case 0:
        sprintf(report_minifader_str,"Status: No Move");
        break;
    case 1:
        sprintf(report_minifader_str,"Status: Up");
        break;
    case 2:
        sprintf(report_minifader_str,"Status: Down");
        break;
    default:
        break;
    }

    if(lfo_mode_is[cmptfader]==0 && lfo_cycle_is_on[cmptfader]==1)
    {
        sprintf(report_minifader_str,"Status: Saw");
    }

    if(is_dock_for_lfo_selected[cmptfader][dokmin]==1)
    {
        strcat(report_minifader_str," [Loop]");
    }
    sprintf(str_minifader_feedback[4],report_minifader_str);
    strcpy(report_minifader_str,"");

    if(lfo_do_next_step[cmptfader][0]==1)
    {
        sprintf(str_minifader_feedback[5],"ToPrev. Dock");
    }
    else if(lfo_do_next_step[cmptfader][1]==1)
    {
        sprintf(str_minifader_feedback[6],"ToNext Dock");
    }
    if(lfo_cycle_steps[cmptfader]==1)
    {
        sprintf(str_minifader_feedback[7],"UpAndDown Docks");
    }


    sprintf(str_minifader_feedback[8],string_time_is_in_the_dock[cmptfader]);

    if(StopPosOn[cmptfader]==1)
    {
        int niv=0;
        switch(dmx_view)
        {
        case 0:
            niv= (int) (((float)LevelStopPos[cmptfader])/2.55);
            break;
        case 1:
            niv=LevelStopPos[cmptfader];
            break;
        default:
            break;
        }
        sprintf(string_fader_stop_pos[cmptfader],"%d",niv);
        sprintf(str_minifader_feedback[9],"Stop Pos ON: %d",niv);
    }
    else if(StopPosOn[cmptfader]==0)
    {
        strcpy(str_minifader_feedback[9],"");
    }
    return(0);
}
