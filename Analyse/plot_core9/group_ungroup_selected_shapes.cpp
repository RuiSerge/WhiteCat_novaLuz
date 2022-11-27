int group_ungroup_selected_shapes()
{
    bool index_there_is_a_group=0;
    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            if(shape_groups[i]!=0) index_there_is_a_group=1;
            break;
        }
    }

    switch(index_there_is_a_group)
    {
    case 0://creation group
        number_of_shapes_groups++;
        for(int i=1; i<=nbre_shapes_on_plot; i++)
        {
            if(shape_selected[i]==1)
            {
                shape_groups[i]=number_of_shapes_groups;
            }
        }
        break;
    case 1://deselection group
        for(int i=1; i<=nbre_shapes_on_plot; i++)
        {
            if(shape_selected[i]==1)
            {
                shape_groups[i]=0;
            }
        }
        number_of_shapes_groups--;
        if(number_of_shapes_groups<0)
        {
            number_of_shapes_groups=0;
        }
        break;
    default:
        break;
    }
    return(0);
}
