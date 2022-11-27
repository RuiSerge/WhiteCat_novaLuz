int Save_Video_Conf()
{
FILE *fph;
if((fph=fopen("user//config_video.txt","w")))
{
fprintf(fph,"#arguments: index size image");
fprintf(fph,"\n%d",camera_size_settings_is);
fprintf(fph,"\n#arguments: your camera prerecorded size ");
fprintf(fph,"\n%dx%d %dx%d",camera_size_array[0][0],camera_size_array[0][1],camera_size_array[1][0],camera_size_array[1][1]);
fprintf(fph,"\n#arguments: (0-1)flip threshold erode blur (Level) thresh erode div");
fprintf(fph,"\n%d %d %d %d %d %d %d",flip_image,threshold_on, erode_mode,blur_on, threshold_level,erode_level,div_facteur);
fprintf(fph,"\n#arguments: preset ocv_mode");
fprintf(fph,"\n%d %d",tracking_dock_selected, ocv_calcul_mode);
}
fclose(fph);
return(0);
}
