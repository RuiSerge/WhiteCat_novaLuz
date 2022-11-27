int refresh_vision_memories( int x_seq, int y_seq)
{

Rect ExclueMem(Vec2D(x_seq,y_seq),Vec2D(10,30));


if(window_focus_id==W_SEQUENCIEL && mouse_x>x_seq && mouse_x<x_seq+450 && mouse_y> y_seq and mouse_y<y_seq+hauteur_globale_sequenciel ) // affichage survol des cases souris
{
Rect DelayOver (Vec2D (x_seq, y_seq ), Vec2D ( 40,20));
DelayOver.SetRoundness(7.5);
Rect InOutOver (Vec2D (x_seq, y_seq ), Vec2D ( 60,20));
InOutOver.SetRoundness(7.5);
Rect MemOver (Vec2D (x_seq, y_seq), Vec2D ( 60,20));
MemOver.SetRoundness(7.5);
Rect LinkOver (Vec2D (x_seq, y_seq ), Vec2D ( 35,20));
LinkOver.SetRoundness(7.5);
Rect bangOver (Vec2D (x_seq, y_seq), Vec2D ( 40,20));
bangOver.SetRoundness(7.5);
Rect Gpl1Over (Vec2D (x_seq, y_seq), Vec2D ( 30,20));
Gpl1Over.SetRoundness(7.5);
Rect TextOver (Vec2D (x_seq, y_seq), Vec2D ( 160,15));
TextOver.SetRoundness(5);



if(mouse_y>y_seq+80 && mouse_y< y_seq+100)
{
if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
{
LinkOver.MoveTo (Vec2D (x_seq+180,y_seq+80));
LinkOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
{
bangOver.MoveTo (Vec2D (x_seq+225, y_seq+80));
bangOver.DrawOutline(CouleurLigne);
}
else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
{
Gpl1Over.MoveTo (Vec2D (x_seq+275, y_seq+80));
Gpl1Over.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
{
if(mouse_y> y_seq+80 && mouse_y < y_seq+95)
{
TextOver.MoveTo (Vec2D (x_seq+310, y_seq+80));
}
else
{
TextOver.MoveTo(Vec2D (x_seq+310, y_seq+95));
}
TextOver.DrawOutline(CouleurLigne);
}
}



else if(mouse_y>y_seq+110 && mouse_y<y_seq+140)
{
if(mouse_x> x_seq+10 && mouse_x<x_seq+50)//DELAYS
{
DelayOver.MoveTo (Vec2D (x_seq+10, y_seq+115 ));
DelayOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+50 && mouse_x<x_seq+110)//IN OUT
{
InOutOver.MoveTo(Vec2D (x_seq+50, y_seq+115 ));
InOutOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
{
MemOver.MoveTo (Vec2D (x_seq+110, y_seq+115 ));
MemOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
{
LinkOver.MoveTo (Vec2D (x_seq+180, y_seq+115 ));
LinkOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
{
bangOver.MoveTo (Vec2D (x_seq+225, y_seq+115 ));
bangOver.DrawOutline(CouleurLigne);
}
else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
{
Gpl1Over.MoveTo (Vec2D (x_seq+275, y_seq+115 ));
Gpl1Over.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
{
if(mouse_y> y_seq+110 && mouse_y < y_seq+125)
{
TextOver.MoveTo (Vec2D (x_seq+310, y_seq+110));
}
else
{
TextOver.MoveTo(Vec2D (x_seq+310, y_seq+125));
}
TextOver.DrawOutline(CouleurLigne);
}
}



else if(mouse_y>y_seq+140 && mouse_y<y_seq+170)
{
if(mouse_x> x_seq+10 && mouse_x<x_seq+50)//DELAYS
{
DelayOver.MoveTo (Vec2D (x_seq+10, y_seq+145 ));
DelayOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+50 && mouse_x<x_seq+110)//IN OUT
{
InOutOver.MoveTo  (Vec2D (x_seq+50, y_seq+145));
InOutOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
{
MemOver.MoveTo  (Vec2D (x_seq+110, y_seq+145));
MemOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
{
LinkOver.MoveTo  (Vec2D (x_seq+180, y_seq+145 ));
LinkOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
{
bangOver.MoveTo  (Vec2D (x_seq+225, y_seq+145 ));
bangOver.DrawOutline(CouleurLigne);
}
else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
{
Gpl1Over.MoveTo  (Vec2D (x_seq+275, y_seq+145 ));
Gpl1Over.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
{
if(mouse_y> y_seq+140 && mouse_y < y_seq+155)
{
TextOver.MoveTo  (Vec2D (x_seq+310, y_seq+140));
}
else
{
TextOver.MoveTo(Vec2D (x_seq+310, y_seq+155));
}
TextOver.DrawOutline(CouleurLigne);
}
}




for(int i=0;i<nbre_memoires_visualisables_en_preset;i++)
{
if(mouse_y>y_seq+145+(35*i)  && mouse_y< y_seq+175+(35*i))
{

if(mouse_x> x_seq+110 && mouse_x<x_seq+170)//MEMS
{
MemOver.MoveTo (Vec2D (x_seq+110,y_seq+145+(35*i)));
MemOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+180 && mouse_x<x_seq+215)//LINKS
{
LinkOver.MoveTo (Vec2D (x_seq+180,y_seq+145+(35*i)));
LinkOver.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+225 && mouse_x<x_seq+265)//BANGER
{
bangOver.MoveTo (Vec2D (x_seq+225, y_seq+145+(35*i) ));
bangOver.DrawOutline(CouleurLigne);
}
else if(mouse_x>x_seq+270 && mouse_x<x_seq+300)//GRID PLAYER
{
Gpl1Over.MoveTo (Vec2D (x_seq+275, y_seq+145+(35*i) ));
Gpl1Over.DrawOutline(CouleurLigne);
}
else if(mouse_x> x_seq+310 && mouse_x<x_seq+470)//TEXT DECRIPTION
{
if(mouse_y> y_seq+140+(35*i) && mouse_y < y_seq+155+(35*i) )
{
TextOver.MoveTo (Vec2D (x_seq+310, y_seq+140+(35*i)));
}
else
{
TextOver.MoveTo(Vec2D (x_seq+310, y_seq+155+(35*i)));
}
TextOver.DrawOutline(CouleurLigne);
}

}
}

}







}*/
