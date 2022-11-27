int load_the_show(char name_of_show[48])
{
    index_is_saving=1;
    char vieux_nomduspectacle[48];
    sprintf(vieux_nomduspectacle, nomduspectacle);
    sprintf(nomduspectacle,name_of_show);
    Load_Show();
    sprintf(string_Last_Order,">> Loaded %s  at %s",name_of_show,tmp_time);
    timer_save_tmp=0;
    sprintf(nomduspectacle,vieux_nomduspectacle);
    index_is_saving=0;
    index_show_save_load_report=1;
    sprintf(my_show_is_coming_from,"Loaded from in %s",name_of_show);//pour retracer d ou vient la conduite
    write_show_coming_from();
    return(0);
}
