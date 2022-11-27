int add_selected_shapes()
{
    for(int i=1; i<nbre_symbol_per_layer; i++)
    {
        if( snap_shape_selected[i]==1 )
        {
            if( nbre_shapes_on_plot<nbre_symbol_per_layer-1)
            {
                copy_shape_to_emply_slot(nbre_shapes_on_plot,i);
                nbre_shapes_on_plot++;
            }
        }
    }

    return(0);
}
