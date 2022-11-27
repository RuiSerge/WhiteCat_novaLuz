int send_immidiateley_my_midi_cc( int letype,  int lechannel, int lanote, int lavelocite)
{
    MidiEvPtr eIMid;

    if ((eIMid = MidiNewEv(letype)))
    {
        Port(eIMid) = 0;
        Chan(eIMid) = lechannel;
        Pitch(eIMid)= lanote;
        Vel(eIMid)  = lavelocite;
        //Dur(eIMid)= 10;
        MidiSendIm(myRefNum, eIMid);
    }

    return(0);
}
