int load_plan_of_theatre( char name_of_plan[256], bool rescan_width_eight)
{

    char temp_namePlot[272];

    sprintf(temp_namePlot,"plans\\%s",name_of_plan);

    LightPlanBitmapMain.Load(temp_namePlot);


    if(rescan_width_eight==1)
    {
        taille_relative_plan_theatre[0]= LightPlanBitmapMain.Width();
        taille_relative_plan_theatre[1]= LightPlanBitmapMain.Height();
    }
    ratio_lock_plot_scale=(float)(taille_relative_plan_theatre[0])/(float)(taille_relative_plan_theatre[1]);

    return(0);
}
