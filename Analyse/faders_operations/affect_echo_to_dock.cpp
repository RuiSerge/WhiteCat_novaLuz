int affect_echo_to_dock(int echo, int ff, int dd)
{
    ClearDock(ff,dd);
    DockTypeIs[ff][dd]=16;
    echo_affected_to_dock[ff][dd]=echo;
    sprintf(string_Last_Order,"Affected DRAW Preset %d To Fader %d Dock %d",echo+1,ff+1, dd+1);
    return(0);
}
