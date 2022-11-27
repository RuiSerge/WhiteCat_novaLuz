int wizard_inspekt_mem()
{
    strcpy(tmp_wizbuffer,"");
    char tmpw[8];

    for (int w=1; w<513; w++)
    {
        if(Memoires[variable_wizard_mem][w]>0)
        {
            switch(dmx_view)
            {
            case 0:
                sprintf(tmpw,"%d=%d ",w,(int)((float)Memoires[variable_wizard_mem][w]/2.55));
                break;
            case 1:
                sprintf(tmpw,"%d=%d ",w,Memoires[variable_wizard_mem][w]);
                break;
            default:
                break;
            }
            strcat(tmp_wizbuffer, tmpw);
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


    return(0);
}
