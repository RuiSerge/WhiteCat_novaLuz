int fermeture_client_iCat()
{

    shutdown(sockiCat,2);
    closesocket(sockiCat);
    sprintf(string_Last_Order,">>Closed Fantastick Client");
    client_icat_is_closed=1;
    return(0);
}
