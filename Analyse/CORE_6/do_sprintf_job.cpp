int do_sprintf_job()//report du calcul des affichages de temps dans la boucle des 10�me de scondes
{

    if (MemoiresExistantes[mem_before_one]==1)
    {
        sprintf(string_mem_before_one,"%d.%d",mem_before_one/10, mem_before_one%10);
    }
    else
    {
        sprintf(string_mem_before_one,"-");
    }

    sprintf(string_ratio_x1x2,"%.2f",((255.0-ratio_X1X2_together)/255));
    sprintf(str_crossfade_speed_is,"%d",crossfade_speed-64);

    float val_accel=0.0;

    affichage_time_format(Times_Memoires[position_onstage][0]);//dout
    sprintf(string_time_memonstage[0],string_conversion_timeis);
    affichage_time_format(Times_Memoires[position_onstage][2]);//dIn
    sprintf(string_time_memonstage[2],string_conversion_timeis);
    affichage_time_format(Times_Memoires[position_onstage][3]);//in
    sprintf(string_time_memonstage[3],string_conversion_timeis);
    affichage_time_format(Times_Memoires[position_onstage][1]);//out
    sprintf(string_time_memonstage[1],string_conversion_timeis);
    if(Times_Memoires[position_preset][0]>0.00)
    {
        if(crossfade_speed<64)
        {
            affichage_time_format(Times_Memoires[position_preset][0]*(64.0/crossfade_speed));
        }
        else if(crossfade_speed==64)
        {
            affichage_time_format(Times_Memoires[position_preset][0]);
        }
        else if(crossfade_speed>64)
        {
            val_accel=Times_Memoires[position_preset][0]- ( (Times_Memoires[position_preset][0] /64) * (crossfade_speed-63));
            affichage_time_format(val_accel);
        }
        sprintf(cross_din,string_conversion_timeis);
    }
    else
    {
        strcpy(cross_din,"");
    }


    if(Times_Memoires[position_preset][2]>0.00)
    {
        if(crossfade_speed<64)
        {
            affichage_time_format(Times_Memoires[position_preset][2]*(64.0/crossfade_speed));
        }
        else if(crossfade_speed==64)
        {
            affichage_time_format(Times_Memoires[position_preset][2]);
        }
        else if(crossfade_speed>64)
        {
            val_accel=Times_Memoires[position_preset][2]- ( (Times_Memoires[position_preset][2] /64) * (crossfade_speed-63));
            affichage_time_format(val_accel);
        }
        sprintf(cross_dout,string_conversion_timeis);
    }
    else
    {
        strcpy(cross_dout,"");
    }

    if(crossfade_speed<64)
    {
        affichage_time_format(Times_Memoires[position_preset][1]*(64.0/crossfade_speed));
        sprintf(cross_in,string_conversion_timeis);
        affichage_time_format(Times_Memoires[position_preset][3]*(64.0/crossfade_speed));
        sprintf(cross_out,string_conversion_timeis);

        report_dIn=(Times_Memoires[position_preset][0]*(64.0/crossfade_speed));
        report_In=(Times_Memoires[position_preset][1]*(64.0/crossfade_speed));
        report_dOut=(Times_Memoires[position_preset][2]*(64.0/crossfade_speed));
        report_Out=(Times_Memoires[position_preset][3]*(64.0/crossfade_speed));

    }
    else if(crossfade_speed==64)
    {
        affichage_time_format(Times_Memoires[position_preset][1]);
        sprintf(cross_in,string_conversion_timeis);
        affichage_time_format(Times_Memoires[position_preset][3]);
        sprintf(cross_out,string_conversion_timeis);

        report_dIn=(Times_Memoires[position_preset][0]);
        report_In=(Times_Memoires[position_preset][1]);
        report_dOut=(Times_Memoires[position_preset][2]);
        report_Out=(Times_Memoires[position_preset][3]);

    }
    else if(crossfade_speed>64)
    {
        val_accel=Times_Memoires[position_preset][1]- ( (Times_Memoires[position_preset][1] /64) * (crossfade_speed-63));
        affichage_time_format(val_accel);
        sprintf(cross_in,string_conversion_timeis);
        val_accel=Times_Memoires[position_preset][3]- ( (Times_Memoires[position_preset][3] /64) * (crossfade_speed-63));
        affichage_time_format(val_accel);
        sprintf(cross_out,string_conversion_timeis);

        report_dIn=
            ((Times_Memoires[position_preset][0]- ( (Times_Memoires[position_preset][0] /64) * (crossfade_speed-63))));
        report_In=
            ((Times_Memoires[position_preset][1]- ( (Times_Memoires[position_preset][1] /64) * (crossfade_speed-63))));

        report_dOut=
            ((Times_Memoires[position_preset][2]- ( (Times_Memoires[position_preset][2] /64) * (crossfade_speed-63))));
        report_Out=
            ((Times_Memoires[position_preset][3]- ( (Times_Memoires[position_preset][3] /64) * (crossfade_speed-63))));

    }


    if(((report_dOut+report_Out)>=(report_dIn+ report_In))&&((report_dOut+report_Out)>=(report_dIn+ report_Out))&&((report_dOut+report_Out)>=(report_dOut+report_In)))
    {
        totalTimeCrossfade= (report_dOut+report_Out);
    }
    if(((report_dIn+ report_In)>=(report_dOut+report_Out))&&((report_dIn+ report_In)>=(report_dIn+ report_Out))&&((report_dIn+ report_In)>=(report_dOut+report_In)))
    {
        totalTimeCrossfade= (report_dIn+ report_In);
    }
    if(((report_dIn+ report_Out)>=(report_dIn+ report_In))&&((report_dIn+ report_Out)>=(report_dOut+report_Out))&&((report_dIn+ report_Out)>=(report_dOut+report_In)))
    {
        totalTimeCrossfade= (report_dIn+ report_Out);
    }
    if(((report_dOut+report_In)>=(report_dIn+ report_In))&&((report_dOut+report_In)>=(report_dIn+ report_Out))&&((report_dOut+report_In)>=(report_dOut+report_Out)))
    {
        totalTimeCrossfade= (report_dOut+report_In);
    }

    affichage_time_format(totalTimeCrossfade);
    sprintf(string_total_time_is,"%s",string_conversion_timeis);

    if((index_go==1 || index_go_back==1)&& index_pause==0)
    {
            //sab 27/01/2015 deb
        //Affichage du temps du crossfade en cours : l'affichage du temps restant, commence souvent � moins "quelque chose".
        //time_left=((crossfade_done_time-totalTimeCrossfade)/BPS_RATE);
        //affichage_time_format(time_left);
                //sprintf(string_time_left_is,"%s",string_conversion_timeis);

        float f_time_left = totalTimeCrossfade - float (crossfade_done_time) / BPS_RATE ;
        affichage_time_format(f_time_left);
        sprintf(string_time_left_is,"%s",string_conversion_timeis);

        //sab 27/01/2015 fin
    }


    int index_nbre_mem_visues=0;
    //sab 02/03/2014 unsued var int last_mem_visue=0;
    for(int memsearch=position_preset+1; memsearch<10000; memsearch++)
    {
        if(MemoiresExistantes[memsearch]==1 && index_nbre_mem_visues<nbre_memoires_visualisables_en_preset)
        {
            index_nbre_mem_visues++;
            for(int tt=0; tt<4; tt++)
            {
                affichage_time_format(Times_Memoires[memsearch][tt]);
                sprintf(string_time_mem8after[index_nbre_mem_visues][tt],string_conversion_timeis);
            }

            if(index_nbre_mem_visues>=nbre_memoires_visualisables_en_preset)
            {
                break;
            }

        }
    }


    float in_speed,out_speed, delay_in_speed, delay_out_speed;
    char the_del_in[12];
    char the_in[12];
    char the_del_out[12];
    char the_out[12];
    int  dd=0;
    for(int cmptfader=0; cmptfader<core_user_define_nb_faders; cmptfader++)
    {
        dd=dock_used_by_fader_is[cmptfader];

        if(lfo_speed[cmptfader]<64)
        {
            delay_in_speed=(time_per_dock[cmptfader][dd][0]*(64.0/lfo_speed[cmptfader]));
            delay_out_speed=(time_per_dock[cmptfader][dd][2]*(64.0/lfo_speed[cmptfader]));
            in_speed=(time_per_dock[cmptfader][dd][1]*(64.0/lfo_speed[cmptfader]));
            out_speed=(time_per_dock[cmptfader][dd][3]*(64.0/lfo_speed[cmptfader]));
        }
        else if(lfo_speed[cmptfader]==64)
        {
            delay_in_speed=time_per_dock[cmptfader][dd][0];
            delay_out_speed=time_per_dock[cmptfader][dd][2];
            in_speed=time_per_dock[cmptfader][dd][1];
            out_speed=time_per_dock[cmptfader][dd][3];
        }
        else if(lfo_speed[cmptfader]>64)
        {
            delay_in_speed=((time_per_dock[cmptfader][dd][0]*3)/(lfo_speed[cmptfader]-62));
            delay_out_speed=((time_per_dock[cmptfader][dd][2]*3)/(lfo_speed[cmptfader]-62));
            in_speed=((time_per_dock[cmptfader][dd][1]*3)/(lfo_speed[cmptfader]-62));
            out_speed=((time_per_dock[cmptfader][dd][3]*3)/(lfo_speed[cmptfader]-62));
        }


        affichage_time_format(delay_in_speed);
        sprintf(the_del_in,string_conversion_timeis);
        affichage_time_format(in_speed);
        sprintf(the_in,string_conversion_timeis);
        affichage_time_format(delay_out_speed);
        sprintf(the_del_out,string_conversion_timeis);
        affichage_time_format(out_speed);
        sprintf(the_out,string_conversion_timeis);

        if(delay_in_speed>0 && delay_out_speed>0)
        {
            sprintf(string_time_is_in_the_dock[cmptfader],"%s- IN:%s / %s -OUT:%s ",the_del_in,the_in,the_del_out,the_out);
        }
        else if (delay_in_speed>0 && delay_out_speed==0)
        {
            sprintf(string_time_is_in_the_dock[cmptfader],"%s- IN:%s / OUT:%s ",the_del_in,the_in,the_out);
        }
        else if (delay_in_speed==0 && delay_out_speed>0)
        {
            sprintf(string_time_is_in_the_dock[cmptfader],"IN:%s / %s -OUT:%s ",the_in,the_del_out,the_out);
        }
        else
        {
            sprintf(string_time_is_in_the_dock[cmptfader],"        IN:%s / OUT:%s ",the_in,the_out);
        }

    }
    sprintf(string_dock_col_sel,"Col.%d",dock_color_selected+1);

    for(int o=0; o<8; o++)
    {
        detect_master_lock(o);
    }




    for(int gr=0; gr<23; gr++)
    {
        in_speed=grid_times[grid_selected_for_view][grid_step_view+gr][1];
        affichage_time_format(in_speed);//in
        sprintf(the_in,string_conversion_timeis);
        out_speed= grid_times[grid_selected_for_view][grid_step_view+gr][3];
        affichage_time_format(out_speed);//out
        sprintf(the_out,string_conversion_timeis);
        sprintf(string_grid_view_timing_global[gr],"%s / %s",the_in,the_out);

        delay_in_speed=grid_times[grid_selected_for_view][grid_step_view+gr][0];
        affichage_time_format(delay_in_speed);//in
        sprintf(the_del_in,string_conversion_timeis);
        delay_out_speed= grid_times[grid_selected_for_view][grid_step_view+gr][2];
        affichage_time_format(delay_out_speed);//out
        sprintf(the_del_out,string_conversion_timeis);
        sprintf(string_grid_view_timing_global_delays[gr],"%s / %s",the_del_in,the_del_out);
    }

    for(int numero=0; numero<index_nbre_players_visibles; numero++)
    {
        sprintf(string_niveauson[numero],"%0.2f",show_player_niveauson[numero]);
        sprintf(string_pitch[numero],"Pitch %0.2f",show_pitch_value[numero]);
        sprintf(string_pan[numero],"Pan %0.2f",show_pan_value[numero]);
        sprintf(time_is_for_fileCueIn[numero],"In: %.1f",(((float)player_seek_position[numero])/audio_rate[numero]));
        sprintf(time_is_for_fileCueOut[numero],"Out: %.1f",(((float)player_loop_out_position[numero])/audio_rate[numero]));
        sprintf(time_is_for_filePos[numero],"Pos: %.1f",(((float)position_of_file_in_player[numero])/audio_rate[numero]));
        sprintf(time_is_for_fileTotal[numero],"Total: %.1f",(((float)length_of_file_in_player[numero])/audio_rate[numero]));
    }

    return(0);
}
