int QuitMidi()
{
    MidiFreeFilter(myFilter);
    //midi driver
    //MidiUnregisterDriver(myRefnum);
    MidiClose(myRefNum);
    return ( 0);
}
