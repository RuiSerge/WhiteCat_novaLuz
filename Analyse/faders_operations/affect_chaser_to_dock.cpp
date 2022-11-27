int affect_chaser_to_dock(int chas,  int fd,int dk )
{
    ClearDock(fd,dk);
    ChaserAffectedToDck[fd][dk]=chas;
    DockTypeIs[fd][dk]=11;
    view_chaser_affected_to_fader[chas][0]=fd;//pour affichage chaser selected dans fenetre
    view_chaser_affected_to_fader[chas][1]=dk;//pour affichage chaser selected dans fenetre
    return(0);
}
