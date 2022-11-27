int arduino_read()
{
    if(arduino_device_0_is_ignited==1)
    {
        for(int y=0; y<=arduino_max_digital; y++)
        {
            previous_digital_data_from_arduino[y]=digital_data_from_arduino[y];
        }

        unsigned char arduino_order[8];
        arduino_order[0]='S';
        arduino_order[1]='D';
        arduino_order[2]='/';
        arduino_order[3]='\0';


        nBytesSendtoArduino=serial0.SendData(arduino_order,4);

        nBytesReadArduino0=serial0.ReadData(input_str_arduino,digital_limit);
        new_arduino_decode_array_method(input_str_arduino);
    }
    return(0);
}
