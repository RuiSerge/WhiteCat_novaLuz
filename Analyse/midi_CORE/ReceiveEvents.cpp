pascal void MSALARMAPI ReceiveEvents(short r);
{
for(int i=0;i<48;i++)//faders
{
midi_needs_no_key_on_key_off[900+i]=1;
}
return(0);
}
