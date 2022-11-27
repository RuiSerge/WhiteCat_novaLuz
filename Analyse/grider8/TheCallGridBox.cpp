int TheCallGridBox(int xb, int yb, int num_grider)
{
Rect GriderNum(Vec2D(xb+10,yb),Vec2D(50,20));
GriderNum.SetRoundness(5);
GriderNum.DrawOutline(CouleurLigne.WithAlpha(0.5));
neuromoyen.Print(ol::ToString(index_grider_selected[num_grider]+1),(xb+20), (yb+15));

if(mouse_x>xb+10 && mouse_x<xb+60 && mouse_y>yb && mouse_y<yb+20
&& window_focus_id==W_GRID  )
{
GriderNum.DrawOutline(CouleurLigne);
if(Midi_Faders_Affectation_Type!=0)
{
GriderNum.DrawOutline(CouleurBlind);
char sttmp[24];
sprintf(sttmp,"CallGrid in GridPl.%d",num_grider+1);
show_type_midi(1524+num_grider,sttmp );
}
}

Rect GiveNameOfGrider(Vec2D(xb+70,yb), Vec2D( 170,20));
GiveNameOfGrider.SetRoundness(7.5);
GiveNameOfGrider.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print( grider_name[index_grider_selected[num_grider]],(xb+75), (yb+15));
if(  window_focus_id==W_GRID && mouse_x>xb+70 && mouse_x<xb+250 && mouse_y>yb && mouse_y<yb+20 && index_type==1 )
{
GiveNameOfGrider.DrawOutline(CouleurLigne);
}

Circle GriderPlus(Vec2D(xb+295,yb+10),12);
Circle GriderMinus(Vec2D(xb+265,yb+10),12);

petitchiffre.Print("-",xb+260,yb+13);
petitchiffre.Print("+",xb+290,yb+13);
GriderPlus.DrawOutline(CouleurLigne);
GriderMinus.DrawOutline(CouleurLigne);

if( window_focus_id==W_GRID )
{

if(mouse_x>xb+253 && mouse_x<xb+277 && mouse_y>yb-2 && mouse_y<yb+22)
{
if(Midi_Faders_Affectation_Type!=0)
{
char sttmp[24];
sprintf(sttmp,"Minus Grid in GridPl.%d",num_grider+1);
show_type_midi(1476+num_grider,sttmp );
GriderMinus.DrawOutline(CouleurBlind);
}
}

if( mouse_x>xb+283 && mouse_x<xb+307 && mouse_y>yb-2 && mouse_y<yb+22)
{
if( Midi_Faders_Affectation_Type!=0)
{
char sttmp[24];
sprintf(sttmp,"Plus Grid in GridPl.%d",num_grider+1);
show_type_midi(1480+num_grider,sttmp );
GriderPlus.DrawOutline(CouleurBlind);
}
}
}
return(0);
}
