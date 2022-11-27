int liste_projecteurs(int xlist,int ylist)
{
Rect Box_list(Vec2D(xlist, ylist), Vec2D( 350,600));
Box_list.SetRoundness(15);
Box_list.SetLineWidth(triple_epaisseur_ligne_fader);
Box_list.Draw(CouleurFond);
if(window_focus_id==914)
{
Box_list.DrawOutline(CouleurFader);
}
else
{
Box_list.DrawOutline(CouleurLigne);
}

neuro.Print( "Spotlights list",(xlist+120), (ylist+30));

Rect EditList(Vec2D(xlist+290,ylist+16),Vec2D(50,20));
EditList.SetRoundness(7.5);
EditList.SetLineWidth(epaisseur_ligne_fader);

if(index_edit_listproj==1){EditList.Draw(CouleurFader);}

Rect MinusPosList(Vec2D(xlist+290,ylist+51),Vec2D(50,20));
MinusPosList.SetRoundness(7.5);
MinusPosList.SetLineWidth(epaisseur_ligne_fader);
Rect PlusPosList(Vec2D(xlist+290,ylist+81),Vec2D(50,20));
PlusPosList.SetRoundness(7.5);
PlusPosList.SetLineWidth(epaisseur_ligne_fader);

for(int co=1;co<List_view_nbre_channels;co++)
{
if(co+line_list_is<513)
{
Rect NameList(Vec2D((xlist+60)-5,(ylist+35+(25*co))),Vec2D(185,23));
NameList.SetRoundness(7.5);
float leveldraw=0.0;
if(bufferSequenciel[co+line_list_is]>bufferFaders[co+line_list_is])
{
leveldraw=((float)(bufferSequenciel[co+line_list_is]))/255;
NameList.Draw(CouleurNiveau.WithAlpha(leveldraw));
}
else if(bufferSequenciel[co+line_list_is]<=bufferFaders[co+line_list_is])
{
leveldraw=((float)(bufferFaders[co+line_list_is]))/255;
NameList.Draw(CouleurFader.WithAlpha(leveldraw));
}
if(Selected_Channel[co+line_list_is]==1)
{
NameList.DrawOutline(CouleurLigne);
}
sprintf(listnum,"Ch. %d :",co+line_list_is);
petitchiffre.Print( listnum,(xlist+10), (ylist+50+(25*co)));

if(dmx_view==1)
{
int leveltoshowis;
if(bufferSequenciel[co+line_list_is]>=bufferFaders[co+line_list_is])
{
  leveltoshowis= bufferSequenciel[co+line_list_is];
}
if(bufferFaders[co+line_list_is]>bufferSequenciel[co+line_list_is])
{
  leveltoshowis= bufferFaders[co+line_list_is];
}
if(leveltoshowis>0)
{
petitpetitchiffre.Print( ol::ToString(leveltoshowis), (xlist+245),(ylist+50+(25*co)));
}
}
else if(dmx_view==0)
{
int leveltoshowis;
if(bufferSequenciel[co+line_list_is]>=bufferFaders[co+line_list_is])
{
    leveltoshowis=(int)(((float)(bufferSequenciel[co+line_list_is])/2.55));
}
if(bufferFaders[co+line_list_is]>bufferSequenciel[co+line_list_is])
{
    leveltoshowis=(int)(((float)(bufferFaders[co+line_list_is])/2.55));
}
if(leveltoshowis>0)
{
petitpetitchiffre.Print( ol::ToString(leveltoshowis), (xlist+245),(ylist+50+(25*co)));
}
}
petitchiffre.Print( descriptif_projecteurs[co+line_list_is],(xlist+60), (ylist+50+(25*co)));
}
}


Rect Curseur_ScrollList(Vec2D(xlist+270,ylist+139+(line_list_is/2)),Vec2D(70,20));
Curseur_ScrollList.SetRoundness(5);
Curseur_ScrollList.DrawOutline(CouleurFader);

EditList.DrawOutline(CouleurLigne);
MinusPosList.DrawOutline(CouleurLigne);
PlusPosList.DrawOutline(CouleurLigne);
petitchiffre.Print("edit",xlist+300, ylist+30);
petitchiffre.Print("line -",xlist+300, ylist+65);
petitchiffre.Print("line +",xlist+300, ylist+95);



Line(Vec2D(xlist+280,ylist+145),Vec2D(xlist+280,ylist+394)).Draw(CouleurLigne);

Line(Vec2D(xlist+280,ylist+145),Vec2D(xlist+285,ylist+145)).Draw(CouleurLigne);
petitpetitchiffre.Print( "  1 -48" ,xlist+285,ylist+147);
Line(Vec2D(xlist+280,ylist+174),Vec2D(xlist+285,ylist+174)).Draw(CouleurLigne);
petitpetitchiffre.Print( " 49 -96",xlist+285,ylist+176);
Line(Vec2D(xlist+280,ylist+198),Vec2D(xlist+285,ylist+198)).Draw(CouleurLigne);
petitpetitchiffre.Print( " 97-144" ,xlist+285,ylist+200);
Line(Vec2D(xlist+280,ylist+222),Vec2D(xlist+285,ylist+222)).Draw(CouleurLigne);
petitpetitchiffre.Print( "145-192" ,xlist+285,ylist+224);
Line(Vec2D(xlist+280,ylist+246),Vec2D(xlist+285,ylist+246)).Draw(CouleurLigne);
petitpetitchiffre.Print( "193-240" ,xlist+285,ylist+248);
Line(Vec2D(xlist+280,ylist+270),Vec2D(xlist+285,ylist+270)).Draw(CouleurLigne);
petitpetitchiffre.Print( "241-288" ,xlist+285,ylist+272);
Line(Vec2D(xlist+280,ylist+293),Vec2D(xlist+285,ylist+293)).Draw(CouleurLigne);
petitpetitchiffre.Print( "289-336" ,xlist+285,ylist+295);
Line(Vec2D(xlist+280,ylist+316),Vec2D(xlist+285,ylist+316)).Draw(CouleurLigne);
petitpetitchiffre.Print( "337-384" ,xlist+285,ylist+319);
Line(Vec2D(xlist+280,ylist+339),Vec2D(xlist+285,ylist+339)).Draw(CouleurLigne);
petitpetitchiffre.Print( "385-432" ,xlist+285,ylist+341);
Line(Vec2D(xlist+280,ylist+370),Vec2D(xlist+285,ylist+370)).Draw(CouleurLigne);
petitpetitchiffre.Print( "433-480" ,xlist+285,ylist+372);
Line(Vec2D(xlist+280,ylist+394),Vec2D(xlist+285,ylist+394)).Draw(CouleurLigne);
petitpetitchiffre.Print( "  ->512" ,xlist+285,ylist+396);


Channel_macros_visu(xlist+10,ylist+470);

 return(0);
}
