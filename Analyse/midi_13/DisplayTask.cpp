pascal void DisplayTask (short ref)
{

    long n;

    n= MidiCountEvs(ref);
    while (n > 16)
    {
        MidiFreeEv (MidiGetEv (ref));
        n--;
    }
    while (n--)
    {
        Display (MidiGetEv (ref));
    }
}
