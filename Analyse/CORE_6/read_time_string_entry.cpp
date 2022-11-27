int read_time_string_entry()
{
    time_minutes=0;
    time_secondes=0;
    time_centiemes=0;

    int position_minutes=0;// dans chaine


    char str_tmp[24];
    sprintf(str_tmp, numeric);

    if(numeric[0]!='.')//si la chaine n'est pas des centiemes de secondes)
    {
        for(int i=0; i<23; i++)
        {
            if(str_tmp[i]=='.' && str_tmp[i+1]=='.' && numeric[0]!='.')
            {
                char tmp_tmp[24];
                sprintf(tmp_tmp,numeric);
                tmp_tmp[i]='\0';
                time_minutes=atoi(tmp_tmp);
                position_minutes=i+1;
            }
        }
        sprintf(str_tmp,"%s", "");
        for(int i=0; i<(24-position_minutes); i++)
        {
            str_tmp[i]=numeric[position_minutes+i];
        }
        char chaine_multiple[2][8];
        char *pch;
        pch = strtok (str_tmp,".");
        int pass=0;
        while (pch != NULL)
        {
            sprintf(chaine_multiple[pass],pch);
            pch = strtok (NULL, ".");
            pass++;
        }

        time_secondes=atoi(chaine_multiple[0]);
        time_centiemes=atoi(chaine_multiple[1]);
    }

    else if (numeric[0]=='.')//centiemes appel�s uniquement
    {
        char cent_t[4];
        for (int i=0; i<4; i++)
        {
            cent_t[i]=numeric[i+1];
            time_centiemes=atoi(cent_t);
        }
    }

    sprintf(string_Last_Order,"Your entry: %d min %d sec %d 1/100", time_minutes, time_secondes, time_centiemes);
    reset_numeric_entry();

    if(time_minutes>59)
    {
        time_minutes=59;
    }
    if(time_secondes>59)
    {
        time_secondes=59;
    }
    if(time_centiemes>99)
    {
        time_centiemes=99;
    }

    angle_timesnap_min=((float)(time_minutes)/59)*5.980005;//=(int)((angle_timesnap_min/6.280005)*63);
    angle_timesnap_sec=((float)(time_secondes)/59)*5.980005;//=(int)((angle_timesnap_sec/((PI*360) / 180))*63);
    angle_timesnap_dix=((float)(time_centiemes)/99)*5.980005;//=(int)((angle_timesnap_dix/6.280005)*10);

    set_time_cursor_to_time_type(time_wheel_datatype_is);

    return(0);
}
