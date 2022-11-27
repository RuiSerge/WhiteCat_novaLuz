int DoMouse()
{
	float fx, fy;

	fx = (mouse_x-1);
	fy = (mouse_y-1);
	V3D_f mousev1 =
	{
		 fx,fy, 0.,
		0., 0.,
		makecol(255, 127, 0) // black vertex
	};

	fx = (mouse_x+20);
	fy = (mouse_y+30);
	V3D_f mousev2 =
	{
		fx,fy, 0.,
		0., 0.,
		makecol(125, 0, 0) // white vertex
	};

	fx = (mouse_x+30);
	fy = (mouse_y+10);
	V3D_f mousev3 =
	{
		fx,fy, 0.,
		0., 0.,
		makecol(125, 0,0) // color vertex
	};



    triangle3d_f(screen, POLYTYPE_GCOL, NULL, &mousev1, &mousev2, &mousev3);



     Line( Vec2D( mouse_x-1,mouse_y-1), Vec2D( mouse_x+20,mouse_y+30),2.0).Draw( CouleurLigne );
     Line( Vec2D( mouse_x+20,mouse_y+30), Vec2D( mouse_x+30,mouse_y+10),2.0).Draw( CouleurLigne );
     Line( Vec2D( mouse_x+30,mouse_y+10), Vec2D( mouse_x-1,mouse_y-1),2.0).Draw(CouleurLigne);

     if(Midi_Faders_Affectation_Type!=0  ){neuromoyen.Print( string_shortview_midi, mouse_x-20,mouse_y+40);};

return(0);
}
