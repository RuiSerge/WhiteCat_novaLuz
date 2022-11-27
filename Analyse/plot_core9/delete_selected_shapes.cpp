int delete_selected_shapes()
{
    snapshot_shapes();
    int nbre_shapes_to_delete=0;
    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            nbre_shapes_to_delete++;
            clear_shape_slot(i);
            rearrange_shapes();
            snap_shape_selected[i]=0;
        }
    }



    nbre_shapes_on_plot-=nbre_shapes_to_delete;
    if(nbre_shapes_on_plot<0)
    {
        nbre_shapes_on_plot=0;
    }

    return(0);
}
