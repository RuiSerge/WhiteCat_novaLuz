int rearrange_shapes()
{
    for(int s=1; s<nbre_shapes_on_plot; s++)
    {
        if(snap_shape_selected[s]==1)
        {
            for(int sz=s; sz<=nbre_shapes_on_plot; sz++)
            {
                if(snap_shape_selected[sz]==0)
                {
                    copy_shape_to_emply_slot(s,sz);
                }
            }
        }
    }
    return(0);
}
