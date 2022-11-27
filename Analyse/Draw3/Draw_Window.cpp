int Draw_Window(int xw,int yw)
{
Rect DrawBckgd(Vec2D(xw,  yw), Vec2D( draw_window_x_size,draw_window_y_size));
DrawBckgd.SetRoundness(15);
DrawBckgd.SetLineWidth(triple_epaisseur_ligne_fader);
DrawBckgd.Draw(CouleurFond);

if(window_focus_id==W_DRAW)
{
DrawBckgd.DrawOutline(CouleurFader);
}
else {DrawBckgd.DrawOutline(CouleurLigne); }
neuro.Print("DRAW",xw+100,yw+30);

neuro.Print(ol::ToString(draw_preset_channel_routing[draw_preset_selected][(index_case[draw_preset_selected])]),xw+40,yw+110);
petitchiffre.Print(ol::ToString(draw_centre_x[draw_preset_selected]),xw+55,yw+125);
petitchiffre.Print(ol::ToString(draw_centre_y[draw_preset_selected]),xw+75,yw+125);
Rect DrawBrush(Vec2D(xw+180,  yw+12), Vec2D( 50,20));
DrawBrush.SetRoundness(5);
DrawBrush.Draw(CouleurLevel);
DrawBrush.DrawOutline(CouleurLigne);

if(window_focus_id==W_DRAW && Midi_Faders_Affectation_Type!=0 && mouse_x> xw+180 && mouse_x<xw+230 && mouse_y>yw+12 && mouse_y<yw+32)//config midi
{
DrawBrush.DrawOutline(CouleurBlind);
}

Rect Ppoint(Vec2D(xw+202,yw+21),Vec2D(3,3));


switch(draw_brush_type[draw_preset_selected])
{
case 0://single point
  Ppoint.Draw(CouleurFond);
break;
case 1://ligne
  petitchiffrenoir.Print("GridPl.",xw+185, yw+25);
break;
default: break;
}

Rect DrawPst(Vec2D(xw,  yw), Vec2D( 50,20));
DrawPst.SetRoundness(5);
for(int pr=0;pr<6;pr++)
{
DrawPst.MoveTo(Vec2D(xw+240+(pr*58),yw+12));
if(draw_preset_selected==pr){DrawPst.Draw(CouleurFader);}
DrawPst.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print(ol::ToString(pr+1),xw+260+(pr*58),yw+25);
if(window_focus_id==W_DRAW && Midi_Faders_Affectation_Type!=0 && mouse_x> xw+240+(pr*58) && mouse_x<xw+290+(pr*58) && mouse_y>yw+12 && mouse_y<yw+32)//config midi
{
DrawPst.DrawOutline(CouleurBlind);
}

}


Rect DrawingMode(Vec2D(xw+20,yw+60),Vec2D(60,20));
DrawingMode.SetRoundness(5);
DrawingMode.DrawOutline(CouleurLigne.WithAlpha(0.5));

switch(draw_mode[draw_preset_selected])
{
case 0:
  DrawingMode.Draw(CouleurLevel);
  petitchiffrenoir.Print("DRAW",xw+33,yw+74);
break;
case 1:
  DrawingMode.Draw(CouleurBlind);
  petitchiffre.Print("ERASE",xw+30,yw+74);
break;
case 2:
  DrawingMode.Draw(CouleurFader);
  petitchiffrenoir.Print("SOLO",xw+33,yw+74);
break;
case 3:
  DrawingMode.Draw(CouleurLigne);
  petitchiffrenoir.Print("GHOST",xw+33,yw+74);
break;
default:
break;
}

if(window_focus_id==W_DRAW && Midi_Faders_Affectation_Type!=0 && mouse_x>xw+20 && mouse_x<xw+80 && mouse_y>yw+60 && mouse_y<yw+80)//config midi
{
DrawingMode.SetLineWidth(2.0);
DrawingMode.DrawOutline(CouleurBlind);
}



petitchiffre.Print("Pressure",xw+105,yw+53);
Rect FrameLevelPressure(Vec2D(xw+180,yw+45),Vec2D(127,10));
Rect LevelPressure(Vec2D(xw+180,yw+45),Vec2D(127*draw_level_to_do[draw_preset_selected],10));
LevelPressure.Draw(CouleurFader);
FrameLevelPressure.DrawOutline(CouleurLigne.WithAlpha(0.5));
minichiffrerouge.Print(ol::ToString((int)( draw_level_to_do[draw_preset_selected]*127)),xw+312,yw+53);
switch(dmx_view)
{
case 0:
petitchiffre.Print(ol::ToString((int) (draw_level_to_do[draw_preset_selected]*100)),xw+330,yw+54);
break;
case 1:
petitchiffre.Print(ol::ToString((int) (draw_level_to_do[draw_preset_selected]*255)),xw+330,yw+54);
break;
default: break;
}

if(window_focus_id==W_DRAW && Midi_Faders_Affectation_Type!=0 && mouse_x>xw+180 && mouse_x<xw+307 && mouse_y>yw+45 && mouse_y<yw+55)//config midi
{
FrameLevelPressure.DrawOutline(CouleurBlind);
}

Circle BMidiOutPressure(xw+316,yw+62, 5);
if(midi_send_out[1653]==1)
{
BMidiOutPressure.Draw(CouleurBlind);
}
BMidiOutPressure.DrawOutline(CouleurGrisMoyen);


petitchiffre.Print("DampDecay",xw+105,yw+78);
Rect FrameDamperDec(Vec2D(xw+180,yw+70),Vec2D(127,10));
Rect DamperDec(Vec2D(xw+180,yw+70),Vec2D(127*draw_damper_decay_factor[draw_preset_selected],10));
DamperDec.Draw(CouleurFader);
FrameDamperDec.DrawOutline(CouleurLigne.WithAlpha(0.5));
minichiffrerouge.Print(ol::ToString((int)( draw_damper_decay_factor[draw_preset_selected]*127)),xw+312,yw+78);
petitchiffre.Print(ol::ToString( draw_damper_decay_factor[draw_preset_selected]),xw+330,yw+84);

if(window_focus_id==W_DRAW && Midi_Faders_Affectation_Type!=0 && mouse_x>xw+180 && mouse_x<xw+307 && mouse_y>yw+70 && mouse_y<yw+80)//config midi
{
FrameDamperDec.DrawOutline(CouleurBlind);
}

Circle BMidiOutTilt(xw+316,yw+87, 5);
if(midi_send_out[1654]==1)
{
BMidiOutTilt.Draw(CouleurBlind);
}
BMidiOutTilt.DrawOutline(CouleurGrisMoyen);



petitchiffre.Print("Ghost Level",xw+105,yw+103);
Rect FrameGhostSize(Vec2D(xw+180,yw+95),Vec2D(127,10));
Rect GhostSize(Vec2D(xw+180,yw+95),Vec2D(127*draw_ghost_to_do[draw_preset_selected],10));
GhostSize.Draw(CouleurFader);
FrameGhostSize.DrawOutline(CouleurLigne.WithAlpha(0.5));
minichiffrerouge.Print(ol::ToString((int)( draw_ghost_to_do[draw_preset_selected]*127)),xw+312,yw+103);
switch(dmx_view)
{
case 0:
petitchiffre.Print(ol::ToString((int) (draw_ghost_to_do[draw_preset_selected]*100)),xw+330,yw+104);
break;
case 1:
petitchiffre.Print(ol::ToString((int) (draw_ghost_to_do[draw_preset_selected]*255)),xw+330,yw+104);
break;
default: break;
}
if(window_focus_id==W_DRAW && Midi_Faders_Affectation_Type!=0 && mouse_x>xw+180 && mouse_x<xw+307 && mouse_y>yw+95 && mouse_y<yw+105)//config midi
{
FrameGhostSize.DrawOutline(CouleurBlind);
}

Circle BMidiOutSize(xw+316,yw+112, 5);
if(midi_send_out[1655]==1)
{
BMidiOutSize.Draw(CouleurBlind);
}
BMidiOutSize.DrawOutline(CouleurGrisMoyen);

Rect ClearBoard(Vec2D(xw+400,yw+40), Vec2D(110,20));
ClearBoard.SetRoundness(7.5);
petitchiffre.Print("Erase Drawing",xw+417,yw+53);
ClearBoard.DrawOutline(CouleurLigne.WithAlpha(0.5));


if(window_focus_id==W_DRAW &&  Midi_Faders_Affectation_Type!=0 && mouse_x>xw+400 && mouse_x<xw+510 && mouse_y>yw+40 && mouse_y<yw+60)
{
ClearBoard.DrawOutline(CouleurBlind);
}

Rect AffectMode(Vec2D(xw+400,yw+75), Vec2D(110,20));
AffectMode.SetRoundness(7.5);

switch(draw_channel_recording_mode) //4 modes: 0 solo - 1 until end of line - 2 until end of col - 3 until end of matrix
{
case 0:
petitchiffre.Print("Rec Ch. Solo",xw+418,yw+88);
break;
case 1:
AffectMode.Draw(CouleurFader);
petitchiffre.Print("Rec Ch.> End Row",xw+405,yw+88);
break;
case 2:
AffectMode.Draw(CouleurGreen);
petitchiffre.Print("Rec Ch.> End Col",xw+410,yw+88);
break;
case 3:
AffectMode.Draw(CouleurBlind);
petitchiffre.Print("Rec Ch.> End Grid",xw+405,yw+88);
break;
default:
break;
}
AffectMode.DrawOutline(CouleurLigne.WithAlpha(0.5));


Rect Affecttodock(Vec2D(xw+400,yw+100), Vec2D(110,20));
Affecttodock.SetRoundness(7.5);
if(index_affect_draw_to_dock==1){Affecttodock.Draw(CouleurFader);}
Affecttodock.DrawOutline(CouleurLigne.WithAlpha(0.5));

petitchiffre.Print( "Affect To Dock",(xw+410), (yw+113));


Rect GriderEditEnable( Vec2D((xw+530),(yw+40)),Vec2D(50,20));
GriderEditEnable.SetRoundness(5);
if(index_enable_edit_Draw==1)
{
GriderEditEnable.Draw(CouleurFader);
}
GriderEditEnable.DrawOutline(CouleurLigne.WithAlpha(0.5));
petitchiffre.Print("edit",xw+540 ,yw+52);

Rect BackGriderCol(Vec2D(xw+550,yw+75),Vec2D(30,20));
BackGriderCol.SetRoundness(4);
BackGriderCol.Draw(CouleurBleuProcedure.WithAlpha(0.5));
petitchiffre.Print("Col.:",xw+525,yw+90);
petitchiffre.Print(ol::ToString(draw_preset_parameters[draw_preset_selected][0]),xw+560,yw+90);

Rect BackGriderRow(Vec2D(xw+550,yw+100),Vec2D(30,20));
BackGriderRow.SetRoundness(4);
BackGriderRow.Draw(CouleurBleuProcedure.WithAlpha(0.5));
petitchiffre.Print("Row:",xw+525,yw+115);
petitchiffre.Print(ol::ToString(draw_preset_parameters[draw_preset_selected][1]),xw+560,yw+115);


if(window_focus_id==W_DRAW  && mouse_x> xw+550 && mouse_x<xw+580 && mouse_y>yw+75 && mouse_y<yw+95 )
{
BackGriderCol.DrawOutline(CouleurLigne.WithAlpha(0.7));
}
if(window_focus_id==W_DRAW  && mouse_x> xw+550 && mouse_x<xw+580 && mouse_y>yw+100 && mouse_y<yw+120 )
{
BackGriderRow.DrawOutline(CouleurLigne.WithAlpha(0.7));
}


Draw_TrackingAera(xw+20,yw+140);

petitchiffre.Print("Midi X:",xw+20,yw+588);
Rect MidiX(Vec2D(xw+65,yw+580),Vec2D(127,10));
Rect MidiXLev(Vec2D(xw+65,yw+580),Vec2D(midi_levels[1660],10));
MidiXLev.Draw(CouleurFader);
MidiX.DrawOutline(CouleurLigne.WithAlpha(0.5));
if(window_focus_id==W_DRAW  && Midi_Faders_Affectation_Type!=0  && mouse_x>= xw+65 && mouse_x<=xw+192 && mouse_y>yw+580 && mouse_y<yw+590 )
{
MidiX.DrawOutline(CouleurBlind);
}


petitchiffre.Print("Midi Y:",xw+200,yw+588);
Rect MidiY(Vec2D(xw+245,yw+580),Vec2D(127,10));
Rect MidiYLev(Vec2D(xw+245,yw+580),Vec2D(midi_levels[1661],10));
MidiYLev.Draw(CouleurFader);
MidiY.DrawOutline(CouleurLigne.WithAlpha(0.5));
if(window_focus_id==W_DRAW  && Midi_Faders_Affectation_Type!=0  && mouse_x>= xw+245 && mouse_x<=xw+372 && mouse_y>yw+580 && mouse_y<yw+590 )
{
MidiY.DrawOutline(CouleurBlind);
}



petitchiffre.Print("GridPlayer:",xw+385,yw+590);


Rect NumGPL(Vec2D(xw+455,yw+578),Vec2D(30,18));
NumGPL.SetRoundness(4);
NumGPL.DrawOutline(CouleurLigne.WithAlpha(0.4));
petitchiffre.Print(ol::ToString(draw_get_gpl[draw_preset_selected]),xw+465,yw+590);

petitchiffre.Print("Offset:",xw+495,yw+590);

Rect OffsetGPL(Vec2D(xw+550,yw+578),Vec2D(35,18));
OffsetGPL.SetRoundness(4);
OffsetGPL.DrawOutline(CouleurLigne.WithAlpha(0.4));
petitchiffre.Print(ol::ToString(draw_offset_gpl[draw_preset_selected]),xw+560,yw+590);


if(window_focus_id==W_DRAW && mouse_y>yw+578 && mouse_y<yw+596 && index_enable_edit_Draw==1)
{
if(mouse_x>xw+455 && mouse_x<xw+455+30){NumGPL.DrawOutline(CouleurLigne);}
else if(mouse_x>xw+495 && mouse_x<xw+495+35){OffsetGPL.DrawOutline(CouleurLigne);}
}


  return(0);
}
