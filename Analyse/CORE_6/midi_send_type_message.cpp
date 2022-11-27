int midi_send_type_message(int msgmidi)
{
    MidiEvPtr eIMid;
    if ((eIMid = MidiNewEv(msgmidi)))
    {
        Port(eIMid) = 0;
        /*Chan(eIMid) = 0;
        Pitch(eIMid)= 0;
        Vel(eIMid)  = 0;*/
        MidiSendIm(myRefNum, eIMid);
    }
    return(0);
}
