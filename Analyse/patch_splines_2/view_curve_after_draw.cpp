int view_curve_after_draw()//verif du report de ma courbe
{
for (int d=0; d<255;d++)
{
 Point(xpatch_window+30+455+d,ypatch_window+50+curve_report[curve_selected][d] ).Draw(Rgba::GREEN);
}
   return(0);
}
