int Close_dmx_interface()
{
for(int i=0;i<NB_INTERFACES;i++)
{
    if(do_DMX_out[i]==1)
    {
     Close_A_specific_dmx_interface(i);
    }
}

if (index_init_EnttecPROIN_ok==1){Close_ProIn();}
return(0);
}
