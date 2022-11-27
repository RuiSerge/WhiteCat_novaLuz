int arduino_init(int device)
{
    if(device==0)
    {
        if(serial0.Open(arduino_com0,arduino_baud_rate0))
        {
            sprintf(string_Arduino_status,">> Open Arduino on PORT %d rate: %d >> OK !",arduino_com0,arduino_baud_rate0);
            arduino_device_0_is_ignited=1;
        }
        else
        {
            sprintf(string_Arduino_status,">> Open Arduino on PORT %d >> FAILED !",arduino_com0);
            arduino_device_0_is_ignited=0;
        }
    }
    return(0);
}
