int SelectDmxDevice(int interfacedmx)
{
    do_DMX_out[interfacedmx]=toggle(do_DMX_out[interfacedmx]);
    switch(do_DMX_out[interfacedmx])
    {
    case 0:
        Close_A_specific_dmx_interface(interfacedmx);
        break;
    case 1:
        Init_A_specific_dmx_interface(interfacedmx);
        break;
    }
    return(0);
}
