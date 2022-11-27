std::vector<Kalman> Arduino_Kalman(analog_limit);
{

     if(index_midi_clock_on==1)
    {
    MidiEvPtr eMid;
    //long  dt = MidiGetTime();
    if ((eMid = MidiNewEv(typeClock)))
    {
        Port(eMid) = 0;
        Chan(eMid) = 0;
        Pitch(eMid)= 0;
        Vel(eMid)  = 0;
        Dur(eMid)= 0;
        MidiSendAt(myRefNum, MidiCopyEv(eMid), 0);

    }
    }
}
