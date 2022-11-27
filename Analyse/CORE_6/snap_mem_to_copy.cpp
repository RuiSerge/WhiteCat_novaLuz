int snap_mem_to_copy()
{
    CTRLC_mem_to_copy=(int)(atof(numeric)*10.0001);
    sprintf(string_Last_Order,"Mem. To Copy: %d.%d", CTRLC_mem_to_copy/10,CTRLC_mem_to_copy%10);
    reset_numeric_entry();
    return(0);
}
