int affect_color_to_dock(int fa, int doc)
{
    ClearDock(fa,doc);
    DockTypeIs[fa][doc]=1;//le type est 1, il est rempli avec une couleur
    colorpreset_linked_to_dock[dock_color_selected][0]=fa;// num fader
    colorpreset_linked_to_dock[dock_color_selected][1]=doc;//num dock
    return(0);
}
