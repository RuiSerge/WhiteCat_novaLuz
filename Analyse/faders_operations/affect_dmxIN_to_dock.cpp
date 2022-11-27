int affect_dmxIN_to_dock(int faa, int docc)
{
    ClearDock(faa,docc);
    DockTypeIs[faa][docc]=3;
    return(0);
}
