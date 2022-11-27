bool check_there_is_someone_in_grid(int grd)
{
    bool answer=0;
    for (int st=0; st<1024; st++)
    {
        for(int c=0; c<513; c++)
        {
            if(grid_levels[grd][st][c]>0)
            {
                answer=1;
                break;
            }
        }
    }
    return(answer);
}
