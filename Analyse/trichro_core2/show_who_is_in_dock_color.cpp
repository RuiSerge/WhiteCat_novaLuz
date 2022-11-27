int show_who_is_in_dock_color(int dockCol, int couleur)
{
for (int co=1;co<513;co++)
{
show_who_is_in_FADER_DOCK[co]=dock_color_channels[dockCol][couleur][co];
}

return(0);
}
