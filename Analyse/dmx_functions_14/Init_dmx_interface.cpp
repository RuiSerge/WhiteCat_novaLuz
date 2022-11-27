int Init_dmx_interface()
{
for(int i=0;i<NB_INTERFACES;i++)
{
    if(do_DMX_out[i]==1)
    {
     Init_A_specific_dmx_interface(i);
    }
}
return(0);
}
