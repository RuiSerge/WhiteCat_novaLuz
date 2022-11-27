int midi_list_and_choose_devices()
{
    TDriverInfos infos;
    short ref, i, n = MidiCountDrivers();

    for( i = 1; i <= n; i++ )
    {
        ref = MidiGetIndDriver(i);
        if (MidiGetDriverInfos (ref, &infos )&& infos.slots>0)
        {
            PrintSlotsInfosDevices(ref);
        }
    }
    return(0);
}
