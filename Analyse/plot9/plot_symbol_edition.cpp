int plot_symbol_edition(int plotx,int ploty)
{
Rect PlotSymbEd(Vec2D(plotx,ploty),Vec2D(200,520));
PlotSymbEd.SetRoundness(15);
PlotSymbEd.DrawOutline(CouleurPlotLine.WithAlpha(0.4));
petitchiffrenoir.Print("SELECTED SYMBOLS:",plotx+10,ploty+15);
Line(Vec2D(plotx+10,ploty+20),Vec2D(plotx+130,ploty+20)).Draw(CouleurPlotLine);

petitchiffrenoir.Print("Rotate",plotx+10,ploty+33);
petitchiffrenoir.Print(ol::ToString(angle_projo_selectionne),plotx+80,ploty+33);
Rect RotateFrame(Vec2D(plotx+10,ploty+40),Vec2D(100,10));
Rect RotateLevel(Vec2D(plotx+10,ploty+40),Vec2D((angle_projo_selectionne*100),10));
RotateLevel.Draw(CouleurGreen);
RotateFrame.DrawOutline(CouleurPlotLine);

if(window_focus_id==W_PLOT && mouse_x>plotx+10 && mouse_x<plotx+110 && mouse_y>ploty+40 && mouse_y<ploty+50
&& Midi_Faders_Affectation_Type!=0)
{
RotateFrame.DrawOutline(CouleurBlind);
show_type_midi(1601,"Plot Rotate");
}



Rect OverRot(Vec2D(plotx+76,ploty+22),Vec2D(60,15));
OverRot.SetRoundness(4);
OverRot.DrawOutline(CouleurPlotLine.WithAlpha(0.5));

Rect AnglePos(Vec2D(-10,-10),Vec2D(10,10));

for(int l=0;l<3;l++)
{
for(int c=0;c<3;c++)
{
AnglePos.MoveTo(Vec2D(plotx+140+(c*15),ploty+10+(l*15)));
AnglePos.DrawOutline(CouleurPlotLine.WithAlpha(0.5));
if( window_focus_id==W_PLOT && mouse_x>plotx+140+(c*15) && mouse_x<plotx+150+(c*15) && mouse_y>ploty+10+(l*15) && mouse_y<ploty+20+(l*15) )
{
AnglePos.Draw(CouleurFader);
}
}
}
AnglePos.MoveTo(Vec2D(plotx+155,ploty+25));
AnglePos.Draw(CouleurPlotFill);
AnglePos.DrawOutline(CouleurPlotFill);


Rect MySymbAction(Vec2D(plotx, ploty+60),Vec2D(60,18));
MySymbAction.SetRoundness(5);

for(int c=0;c<3;c++)
{
for(int l=0;l<2;l++)
{
MySymbAction.MoveTo(Vec2D(plotx+5+(c*65),ploty+60+(l*20)));
MySymbAction.Draw(CouleurPlotLine.WithAlpha(0.5));

if(window_focus_id==W_PLOT && index_edit_light_plot==1 && index_click_inside_relativ_xy==0
&& mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60+(l*20) && mouse_y<ploty+78)
{
MySymbAction.DrawOutline(CouleurLigne.WithAlpha(0.5));
}


switch(c+(l*3))
{
case 0:
if(window_focus_id==W_PLOT && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60 && mouse_y<ploty+78
&&  Midi_Faders_Affectation_Type!=0)
{
MySymbAction.DrawOutline(CouleurBlind);
show_type_midi(1602,"Plot Dub");
}
petitchiffre.Print("Dub",plotx+20+(c*65),ploty+72+(l*20));
break;
case 1:
if(window_focus_id==W_PLOT && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60 && mouse_y<ploty+78
&&  Midi_Faders_Affectation_Type!=0)
{
MySymbAction.DrawOutline(CouleurBlind);
show_type_midi(1603,"Plot Delete");
}
petitchiffre.Print("Delete",plotx+10+(c*65),ploty+72+(l*20));
break;
case 2:
if(window_focus_id==W_PLOT && mouse_x>plotx+5+(c*65) && mouse_x<plotx+65+(c*65) && mouse_y>ploty+60 && mouse_y<ploty+78
&& Midi_Faders_Affectation_Type!=0)
{
MySymbAction.DrawOutline(CouleurBlind);
show_type_midi(1604,"Plot SendTo");
}
MySymbAction.Draw(CouleurFader.WithAlpha(index_plot_send_to_mode));
petitchiffre.Print("SendTo",plotx+10+(c*65),ploty+72+(l*20));
break;
case 3:
petitchiffre.Print("Down",plotx+15+(c*65),ploty+72+(l*20));
break;
case 4:
petitchiffre.Print("Top",plotx+22+(c*65),ploty+72+(l*20));
break;
case 5:
petitchiffre.Print("Grp/unGrp",plotx+7+(c*65),ploty+72+(l*20));
break;
default:
break;
}
}
}

Rect MySymbAlign(Vec2D(plotx+5,ploty+80),Vec2D(40,18));
 MySymbAlign.SetRoundness(5);
for(int c=0;c<4;c++)
{
 MySymbAlign.MoveTo(Vec2D(plotx+10+(c*45),ploty+110));
 MySymbAlign.Draw(CouleurBleuProcedure.WithAlpha(0.5));
 switch(c)
{
case 0:
petitchiffre.Print("AlignX",plotx+10+(c*45),ploty+122);
break;
case 1:
petitchiffre.Print("AlignY",plotx+10+(c*45),ploty+122);
break;
case 2:
petitchiffre.Print("<-X->",plotx+15+(c*45),ploty+122);
break;
case 3:
petitchiffre.Print("<-Y->",plotx+15+(c*45),ploty+122);
break;
default:
break;
}
}
return(0);
}
