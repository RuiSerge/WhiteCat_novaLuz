void ticker_arduino()
{
   ticks_arduino++;
   if(arduino_device_0_is_ignited==1 &&  ticks_arduino!= old_ticks_arduino
        && index_is_saving==0 && init_done==1 && index_writing_curve==0 &&  index_quit==0)
    {
    arduino_merge_and_do_data_out();
    arduino_read();//doit etre pos� apr�s data out
    serial0.Flush();
    old_ticks_arduino=ticks_arduino;
    arduino_do_digital_in_whitecat();arduino_do_analog_in_whitecat();
    }
}
