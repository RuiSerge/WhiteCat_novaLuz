int affect_time_entry_to_mem(int index_t,int mem_set_to_time)
{
    if(numeric_postext>0)
    {
        read_time_string_entry();
        Times_Memoires[mem_set_to_time][index_t]=(time_minutes*60)+time_secondes+(0.01*time_centiemes);
    }

    someone_changed_in_sequences=1;//icat
    return(0);
}
