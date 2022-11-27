int plot_draw_plan_bitmap(int xplot, int yplot, float alphaplan)
{

LightPlanBitmapMain.BlitTransformed(xplot+position_relative_plan_theatre[0], yplot+position_relative_plan_theatre[1],taille_relative_plan_theatre[0],taille_relative_plan_theatre[1],orientation_plan_theatre*6.5,alphaplan);

return(0);
}
