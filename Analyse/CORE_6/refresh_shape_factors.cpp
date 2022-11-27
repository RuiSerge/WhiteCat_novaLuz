int  refresh_shape_factors(int shapetype)
{

    switch(shapetype)
    {
    case 0:    //curtain
        general_shape_size_to_apply=50.0;
        break;
    case 1:     //ligne  plain
        general_shape_size_to_apply=12.0;
        break;
    case 2:     //stripline 1
        general_shape_size_to_apply=20.0;
        break;
    case 3:     //stripline 2
        general_shape_size_to_apply=20.0;
        break;
    case 4:     //stripline 3
        general_shape_size_to_apply=20.0;
        break;
    case 5:     //stripline 4
        general_shape_size_to_apply=20.0;
        break;
    case 6:     //stripline 5
        general_shape_size_to_apply=20.0;
        break;
    case 7://plot_draw_rectangle(int plotx1, int ploty1, int shapesizex, int shapesizey, float shaperotation, float alphashape, float roundedshape, int colorpattern, bool isselected)
        general_shape_size_to_apply=12.0;
        break;
    case 8://plot_draw_circle(int plotx1, int ploty1, float sizeshape,  float alphashape,   int colorpattern, bool isselected)
        general_shape_size_to_apply=6.0;
        break;
    case 9://plot_draw_slice(int plotx1, int ploty1, float sizeshape, float opening_angle, float shaperotation, float alphashape,   int colorpattern, bool isselected)
        general_shape_size_to_apply=10.0;
        break;
    case 10://polygon
        general_shape_size_to_apply=10.0;
        break;
    case 11://texts
        general_shape_size_to_apply=10.0;
        break;
    default:
        general_shape_size_to_apply=10.0;
        break;
    }
    return(0);
}
