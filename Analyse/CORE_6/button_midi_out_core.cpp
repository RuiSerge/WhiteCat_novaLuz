int button_midi_out_core(int xmi, int ymi, int control)
{
    if(mouse_x>xmi-10 && mouse_x<xmi+10  && mouse_y>ymi-10 && mouse_y<ymi+10)
    {
        midi_send_out[control]=toggle(midi_send_out[control]);
        mouse_released=1;
    }
    return(0);
}
