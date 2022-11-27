int arduino_merge_and_do_data_out()//refonte en un seul tableau d'envoi DIGITAUX + PWM
{

unsigned char arduino_order[8];
arduino_order[0]='S';arduino_order[1]='D';arduino_order[2]='/';arduino_order[3]='\0';
nBytesSendtoArduino=serial0.SendData(arduino_order,4);

unsigned char temp_send_arduino[(3+arduino_max_digital+3+1)];    //header/tableau/headerfin/return
for(int i=0;i<(3+arduino_max_digital+3+1);i++)
{
    temp_send_arduino[i]=1;//pour �viter tout caractere null cassant la chaine
}

temp_send_arduino[0]='D';temp_send_arduino[1]='O';temp_send_arduino[2]='/';

int value_dm=0;
switch(dmx_view)
{
case 0: value_dm=(int)(10*2.55); break;
case 1: value_dm=10; break;
default: break;
}


for(int p=0;p<=arduino_max_digital;p++)
{
    switch(arduino_digital_type[p])
    {
    case 2://si l'affectation est type  ON/OFF
    if(arduino_digital_function_output[p][0]==1) //CHANNEL >10
    {
    if(MergerArray[(arduino_digital_function_output[p][1])]>value_dm)
    {digital_data_to_arduino[p]=1;temp_send_arduino[3+p]=127;}
    else {digital_data_to_arduino[p]=0;temp_send_arduino[3+p]=32;}
    }
    else if(arduino_digital_function_output[p][0]==2 && arduino_digital_function_output[p][1]>0 && arduino_digital_function_output[p][1]<49) //Fader >10
    {
    if(Fader[(arduino_digital_function_output[p][1]-1)]>value_dm)
    {digital_data_to_arduino[p]=1;temp_send_arduino[3+p]=127;}
    else {digital_data_to_arduino[p]=0;temp_send_arduino[3+p]=32;}
    }
    break;

    case 3://si l'affectation est type  PWM
    //CHANNEL
    if(arduino_digital_function_output[p][0]==1 && arduino_digital_function_output[p][1]>0 && arduino_digital_function_output[p][1]<513)
    {
    pwm_data_to_arduino[p]=MergerArray[(arduino_digital_function_output[p][1])];
    temp_send_arduino[3+p]=pwm_data_to_arduino[p];
    if(temp_send_arduino[3+p]<=0) temp_send_arduino[3+p]=1;//eviter le caractere NULL
    }
    //FADER
    else if(arduino_digital_function_output[p][0]==2 && arduino_digital_function_output[p][1]>0 && arduino_digital_function_output[p][1]<49)
    {
    pwm_data_to_arduino[p]=(int)Fader[(arduino_digital_function_output[p][1])+1];
    temp_send_arduino[3+p]=pwm_data_to_arduino[p];
    if(temp_send_arduino[3+p]<=0) temp_send_arduino[3+p]=1;//eviter le caractere NULL
    }
    break;

    default://0 or input
    temp_send_arduino[3+p]=1;//�viter de casser la chaine avec un caractere null
    break;
    }
}



temp_send_arduino[(3+arduino_max_digital+1)]='E';
temp_send_arduino[(3+arduino_max_digital+2)]='D';
temp_send_arduino[(3+arduino_max_digital+3)]='/';
temp_send_arduino[(3+arduino_max_digital+4)]='\0';

nBytesSendtoArduino=serial0.SendData(temp_send_arduino,sizeof(temp_send_arduino));


return(0);
}
