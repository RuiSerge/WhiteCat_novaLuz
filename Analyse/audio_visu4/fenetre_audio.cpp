int fenetre_audio(int xb,int yb)
{

Rect audio_backg(Vec2D(xb,yb), Vec2D( 600,150+(index_nbre_players_visibles*120)));
audio_backg.SetRoundness(15);
audio_backg.Draw(CouleurFond);
audio_backg.SetLineWidth(triple_epaisseur_ligne_fader);
if(window_focus_id==919)
{
audio_backg.DrawOutline(CouleurFader);
}
else
{
audio_backg.DrawOutline(CouleurLigne);
}

neuro.Print( "AudioPlayers",(xb+80), (yb+30));

Rect AudioFolderis(Vec2D(xb+350,yb+10),Vec2D(240,30));
AudioFolderis.SetRoundness(7.5);
AudioFolderis.Draw(CouleurSurvol);
neuromoyen.Print(audio_folder,xb+365,yb+25);



Rect BackDeroule(Vec2D(xb+350,yb+45),Vec2D(240,(index_nbre_players_visibles*120)));
BackDeroule.SetRoundness(15);
BackDeroule.Draw(CouleurConfig.WithAlpha(0.7));
bool ind=0;

for (int y=1;y<(index_nbre_players_visibles*6);y++)
{
Rect OverAudioFile(Vec2D(xb+355,(yb+33+(y*20))),Vec2D(200,18));
OverAudioFile.SetRoundness(7.5);

OverAudioFile.Draw(CouleurFond.WithAlpha(0.5*ind));
ind=toggle(ind);
if(strcmp(audiofile_name,list_audio_files[audiofile_selected])==0 && (audiofile_selected==(y+line_audio)) )
{OverAudioFile.Draw(CouleurBlind);}

if(window_focus_id==919 && mouse_x>xb+355 && mouse_x<xb+505 && mouse_y>(yb+33+(y*20)) && mouse_y<(yb+48+(y*20)))
{
OverAudioFile.DrawOutline(CouleurLigne);
}


petitpetitchiffre.Print(ol::ToString(line_audio+y),xb+360,yb+45+(y*20));
Canvas::SetClipping( xb+355,yb+35+(y*20),230,20);
petitpetitchiffre.Print(list_audio_files[line_audio+y],xb+375,yb+45+(y*20));
Canvas::DisableClipping();
}

Circle LineUp(Vec2D(xb+570,yb+65),12);
LineUp.Draw(CouleurFond);
Circle LineDown(Vec2D(xb+570,yb+(index_nbre_players_visibles*120)),12);
LineDown.Draw(CouleurFond);


petitchiffre.Print("-",xb+566,yb+70);
petitchiffre.Print("+",xb+566,yb+(index_nbre_players_visibles*120)+5);
LineUp.DrawOutline(CouleurLigne);
LineDown.DrawOutline(CouleurLigne);

    Rect AudioRescanDriver( Vec2D(xb+230,yb+10), Vec2D ( 50,20));
    AudioRescanDriver.SetRoundness(7.5);
    AudioRescanDriver.DrawOutline(CouleurLigne);

   Rect EditSound( Vec2D(xb+230,yb+40), Vec2D ( 50,20));
    EditSound.SetRoundness(7.5);
    if(index_edit_audio==1){EditSound.Draw(CouleurFader);}
    EditSound.DrawOutline(CouleurLigne);
    petitpetitchiffre.Print("EDIT",xb+240,yb+53);


for(int lop=0;lop<index_nbre_players_visibles;lop++)
{
lecteur_audio(xb+5,yb+70+(lop*140),lop);
}

Rect AffectA(Vec2D(xb+440,yb+55+(index_nbre_players_visibles*120)),Vec2D(140,20));
AffectA.SetRoundness(5);
AffectA.Draw(CouleurFader.WithAlpha(index_affect_audio_to_dock));
AffectA.DrawOutline(CouleurLigne);
petitchiffre.Print("AFFECT TO DOCK",xb+460,yb+70+(index_nbre_players_visibles*120));

petitchiffre.Print("Volume",xb+400,yb+100+(index_nbre_players_visibles*120));
petitchiffre.Print("Pan",xb+400,yb+120+(index_nbre_players_visibles*120));
petitchiffre.Print("Pitch",xb+400,yb+140+(index_nbre_players_visibles*120));

for(int pl=0;pl<index_nbre_players_visibles;pl++)
{
for (int co=0;co<3;co++)
{
 Rect AffectAudioType(Vec2D(xb+460+(pl*30),yb+90+(index_nbre_players_visibles*120)+(co*20)),Vec2D(20,15));
 AffectAudioType.SetRoundness(3);
 if(player_to_affect_to_dock==pl && audio_type_for_dock_affectation_is==co){AffectAudioType.Draw(CouleurFader);}
 AffectAudioType.DrawOutline(CouleurLigne);
}
 petitpetitchiffre.Print(ol::ToString((pl+1)),xb+467+(pl*30),yb+85+(index_nbre_players_visibles*120));
}


if(window_focus_id==919  )
{
if(mouse_x>xb+350 && mouse_x<xb+590 && mouse_y>yb+10 && mouse_y<yb+40)
{
AudioFolderis.DrawOutline(CouleurLigne);
}
else if( mouse_x>xb+230 && mouse_x<xb+280 && mouse_y>yb+10 && mouse_y<yb+30 )
    {
    AudioRescanDriver.Draw(CouleurSurvol);
    }
else if( mouse_x>xb+558 && mouse_x<xb+582  )
{
if(mouse_y>yb+53 && mouse_y<yb+72)
{
LineUp.Draw(CouleurSurvol);
}
if(mouse_y>yb+(index_nbre_players_visibles*120)-7 && mouse_y<yb+(index_nbre_players_visibles*120)+5)
{
LineDown.Draw(CouleurSurvol);
}
}
}


petitpetitchiffre.Print("rescan!",xb+235,yb+23);
return(0);
}
