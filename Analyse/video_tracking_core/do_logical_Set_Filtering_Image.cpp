int do_logical_Set_Filtering_Image()
{
    if(mouse_x>=videoX+40 && mouse_x<=videoX+295)
    {

        if(mouse_y>videoY+70 && mouse_y<videoY+120)
        {
            threshold_level=mouse_x-(videoX+40);
            camera_modes_and_settings[ocv_calcul_mode][0]=threshold_level;
        }

        if(mouse_y>videoY+130 && mouse_y<videoY+180)
        {
            erode_level=((mouse_x-(videoX+40))/25);
            camera_modes_and_settings[ocv_calcul_mode][1]=erode_level;
        }

        if(ocv_calcul_mode==0)
        {
            if(mouse_y>videoY+180 && mouse_y<videoY+230)
            {
                div_facteur=(mouse_x-(videoX+40));
                camera_modes_and_settings[ocv_calcul_mode][2]=div_facteur;
            }
        }

    }


    if(mouse_y> videoY+video_size_y+110 && mouse_y< videoY+video_size_y+110+25)
    {
        if(mouse_x>videoX+30 && mouse_x<videoX+90 )
        {
            flip_image=toggle(flip_image);
            mouse_released=1;
        }

        if(mouse_x>videoX+100 && mouse_x<videoX+160 )
        {
            threshold_on=toggle(threshold_on);
            camera_modes_and_settings[ocv_calcul_mode][8]=threshold_on;
            mouse_released=1;
        }

        if(mouse_x>videoX+170 && mouse_x<videoX+230 )
        {
            erode_mode=toggle(erode_mode);
            camera_modes_and_settings[ocv_calcul_mode][9]=erode_mode;
            mouse_released=1;
        }

        if(mouse_x>videoX+240 && mouse_x<videoX+300 )
        {
            blur_on=toggle(blur_on);
            camera_modes_and_settings[ocv_calcul_mode][10]=blur_on;
            mouse_released=1;
        }

    }

    return(0);
}
