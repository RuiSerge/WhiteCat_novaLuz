int DoReportChaserTrack(int numchaser, int numtrack)
{
 for (int u=1;u<514;u++)
 {
 TrackContains[numchaser][numtrack][u]=bufferSaisie[u];
 if(bufferFaders[u]>TrackContains[numchaser][numtrack][u]){TrackContains[numchaser][numtrack][u]=bufferFaders[u];}
 }
 for (int x=1;x<514;x++)
 {
 bufferSaisie[x]=0;
 bufferBlind[x]=0;
 Selected_Channel[x]=0;
 }

 for (int fder=0;fder<48;fder++)
 {
 if(view_chaser_affected_to_fader[numchaser][0]!=fder)
 {
 Fader[fder]=0;
 }
 }


 return(0);
}
