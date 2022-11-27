int launchpad_set_bool_value(int control,int value)
{
if(value==0)
{midi_launchpad_state[control]=0;}
else if(value>0) {midi_launchpad_state[control]=1;}
return(0);
}
