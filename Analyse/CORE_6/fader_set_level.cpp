int fader_set_level(int cmptfader, int val)
{
switch(fader_damper_is_on[cmptfader])
{
case 0:
Fader[cmptfader]=val;
midi_levels[cmptfader]=(Fader[cmptfader]/2);
Fader_dampered[cmptfader].fix_all_damper_state_value(val);
Fader_dampered[cmptfader].set_target_val(val);
break;
case 1:
Fader_dampered[cmptfader].set_target_val(val);
index_fader_is_manipulated[cmptfader]=1;
break;
default:
break;
}

index_fader_is_manipulated[cmptfader]=1;midi_levels[cmptfader]=(Fader[cmptfader]/2);
if(midi_send_out[cmptfader]==1){ index_send_midi_out[cmptfader]=1;}
return(0);
}
