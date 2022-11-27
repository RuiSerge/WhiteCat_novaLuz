int plot_draw_symbol_serviceligth(int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{

float taille_x=40.0*size_symbol;

Circle lentille(Vec2D(plotx,ploty),taille_x);
lentille.Draw(CouleurPlotFill);
if( symbol_is_selected[plot_calc_number_is][num_symbol]==1)
{
lentille.Draw(CouleurFader);

}
lentille.DrawOutline(CouleurPlotLine);
neuromoyen.Print("S",plotx-5,ploty+5);

return(0);
}
