int reset_memoires()
{
    for(int j=0; j<32; j++)
    {
        for (int i=0; i<48; i++)
        {
            dock_move_xy[j][i][0]=0;
            dock_move_xy[j][i][1]=0;
            dock_time[j][i]=0;
            for(int z=0; z<16; z++)
            {
                dock_asservis[j][i][z]=0;
            }
        }
        dock_move_actual_step[j]=1;// le step actuel
        dock_moves_contains_steps[j]=1; // le nombre de steps contenus

        spline_ratio[j]=0.0;//pour chaque spline
        x_val_at_beg[j]=0.0;
        y_val_at_beg[j]=0.0;
        x_val_at_end[j]=0.0;
        y_val_at_end[j]=0.0;
        x_fract[j]=0.0;
        y_fract[j]=0.0;
    }
    return(0);
}
