int key_backward()
{
           if (key_shifts & KB_CTRL_FLAG || index_false_control==1)
           {
           if(index_go==0 && index_go_back==0 && index_pause==0)
           {
           position_onstage=mem_before_one;
           }
           else {index_go=0;index_pause=0; index_go_back=0;}
           refresh_mem_onstage(position_onstage);
           detect_mem_before_one();
           detect_mem_preset();
           refresh_mem_onpreset(position_preset);
           niveauX1=255; niveauX2=0;
           refresh_banger_wx();
           refresh_integrated_gridplayer1();
           reset_modified_levels_in_crossfade();
           }
           else if (key_shifts & KB_SHIFT_FLAG || index_false_shift==1)
           {
           index_go=0;index_pause=0; index_go_back=0;
           detect_mem_preset_previous();
           refresh_mem_onpreset(position_preset);
           niveauX2=0;
           }
           strcpy(string_time_left_is,"");
           someone_changed_in_sequences=1;//icat
return(0);
}
