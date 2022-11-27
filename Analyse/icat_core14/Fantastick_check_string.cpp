int Fantastick_check_string()
{
    char string_to_send[256+36];
    for(int id=1; id<iCat_nbre_de_strings[iCatPageis]+1; id++)
    {
        switch(iCat_affectation_string_type_is[iCatPageis][id])
        {
        case 1://INPUTS
            switch(iCat_affectation_string_action_is[iCatPageis][id])
            {
            case 1: //input
                if(previous_numeric_postext!=numeric_postext)
                {
                    sprintf(string_to_send,"model Str%d text %s",id,string_numeric_entry);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                previous_numeric_postext=numeric_postext;
                break;
            case 2://last ch
                if(previous_last_ch_selected!=last_ch_selected)
                {
                    sprintf(string_to_send,"model Str%d text >>Last Ch.selected: %d",id,last_ch_selected);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                previous_last_ch_selected=last_ch_selected;
                break;
            case 3://dimmers
                if(previous_last_dim_selected!=last_dim_selected)
                {
                    sprintf(string_to_send,"model Str%d text %s",id,string_secondary_feeback);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                previous_last_dim_selected=last_dim_selected;
                break;
            case 4://last order
                if(strcmp(string_Last_Order,previous_string_Last_Order)!=0)
                {
                    sprintf(string_to_send,"model Str%d text %s",id,string_Last_Order);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                sprintf(previous_string_Last_Order,string_Last_Order);
                break;
            case 5://confirm
                if(strcmp(string_confirmation,previous_string_confirmation)!=0)
                {
                    sprintf(string_to_send,"model Str%d text %s",id,string_confirmation);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                }
                sprintf(previous_string_confirmation,string_confirmation);
                break;
            default:
                strcpy(string_to_send,"");
                break;
            }
            break;
        //fin inputs
        case 2: // sequenciel
            if(someone_changed_in_sequences==1)
            {
                //ventilation_temps_vers_char();//pour sytrings din dout etc
                strcpy(string_to_send,"");
                switch(iCat_affectation_string_action_is[iCatPageis][id])
                {
                case 1://Stage
                    //num
                    sprintf(string_to_send,"model Str%d text %d.%d",id,position_onstage/10,position_onstage%10);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //autogo
                    if(Links_Memoires[position_onstage]==1)
                    {
                        sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                        nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(iCat_pos_string[iCatPageis][id][0]*2)+(60*ratio_iCat_string[iCatPageis][id]), (iCat_pos_string[iCatPageis][id][1]*2)+(5*ratio_iCat_string[iCatPageis][id]));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    else
                    {
                        sprintf(string_to_send, "model Autogo%d position -999 -999 0",id);
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    //desc
                    sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[position_onstage]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //time
                    sprintf(string_to_send,"model StrTime%d text D.Out: %s OUT: %s  ",id,cross_dout,cross_out);
                    nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    break;
                case 2://preset
                    //num
                    sprintf(string_to_send,"model Str%d text %d.%d",id,position_preset/10,position_preset%10);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //autogo
                    if(Links_Memoires[position_preset]==1)
                    {
                        sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                        nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(iCat_pos_string[iCatPageis][id][0]*2)+(60*ratio_iCat_string[iCatPageis][id]), (iCat_pos_string[iCatPageis][id][1]*2)+(5*ratio_iCat_string[iCatPageis][id]));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    else
                    {
                        sprintf(string_to_send, "model Autogo%d position -999 -999 0",id);
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    //desc
                    sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[position_preset]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //annotation
                    sprintf(string_to_send,"model StrAnn%d text %s",id,annotation_memoires[position_preset]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //time
                    sprintf(string_to_send,"model StrTime%d text D.In: %s IN: %s  ",id,cross_din,cross_in);
                    nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    break;
                case 3://mem before one
                    //num
                    sprintf(string_to_send,"model Str%d text %d.%d",id,mem_before_one/10,mem_before_one%10);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //autogo
                    if(Links_Memoires[mem_before_one]==1)
                    {
                        sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                        nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(iCat_pos_string[iCatPageis][id][0]*2)+(60*ratio_iCat_string[iCatPageis][id]), (iCat_pos_string[iCatPageis][id][1]*2)+(5*ratio_iCat_string[iCatPageis][id]));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    else
                    {
                        sprintf(string_to_send, "model Autogo%d position -999 -999 0",id);
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    //desc
                    sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[mem_before_one]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    break;
                case 4://mem after one
                    mem_after_one=0;
                    for(int memsearch=position_preset+1; memsearch<10000; memsearch++)
                    {
                        if(MemoiresExistantes[memsearch]==1 )
                        {
                            mem_after_one=memsearch;
                            //num
                            sprintf(string_to_send,"model Str%d text %d.%d",id,mem_after_one/10,mem_after_one%10);
                            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                            //autogo
                            if(Links_Memoires[mem_after_one]==1)
                            {
                                sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                                nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                                sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(iCat_pos_string[iCatPageis][id][0]*2)+(60*ratio_iCat_string[iCatPageis][id]), (iCat_pos_string[iCatPageis][id][1]*2)+(5*ratio_iCat_string[iCatPageis][id]));
                                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                                sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                            }
                            else
                            {
                                sprintf(string_to_send, "model Autogo%d position -999 -999 0",id);
                                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                            }
                            //desc
                            sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[mem_after_one]);
                            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                            break;
                        }
                    }
                    break;
                default:
                    break;
                }
            }//fin si someone_changed_in_sequences

            //times changed
            if(someone_changed_in_time_sequences==1)//uniquement affichage time crossfade
            {
                strcpy(string_to_send,"");
                switch(iCat_affectation_string_action_is[iCatPageis][id])
                {
                case 1://Stage
                    //time
                    sprintf(string_to_send,"model StrTime%d text D.Out: %s OUT: %s  ",id,cross_dout,cross_out);
                    nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    break;
                case 2://preset
                    //time
                    sprintf(string_to_send,"model StrTime%d text D.In: %s IN: %s  ",id,cross_din,cross_in);
                    nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    break;
                default:
                    break;
                }
            }
            break;
        default:
            break;

        }
    }
    someone_changed_in_sequences=0;
    someone_changed_in_time_sequences=0;
    return(0);
}
