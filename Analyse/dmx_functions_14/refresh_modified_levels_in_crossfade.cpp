int refresh_modified_levels_in_crossfade()
{
for(int i=0;i<513;i++)
{
if(bufferSaisie[i]+channel_level_mofification_while_crossfade[i]>255){bufferSaisie[i]=255;}
else if(bufferSaisie[i]+channel_level_mofification_while_crossfade[i]<0){bufferSaisie[i]=0;}
else {bufferSaisie[i]+=channel_level_mofification_while_crossfade[i];}
}
reset_modified_levels_in_crossfade();
return(0);
}
