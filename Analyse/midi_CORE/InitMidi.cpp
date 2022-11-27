int InitMidi()
{
    /*if ( !MidiShare())
    {
    sprintf (string_Last_Order,"MidiShare not available\n");
    }
    InitTblLibEv();

    myRefNum = MidiOpen("WhiteCat"); //ouverture classique
    */
    /*		TDriverInfos infos = { "WhiteCat", 100, 0, { 0, 0 } };
    		TDriverOperation op = { WakeUp, Sleep, {0, 0 } };
    		myRefnum = MidiRegisterDriver(&infos, &op);*/

    /*if (myRefNum < 0) {sprintf(string_Last_Order,"MidiOpen failed!");}


    MidiSetRcvAlarm(myRefNum,ReceiveEvents);

    MidiConnect(0, myRefNum, true);//in
    MidiConnect(myRefNum,0,true);//out

    myFilter = MidiNewFilter();
    InstallFilter( myRefNum,myFilter ); //filtrage
    */
    if ( !MidiShare())
    {
        sprintf (string_Last_Order,"MidiShare not available\n");
    }
    InitTblLibEv();
    myRefNum = MidiOpen(AppliName);
    if (myRefNum < 0)
    {
        sprintf(string_Last_Order,"MidiOpen failed!");
    }

    MidiSetRcvAlarm(myRefNum,ReceiveEvents);
    MidiConnect(0, myRefNum, true);//in
    MidiConnect(myRefNum,0,true);//out
    myFilter = MidiNewFilter();
    InstallFilter( myRefNum,myFilter ); //filtrage


    return(0);
}
