int prepare_crossfade()
{
    if(crossfade_speed<64)
    {
        fraction_X2_in= 255.0/ (Times_Memoires[position_preset][1]*(((float)BPS_RATE)*(64.0/crossfade_speed)));
        fraction_X1_out=  255.0/ (Times_Memoires[position_preset][3]*(((float)BPS_RATE)*(64.0/crossfade_speed)));
        crossfade_time_delay_in=(int)(Times_Memoires[position_preset][0]*(((float)BPS_RATE)*(64.0/crossfade_speed)));
        crossfade_time_delay_out=(int)(Times_Memoires[position_preset][2]*(((float)BPS_RATE)*(64.0/crossfade_speed)));
    }
    else if(crossfade_speed==64)
    {
        fraction_X2_in= 255.0/ (Times_Memoires[position_preset][1]*BPS_RATE);
        fraction_X1_out= 255.0/ (Times_Memoires[position_preset][3]*BPS_RATE);
        crossfade_time_delay_in=(int) (Times_Memoires[position_preset][0]*BPS_RATE);
        crossfade_time_delay_out=(int)(Times_Memoires[position_preset][2]*BPS_RATE);
    }
    else if(crossfade_speed>64)
    {
        fraction_X2_in= 255.0/ ((Times_Memoires[position_preset][1]- ( (Times_Memoires[position_preset][1] /64) * (crossfade_speed-63)))*BPS_RATE); //-62 evite un passage de temps pas bon, cf curseur
        fraction_X1_out=  255.0/ ((Times_Memoires[position_preset][3]- ( (Times_Memoires[position_preset][3] /64) * (crossfade_speed-63)))*BPS_RATE);
        crossfade_time_delay_in= (int) ((Times_Memoires[position_preset][0]- ( (Times_Memoires[position_preset][0] /64) * (crossfade_speed-63)))*BPS_RATE); //-62 evite un passage de temps pas bon, cf curseur
        crossfade_time_delay_out= (int) ((Times_Memoires[position_preset][2]- ( (Times_Memoires[position_preset][2] /64) * (crossfade_speed-63)))*BPS_RATE);
    }


    return(0);
}
