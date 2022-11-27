int raccrochage_midi_visuel_circulaire (int Xb, int Yb, int IDmidi, int largeur, int hauteur)
{

Circle BMidiRaccroche(Xb+largeur,Yb+hauteur+15, 6);//raccroche midi
if(is_raccrochage_midi_remote[IDmidi]==1)
{
BMidiRaccroche.Draw(CouleurFader);

float tmp_angle_snap=((PI*360) / (22860))*val_raccrochage_midi[IDmidi];//((PI*360) / (180*127))*val_raccrochage_midi[IDmidi];
float tmp_vx = cos(tmp_angle_snap)*125;
float tmp_vy = sin(tmp_angle_snap)*125;
float tmp_position_curseur_hue_x= xtrichro_window+tmp_vx;
float tmp_position_curseur_hue_y=ytrichro_window+tmp_vy ;


 //affichage du pointeur de hue
Circle monCurseurHue( Vec2D(tmp_position_curseur_hue_x, tmp_position_curseur_hue_y), 10 );
monCurseurHue.Draw( CouleurFond );
Line MonNiveauMidi(Vec2D(Xb+largeur-6,Yb+hauteur+15 ),Vec2D(tmp_position_curseur_hue_x,Yb+hauteur+15 ));
MonNiveauMidi.SetLineWidth(epaisseur_ligne_fader);
MonNiveauMidi.Draw(CouleurFond,CouleurLigne);

Line MaJonction(Vec2D(tmp_position_curseur_hue_x,Yb+hauteur+15),Vec2D(tmp_position_curseur_hue_x,tmp_position_curseur_hue_y));
MaJonction.SetLineWidth(epaisseur_ligne_fader);
MaJonction.Draw(CouleurLigne,CouleurFond);

}
BMidiRaccroche.DrawOutline(CouleurLigne);
return(0);
}
