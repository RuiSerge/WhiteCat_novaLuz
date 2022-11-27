int Grider_Box(int xb, int yb)
{
Rect GriderBack(Vec2D(xb,yb),Vec2D(largeurGrider,hauteurGrider));
GriderBack.SetRoundness(15);
GriderBack.SetLineWidth(triple_epaisseur_ligne_fader);
GriderBack.Draw(CouleurFond);
if(window_focus_id==926)
{
GriderBack.DrawOutline(CouleurFader);
}
else
{
GriderBack.DrawOutline(CouleurLigne);
}


neuro.Print( "Grid",(xb+90), (yb+15));
neuro.Print( "Players",(xb+90), (yb+35));

Rect BackGriderChan(Vec2D(xb+245,yb+15),Vec2D(40,20));
BackGriderChan.SetRoundness(4);
BackGriderChan.Draw(CouleurBleuProcedure.WithAlpha(0.5));
petitchiffre.Print("Beg.Chan.",xb+180,yb+30);
petitchiffre.Print(ol::ToString(grider_begin_channel_is),xb+250,yb+30);

Rect BackGriderCol(Vec2D(xb+315,yb+15),Vec2D(30,20));
BackGriderCol.SetRoundness(4);
BackGriderCol.Draw(CouleurBleuProcedure.WithAlpha(0.5));
petitchiffre.Print("Col.:",xb+290,yb+30);
petitchiffre.Print(ol::ToString(grider_nb_col),xb+320,yb+30);

Rect BackGriderRow(Vec2D(xb+385,yb+15),Vec2D(30,20));
BackGriderRow.SetRoundness(4);
BackGriderRow.Draw(CouleurBleuProcedure.WithAlpha(0.5));
petitchiffre.Print("Rows:",xb+347,yb+30);
petitchiffre.Print(ol::ToString(grider_nb_row),xb+390,yb+30);

Rect GriderEditEnable( Vec2D((xb+430),(yb+15)),Vec2D(50,20));
GriderEditEnable.SetRoundness(7.5);
if(index_enable_edit_Grider==1)
{
GriderEditEnable.Draw(CouleurFader);
}
GriderEditEnable.DrawOutline(CouleurLigne);
petitchiffre.Print("edit",xb+440 ,yb+27);

petitpetitchiffre.Print("GridPlayers",xb+535,yb+13);
for(int o=0;o<core_user_define_nb_gridplayers;o++)
{
Rect ShowGridB(Vec2D(xb+540+(o*15),yb+20),Vec2D(10,10));
if(index_show_grid_player[o]==1)
{ShowGridB.Draw(CouleurFader);}
ShowGridB.DrawOutline(CouleurLigne.WithAlpha(0.7));
if(window_focus_id==W_GRID  && mouse_x>xb+540+(o*15) && mouse_x<xb+540+(o*15)+10 && mouse_y>yb+20 && mouse_y<yb+30)
{
if(Midi_Faders_Affectation_Type!=0)
{
char sttmp[24];
sprintf(sttmp,"View GridPlayer %d",o+1);
show_type_midi(1472+o,sttmp );
ShowGridB.SetLineWidth(2.0);
ShowGridB.DrawOutline(CouleurBlind);
}
}
}

if( window_focus_id==W_GRID  && mouse_y>yb+15 && mouse_y<yb+35)
{
if(mouse_x>xb+245 && mouse_x<xb+285 &&  index_enable_edit_Grider==1)//chan edit
{
BackGriderChan.DrawOutline(CouleurLigne);
}
if(mouse_x>xb+315 && mouse_x<xb+355 &&  index_enable_edit_Grider==1)//col edit
{
BackGriderCol.DrawOutline(CouleurLigne);
}
if(mouse_x>xb+385 && mouse_x<xb+425 &&  index_enable_edit_Grider==1)//rows edit
{
BackGriderRow.DrawOutline(CouleurLigne);
}
}




petitpetitchiffre.Print("View",xb+495,yb+13);
Rect AllowGridViewerB(Vec2D(xb+495,yb+20),Vec2D(40,10));
AllowGridViewerB.Draw(CouleurFader.WithAlpha(show_global_view_grider));
AllowGridViewerB.DrawOutline(CouleurLigne);

if( window_focus_id==W_GRID && mouse_b&1 && mouse_released==0)
{
if(mouse_x>xb+495 && mouse_x<xb+535 && mouse_y>yb+20 && mouse_y<yb+30)
{
show_global_view_grider=toggle(show_global_view_grider);
refresh_hauteur_fenetre_grider();
mouse_released=1;
}
}


if(show_global_view_grider==1)
 {GlobalGridViewer(xb,yb+40); }

 //AFFICHAGE DES GRID PLAYERS
int numerodeplayer_affiche=0;
for(int yo=0;yo<core_user_define_nb_gridplayers;yo++)
{
if(index_show_grid_player[yo]==1)
{
Grid_player(xb, yb+50+hauteurGlobalGridviewer+(numerodeplayer_affiche*(60+(grider_facteur_hauteur*size_grille))), yo);
numerodeplayer_affiche++;
}
}

return(0);
}
