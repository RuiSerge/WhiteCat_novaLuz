int affect_network_to_dock(int faa, int docc)
{
    ClearDock(faa,docc);
    DockTypeIs[faa][docc]=2;
    DockNetIs[faa][docc]=select_artnet_to_listen; // numero univ
    return(0);
}
