int write_show_coming_from()
{
    FILE *fpi;
    if((fpi=fopen("user/show_coming_from.txt","w")))//etait wb
    {
        fprintf(fpi,"%s",my_show_is_coming_from);
    }
    fclose(fpi);
    return(0);
}
