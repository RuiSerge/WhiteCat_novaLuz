int check_presence_of_any_channel_in_A_view(int v)
{
    bool reponse=0;

    if(Channel_View_MODE[v]==1)
    {
        for(int c=0; c<channel_number_in_View[v]; c++)
        {
            if(Selected_Channel[(Channel_View_ROUTING[v][c])]==1)
            {
                reponse=1;
                break;
            }
        }
    }
    return(reponse);
}
