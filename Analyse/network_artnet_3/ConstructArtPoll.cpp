int ConstructArtPoll()
{
 for (int i=0;i<7;i++)
 {
 ArtPollBuffer[i]=ArtNetHead[i];
 }
 //opérateur
  //Opcode low byte first
  unsigned char OpPollHbyteSend=(unsigned  char) (OpPoll>>8);
  unsigned char OpPollLbyteSend= (unsigned char) (OpPoll);
  ArtPollBuffer[8]=OpPollLbyteSend;
  ArtPollBuffer[9]=OpPollHbyteSend;
 //protocole
  ArtPollBuffer[10]=0;
  ArtPollBuffer[11]=14;
  //talk to me
  //ArtPollBuffer[12]=0;
  ArtPollBuffer[12]=0x00000001;//ook
 // ArtPollBuffer[12]=0x00000011;
  // bit 0 = not used
  //   Prev def was bit 0 = 0 if reply is broadcast
  // 	            bit 0 = 1 if reply is to server IP
  // All replies are noe broadcast as this feature caused too many
  // tech support calls
  // bit 1 = 0 then Node only replies when polled
  // bit 1 = 1 then Node sends reply when it needs to

  //filler ending packet
  ArtPollBuffer[13]=0;
  return(0);
}
