int draw_pdf_gridayer_state( int grd)
{
sprintf(header_export,"GRIDPLAYER %d:   ",grd+1 );
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Contains Grid: %d Actual Step is: %d",index_grider_selected[grd]+1,index_grider_step_is[grd]+1 );
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Is Playing: %d Seek Pos is: %d AutoStop Mode is: %d",grider_is_playing[grd],index_grider_seek_pos[grd]+1,grider_autostopmode[grd] );
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Macros: Goto Mode: %d CountMode: %d SeekTo Mode: %d StopPlay Mode: %d",grider_goto_mode[grd],grider_count_mode[grd],grider_seekto_mode[grd],grider_stoplay_mode[grd] );
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
sprintf(header_export,"Speed is slaved: %d Speed Level: %d ",grid_player_slave[grd],grid_crossfade_speed[grd] );
if(grd==0){
char tmp[32];
sprintf(tmp,"CuelistSpeed is linked: %d",index_link_speed_crossfade_to_gpl1);
strcat(header_export,tmp);
}
draw_info(page, 100, debut_lignes -(position_ligne1 +(cmptline_pdf*12)),header_export);
cmptline_pdf++;
cmptline_pdf++;
return(0);
}
