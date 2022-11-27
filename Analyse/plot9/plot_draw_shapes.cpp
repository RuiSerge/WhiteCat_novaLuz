int plot_draw_shapes(int plotx, int ploty)
{

    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        switch(shape_type[i])
        {
        case 0:    //curtain
            plot_draw_shape_curtain(plotx+ shape_position[i][0], ploty+shape_position[i][1],  plotx+shape_position[i][2], ploty+shape_position[i][3], shape_attributes[i][0]/5,  general_alpha_for_shape,shape_color_type[i],shape_selected[i]);
            break;
        case 1:     //ligne  plain
            plot_draw_shape_line(plotx+ shape_position[i][0],  ploty+shape_position[i][1], plotx+ shape_position[i][2],ploty+shape_position[i][3], shape_attributes[i][0]/10,  general_alpha_for_shape, shape_color_type[i],shape_selected[i]);
            break;
        case 2:     //stripline 1  int plotx1, int ploty1, int plotx2, int ploty2, float sizeshape,  float alphag, short typeofline,int col pattren bool isselected, bool extreme)
            plot_draw_shape_stripline(plotx+ shape_position[i][0],  ploty+shape_position[i][1], plotx+ shape_position[i][2],ploty+shape_position[i][3], shape_attributes[i][0]/10,  general_alpha_for_shape,0, shape_color_type[i],shape_selected[i], 1);
            break;
        case 3:     //stripline 2
            plot_draw_shape_stripline(plotx+ shape_position[i][0],  ploty+shape_position[i][1], plotx+ shape_position[i][2],ploty+shape_position[i][3], shape_attributes[i][0]/10,  general_alpha_for_shape,1, shape_color_type[i],shape_selected[i], 1);
            break;
        case 4:     //stripline 3
            plot_draw_shape_stripline(plotx+ shape_position[i][0],  ploty+shape_position[i][1], plotx+ shape_position[i][2],ploty+shape_position[i][3], shape_attributes[i][0]/10,  general_alpha_for_shape,2, shape_color_type[i],shape_selected[i], 1);
            break;
        case 5:     //stripline 4
            plot_draw_shape_stripline(plotx+ shape_position[i][0],  ploty+shape_position[i][1], plotx+ shape_position[i][2],ploty+shape_position[i][3], shape_attributes[i][0]/10,  general_alpha_for_shape,3, shape_color_type[i],shape_selected[i], 1);
            break;
        case 6:     //stripline 5
            plot_draw_shape_stripline(plotx+ shape_position[i][0],  ploty+shape_position[i][1], plotx+ shape_position[i][2],ploty+shape_position[i][3], shape_attributes[i][0]/10,  general_alpha_for_shape,4, shape_color_type[i],shape_selected[i], 1);
            break;
        case 7://plot_draw_rectangle(int plotx1, int ploty1, int shapesizex, int shapesizey, float shaperotation, float alphashape,  int colorpattern, bool isselected)
            plot_draw_rectangle(plotx+ shape_position[i][0],  ploty+shape_position[i][1], shape_attributes[i][2]*shape_attributes[i][0],shape_attributes[i][3]*shape_attributes[i][0], shape_attributes[i][1],  general_alpha_for_shape,shape_color_type[i],shape_selected[i]);
            break;
        case 8://plot_draw_circle(int plotx1, int ploty1, float sizeshape,  float alphashape,   int colorpattern, bool isselected)
            plot_draw_circle(plotx+shape_position[i][0],  ploty+shape_position[i][1],5*shape_attributes[i][0], general_alpha_for_shape,shape_color_type[i],shape_selected[i]);
            break;
        case 9://plot_draw_slice(int plotx1, int ploty1, float sizeshape, float opening_angle, float shaperotation, float alphashape,   int colorpattern, bool isselected)
            plot_draw_slice(plotx+shape_position[i][0],  ploty+shape_position[i][1],5*shape_attributes[i][0], shape_attributes[i][4]*6.5,shape_attributes[i][1],general_alpha_for_shape,shape_color_type[i],shape_selected[i]);
            break;
        case 10://polygon int plotx1, int ploty1, float sizeshape, float shaperotation,int numPoints,  float alphashape,   int colorpattern, bool isselected)
            plot_draw_polygon(plotx+shape_position[i][0],  ploty+shape_position[i][1], shape_attributes[i][0]*5,shape_attributes[i][1],(int)shape_attributes[i][2], general_alpha_for_shape,shape_color_type[i],shape_selected[i]);
            break;
        case 11://(int plotx,int ploty, float fontsize,int fonttype,  char *text,float alphatext, bool isselected)
            plot_draw_text(plotx+shape_position[i][0],  ploty+shape_position[i][1],(int)shape_attributes[i][0],(int)shape_attributes[i][2],shape_legend_name[i],general_alpha_for_shape, shape_selected[i]);
            break;
        default:
            break;
        }

        if(index_show_shape_id==1)
        {
            petitchiffrenoir.Print(ol::ToString(i), plotx+shape_position[i][0]+10,  ploty+shape_position[i][1]+10);
            if(shape_groups[i]!=0)
            {
                char Gr[8];
                sprintf(Gr,"Gr. %d",shape_groups[i]);
                petitchiffrenoir.Print(Gr, plotx+shape_position[i][0]+10,  ploty+shape_position[i][1]+20);
            }
        }
        if(shape_type[i]!=11)
        {
            petitchiffrenoir.Print(shape_legend_name[i], plotx+shape_position[i][0]+shape_relativ_position_legend_name[i][0],  ploty+shape_position[i][1]+shape_relativ_position_legend_name[i][1]);
        }
    }
    return(0);
}
