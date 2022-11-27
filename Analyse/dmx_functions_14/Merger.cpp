int Merger()
{
 //rafraichissement visuel, pour pb de synchro entre calculs et rapidité affichage mis en amont d une frame
 for (int i=1;i<514;i++)
 {
 buffer_affichage_valeurs_sequenciel[i]=bufferSequenciel[i];
 }

 if(core_do_calculations[1]==1)
 {
 Merger_Sequenciel();
 }
 if(core_do_calculations[0]==1)
 {
 calculs_etats_faders_et_contenus();//contenus fader par fader
 Merger_Faders();//buffer fader general
 }

 int circrootpatch=0;
 for (int i=1;i<514;i++)
 {
 switch(freeze_array[i])
 {
 case 0:
 MergerArray[i]= Tmax (bufferSequenciel[i],bufferFaders[i]);
 //MASTER
 if(Channels_excluded_from_grand_master[i]==0)
 {
 MergerArray[i]=(int)(((float)(MergerArray[i])/255)*niveauGMaster);
 }
 break;
 case 1:
 MergerArray[i]=freeze_state[i];
 break;
 default: break;
 }

 //go et pause channel
 if(index_go==1 && index_pause==0 && go_channel_is>0 && go_channel_is<513)
 {
  bufferSequenciel[go_channel_is]=(unsigned char) (255* alpha_blinker);
  MergerArray[go_channel_is]=(unsigned char)(255* alpha_blinker);
 }

  if(index_go==1 && index_pause==1 && pause_channel_is>0 && pause_channel_is<513)
 {
  bufferSequenciel[pause_channel_is]=(unsigned char) (255* alpha_blinker);
  MergerArray[pause_channel_is]=(unsigned char)(255* alpha_blinker);
 }

 if(index_go==0 && index_pause==0 )
 {
 if(go_channel_is>0 && go_channel_is<513)
 {bufferSequenciel[go_channel_is]=0;
  MergerArray[go_channel_is]=0;}
 if(pause_channel_is>0 && pause_channel_is<513)
  {bufferSequenciel[pause_channel_is]=0;
  MergerArray[pause_channel_is]=0;}
 }

 //Patch
 circrootpatch=Patch[i];
 DmxBlockPatch[i]=(MergerArray[circrootpatch]);

 //Curve
 for(int courb=0;courb<16;courb++)
 {
 if(curves[i]==courb)
 {
 DmxBlock[i]=255-curve_report[courb][(DmxBlockPatch[i])];
 }
 }


 //check channel override la sortie
 if(index_patch_overide==1)
 {
 if(patch_overide[i]==1){DmxBlock[i]=dimmer_check_level;}//75%
 }

 }
 return(0);
}
