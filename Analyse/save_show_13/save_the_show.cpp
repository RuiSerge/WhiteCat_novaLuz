int save_the_show(char name_of_show[48])
{
    index_is_saving=1;
    char vieux_nomduspectacle[48];
    sprintf(vieux_nomduspectacle, nomduspectacle);

    sprintf(nomduspectacle,name_of_show);
    Save_Show();
    save_load_print_to_screen("Saving Arduino Conf");
    sprintf(string_Last_Order,">> Saved %s  at %s",nomduspectacle,tmp_time);
    timer_save_tmp=0;
    sprintf(my_show_is_coming_from,"Saved in %s",nomduspectacle);//pour retracer d ou vient la conduite
    idf++;
    write_show_coming_from();
    sprintf(nomduspectacle,vieux_nomduspectacle);
    index_is_saving=0;
    return(0);
}
