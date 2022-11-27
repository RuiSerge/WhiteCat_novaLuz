int copy_banger(int source,int dest)
{
    if(index_banger_to_copy_in!=-999)
    {
        sprintf(bangers_name[dest],bangers_name[source]);
        sprintf(string_alarm[dest],string_alarm[source]);
        for(int i=0; i<6; i++)
        {
            bangers_type[dest][i]=bangers_type[source][i];
            bangers_action[dest][i]=bangers_action[source][i];
            bangers_params[dest][i][0]=bangers_params[source][i][0];
            bangers_params[dest][i][1]=bangers_params[source][i][1];
            bangers_delay[dest][i]=bangers_delay[source][i];

        }
        sprintf(string_Last_Order,"Copyed Banger %d in Banger %d", source+1, dest+1);
        index_banger_to_copy_in=-999;
        index_copy_banger=0;
    }
    return(0);
}
