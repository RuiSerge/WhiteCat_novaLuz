int do_curve_affectation()
{
    for(int k=0; k<513; k++)
    {
        if(Dimmers_selected[k]==1)
        {
            curves[k]=curve_selected;
        }
    }
    return(0);
}
