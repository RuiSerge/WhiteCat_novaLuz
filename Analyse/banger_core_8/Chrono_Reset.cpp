int Chrono_Reset()
{
 actual_tickers_chrono=0;
 time_minutes=0;
 time_secondes=0;
 time_centiemes=0;

 angle_timesnap_min=0.0;
angle_timesnap_sec=0.0;
angle_timesnap_dix=0.0;
set_time_cursor_to_time_type(time_wheel_datatype_is);

 return(0);
}
