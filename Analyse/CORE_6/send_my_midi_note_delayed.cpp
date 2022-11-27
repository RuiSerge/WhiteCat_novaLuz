int send_my_midi_note_delayed( int letype,  int lechannel, int lanote, int lavelocite, int laduree, int delay)
{
    MidiEvPtr eMid;
    long  dt = MidiGetTime();
    if ((eMid = MidiNewEv(letype)))
    {
        Port(eMid) = 0;
        Chan(eMid) = lechannel;
        Pitch(eMid)= lanote;
        Vel(eMid)  = lavelocite;
        Dur(eMid)= laduree;
        MidiSendAt(myRefNum, MidiCopyEv(eMid), dt+delay);

    }
    return(0);
}
