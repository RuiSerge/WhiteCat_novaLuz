int new_arduino_decode_array_method(unsigned char *tmp_ard)
{
int tmp_d=0;
if(tmp_ard[0]=='W' && tmp_ard[1]=='C' && tmp_ard[2]=='/' )//Whitecat keyboard
{

for(int o=0;o<=arduino_max_digital;o++)//OK
{
tmp_d=(int)tmp_ard[o+3];
if(tmp_d>64){digital_data_from_arduino[o]=1;}
else {digital_data_from_arduino[o]=0;}
}

for(int o=0;o<=arduino_max_analog;o++)//modif +1 3 mars 2016
{
switch(kalman_is_on[o])
{
    case 0:
        analog_data_from_arduino[o]=(int)(tmp_ard[3+o+arduino_max_digital+1]);
    break;
    case 1:
        analog_data_from_arduino[o]= Arduino_Kalman[o].kalmanUpdate(tmp_ard[3+o+arduino_max_digital+1]);
       // analog_data_from_arduino[o]= Arduino_Kalman[o].kalmanUpdate(analog_data_from_arduino[o]);//au carr�
    break;
}
}
sprintf( string_Arduino_status,">>ARDUINO : Received Data");

}


return(0);
}
