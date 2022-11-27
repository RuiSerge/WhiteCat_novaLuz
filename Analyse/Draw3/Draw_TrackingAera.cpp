int Draw_TrackingAera(int xw,int yw)
{

Rect Aera(Vec2D(xw,yw),Vec2D(draw_tracking_aera_size_x,draw_tracking_aera_size_y));
Aera.SetLineWidth(2.0);
Aera.SetRoundness(4);
Aera.Draw(CouleurBleuProcedure.WithAlpha(0.1));

Rect Level(Vec2D(xw,yw),Vec2D(draw_largeur_case[draw_preset_selected],draw_hauteur_case[draw_preset_selected]));

int ind=0;
for(int col=0;col<draw_preset_parameters[draw_preset_selected][0];col++)
{
Line(Vec2D(xw+(col*draw_largeur_case[draw_preset_selected]),yw),Vec2D(xw+(col*draw_largeur_case[draw_preset_selected]),yw+(draw_preset_parameters[draw_preset_selected][1]*draw_hauteur_case[draw_preset_selected]))).Draw(CouleurFond.WithAlpha(0.5));

for(int lig=0;lig<draw_preset_parameters[draw_preset_selected][1];lig++)
{
Line(Vec2D(xw,yw+(lig*draw_hauteur_case[draw_preset_selected])),Vec2D(xw+(draw_preset_parameters[draw_preset_selected][0]*draw_largeur_case[draw_preset_selected]),yw+(lig*draw_hauteur_case[draw_preset_selected]))).Draw(CouleurFond.WithAlpha(0.5));

ind=col+(lig*draw_preset_parameters[draw_preset_selected][0]);
Level.MoveTo(Vec2D(xw+(col*draw_largeur_case[draw_preset_selected]),yw+(lig*draw_hauteur_case[draw_preset_selected])));
Level.Draw(CouleurLevel.WithAlpha(draw_preset_levels[draw_preset_selected][ind]));

if(draw_preset_parameters[draw_preset_selected][0]<=12)
{
petitchiffre.Print(ol::ToString(draw_preset_channel_routing[draw_preset_selected][ind]),xw+1+(col*draw_largeur_case[draw_preset_selected]),yw+(lig*draw_hauteur_case[draw_preset_selected])+10);
}
else
{
minichiffre.Print(ol::ToString(draw_preset_channel_routing[draw_preset_selected][ind]),xw+1+(col*draw_largeur_case[draw_preset_selected]),yw+(lig*draw_hauteur_case[draw_preset_selected])+10);
}

}
}


Rect Curseur(Vec2D(xw+draw_centre_x[draw_preset_selected]*draw_largeur_case[draw_preset_selected],yw+draw_centre_y[draw_preset_selected]*draw_hauteur_case[draw_preset_selected]),
Vec2D(draw_largeur_case[draw_preset_selected], draw_hauteur_case[draw_preset_selected]  ));
Curseur.SetLineWidth(3.0);
Curseur.DrawOutline(CouleurBlind);

return(0);
}
