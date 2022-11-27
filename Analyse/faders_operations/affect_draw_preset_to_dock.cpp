int  affect_draw_preset_to_dock(int pr,int ff, int dd)
{
    ClearDock(ff,dd);
    DockTypeIs[ff][dd]=15;
    DrawAffectedToDck[ff][dd]=pr;
    sprintf(string_Last_Order,"Affected DRAW Preset %d To Fader %d Dock %d",pr+1,ff+1, dd+1);
    draw_preset_selected_for_order=0;

    return(0);
}
