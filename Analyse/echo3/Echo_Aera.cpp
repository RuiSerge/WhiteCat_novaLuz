int Echo_Aera(int xe, int ye)
{
Rect Aera(Vec2D(xe,ye),Vec2D(500,127));
Aera.SetRoundness(4);
Aera.Draw(Discrete8);

Rect PreviousChan(Vec2D(xe,ye),Vec2D(25,127));
PreviousChan.SetRoundness(4);
Line(Vec2D(xe+5,ye+64),Vec2D(xe+15,ye+54)).Draw(CouleurLigne);
Line(Vec2D(xe+15,ye+54),Vec2D(xe+15,ye+74)).Draw(CouleurLigne);
Line(Vec2D(xe+15,ye+74),Vec2D(xe+5,ye+64)).Draw(CouleurLigne);


Rect NextChan(Vec2D(xe+475,ye),Vec2D(25,127));
NextChan.SetRoundness(4);
Line(Vec2D(xe+490,ye+64),Vec2D(xe+480,ye+54)).Draw(CouleurLigne);
Line(Vec2D(xe+480,ye+54),Vec2D(xe+480,ye+74)).Draw(CouleurLigne);
Line(Vec2D(xe+480,ye+74),Vec2D(xe+490,ye+64)).Draw(CouleurLigne);


Rect ChanEcho(Vec2D(xe+475,ye),Vec2D(30,6));





int echochanis=0;

for (int sh=0;sh<15;sh++)
{
Line(Vec2D(xe+25+(sh*30),ye),Vec2D(xe+25+(sh*30),ye+127)).Draw(CouleurLigne.WithAlpha(0.7));

echochanis=echo_grid_channel_position[echo_selected]+sh;


Rect MassE(Vec2D(xe+25+(sh*30),ye+(127*(1.0-echo_levels[echo_selected][1][echochanis]))),Vec2D(30,echo_levels[echo_selected][1][echochanis]*127));
MassE.Draw(Discrete2);

ChanEcho.MoveTo(Vec2D(xe+25+(sh*30),ye+127-(snap_echo_to_recall[echo_selected][echochanis]*127)));
ChanEcho.Draw(CouleurFond.WithAlpha(0.3));

ChanEcho.MoveTo(Vec2D(xe+25+(sh*30),ye+127-(echo_levels[echo_selected][0][echochanis]*127)));
ChanEcho.Draw(CouleurLigne);

petitchiffrenoir.Print(ol::ToString(echochanis+1),xe+30+(sh*30),ye+10);

if(window_focus_id==W_ECHO && mouse_x>xe+25+(sh*30) && mouse_x<xe+55+(sh*30) && mouse_y>=ye-5 && mouse_y<=ye+135)
{
echo_over_channel=echo_grid_channel_position[echo_selected]+sh;
}

}
Line(Vec2D(xe+25+450,ye),Vec2D(xe+475,ye+127)).Draw(CouleurLigne.WithAlpha(0.7));




char tcmp[24];
if(window_focus_id==W_ECHO && dragging_channel_in_echo==0)
{
if( mouse_x>xe && mouse_x<xe+25 && mouse_y>ye && mouse_y<ye+127)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
sprintf(tcmp,"Echo Previous Chan");
show_type_midi(1691, tcmp);
PreviousChan.DrawOutline(CouleurBlind);
}
else
{PreviousChan.DrawOutline(CouleurLigne.WithAlpha(0.5));}
}
else if( mouse_x>xe+475 && mouse_x<xe+500 && mouse_y>ye && mouse_y<ye+127)
{
if( Midi_Faders_Affectation_Type!=0)//config midi
{
sprintf(tcmp,"Echo next Chan");
show_type_midi(1692, tcmp);
NextChan.DrawOutline(CouleurBlind);
}
else {NextChan.DrawOutline(CouleurLigne.WithAlpha(0.5));  }
}
}

return(0);
}
