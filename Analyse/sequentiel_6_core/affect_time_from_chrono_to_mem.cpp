int affect_time_from_chrono_to_mem(int mem_to_set_time)
{
    for(int ty=0; ty<4; ty++)
    {
        if(index_type_of_time_to_affect[ty]==1)
        {
            Times_Memoires[mem_to_set_time][ty]= (time_minutes*60)+time_secondes+ ((float)time_centiemes)/100;
        }
    }
    show_im_recording_a_time=1;
    someone_changed_in_sequences=1;//icat
    return(0);
}
