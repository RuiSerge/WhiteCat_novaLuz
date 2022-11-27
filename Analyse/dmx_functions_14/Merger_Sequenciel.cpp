int Merger_Sequenciel()
{
for (int p=1;p<514;p++)
{
 if (bufferSaisie[p]==bufferBlind[p])
 {
  bufferSequenciel[p]=bufferBlind[p];
 }
 else if(bufferSaisie[p]>bufferBlind[p])
 {
 bufferSequenciel[p]=
 bufferBlind[p]+(unsigned char)(((float)(bufferSaisie[p]-bufferBlind[p])/255)*niveauX1);
 }
 else if(bufferSaisie[p]<bufferBlind[p])
 {
 bufferSequenciel[p]=
 bufferSaisie[p]+(unsigned char)(((float)(bufferBlind[p]-bufferSaisie[p])/255)*niveauX2);
 }
 if(index_crossfading==1 || index_pause==1)
 {
 if((bufferSequenciel[p]+ channel_level_mofification_while_crossfade[p]>=0) && (bufferSequenciel[p]+ channel_level_mofification_while_crossfade[p]<=255))
 {bufferSequenciel[p]+=channel_level_mofification_while_crossfade[p];}
 else if (bufferSequenciel[p]+ channel_level_mofification_while_crossfade[p]>255){bufferSequenciel[p]=255;}
 else if (bufferSequenciel[p]+ channel_level_mofification_while_crossfade[p]<0){bufferSequenciel[p]=0;}
 }
}
return(0);
}
