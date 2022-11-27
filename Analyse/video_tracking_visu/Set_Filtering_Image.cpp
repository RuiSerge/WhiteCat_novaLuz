int Set_Filtering_Image()
{

int hauteur_cadre_filter_image=0;
if(ocv_calcul_mode==0)
{hauteur_cadre_filter_image=180;}
else{hauteur_cadre_filter_image=130;}

Rect Background_Thres(Vec2D(videoX+30, videoY+70),Vec2D(265,hauteur_cadre_filter_image));
Background_Thres.SetRoundness(5);
Background_Thres.Draw(CouleurFond.WithAlpha(0.3));

Line(videoX+40, videoY+100,videoX+277,videoY+100,2.0).Draw( CouleurSurvol);
Rect Curseur_Thres(Vec2D(videoX+20+threshold_level, videoY+90),Vec2D(40,25));
Curseur_Thres.SetRoundness(7.5);
Curseur_Thres.Draw(CouleurSurvol);

Line(videoX+40, videoY+160,videoX+277,videoY+160,2.0).Draw( CouleurSurvol);
Rect Curseur_Erode(Vec2D(videoX+20+(erode_level*25), videoY+150),Vec2D(40,25));
Curseur_Erode.SetRoundness(7.5);
Curseur_Erode.Draw(CouleurSurvol);


Rect Curseur_div(Vec2D(videoX+20+(div_facteur), videoY+210),Vec2D(40,25));
Curseur_div.SetRoundness(7.5);
if(ocv_calcul_mode==0)
{
Line(videoX+40, videoY+220,videoX+277,videoY+220,2.0).Draw( CouleurSurvol);
Curseur_div.Draw(CouleurSurvol);
}

sprintf(string_threshold_is,"Threshold: %d / 255 :",threshold_level);
petitchiffre.Print(string_threshold_is, videoX+35,videoY+85);
sprintf(string_erode_is,"Erode: %d / 10 :",erode_level);
petitchiffre.Print(string_erode_is, videoX+35,videoY+140);
if(ocv_calcul_mode==0)
{
sprintf(string_div_is,"Div amount: %d / 255 :",div_facteur);
petitchiffre.Print(string_div_is, videoX+35,videoY+200);
}


Rect OnFlip(Vec2D(videoX+30, videoY+video_size_y+110),Vec2D(60,25));
OnFlip.SetRoundness(7.5);
OnFlip.SetLineWidth(epaisseur_ligne_fader);
OnFlip.Draw(CouleurFond);

Rect OnThreshold(Vec2D(videoX+100, videoY+video_size_y+110),Vec2D(60,25));
OnThreshold.SetRoundness(7.5);
OnThreshold.SetLineWidth(epaisseur_ligne_fader);
OnThreshold.Draw(CouleurFond);

Rect ModeErode(Vec2D(videoX+170, videoY+video_size_y+110),Vec2D(60,25));
ModeErode.SetRoundness(7.5);
ModeErode.SetLineWidth(epaisseur_ligne_fader);
ModeErode.Draw(CouleurFond);

Rect OnOffBlur(Vec2D(videoX+240, videoY+video_size_y+110),Vec2D(60,25));
OnOffBlur.SetRoundness(7.5);
OnOffBlur.SetLineWidth(epaisseur_ligne_fader);
OnOffBlur.Draw(CouleurFond);



if(flip_image==1){OnFlip.Draw(CouleurFader);}
if(threshold_on==1){OnThreshold.Draw(CouleurFader);}
if(erode_mode==1){ModeErode.Draw(CouleurFader);}
if(blur_on==1){OnOffBlur.Draw(CouleurFader);}

petitchiffre.Print("FLIP",videoX+40, videoY+video_size_y+125);
petitchiffre.Print("THRES.",videoX+105, videoY+video_size_y+125);
petitchiffre.Print("EROD",videoX+180, videoY+video_size_y+125);
petitchiffre.Print("BLUR",videoX+250, videoY+video_size_y+125);

OnFlip.DrawOutline(CouleurLigne);
OnThreshold.DrawOutline(CouleurLigne);
ModeErode.DrawOutline(CouleurLigne);
OnOffBlur.DrawOutline(CouleurLigne);

return(0);
}
