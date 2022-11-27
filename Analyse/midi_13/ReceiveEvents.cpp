pascal void MSALARMAPI ReceiveEvents(short r)
{
    MidiEvPtr ev;
    while ( (ev=MidiGetEv(r)) )
    {
        Display(ev);
    }

}
