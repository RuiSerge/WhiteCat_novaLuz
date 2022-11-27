int check_select_deselect_shape(int posx, int posy)
{

    for(int i=nbre_shapes_on_plot+1; i>0 ; i--)
    {
        if(mouse_x>posx+shape_position[i][0]-10 && mouse_x<posx+shape_position[i][0]+10
                && mouse_y>posy+shape_position[i][1]-10 && mouse_y<posy+shape_position[i][1]+10)
        {
            shape_selected[i]=toggle(shape_selected[i]);
            handle_selected_for_line_editing=0;

            if(shape_selected[i]==1)
            {
                index_last_shape_selected=i;
                if(index_type==1)
                {
                    sprintf(numeric,shape_legend_name[i]);
                    numeric_postext=24;
                }
            }
            if(shape_groups[index_last_shape_selected]!=0)
            {
                for(int gr=0; gr<nbre_shapes_on_plot+1 ; gr++)
                {
                    if(shape_groups[gr]==shape_groups[index_last_shape_selected])
                    {
                        shape_selected[gr]=shape_selected[index_last_shape_selected];
                    }
                }
            }
            mouse_released=1;
            refresh_view_shape_params(i);
            break;
        }
        if(shape_type[i]<7 && mouse_x>posx+shape_position[i][2]-10 && mouse_x<posx+shape_position[i][2]+10
                && mouse_y>posy+shape_position[i][3]-10 && mouse_y<posy+shape_position[i][3]+10   )
        {

            handle_selected_for_line_editing=1;
            shape_selected[i]=1;
            editing_shape_line_number=i;
            index_last_shape_selected=i;
            break;
        }
    }


    return(0);
}
