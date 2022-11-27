int PatchBox(int XChan, int YChan, float scroll_chan)
{
Rect PatchSpace( Vec2D((XChan),(YChan)),Vec2D(450,600));
PatchSpace.SetRoundness(15);
PatchSpace.SetLineWidth(triple_epaisseur_ligne_fader);
PatchSpace.Draw(CouleurFond);
if(window_focus_id==W_PATCH)
{
PatchSpace.DrawOutline(CouleurFader);
}
else
{
PatchSpace.DrawOutline(CouleurLigne);
}


 Rect ScrollMyPatch(Vec2D(XChan+340,YChan+50+scroller_patch),Vec2D(90,20));
 ScrollMyPatch.SetRoundness(7.5);
 ScrollMyPatch.SetLineWidth(epaisseur_ligne_fader);
 ScrollMyPatch.DrawOutline(CouleurLigne);

Line( Vec2D( XChan+420, YChan+50 ), Vec2D( XChan+420,YChan+260)).Draw( CouleurLigne );

neuro.Print("DIMMERS",XChan+330,YChan+30);

Line( Vec2D( XChan+410, YChan+51+12 ), Vec2D( XChan+420,YChan+51+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+73+12 ), Vec2D( XChan+420,YChan+73+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+92+12 ), Vec2D( XChan+420,YChan+92+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+111+12 ), Vec2D( XChan+420,YChan+111+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+128+12 ), Vec2D( XChan+420,YChan+128+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+149+12 ), Vec2D( XChan+420,YChan+149+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+169+12 ), Vec2D( XChan+420,YChan+169+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+190+12 ), Vec2D( XChan+420,YChan+190+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+209+12 ), Vec2D( XChan+420,YChan+209+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+228+12 ), Vec2D( XChan+420,YChan+228+12)).Draw( CouleurLigne );
Line( Vec2D( XChan+410, YChan+247+12 ), Vec2D( XChan+420,YChan+247+12)).Draw( CouleurLigne );


petitpetitchiffre.Print("1-54",XChan+350,YChan+51+12);
petitpetitchiffre.Print("55-102",XChan+350,YChan+73+12);
petitpetitchiffre.Print("103-150",XChan+350,YChan+92+12);
petitpetitchiffre.Print("151-192",XChan+350,YChan+111+12);
petitpetitchiffre.Print("193-246",XChan+350,YChan+128+12);
petitpetitchiffre.Print("247-294",XChan+350,YChan+149+12);
petitpetitchiffre.Print("295-348",XChan+350,YChan+169+12);
petitpetitchiffre.Print("349-396",XChan+350,YChan+190+12);
petitpetitchiffre.Print("397-444",XChan+350,YChan+209+12);
petitpetitchiffre.Print("445-492",XChan+350,YChan+228+12);
petitpetitchiffre.Print("493-512",XChan+350,YChan+247+12);


 Rect SelectPatchAction(Vec2D(XChan+345,  YChan+320),Vec2D(90,20));
 SelectPatchAction.SetRoundness(7.5);
 SelectPatchAction.SetLineWidth(epaisseur_ligne_fader);
 if(index_affect_patch==1){SelectPatchAction.Draw(CouleurFader); }

 Rect SelectPatchActionCurv(Vec2D(XChan+345, YChan+440),Vec2D(90,20));
 SelectPatchActionCurv.SetRoundness(7.5);
 SelectPatchActionCurv.SetLineWidth(epaisseur_ligne_fader);
 if(index_menu_curve==1)  {SelectPatchActionCurv.Draw(CouleurFader);}

 Rect SelectPatchOverride(Vec2D(XChan+345, YChan+470),Vec2D(110,20));
 SelectPatchOverride.SetRoundness(7.5);
 SelectPatchOverride.SetLineWidth(epaisseur_ligne_fader);
 if(index_patch_overide==1)  {SelectPatchOverride.Draw(CouleurBlind.WithAlpha(alpha_blinker));}

SelectPatchOverride.MoveTo(Vec2D(XChan+345, YChan+500));
if(index_build_patch_from_plot==1){SelectPatchOverride.Draw(CouleurBlind);}

SelectPatchOverride.MoveTo(Vec2D(XChan+345, YChan+530));
if(index_show_first_dim==1){SelectPatchOverride.Draw(CouleurNiveau);}

petitchiffre.Print("Unselect",XChan+350,YChan+302);
petitchiffre.Print("Affect",XChan+350,YChan+332);
petitchiffre.Print("All",XChan+350,YChan+362);
petitchiffre.Print("Clear",XChan+350,YChan+392);
petitchiffre.Print("Default",XChan+350,YChan+422);
petitchiffre.Print("Curve",XChan+350,YChan+452);
petitchiffre.Print("Check Dimmers",XChan+350,YChan+482);
petitchiffre.Print("Link LightPlot",XChan+350,YChan+512);
petitchiffre.Print("Show 1st Dimmer",XChan+350,YChan+542);



Canvas::SetClipping(XChan+30,YChan+50,XChan+30+280,YChan+495);

Rect lignefond( Vec2D(XChan,YChan),Vec2D(280,25) );
lignefond.SetRoundness(5);
Rect DimIsSelected( Vec2D(XChan,YChan),Vec2D(40,55) );
DimIsSelected.SetRoundness(10);
DimIsSelected.SetLineWidth(epaisseur_ligne_fader);



int maxchan_per_ligne=7;
int grad=0;
for (int l=0;l<86;l++)
{
if(l==85){maxchan_per_ligne=3;} //derniere ligne à 512

lignefond.MoveTo( Vec2D(XChan+30,YChan+85+(l*60) - (int)(scroller_patch* scroll_chan)) );
lignefond.SetRoundness(5);
if(((YChan+100+(l*60) - (int)(scroller_patch* scroll_chan))>YChan+30)&&((YChan+90+(l*60) - (int)(scroller_patch* scroll_chan))<YChan+570))
{
lignefond.Draw(CouleurSurvol);
}

for (int c=1; c<maxchan_per_ligne;c++)
{

if(((YChan+100+(l*60) - (int)(scroller_patch* scroll_chan))>YChan+30)&&((YChan+90+(l*60) - (int)(scroller_patch* scroll_chan))<YChan+570))
{
grad=c+(l*6);
if(Dimmers_selected[grad]==1)
{
DimIsSelected.MoveTo( Vec2D(XChan-5+(45*c),YChan+85+(l*60) - (int)(scroller_patch* scroll_chan)));
DimIsSelected.Draw(CouleurFader);
DimIsSelected.DrawOutline(CouleurLigne);
}

petitchiffre.Print(ol::ToString(grad) ,(XChan + (45*c)),(YChan+100+(l*60) - (int)(scroller_patch* scroll_chan)),CENTER);
petitchiffre.Print(ol::ToString(Patch[(grad)]),(XChan + (45*c)),(YChan+120+(l*60) - (int)(scroller_patch* scroll_chan)),CENTER);
petitpetitchiffre.Print(ol::ToString(curves[grad]+1),(XChan + (45*c))+5,(YChan+135+(l*60) - (int)(scroller_patch* scroll_chan)),CENTER);
}
}
}
Canvas::DisableClipping();


if(index_menu_curve==1 )
{menu_curve(XChan+455,YChan);}

Rect PatchSpacebandeau( Vec2D((XChan),(YChan)),Vec2D(320,55));
PatchSpacebandeau.SetRoundness(15);
PatchSpacebandeau.Draw(CouleurFond);


return(0);
}
