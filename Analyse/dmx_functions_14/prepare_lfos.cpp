int prepare_lfos(int cmptfader, int dksel)
{
if(lfo_speed[cmptfader]<64)
{
fraction_lfo_in[cmptfader]= 255.0/ (time_per_dock[cmptfader][dksel][1]*(((float)BPS_RATE)*(64.0/lfo_speed[cmptfader])));
fraction_lfo_out[cmptfader]=  255.0/ (time_per_dock[cmptfader][dksel][3]*(((float)BPS_RATE)*(64.0/lfo_speed[cmptfader])));
time_delay_in[cmptfader]=(int)(time_per_dock[cmptfader][dksel][0]*(((float)BPS_RATE)*(64.0/lfo_speed[cmptfader])));
time_delay_out[cmptfader]=(int)(time_per_dock[cmptfader][dksel][0]*(((float)BPS_RATE)*(64.0/lfo_speed[cmptfader])));
}
else if(lfo_speed[cmptfader]==64)
{
fraction_lfo_in[cmptfader]= 255.0/ (time_per_dock[cmptfader][dksel][1]*BPS_RATE);
fraction_lfo_out[cmptfader]= 255.0/ (time_per_dock[cmptfader][dksel][3]*BPS_RATE);
time_delay_in[cmptfader]=(int) (time_per_dock[cmptfader][dksel][0]*BPS_RATE);
time_delay_out[cmptfader]=(int)(time_per_dock[cmptfader][dksel][2]*BPS_RATE);
}
else if(lfo_speed[cmptfader]>64)
{
fraction_lfo_in[cmptfader]= 255.0/ (time_per_dock[cmptfader][dksel][1]*(((float)BPS_RATE*3)/(lfo_speed[cmptfader]-62))); //-62 evite un passage de temps pas bon, cf curseur
fraction_lfo_out[cmptfader]=  255.0/ (time_per_dock[cmptfader][dksel][3]*(((float)BPS_RATE*3)/(lfo_speed[cmptfader]-62)));
time_delay_in[cmptfader]= (int) (time_per_dock[cmptfader][dksel][0]*(((float)BPS_RATE*3)/(lfo_speed[cmptfader]-62))); //-62 evite un passage de temps pas bon, cf curseur
time_delay_out[cmptfader]= (int) (time_per_dock[cmptfader][dksel][2]*(((float)BPS_RATE*3)/(lfo_speed[cmptfader]-62)));
}

return(0);
}
