int clear_a_grid(int grid_number)
{
    for(int st=0; st<1023; st++)
    {
        clear_a_grid_step(grid_number,st);
        sprintf(string_Last_Order,"Cleared Grid %d", grid_number+1);
    }
    strcpy(grider_name[grid_number],"");

    return(0);
}
