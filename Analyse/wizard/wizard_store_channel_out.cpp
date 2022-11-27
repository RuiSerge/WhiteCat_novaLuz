int wizard_store_channel_out()
{
    number_outchannels=0;
    clear_wizard_store_ch_out();
    for (int w=1; w<513; w++)
    {
        wizard_buffer_out[w]=Selected_Channel[w];
    }
    strcpy( tmp_wizbuffer,"");
    char tmpw[6];
    for (int w=1; w<513; w++)
    {
        if(wizard_buffer_out[w]==1)
        {
            sprintf(tmpw,"%d-", w);
            strcat(tmp_wizbuffer, tmpw);
            number_outchannels++;
        }
    }

    for (int ly=0; ly<36; ly++)
    {
        strcpy(show_buff_wizOUT[ly],"");
        for (int by=0; by<71; by++)
        {
            show_buff_wizOUT[ly][by]=tmp_wizbuffer[(ly*71)+by];
        }
        show_buff_wizOUT[ly][72]='\0';
    }

    for (int ci=1; ci<513; ci++)
    {
        Selected_Channel[ci]=0;
    }
    last_ch_selected=0;
    index_level_attribue=0;

    index_do_dock=0;
    return(0);
}
