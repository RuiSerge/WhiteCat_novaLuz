int call_mem_onpreset()
{

    int mem_to_call=(int)(atof(numeric)*10.0001);
    if ( mem_to_call>10000)
    {
        sprintf(string_Last_Order,"a Mem can't be > to 1000");
    }
    else
    {
        if(MemoiresExistantes[mem_to_call]==0)
        {
            sprintf(string_Last_Order,"Mem %d.%d doesn't exist", mem_to_call/10,mem_to_call%10);
        }
        else if (MemoiresExistantes[mem_to_call]==1)
        {
            sprintf(string_Last_Order,"Loaded %d.%d on preset", mem_to_call/10,mem_to_call%10);
            position_preset=mem_to_call;
            refresh_mem_onpreset(position_preset);
            ratio_X1X2_together=ratio_cross_manuel[mem_to_call];
        }
    }
    reset_numeric_entry();
    someone_changed_in_sequences=1;//icat

    return(0);
}
