int init_artnet_variables()
{

 OpHbyteReceive=(unsigned  char) (OpOutput>>8);
 OpLbyteReceive= (unsigned char) (OpOutput);
 OpPollRHbyte=(unsigned  char) (OpPollReply>>8);
 OpPollRLbyte= (unsigned char) (OpPollReply);
 OpPollHbyte=(unsigned  char) (OpPoll>>8);
 OpPollLbyte=OpPoll;
 return(0);
}
