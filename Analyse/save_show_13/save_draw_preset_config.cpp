int save_draw_preset_config()
{

FILE *fpp;
if((fpp=fopen("draw_presets_states.txt","w")))//etait wb
{
fprintf(fpp,"#DRAW PRESET CONFIGURATION\n");

for(int i=0;i<6;i++)
{
fprintf(fpp,"#arguments Preset %d:MODE (0 to 3) / LEVEL (float) / TILT (float)/ SIZE (float)/ GHOST (float) / BRUSH TYPE (int) /\n",i+1);
fprintf(fpp,"#arguments 2ndLine :GPL NUM ( 1 to 4 ) / Offset ( 1 to 513 ) / position point / col / row /\n");
fprintf(fpp, "M %d / %f / %f / %f / %d /\n",draw_mode[i],draw_level_to_do[i],draw_damper_decay_factor[i],draw_ghost_to_do[i],draw_brush_type[i]);
fprintf(fpp, "G %d / %d / %d / %d / %d /\n",draw_get_gpl[i],draw_offset_gpl[i], index_case[i],draw_centre_x[i], draw_centre_y[i]);
}
fclose(fpp);
sprintf(string_save_load_report[idf],"Saved draw_presets_states.txt");
}
if( !fpp )
	{
	 sprintf(string_save_load_report[idf],"!draw_presets_states.txt");
   }



return(0);
}
