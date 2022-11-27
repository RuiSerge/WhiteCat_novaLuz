int init_kbd_custom()
{
    for(int i=0; i<256; i++)
    {
        kbd_custom[i][0]=i;
        kbd_custom[i][1]=0;
    }
    return(0);
}
