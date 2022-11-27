int recall_fader_state_echo(int f)
{
    Fader[f]=fader_before_bounce[f];
    return(0);
}
