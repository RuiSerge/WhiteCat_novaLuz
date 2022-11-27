int show_who_is_in_dock (int fader, int thedokis)
{
    for(int doloop=1; doloop<514; doloop++)
    {
        if( FaderDockContains[fader][thedokis][doloop]==0)
        {
            show_who_is_in_FADER_DOCK[doloop]=0;
        }
        else if( FaderDockContains[fader][thedokis][doloop]>0)
        {
            show_who_is_in_FADER_DOCK[doloop]=1;
        }
    }


    switch (miditable[0][fader])
    {
    case 0:
        sprintf(thetypinfo,"Note");
        break;
    case 1:
        sprintf(thetypinfo,"Key On");
        break;
    case 2:
        sprintf(thetypinfo,"Key Off");
        break;
    case 4:
        sprintf(thetypinfo,"Ctrl Change");
        break;
    default:
        break;
    }

    sprintf(string_last_midi_id,"FADER is Ch: %d Pitch: %d Typ: %s", miditable[1][fader],miditable[2][fader],thetypinfo);


    if(thedokis==0 || thedokis==1) //up down button
    {

        switch (miditable[0][48+fader+(thedokis*48)])
        {
        case 0:
            sprintf(thetypinfo,"Note");
            break;
        case 1:
            sprintf(thetypinfo,"Key On");
            break;
        case 2:
            sprintf(thetypinfo,"Key Off");
            break;
        case 4:
            sprintf(thetypinfo,"Ctrl Change");
            break;
        default:
            break;
        }

        sprintf(string_last_midi_id,"DOCK is Ch: %d Pitch: %d Type: %s", miditable[1][48+fader+(thedokis*48)],miditable[2][48+fader+(thedokis*48)],thetypinfo);
    }

    sprintf(string_last_over_dock,">>Last Over Dock: Fader %d Dock %d", fader+1,thedokis+1);
    over_fader=fader;
    over_dock=thedokis;

    return(0);
}
