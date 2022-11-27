int ArtDmx()
{
    //preparation pour tests
    for (int i=0; i<7; i++)
    {
        ArtDmxBuffer[i]=ArtNetHead[i];
    }
    //Opcode low byte first
    unsigned char OpHbyteSend=(unsigned  char) (OpOutput>>8);
    unsigned char OpLbyteSend= (unsigned char) (OpOutput);
    ArtDmxBuffer[8]=OpLbyteSend;
    ArtDmxBuffer[9]=OpHbyteSend;
    //protocole
    ArtDmxBuffer[10]=0;
    ArtDmxBuffer[11]=14;
    //pas de sequence
    ArtDmxBuffer[12]=0;
    //physical
    ArtDmxBuffer[13] = 0;
    // universe (two bytes)
    unsigned char UHbyte=(unsigned  char) (Univers>>8);
    unsigned char ULbyte= (unsigned char) (Univers);
    ArtDmxBuffer[14]=ULbyte;//ou 0
    ArtDmxBuffer[15]=UHbyte;
    //data length
    unsigned char DHbyte=(unsigned  char) (DataLength>>8);
    unsigned char DLbyte= (unsigned char) (DataLength);
    ArtDmxBuffer[16] = DHbyte;
    ArtDmxBuffer[17] = DLbyte;

    for (int t=HeaderLength+1; t<Dim; t++)
    {
        ArtDmxBuffer[t]=DmxBlock[t-HeaderLength];
    }

    return(0);
}
