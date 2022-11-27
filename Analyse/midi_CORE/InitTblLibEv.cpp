int InitTblLibEv() {
int InitTblLibEv() {
  int i;

  for (i=0;i<255;i++) strcpy(TblLibEv[i],"");

  strcpy(TblLibEv[typeNote],		 "Note        ");
  strcpy(TblLibEv[typeKeyOn],		 "Key On      ");
  strcpy(TblLibEv[typeKeyOff],		 "Key Off     ");
  strcpy(TblLibEv[typeKeyPress],	 "Key Press   ");
  strcpy(TblLibEv[typeCtrlChange],	 "Ctrl Change ");
  strcpy(TblLibEv[typeProgChange],	 "Prog Change ");
  strcpy(TblLibEv[typeChanPress],	 "Chan Press  ");
  strcpy(TblLibEv[typePitchWheel],	 "Pitch Wheel ");
  strcpy(TblLibEv[typeSongPos],	 	 "SongPos     ");
  strcpy(TblLibEv[typeSongSel],	 	 "SongSel     ");
  strcpy(TblLibEv[typeClock],		 "Clock       ");
  strcpy(TblLibEv[typeStart],		 "Start       ");
  strcpy(TblLibEv[typeContinue],	 "Continue    ");
  strcpy(TblLibEv[typeStop],		 "Stop        ");
  strcpy(TblLibEv[typeTune],		 "Tune        ");
  strcpy(TblLibEv[typeActiveSens],	 "Active Sens.");
  strcpy(TblLibEv[typeReset],		 "Reset       ");
  strcpy(TblLibEv[typeSysEx],		 "System Excl.");
  strcpy(TblLibEv[typeStream],		 "Stream      ");
  strcpy(TblLibEv[typePrivate],	 	 "Private     ");
  strcpy(TblLibEv[typeProcess],	  	 "Process     ");
  strcpy(TblLibEv[typeDProcess],	 "DProcess    ");
  strcpy(TblLibEv[typeQuarterFrame], "QuarterFrame");
  strcpy(TblLibEv[typeCtrl14b],	 	 "Ctrl 14bits ");
  strcpy(TblLibEv[typeNonRegParam],  "NonRegParam.");
  strcpy(TblLibEv[typeRegParam],	 "Reg Param   ");
  strcpy(TblLibEv[typeSeqNum],		 "Seq Number  ");


  strcpy(TblLibEv[typeTextual],	 	 "Text        ");

  strcpy(TblLibEv[typeCopyright],	 "Copyright   ");
  strcpy(TblLibEv[typeSeqName],	 	 "Seq Name    ");
  strcpy(TblLibEv[typeInstrName],	 "Instr Name  ");
  strcpy(TblLibEv[typeLyric],		 "Lyric       ");
  strcpy(TblLibEv[typeMarker],		 "Marker      ");
  strcpy(TblLibEv[typeCuePoint],	 "CuePoint    ");
  strcpy(TblLibEv[typeChanPrefix],	 "Chan Prefix ");
  strcpy(TblLibEv[typePortPrefix],	 "Port Prefix ");
  strcpy(TblLibEv[typeEndTrack],	 "End Track   ");
  strcpy(TblLibEv[typeTempo],		 "Tempo       ");
  strcpy(TblLibEv[typeSMPTEOffset],  "SMPTE Offset");
  strcpy(TblLibEv[typeTimeSign],	 "Time Sign.  ");
  strcpy(TblLibEv[typeKeySign],	 	 "Key Sign.   ");
  strcpy(TblLibEv[typeSpecific],	 "Specific    ");
  strcpy(TblLibEv[typeReserved],	 "Reserved    ");
  strcpy(TblLibEv[typeDead],		 "Dead        ");
return(0);
}
