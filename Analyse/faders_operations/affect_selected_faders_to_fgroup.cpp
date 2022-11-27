int affect_selected_faders_to_fgroup(int fd, int dk)
{
 ClearDock(fd,dk);
 DockTypeIs[fd][dk]=13;
 record_minifaders_selected_as_fgroup(fd,dk);
 return(0);
}
