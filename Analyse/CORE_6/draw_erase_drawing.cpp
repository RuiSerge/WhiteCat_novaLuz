int draw_erase_drawing(int p)
{
    for(int ch=0; ch<500; ch++)
    {
        draw_preset_levels[p][ch]=0.0;
    }
    sprintf(string_Last_Order,"Erased Drawing %d",p+1);
    return(0);
}
