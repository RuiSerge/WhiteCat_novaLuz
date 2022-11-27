int  AnalyseArtPollReply()
{
index_show_artpoll_reply_content=1;
bool index_is_artnet=0;
bool index_is_artpollRep=0;


if( artpollreply_message[0]==ArtNetHead[0] && artpollreply_message[1]==ArtNetHead[1] && artpollreply_message[2]==ArtNetHead[2] && artpollreply_message[3]==ArtNetHead[3]
 && artpollreply_message[4]==ArtNetHead[4]  && artpollreply_message[5]==ArtNetHead[5]  && artpollreply_message[6]==ArtNetHead[6]  && artpollreply_message[7]==ArtNetHead[7] )
 {index_is_artnet=1;}



if(artpollreply_message[8]==OpPollRLbyte && artpollreply_message[9]==OpPollRHbyte)//L 8 H 9
{index_is_artpollRep=1;}


if(index_is_artnet==1 && index_is_artpollRep==1)
{
sprintf(string_Last_Order,">>Received ArtPollReply %d",count_artopoll_received);
count_artopoll_received++;

sprintf(nodefirmware_versinfo,"v.  %d . %d",(unsigned char) artpollreply_message[16],(unsigned char) artpollreply_message[17]);

sprintf(subnetis,"SubNet %d",(unsigned char) artpollreply_message[19]);


for (int ish=0;ish<18;ish++)
{shortname_device[ish]=artpollreply_message[26+ish];}


sprintf(PollReplyIs[count_artopoll_received],"-/IP %d  . %d . %d . %d  / %s / %s / %s",(unsigned char)artpollreply_message[10],(unsigned char)artpollreply_message[11],
(unsigned char)artpollreply_message[12],(unsigned char)artpollreply_message[13],shortname_device,subnetis,nodefirmware_versinfo);


}

return(0);
}
