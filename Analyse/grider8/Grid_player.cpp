int Grid_player(int xb, int yb, int num_grider)
{
    Line(Vec2D(xb+10,yb-10),Vec2D(xb+largeurGrider, yb-10)).Draw(CouleurLigne);
    neuromoyen.Print("GridPlayer",xb+500,yb+15);
    neuro.Print(ol::ToString(num_grider+1),xb+578,yb+17);

    TheCallGridBox(xb,yb,num_grider);
    TheStepBox(xb+315,yb, num_grider);
    ThePlayCommands(xb+400,yb,num_grider);



    TheGrid_commands(xb+20,yb+35,num_grider);//pos x, posy y, num player
    TheGrid_divers(xb+220,yb+30,num_grider);//pos x, posy y, num player
    TheGrid_matrix(xb+340,yb+35,num_grider);//pos x pos y taille de case num player

    return(0);
}
