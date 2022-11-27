int reset_all_bangers()//for load show and stop all running bangers
{
    for (int i=0; i<127; i++)
    {
        bang_is_sended[i]=1;//pour ne pas envoyer le banger
        for(int eventnum=0; eventnum<6; eventnum++)
        {
            event_sended[i][eventnum]=0;//reset des envois
        }
    }
    return(0);
}
