int refresh_continuously_iCat_trackerzones()
{
    int aire=0;
    int x1=0;
    int y1=0;
    char string_mf_id[16];
    for(int i=1; i<iCat_nbre_de_tracking_zone[iCatPageis]+1; i++)
    {
        switch(iCat_trackzone_type_is[iCatPageis][i])
        {
        case 1://mover
            pos_iCat_tracker[iCatPageis][i][0]=mover_params[0][0];
            pos_iCat_tracker[iCatPageis][i][1]=mover_params[1][0];

            if(previous_pos_iCat_tracker[iCatPageis][i][0]!=pos_iCat_tracker[iCatPageis][i][0] || previous_pos_iCat_tracker[iCatPageis][i][1]!=pos_iCat_tracker[iCatPageis][i][1])
            {
                sprintf(StrOrderToiCat,"model trackPosition%d position %d %d 0",i,
                        (iCat_pos_trackzone[iCatPageis][i][0]*2)+((pos_iCat_tracker[iCatPageis][i][0]/2)*ratio_iCat_trackzone[iCatPageis][i]),
                        (iCat_pos_trackzone[iCatPageis][i][1]*2)+((pos_iCat_tracker[iCatPageis][i][1]/2)*ratio_iCat_trackzone[iCatPageis][i]));

                nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


                sprintf(string_mf_id,"%d-%d",pos_iCat_tracker[iCatPageis][i][0],pos_iCat_tracker[iCatPageis][i][1]);
                sprintf(StrOrderToiCat,"model trackTextPos%d text %s",i,string_mf_id);
                nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

                previous_pos_iCat_tracker[iCatPageis][i][0]=pos_iCat_tracker[iCatPageis][i][0] ;
                previous_pos_iCat_tracker[iCatPageis][i][1]=pos_iCat_tracker[iCatPageis][i][1] ;
            }
            break;
        case 2://draw"Draw Activ");



            if(previous_pos_iCat_tracker[iCatPageis][i][0]!=pos_iCat_tracker[iCatPageis][i][0] || previous_pos_iCat_tracker[iCatPageis][i][1]!=pos_iCat_tracker[iCatPageis][i][1])
            {
                for(int lign=0; lign<draw_preset_parameters[draw_preset_selected][1]; lign++)
                {
                    for(int col=0; col<draw_preset_parameters[draw_preset_selected][0]; col++)
                    {
                        int coordonnee=col+(lign*draw_preset_parameters[draw_preset_selected][0]);
                        sprintf(StrOrderToiCat,"model DrawAera%dOffstet%d color 0. %.1f %.1f",i,coordonnee,
                                draw_preset_levels[draw_preset_selected][coordonnee]*1.0,draw_preset_levels[draw_preset_selected][coordonnee]*0.8);
                        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                }
            }

            x1=iCat_pos_trackzone[iCatPageis][i][0];
            y1=iCat_pos_trackzone[iCatPageis][i][1];
            sprintf(StrOrderToiCat,"model DrawAera%dCurseur xyz %d %d -0.5 %d %d -0.5 %d %d -0.5 %d %d -0.5",
                    i,
                    (x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0])*draw_centre_x[draw_preset_selected] ),
                    (y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1])*draw_centre_y[draw_preset_selected] ),

                    (x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected])),
                    (y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

                    (x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
                    (y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

                    (x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
                    (y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1]) *draw_centre_y[draw_preset_selected]));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

            break;
        case 3://draw"Draw Matrix num");
            aire=iCat_trackzone_affectation_is[iCatPageis][i]-1;

            if(previous_pos_iCat_tracker[iCatPageis][i][0]!=pos_iCat_tracker[iCatPageis][i][0] || previous_pos_iCat_tracker[iCatPageis][i][1]!=pos_iCat_tracker[iCatPageis][i][1])
            {
                for(int lign=0; lign<draw_preset_parameters[aire][1]; lign++)
                {
                    for(int col=0; col<draw_preset_parameters[aire][0]; col++)
                    {
                        int coordonnee=col+(lign*draw_preset_parameters[aire][0]);
                        sprintf(StrOrderToiCat,"model DrawSelAera%dOffstet%d color 0. %.1f %.1f",i,coordonnee,
                                draw_preset_levels[aire][coordonnee]*1.0,draw_preset_levels[aire][coordonnee]*0.8);
                        nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                }
            }

            x1=iCat_pos_trackzone[iCatPageis][i][0];
            y1=iCat_pos_trackzone[iCatPageis][i][1];
            sprintf(StrOrderToiCat,"model DrawAera%dCurseur xyz %d %d -0.5 %d %d -0.5 %d %d -0.5 %d %d -0.5",
                    i,
                    (x1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0])*draw_centre_x[draw_preset_selected] ),
                    (y1*2)+(( (largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1])*draw_centre_y[draw_preset_selected] ),

                    (x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected])),
                    (y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

                    (x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
                    (y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1]) *(draw_centre_y[draw_preset_selected]+1)),

                    (x1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][0]) *(draw_centre_x[draw_preset_selected]+1)),
                    (y1*2)+( ((largeur_trackzone*ratio_iCat_trackzone[iCatPageis][i])/draw_preset_parameters[draw_preset_selected][1]) *draw_centre_y[draw_preset_selected]));
            nbrbytessendediCat=sendto(sockiCat,  StrOrderToiCat,strlen(StrOrderToiCat)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


            break;
        default:
            break;
        }

        index_refresh_valeursTRCK_continous=0;
    }
    return(0);
}
