int SplineCurve()
{

    curve_node_count=6;
    curve_curviness = ftofix(curve_spline_level);
    curve_calc_tangents();
    curve_draw_splines();//l attribution des pas est fait dans drawsplines
    view_curve_after_draw();
    return(0);
}
