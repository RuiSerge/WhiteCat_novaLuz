short midi_send_program_change(int lechannel, short prg_)
{
    MidiEvPtr eMid;
    if ((eMid = MidiNewEv(typeProgChange)))
    {
        Port(eMid) = 0;
        Chan(eMid) = lechannel;
        MidiSetField(eMid,0,prg_);
        MidiSendIm(myRefNum, eMid);

    }
    return(0);
}
