int plot_draw_symbol_ACL( int plotx, int ploty, float size_symbol, float  angle_pc, int num_symbol, int plot_calc_number_is)
{
    float taille_x=120.0*size_symbol;


    double txcl=0;
    double tycl=0;
    float rayon=taille_x/3;
    for (int r=-2; r<2; r++)
    {
        txcl= cos(angle_pc*-6.5)*(rayon+(18*size_symbol));
        tycl = sin(angle_pc*-6.5)*(rayon+(18*size_symbol));
        plot_draw_symbol_Par_4((int)(plotx+(txcl*r/2)), (int)(ploty+(tycl*r/2)),size_symbol,  angle_pc, num_symbol, plot_calc_number_is);
    }

    return(0);
}
