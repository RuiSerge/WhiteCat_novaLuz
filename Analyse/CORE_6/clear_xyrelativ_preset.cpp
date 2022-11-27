int clear_xyrelativ_preset(int pr)
{
    for(int i=0; i<5; i++)
    {
        plot_relativxy_preset[pr][i][0]=0;
        plot_relativxy_preset[pr][i][1]=0;
    }
    return(0);
}
