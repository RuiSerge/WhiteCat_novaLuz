int plot_draw_levels(int plotx, int ploty, int plot_calc_number_is)
{

for(int i=1;i<=nbre_symbols_on_plot[plot_calc_number_is];i++)
{

if(plot_index_show_levels==1 && symbol_channel_is[plot_calc_number_is][i]!=0 && symbol_channel_is[plot_calc_number_is][i]<513 )
{
char lev[8];
Rect etiquette(Vec2D(plotx+pos_symbol[plot_calc_number_is][i][0]-15,ploty+pos_symbol[plot_calc_number_is][i][1]-35),Vec2D(30,20));
etiquette.SetRoundness(5);
switch(index_blind)
{
case 0:
if(bufferSequenciel[( symbol_channel_is[plot_calc_number_is][i])]>0)
{
switch(dmx_view)
{
case 0://stage et faders
sprintf(lev,"%d",(int) ((float)(bufferSequenciel[( symbol_channel_is[plot_calc_number_is][i])])/2.55));
break;
case 1:
sprintf(lev,"%d",bufferSequenciel[( symbol_channel_is[plot_calc_number_is][i])]);
break;
default: break;
}
etiquette.Draw(CouleurPlotLine.WithAlpha(0.2));
etiquette.Draw(CouleurBleuProcedure.WithAlpha(((float)(bufferSequenciel[( symbol_channel_is[plot_calc_number_is][i])])/255)));
petitchiffre.Print(lev,plotx+pos_symbol[plot_calc_number_is][i][0]-10,ploty+pos_symbol[plot_calc_number_is][i][1]-20);
}
if( plot_index_show_levels_from_faders==1 && bufferFaders[( symbol_channel_is[plot_calc_number_is][i])]>0)
{
etiquette.MoveTo(Vec2D(plotx+pos_symbol[plot_calc_number_is][i][0]-15,ploty+pos_symbol[plot_calc_number_is][i][1]-55));
switch(dmx_view)
{
case 0:
sprintf(lev,"%d",(int) ((float)(bufferFaders[( symbol_channel_is[plot_calc_number_is][i])])/2.55));
break;
case 1:
sprintf(lev,"%d",bufferFaders[( symbol_channel_is[plot_calc_number_is][i])]);
break;
default: break;
}
etiquette.Draw(CouleurPlotLine.WithAlpha(0.2));
etiquette.Draw(CouleurFader.WithAlpha(((float)(bufferFaders[( symbol_channel_is[plot_calc_number_is][i])])/255)));
etiquette.DrawOutline(CouleurPlotLine.WithAlpha(0.8));
petitchiffre.Print(lev,plotx+pos_symbol[plot_calc_number_is][i][0]-10,ploty+pos_symbol[plot_calc_number_is][i][1]-40);
}
break;
case 1://blind
if(bufferBlind[( symbol_channel_is[plot_calc_number_is][i])]>0)
{
switch(dmx_view)
{
case 0:
sprintf(lev,"%d",(int) ((float)(bufferBlind[( symbol_channel_is[plot_calc_number_is][i])])/2.55));
break;
case 1:
sprintf(lev,"%d",bufferBlind[( symbol_channel_is[plot_calc_number_is][i])]);
break;
default: break;
}
etiquette.Draw(CouleurPlotLine.WithAlpha(0.2));
etiquette.Draw(CouleurBlind.WithAlpha(((float)(bufferBlind[( symbol_channel_is[plot_calc_number_is][i])])/255)));
petitchiffre.Print(lev,plotx+pos_symbol[plot_calc_number_is][i][0]-10,ploty+pos_symbol[plot_calc_number_is][i][1]-20);
}
break;
default: break;
}
}

}
return(0);
}
