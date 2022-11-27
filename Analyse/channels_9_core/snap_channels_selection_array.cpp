int snap_channels_selection_array()//pour saisie continue des circuits, au click button
{
    for (int i=0; i<513; i++)
    {
        Temp_Selected_Channel[i]=Selected_Channel[i];
    }
    return(0);
}
