int ReceiveArtDmx()
{
 if( artnet_message[0]==ArtNetHead[0] && artnet_message[1]==ArtNetHead[1] && artnet_message[2]==ArtNetHead[2] && artnet_message[3]==ArtNetHead[3]
 && artnet_message[4]==ArtNetHead[4]  && artnet_message[5]==ArtNetHead[5]  && artnet_message[6]==ArtNetHead[6]  && artnet_message[7]==ArtNetHead[7] )
 {is_artnet=1;}

 if( OpLbyteReceive==artnet_message[8] && OpHbyteReceive==artnet_message[9]  )
  {
   is_opcode_is_dmx=1;
   //pour recup si besoin
   is_artnet_version_i1=artnet_message[10]; is_artnet_version_i2=artnet_message[11];
   seq_artnet=artnet_message[12];//0
   artnet_physical=artnet_message[13];//0
   }
 else if( artnet_message[8]==OpPollLbyte && artnet_message[9]==OpPollHbyte  )
  {
   is_opcode_is_polling=1;
  }

 if(is_artnet==1 && is_opcode_is_dmx==1 )
 {
 incoming_universe= bytes_to_short(artnet_message[15],artnet_message[14]);//extraction de l'univers
 index_do_light_diode_artnet=1;

 for (int    p=0;p<512;p++)
 {ArtNet_16xUniverse_Receiving[p+1][incoming_universe]=artnet_message[p+HeaderLength+1];}
  //reinit
 is_artnet=0;is_opcode_is_dmx=0; is_artnet_version_i1=0; is_artnet_version_i2=0;
 incoming_universe=999;//reinit hors écran

 }

 else if (is_artnet==1 && is_opcode_is_polling==1 )
 {
  DoArtPollReply();
  is_opcode_is_polling=0;is_artnet=0;
 }

 return(0);
}
