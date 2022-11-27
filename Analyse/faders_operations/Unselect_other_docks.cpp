int Unselect_other_docks(int themaster, int thedock)
{
 for (int rdk=0;rdk<core_user_define_nb_docks;rdk++)
 {
 if (rdk!=thedock)
 {DockIsSelected[themaster][rdk]=0;}
 }
 return(0);
}
