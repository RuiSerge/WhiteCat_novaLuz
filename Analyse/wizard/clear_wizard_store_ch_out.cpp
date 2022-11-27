int clear_wizard_store_ch_out()
{
    for (int p=0; p<2160; p++)
    {
        tmp_wizbuffer[p]=' ';
    }

    for (int ly=0; ly<36; ly++)
    {
        show_buff_wizOUT[ly][72]=' ';
        strcpy(show_buff_wizOUT[ly],"");
        for (int by=0; by<73; by++)
        {
            show_buff_wizOUT[ly][by]=' ';
        }

    }
    for (int w=1; w<513; w++)
    {
        wizard_buffer_out[w]=0;
    }
    number_outchannels=0;
    position_ligne_wizard_out=0;
    return(0);
}
