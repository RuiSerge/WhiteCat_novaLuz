pascal void MSALARMAPI ReceivePolling ( long date, short r, long a, long b, long c)
{

    long n;

    n= MidiCountEvs (r);

    if (n)
    {
        DisplayTask(r);
        MidiTask (ReceivePolling, date+100, r, a, 0, 0);
    }
    else MidiSetRcvAlarm (r, ReceiveEvents);
}
