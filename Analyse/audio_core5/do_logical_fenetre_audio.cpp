int do_logical_fenetre_audio(int xb,int yb)
{

    if(mouse_x>xb+350 && mouse_x<xb+590 && mouse_y>yb+10 && mouse_y<yb+40)
    {
        if(index_type==1 )
        {
            index_ask_confirm=1;
            index_do_ask_call_audio_folder=1;
            mouse_released=1;
        }
    }


    for (int y=1; y<(index_nbre_players_visibles*6* 24); y++)
    {

        if(mouse_x>xb+355 && mouse_x<xb+355+150 && mouse_y>(yb+45+(y*20)-12) && mouse_y<(yb+45+(y*20)+3))
        {
            audiofile_selected=(y+line_audio);
            sprintf(audiofile_name,list_audio_files[audiofile_selected]);
            mouse_released=1;
        }
    }


    if(mouse_x>xb+570-12 && mouse_x<xb+570+12)
    {
        if(mouse_y>yb+65-12 && mouse_y<yb+65+12)
        {
            if(line_audio>0)
            {
                line_audio--;
                mouse_released=1;
            }
        }
        if(mouse_y>yb+(index_nbre_players_visibles*6* 20)-7 && mouse_y<yb+(index_nbre_players_visibles*6* 20)+5)
        {
            if(line_audio+24<128)
            {
                line_audio++;
                mouse_released=1;
            }
        }
    }


    if(mouse_x>xb+230 && mouse_x<xb+230+50 && mouse_y>yb+10 && mouse_y<yb+10+20)
    {
        mouse_released=1;
        scan_audiofolder();
        // Save_audiofiles_cues();
        Load_audiofiles_cues();

    }

    if(mouse_x>xb+230 && mouse_x<xb+230+50 && mouse_y>yb+40 && mouse_y<yb+40+20)
    {
        index_edit_audio=toggle(index_edit_audio);
        mouse_released=1;
    }



    for(int lop=0; lop<index_nbre_players_visibles; lop++)
    {
        do_logical_lecteur_audio(xb+5,yb+70+(lop*140),lop);
    }


    if(mouse_x>xb+440 && mouse_x<xb+440+140 && mouse_y>yb+55+(index_nbre_players_visibles*6*20) && mouse_y<yb+55+(index_nbre_players_visibles*6*20)+20)
    {
        if(index_affect_audio_to_dock==0)
        {
            reset_index_actions();
            reset_indexs_confirmation();
            index_affect_audio_to_dock=1;
        }
        else
        {
            reset_index_actions();
        }
        index_do_dock=index_affect_audio_to_dock;
        mouse_released=1;

    }

    for(int pl=0; pl<index_nbre_players_visibles; pl++)
    {
        for (int co=0; co<3; co++)
        {

            if(index_affect_audio_to_dock==1 && mouse_x>xb+460+(pl*30) && mouse_x<xb+460+(pl*30)+20 && mouse_y>yb+90+(index_nbre_players_visibles*6*20)+(co*20) && mouse_y<yb+90+(index_nbre_players_visibles*6*20)+(co*20)+15)
            {

                player_to_affect_to_dock=pl;
                audio_type_for_dock_affectation_is=co; // 0 volume 1 pan 2 pitch
                mouse_released=0;

            }
        }
    }


    return(0);
}
