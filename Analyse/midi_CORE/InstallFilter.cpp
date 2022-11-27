pascal void InstallFilter( short refNum, MidiFilterPtr filter )
{
     	short i;

    if (!myFilter) return;
	for (i = 0 ; i < 256 ; i++ )
	{
	 	MidiAcceptType(myFilter,i,false);
		MidiAcceptPort(myFilter,i,true);
	}
	for (i = 0 ; i < 16 ; i++ ) MidiAcceptChan(myFilter,i,true);

	MidiAcceptType(myFilter,typeKeyOn, true);
	MidiAcceptType(myFilter,typeKeyOff, true);
	MidiAcceptType(myFilter,typeCtrlChange, true);
 	MidiAcceptType(myFilter,typePitchWheel, true);
 	MidiAcceptType(myFilter,typeProgChange, true);
 	//midi clock
    MidiAcceptType(myFilter, typeStop, true);*/
    //Notes off Note On pour Twister
    MidiAcceptType(myFilter,NoteOff , true);
    MidiAcceptType(myFilter,NoteOn , true);

	MidiSetFilter(refNum, myFilter);
}
