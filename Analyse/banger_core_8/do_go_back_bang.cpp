int do_go_back_bang(int banger_is)
{
    if(bang_is_sended[banger_is]==0 )//|| (bang_is_sended[banger_is]==1 && index_go_back==1 && banger_is==Banger_Memoire[position_preset])si bang pas fini, ou si fini mais present dans un crossfade
    {
        for (int y=0; y<6; y++)
        {
            if(bangers_type[banger_is][y]!=0 )
            {
                Bang_event_back(banger_is, y);
                event_sended[banger_is][y]=1;
            }
        }
        bang_is_sended[banger_is]=1;//bloquage de l envoi des autres évènements
    }

    return(0);
}
