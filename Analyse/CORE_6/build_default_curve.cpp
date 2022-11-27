int build_default_curve(int curve)
{
    mouse_released=1;

    for (int pt=1; pt<MAX_curve_nodeS-1; pt++)
    {
        curve_ctrl_pt[curve][pt][0]=(int)((((float)255)/6) *pt);
        curve_ctrl_pt[curve][pt][1]=255-(int)((((float)255)/6) *pt);
    }
    curve_ctrl_pt[curve][1][0]=0;
    curve_ctrl_pt[curve][1][1]=255;//point 1 en 0 0
    curve_ctrl_pt[curve][5][0]=255;
    curve_ctrl_pt[curve][5][1]=0;//point 5 en 255 255

    curve_ctrl_pt[curve][6][0]=255;
    curve_ctrl_pt[curve][6][1]=0;//point 5 en 255 255

    the_curve_spline_level[curve]=168;
    index_curve_spline_level=168;
    curve_spline_level=(((float)index_curve_spline_level)/127)-1;
    curve_node_count=6;
    curve_curviness = ftofix(curve_spline_level);


    curve_spline_level=(((float)index_curve_spline_level)/127)-1;

    for (int i=0;i<255;i++)
    {
    curve_report[curve][i]=255-i;
    }

    view_curve_after_draw();
    return(0);
}
