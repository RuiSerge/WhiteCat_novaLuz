int check_presence_of_a_channel_in_views( int idch)
{
    bool reponse=0;
    for(int v=0; v<nbre_de_vues_circuits; v++)
    {
        if(Channel_View_MODE[v]==1)
        {
            for(int c=0; c<channel_number_in_View[v]; c++)
            {
                if(Channel_View_ROUTING[v][c]==idch)
                {
                    reponse=1;
                    break;
                }
            }
        }
        if(reponse==1)
        {
            break;
        }
    }
    return(reponse);
}
