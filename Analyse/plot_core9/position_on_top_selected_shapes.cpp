int position_on_top_selected_shapes()
{
    /*
    delete_selected_shapes();
    add_selected_shapes();
    */
    snapshot_shapes();
    for(int i=1; i<nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            exchange_shape_position(i,nbre_shapes_on_plot);
            break;
        }
    }
    return(0);
}
