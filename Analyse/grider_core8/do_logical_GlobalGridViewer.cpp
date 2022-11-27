int do_logical_GlobalGridViewer(int xb, int yb, int taillecase)
{

    if(mouse_x>xb+40 && mouse_x<xb+40+50 && mouse_y>yb+10 && mouse_y<yb+10+20  )
    {
        if(mouse_released==0)
        {
            if(numeric_postext>0)
            {
                int temp_num_grid=atoi(numeric);
                if(temp_num_grid>0 && temp_num_grid<128)
                {
                    grid_selected_for_view  =temp_num_grid-1;
                    reset_numeric_entry();
                }
            }
        }
        mouse_released=1;
    }


    if(mouse_x>xb+150 && mouse_x<xb+150+50 && mouse_y>yb+10 && mouse_y<yb+10+20 )
    {
        if( mouse_released==0)
        {
            if(numeric_postext>0)
            {
                int temp_num_grid=atoi(numeric);
                if(temp_num_grid>0 && temp_num_grid<1024)
                {
                    grid_step_view =temp_num_grid-1;
                    reset_numeric_entry();
                }
            }
            mouse_released=1;
        }
    }


    if(mouse_x>xb+220 && mouse_x<xb+220+20 && mouse_y>yb+10 && mouse_y<yb+10+20)
    {
        if( mouse_released==0)
        {
            grid_step_view--;
            if(grid_step_view<0)
            {
                grid_step_view=0;
            }
            mouse_released=1;
        }
    }
    if(mouse_x>xb+250 && mouse_x<xb+250+20 && mouse_y>yb+10 && mouse_y<yb+10+20)
    {
        if( mouse_released==0)
        {
            grid_step_view++;
            if(grid_step_view>1022)
            {
                grid_step_view=1022;
            }
            mouse_released=1;
        }
    }

    return(0);
}
