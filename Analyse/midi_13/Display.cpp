pascal void Display ( MidiEvPtr e)
{

    //sab 02/03/2014 unused var char s[120];

    if (e)
    {
        EvAquire (e);

        MidiFreeEv(e);
    }
}
