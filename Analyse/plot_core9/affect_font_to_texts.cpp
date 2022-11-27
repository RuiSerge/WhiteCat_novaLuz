int affect_font_to_texts(int ftt )
{
    for(int i=1; i<=nbre_shapes_on_plot; i++)
    {
        if(shape_selected[i]==1)
        {
            shape_attributes[i][2]=(float)ftt;
        }
    }
    return(0);
}
