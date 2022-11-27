int do_direct_channel(int fad,int dk)
{
if(numeric_postext>0)
{
last_ch_selected=atoi(numeric);
reset_numeric_entry();
numeric_postext=0;
}

if(last_ch_selected>0 && last_ch_selected<513)
{
ClearDock(fad,dk);
switch(multiple_direct_chan)
{
case 0:
DockTypeIs[fad][dk]=10;//direct channel mode
FaderDirectChan[fad][dk]=last_ch_selected;
sprintf( DockName[fad][dk], descriptif_projecteurs[last_ch_selected]);
sprintf(string_Last_Order,">>Direct Channel x1 done");
break;
case 1:
for(int l=0;l<12;l++)
{
if(fad+l<core_user_define_nb_faders)
{
DockTypeIs[fad+l][dk]=10;//direct channel mode
FaderDirectChan[fad+l][dk]=last_ch_selected+l;
sprintf( DockName[fad+l][dk], descriptif_projecteurs[last_ch_selected+l]);
}
}
sprintf(string_Last_Order,">>Direct Channel x12 done");
break;
default:
break;
}
}
else
{
sprintf(string_Last_Order,">>Direct Channel: Please select a channel !");
}
return(0);
}
