int send_my_midi_note( int letype,  int lechannel, int lanote, int lavelocite, int laduree)
{
    MidiEvPtr eMid;
    if ((eMid = MidiNewEv(letype)))
    {
        Port(eMid) = 0;
        Chan(eMid) = lechannel;
        Pitch(eMid)= lanote;
        Vel(eMid)  = lavelocite;
        Dur(eMid)= laduree;
        MidiSendIm(myRefNum, eMid);

    }
    return(0);
}
