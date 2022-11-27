int plot_draw_plan_grid_for_view_point(int plotx, int ploty, int viewpx, int viewpy)
{
    if(plot_quadrillage_size!=0)
    {

        plot_nbre_col=(plot_window_x_size-position_plan_x)/plot_quadrillage_size;
        plot_nbre_lin=(plot_window_y_size-position_plan_y)/plot_quadrillage_size;

        float reliquatx=(viewpx-plotx)%plot_quadrillage_size;
        float reliquaty=(viewpy-ploty)%plot_quadrillage_size;
        for(int i=0; i<=plot_nbre_col; i++)
        {
            switch(plot_grid_type)
            {
            case 0:
                plot_draw_shape_stripline(plotx+(i*plot_quadrillage_size)+reliquatx,ploty,plotx+(i*plot_quadrillage_size)+reliquatx,ploty+(plot_window_y_size-position_plan_y), 1.0, alpha_grille,0,0, 0, 0);
                break;
            case 1:
                Line
                (Vec2D(plotx+(i*plot_quadrillage_size)+reliquatx,ploty),Vec2D(plotx+(i*plot_quadrillage_size)+reliquatx,ploty+(plot_window_y_size-position_plan_y))).Draw(CouleurPlotLine.WithAlpha(alpha_grille));
                break;
            default:
                break;
            }
        }
        for(int i=0; i<=plot_nbre_lin; i++)
        {
            switch(plot_grid_type)
            {
            case 0:
                plot_draw_shape_stripline(plotx,ploty+(i*plot_quadrillage_size)+reliquaty,plotx+(plot_window_x_size-position_plan_x),ploty+(i*plot_quadrillage_size)+reliquaty, 1.0,  alpha_grille,0, 0,0, 0);
                break;
            case 1:
                Line(Vec2D(plotx,ploty+(i*plot_quadrillage_size)+reliquaty),Vec2D(plotx+(plot_window_x_size-position_plan_x),ploty+(i*plot_quadrillage_size)+reliquaty)).Draw(CouleurPlotLine.WithAlpha(alpha_grille));
                break;
            default:
                break;
            }
        }
    }


    return(0);
}
