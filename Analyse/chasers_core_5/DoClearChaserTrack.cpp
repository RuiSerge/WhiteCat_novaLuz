int DoClearChaserTrack(int numchaser, int numtrack)
{
 for (int dc=1;dc<514;dc++)
 {
 TrackContains[numchaser][numtrack][dc]=0;//nettoyage du fader
 }
 for(int p=0;p<nbre_de_cases_par_track;p++)
 {
 chaser_step_operation[numchaser][numtrack][p]=0;
 track_is_on[numchaser][numtrack]=1;
 track_level[numchaser][numtrack]=127;
 TrackTypeIs[numchaser][numtrack]=0;
 strcpy(chaser_track_name[numchaser][numtrack],"");
 }
sprintf(string_Last_Order,">> Cleared Track %d Chaser %d",numtrack+1,numchaser+1);
 return(0);
}
