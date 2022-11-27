int check_if_dmx_change()
{
 for(int iop=0;iop<512;iop++)
 {
 if (artnet_backup[iop]!=DmxBlock[iop])
 {
 do_send_on_change=1;
 break;
 }
 }
 return(0);
}
