int To_iCat_DrawString(int id, int x1,int y1, int affectation, int action)
{
    char string_to_send[296];
    switch(iCat_affectation_string_type_is[iCatPageis][id])
    {
    case 1: //Feedback

        switch(iCat_affectation_string_action_is[iCatPageis][id])
        {
        case 1: //input
            sprintf(string_to_send,"model Str%d text -%s",id,string_numeric_entry);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            break;
        case 2://last ch
            sprintf(string_to_send,"model Str%d text -%s",id,string_last_ch);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            break;
        case 3://dimmers
            sprintf(string_to_send,"model Str%d text -%s",id,string_secondary_feeback);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            break;
        case 4://last order
            sprintf(string_to_send,"model Str%d text -%s",id,string_Last_Order);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            break;
        case 5://confirm string
            sprintf(string_to_send,"model Str%d text -%s",id,string_confirmation);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            break;
        default:
            strcpy(string_to_send,"");
            break;
        }
        sprintf(string_to_send, "model Str%d position %d %d 0",id,(x1*2), (y1*2)+ ((12*2*ratio_iCat_string[iCatPageis][id])/2));
        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(string_to_send, "model Str%d font %s",id,iphone_fonts[0]);
        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
        sprintf(string_to_send, "model Str%d fontsize %d",id, 12*ratio_iCat_string[iCatPageis][id]);
        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);


        //fin feedback
        break;
    case 2: //string sequences
        strcpy(string_to_send,"");
        switch(iCat_affectation_string_action_is[iCatPageis][id])
        {
        case 1://Stage
            //num
            sprintf(string_to_send,"model Str%d text %s",id,string_mem_onstage);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d position %d %d 0",id,(x1*2), (y1*2)+ ((14*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d fontsize %d",id, 14*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send,"model Str%d color 0.0 0.5 0.6",id);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            //autogo
            if(Links_Memoires[position_onstage]==1)
            {
                sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(x1*2)+(60*ratio_iCat_string[iCatPageis][id]), (y1*2)+(5*ratio_iCat_string[iCatPageis][id]));
                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            }
            //desc
            sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[position_onstage]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d position %d %d 0",id,(x1*2), (y1*2)+ ((14*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d font %s",id,iphone_fonts[0]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

            //time
            sprintf(string_to_send,"model StrTime%d text D.Out: %s OUT: %s  ",id,cross_dout,cross_out);
            nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrTime%d position %d %d 0",id,(x1*2), (y1*2)+ ((24*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrTime%d font %s",id,iphone_fonts[0]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrTime%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);

            break;
        case 2://preset
            //num
            sprintf(string_to_send,"model Str%d text %s",id,string_mem_preset);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d position %d %d 0",id,(x1*2), (y1*2)+ ((14*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d fontsize %d",id, 14*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send,"model Str%d color 0.6 0.0 0.0",id);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            //autogo
            if(Links_Memoires[position_preset]==1)
            {
                sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(x1*2)+(60*ratio_iCat_string[iCatPageis][id]), (y1*2)+(5*ratio_iCat_string[iCatPageis][id]));
                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            }
            //desc
            sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[position_preset]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d position %d %d 0",id,(x1*2), (y1*2)+ ((14*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d font %s",id,iphone_fonts[0]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            //annotation
            sprintf(string_to_send,"model StrAnn%d text %s",id,annotation_memoires[position_preset]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrAnn%d position %d %d 0",id,(x1*2), (y1*2)+ ((24*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrAnn%d font %s",id,iphone_fonts[0]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrAnn%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            //time
            sprintf(string_to_send,"model StrTime%d text D.In: %s IN: %s  ",id,cross_din,cross_in);
            nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrTime%d position %d %d 0",id,(x1*2), (y1*2)+ ((34*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrTime%d font %s",id,iphone_fonts[0]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrTime%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            break;
        case 3://mem before one
            //num
            sprintf(string_to_send,"model Str%d text %s",id,string_mem_before_one);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d position %d %d 0",id,(x1*2), (y1*2)+ ((12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Str%d font %s",id,iphone_fonts[5]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model Strc%d fontsize %d",id, 12*ratio_iCat_string[iCatPageis][id]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send,"model Str%d color 1.0 1.0 1.0",id);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            //autogo
            if(Links_Memoires[mem_before_one]==1)
            {
                sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(x1*2)+(60*ratio_iCat_string[iCatPageis][id]), (y1*2)+(5*ratio_iCat_string[iCatPageis][id]));
                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            }
            //desc
            sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[mem_before_one]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d position %d %d 0",id,(x1*2), (y1*2)+ ((12*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d font %s",id,iphone_fonts[0]);
            nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
            sprintf(string_to_send, "model StrDesc%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
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
                    sprintf(string_to_send, "model Str%d position %d %d 0",id,(x1*2), (y1*2)+ ((12*2*ratio_iCat_string[iCatPageis][id])/2));
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    sprintf(string_to_send, "model Str%d font %s",id,iphone_fonts[5]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    sprintf(string_to_send, "model Strc%d fontsize %d",id, 12*ratio_iCat_string[iCatPageis][id]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    sprintf(string_to_send,"model Str%d color 1.0 1.0 1.0",id);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    //autogo
                    if(Links_Memoires[mem_after_one]==1)
                    {
                        sprintf(string_to_send,"model Autogo%d image http://www.le-chat-noir-numerique.fr/iCat/autogo_view.jpg",id);
                        nbrbytessendediCat=sendto(sockiCat, string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d position %d %d 0",id,(x1*2)+(60*ratio_iCat_string[iCatPageis][id]), (y1*2)+(5*ratio_iCat_string[iCatPageis][id]));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                        sprintf(string_to_send, "model Autogo%d scale %.1f %.1f 0",id,((float)ratio_iCat_string[iCatPageis][id]/2),((float)ratio_iCat_string[iCatPageis][id]/2));
                        nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    }
                    //desc
                    sprintf(string_to_send,"model StrDesc%d text %s",id,descriptif_memoires[mem_after_one]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    sprintf(string_to_send, "model StrDesc%d position %d %d 0",id,(x1*2), (y1*2)+ ((12*ratio_iCat_string[iCatPageis][id])+(12*2*ratio_iCat_string[iCatPageis][id])/2));
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    sprintf(string_to_send, "model StrDesc%d font %s",id,iphone_fonts[0]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    sprintf(string_to_send, "model StrDesc%d fontsize %d",id, 10*ratio_iCat_string[iCatPageis][id]);
                    nbrbytessendediCat=sendto(sockiCat,  string_to_send,strlen(string_to_send)+1,0,(SOCKADDR*)&siniCat,sinsizeiCat);
                    break;
                }
            }

            break;
        default:
            break;
        }

        break;
    default:
        break;
    }

    return(0);
}
