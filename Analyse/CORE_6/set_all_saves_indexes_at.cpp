bool set_all_saves_indexes_at(bool val)
{
    for (int i=0; i<72; i++)
    {
        specify_who_to_save_load[i]=val;
    }
    return(0);
}
