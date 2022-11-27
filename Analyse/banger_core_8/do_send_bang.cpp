int do_send_bang()//remise à zéro du bang concerné pour le lancement depuis une mémoire
{
    if(index_banger_is_on==1 && (Banger_Memoire[position_preset]>0 && Banger_Memoire[position_preset]<128))
    {
        int banger_to_send=Banger_Memoire[position_preset]-1;
        back_up_fader_if_a_fader_inside(banger_to_send);
        sprintf(string_Last_Order,">> Banging %d from mem %d.%d",Banger_Memoire[position_preset],position_preset/10,position_preset%10);
        start_time_for_banger[banger_to_send]=actual_time;

        for (int o=0; o<6; o++) //reset des évènements
        {
            event_sended[banger_to_send][o]=0;
        }
        bang_is_sended[banger_to_send]=0;//reset de l event si il a été lancé dejà une fois
    }

    return(0);
}
