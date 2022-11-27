void plot_draw_text(int plotx,int ploty, int fontsize,int fonttype,  const std::string label,float alphatext, bool isselected)
{
const std::string text = label.substr(0,25);

int xsi=0;
int ysi=0;
switch(fonttype)
{
case 0:
xsi=minichiffrenoir.FirstLineWidth( text );
ysi=minichiffrenoir.FirstLineHeight( text );
minichiffrenoir.Print(text,plotx,ploty);
break;
case 1:
xsi=minichiffre.FirstLineWidth( text );
ysi=minichiffre.FirstLineHeight( text );
minichiffre.Print(text,plotx,ploty);
break;
case 2:
xsi=minichiffrerouge.FirstLineWidth( text );
ysi=minichiffrerouge.FirstLineHeight( text );
minichiffrerouge.Print(text,plotx,ploty);
break;
case 3:
xsi=petitchiffrenoir.FirstLineWidth( text );
ysi=petitchiffrenoir.FirstLineHeight( text );
petitchiffrenoir.Print(text,plotx,ploty);
break;
case 4:
xsi=petitchiffre.FirstLineWidth( text );
ysi=petitchiffre.FirstLineHeight( text );
petitchiffre.Print(text,plotx,ploty);
break;
case 5:
xsi=petitchiffrerouge.FirstLineWidth( text );
ysi=petitchiffrerouge.FirstLineHeight( text );
petitchiffrerouge.Print(text,plotx,ploty);
break;
case 6:
xsi=petitdoomInspekt.FirstLineWidth( text );
ysi=petitdoomInspekt.FirstLineHeight( text );
petitdoomInspekt.Print(text,plotx,ploty);
break;
case 7:
xsi=neuromoyen.FirstLineWidth( text );
ysi=neuromoyen.FirstLineHeight( text );
neuromoyen.Print(text,plotx,ploty);
break;
case 8:
xsi=neuro.FirstLineWidth( text );
ysi=neuro.FirstLineHeight( text );
neuro.Print(text,plotx,ploty);
break;
case 9:
xsi=petitdoomblanc.FirstLineWidth( text );
ysi=petitdoomblanc.FirstLineHeight( text );
petitdoomblanc.Print(text,plotx,ploty);
break;
case 10:
xsi=doomblanc.FirstLineWidth( text );
ysi=doomblanc.FirstLineHeight( text );
doomblanc.Print(text,plotx,ploty);
break;
case 11:
xsi=doom.FirstLineWidth( text );
ysi=doom.FirstLineHeight( text );
doom.Print(text,plotx,ploty);
break;
case 12:
xsi=doomrouge.FirstLineWidth( text );
ysi=doomrouge.FirstLineHeight( text );
doomrouge.Print(text,plotx,ploty);
break;
case 13:
xsi=neuroTitle.FirstLineWidth( text );
ysi=neuroTitle.FirstLineHeight( text );
neuroTitle.Print(text,plotx,ploty);
break;
default:
break;
}

if(isselected==1)
{
Rect BoxB(Vec2D(plotx,ploty-ysi),Vec2D(xsi,ysi));
BoxB.DrawOutline(CouleurBlind);
}
if( index_edit_light_plot==1 && index_menus_lighting_plot==1)//visualition du centre projo
{
Line(Vec2D(plotx-5,ploty-5),Vec2D(plotx+5,ploty+5)).Draw(CouleurBlind);
Line(Vec2D(plotx+5,ploty-5),Vec2D(plotx-5,ploty+5)).Draw(CouleurBlind);
}


}
