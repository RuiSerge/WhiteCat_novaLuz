int reset_launchpad()
{
    define_colors();
    send_my_midi_note(4,0,0,0,10);
    send_my_midi_note_delayed(4,0,0,1,10,10);
    launchpad_refresh_buffer_led();

    return(0);
}
