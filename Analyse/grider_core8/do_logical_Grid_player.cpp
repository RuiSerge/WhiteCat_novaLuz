int do_logical_Grid_player(int xb, int yb, int num_grider)
{

do_logical_TheCallGridBox(xb,yb,num_grider);

do_logical_TheStepBox(xb+315,yb, num_grider);
do_logical_ThePlayCommands(xb+400,yb,num_grider);




do_logical_TheGrid_commands(xb+20,yb+35,num_grider);//pos x, posy y, num player
do_logical_TheGrid_divers(xb+20+200,yb+30,num_grider);//pos x, posy y, num player
do_logical_TheGrid_matrix(xb+20+320,yb+35,size_grille,num_grider);//pos x pos y taille de case num player

return(0);
}
