int check_wich_channel_is_in_view(int idch)//pour srcoll bar
{
    bool reponse=0;
    int prs=0;
    for(int v=0; v<nbre_de_vues_circuits; v++)
    {
        if(Channel_View_MODE[v]==1)
        {
            for(int c=0; c<channel_number_in_View[v]; c++)
            {
                if(Channel_View_ROUTING[v][c]==idch)
                {
                    reponse=1;
                    prs=v;
                    break;
                }
            }
        }
        if(reponse==1)
        {
            break;
        }
    }
    return(prs);

}
