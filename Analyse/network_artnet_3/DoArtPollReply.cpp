 int  DoArtPollReply()
{
   nbrbytessended=sendto(sockartnet, ArtPollReplyBuffer,sizeof( ArtPollReplyBuffer),0,(SOCKADDR*)&sinS,sinsize);
   sprintf(string_Last_Order,">>Polled !");

   return(0);
}
