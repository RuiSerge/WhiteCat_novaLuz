int refresh_ocv_settings()
{
    threshold_level=camera_modes_and_settings[ocv_calcul_mode][0];
    erode_level=camera_modes_and_settings[ocv_calcul_mode][1];
    div_facteur=camera_modes_and_settings[ocv_calcul_mode][2];
    threshold_on=camera_modes_and_settings[ocv_calcul_mode][8];
    erode_mode=camera_modes_and_settings[ocv_calcul_mode][9];
    blur_on=camera_modes_and_settings[ocv_calcul_mode][10];
    return(0);
}
