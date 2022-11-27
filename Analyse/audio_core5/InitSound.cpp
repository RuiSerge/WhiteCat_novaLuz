int InitSound()
{
  ShowSupportedAudioDevices();
  device=OpenDevice(0);// s ouvre automatiquement en winmm

  if (!device) {
    sprintf (string_Last_Order,"No Sound Device available !");
  }
else
  {  //affiche le device
  sprintf(audio_device_name,device->getName());
  }


 for(int i=0;i<4;i++)
 {
 player_pitch[i]=64;
 player_pan[i]=64;
 player_niveauson[i]=127;
 audio_rate[i]=44100;
 }


 return(0);
}
