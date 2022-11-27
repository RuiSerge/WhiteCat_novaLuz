int fermeture_clientserveur_iCat()
{
    shutdown(sockRiCat,2);
    closesocket(sockRiCat);
    sprintf(string_Last_Order,">>Closed Fantastick server");
    iCat_serveur_is_initialized=0;

    if(client_icat_is_closed==0)
    {
        fermeture_client_iCat();
    }
    return(0);
}
