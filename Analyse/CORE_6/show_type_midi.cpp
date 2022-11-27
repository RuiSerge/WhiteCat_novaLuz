void show_type_midi(int control, const std::string command)
{

    switch(miditable[0][control])
    {
    case 0:
        sprintf(thetypinfo,"Note");
        break;
    case 1:
        sprintf(thetypinfo,"K.On");
        break;
    case 2:
        sprintf(thetypinfo,"K.Off");
        break;
    case 4:
        sprintf(thetypinfo,"C.Change");
        break;
    default:
        strcpy(thetypinfo,"");
        break;
    }
    sprintf(string_last_midi_id,"%s selected is Ch: %d Pitch: %d Typ: %s",command.c_str(), miditable[1][control],miditable[2][control],thetypinfo);
    sprintf(string_shortview_midi,"%s %d/%d",thetypinfo,miditable[1][control],miditable[2][control]);
}
