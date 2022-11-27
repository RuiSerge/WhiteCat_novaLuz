int DoDockChaserTrack(int numchaser, int numtrack)
{

 if(numeric_postext==0)//si pas de chaine de caracteres tapés
 {
 TrackTypeIs[numchaser][numtrack]=0;//le type est 0, circuits normaux
 if(index_blind==0)
 {
 for (int dc=1;dc<514;dc++)
 {
 TrackContains[numchaser][numtrack][dc]=0;//nettoyage du fader
 TrackContains[numchaser][numtrack][dc]=bufferSequenciel[dc];
 //rajout
 Selected_Channel[dc]=0;
 }
 index_do_dock=0;
 sprintf(string_Last_Order,">>n Stage Stored in Chaser %d Track %d",numchaser+1, numtrack+1);
 }

 else if(index_blind==1)
 {
 for (int dc=1;dc<514;dc++)
 {
 TrackContains[numchaser][numtrack][dc]=bufferBlind[dc];
 }
 index_do_dock=0;
 sprintf(string_Last_Order,">>n Preset Stored in Chaser %d Track %d",numchaser+1, numtrack+1);
 }
 }
 else if (numeric_postext>0)
 {
 int mem_to_load_in_chaser= (int)(atof(numeric)*10.0001);
 if(MemoiresExistantes[mem_to_load_in_chaser]==1)
 {
 DoClearChaserTrack(numchaser,numtrack);
 TrackTypeIs[numchaser][numtrack]=1;
 mem_to_load_in_chaser= (int)(atof(numeric)*10.0001);
 TrackHasMem[numchaser][numtrack]=mem_to_load_in_chaser;
 sprintf(chaser_track_name[numchaser][numtrack],descriptif_memoires[mem_to_load_in_chaser]);
 reset_numeric_entry();
 sprintf(string_Last_Order,">>n Stored Mem %.1f in Chaser %d Track %d",(float (mem_to_load_in_chaser))/10,numchaser+1,numtrack+1);
 mem_to_load_in_chaser= 0;
 }
 else
 {sprintf(string_Last_Order,">>n Mem %.1f doesn't exist",(float (mem_to_load_in_chaser))/10);  }

 }
 return(0);
}
