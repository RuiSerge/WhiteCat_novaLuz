int set_plot_background_to_default()
{
    sprintf(Name_of_plane_is,"defaultplot.jpg");
    load_plan_of_theatre(Name_of_plane_is, 1);
    position_relative_plan_theatre[0]=taille_relative_plan_theatre[0]/2;
    position_relative_plan_theatre[1]=taille_relative_plan_theatre[1]/2;
    orientation_plan_theatre=0.0;
    alpha_plan=1.0;
    plot_view_port_x=0;
    plot_view_port_y=0;

    for(int i=0; i<127; i++) //pour rafraichissement au chargement dans la liste des plans
    {
        if(strcmp( Name_of_plane_is,list_import_plans[i])==0)
        {
            importplan_selected=i;
        }
    }
    return(0);
}
