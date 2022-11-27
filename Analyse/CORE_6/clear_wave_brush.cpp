int clear_wave_brush(int preset)
{
    for(int i=0; i<26; i++)
    {
        brush_slots[preset][i]=0.0;
    }
    return(0);
}
