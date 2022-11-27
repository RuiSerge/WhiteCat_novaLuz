int Load_User_Profile()
{

    FILE *fpA;

    if ((fpA=fopen(file_color_profile, "rb"))==NULL)
    {
        sprintf(string_save_load_report[idf],"Error opening file %s", file_color_profile);
    }
    else
    {
        sprintf(string_save_load_report[idf],"Opening file %s",   file_color_profile);
        if (fread( couleurs_user, sizeof(float), color_profile_size, fpA) !=color_profile_size)
        {
            sprintf(string_save_load_report[idf],"Error Loaded %s", file_color_profile);
        }
        else sprintf(string_save_load_report[idf],"Loaded file %s",file_color_profile);
        fclose(fpA);
    }
    for(int tmp=0; tmp<12; tmp++)
    {
        Rgba TmpColor (couleurs_user[tmp][0],couleurs_user[tmp][1],couleurs_user[tmp][2]);

        switch (tmp)
        {
        case 0:
            CouleurUser1=TmpColor;
            break;
        case 1:
            CouleurUser2=TmpColor;
            break;
        case 2:
            CouleurUser3=TmpColor;
            break;
        case 3:
            CouleurUser4=TmpColor;
            break;
        case 4:
            CouleurUser5=TmpColor;
            break;
        case 5:
            CouleurUser6=TmpColor;
            break;
        case 6:
            CouleurUser7=TmpColor;
            break;
        case 7:
            CouleurUser8=TmpColor;
            break;
        case 8:
            CouleurUser9=TmpColor;
            break;
        case 9:
            CouleurUser10=TmpColor;
            break;
        case 10:
            CouleurUser11=TmpColor;
            break;
        case 11:
            CouleurUser12=TmpColor;
            break;
        }
    }
    return(0);
}
