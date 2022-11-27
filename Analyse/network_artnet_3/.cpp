int ConstructArtPollReply ()//size 250
{

 for (int i=0;i<7;i++)
 {
 ArtPollReplyBuffer[i]=ArtNetHead[i];
 }
 //opérateur
  unsigned char OpPollRHbyte=(unsigned  char) (OpPollReply>>8);
  unsigned char OpPollRLbyte= (unsigned char) (OpPollReply);
 ArtPollReplyBuffer[8]=OpPollRLbyte;
 ArtPollReplyBuffer[9]=OpPollRHbyte;
 //adresse ethernet de cette machine
 ArtPollReplyBuffer[10]=(unsigned char)my_ip_is[0];
 ArtPollReplyBuffer[11]=(unsigned char)my_ip_is[1];
 ArtPollReplyBuffer[12]=(unsigned char)my_ip_is[2];
 ArtPollReplyBuffer[13]=(unsigned char)my_ip_is[3];
 //2 bytes pour le port artnet
 ArtPollReplyBuffer[14]= (unsigned char)(clientport_artnet);
 ArtPollReplyBuffer[15]= (unsigned char)(clientport_artnet>>8);

ArtPollReplyBuffer[16]=0;
ArtPollReplyBuffer[17]=14;
ArtPollReplyBuffer[18]=0;
ArtPollReplyBuffer[19]=0; //Sub NET (0-15)
ArtPollReplyBuffer[20]=(unsigned char)(OemUser>>8);
ArtPollReplyBuffer[21]=(unsigned char)(OemUser);

ArtPollReplyBuffer[22]=0;//none

ArtPollReplyBuffer[23]=0;

ArtPollReplyBuffer[24]=0;
ArtPollReplyBuffer[25]=0;
for (int i=26;i<(26+ShortNameLength-1);i++)// le petit nom fait 18
{
 ArtPollReplyBuffer[i]= ArtShortName[(i-26)]  ;
}
for (int it=44;it<(44+LongNameLength-1);it++)// le petit nom fait 64
{
 ArtPollReplyBuffer[it]= ArtLongName[(it-44)]  ;
}
for (int it=108;it<(108+NodeReportLength-1);it++)// le node report fait 64
{
 ArtPollReplyBuffer[it]= ArtNodeReport[(it-108)]  ;
}
ArtPollReplyBuffer[172]=0; //hi
ArtPollReplyBuffer[173]=4; //low If num i/p ports is dif to output ports, return biggest
ArtPollReplyBuffer[174]=0;//port 1 type
ArtPollReplyBuffer[175]=0;//port 2 type
ArtPollReplyBuffer[176]=0;//port 3 type
ArtPollReplyBuffer[177]=0;//port 4 type
ArtPollReplyBuffer[178]=0;//port 1 type
ArtPollReplyBuffer[179]=0;//port 2 type
ArtPollReplyBuffer[180]=0;//port 3 type
ArtPollReplyBuffer[181]=0;//port 4 type
ArtPollReplyBuffer[182]=0;//port 1 type
ArtPollReplyBuffer[183]=0;//port 2 type
ArtPollReplyBuffer[184]=0;//port 3 type
ArtPollReplyBuffer[185]=0;//port 4 type
ArtPollReplyBuffer[186]=0;//port 1 type
ArtPollReplyBuffer[187]=0;//port 2 type
ArtPollReplyBuffer[188]=0;//port 3 type
ArtPollReplyBuffer[189]=0;//port 4 type
ArtPollReplyBuffer[190]=0;//port 1 type
ArtPollReplyBuffer[191]=0;//port 2 type
ArtPollReplyBuffer[192]=0;//port 3 type
ArtPollReplyBuffer[193]=0;//port 4 type
ArtPollReplyBuffer[194]=0;
ArtPollReplyBuffer[195]=0;
ArtPollReplyBuffer[196]=0;
ArtPollReplyBuffer[197]=0;
ArtPollReplyBuffer[198]=0;
ArtPollReplyBuffer[199]=0;

ArtPollReplyBuffer[200]=StyleServer;
ArtPollReplyBuffer[201]=0;
ArtPollReplyBuffer[202]=0;
ArtPollReplyBuffer[203]=0;
ArtPollReplyBuffer[204]=0;
ArtPollReplyBuffer[205]=0;
ArtPollReplyBuffer[206]=0;

for (int fill=207;fill<(207+32);fill++)
{ArtPollReplyBuffer[fill]=0;}
ArtPollReplyBuffer[239]=255;

return(0);
}
