int check_presence_of_A_channel_in_A_view(int v, int ch)
{
    bool reponse=0;

    for(int c=0; c<channel_number_in_View[v]; c++)
    {
        if(Channel_View_ROUTING[v][c]==ch)
        {
            reponse=1;
            break;
        }
    }

    return(reponse);
}
