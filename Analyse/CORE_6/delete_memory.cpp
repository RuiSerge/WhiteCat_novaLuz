int delete_memory(int mem_to_delete)
{
    sprintf(string_confirmation,"Delete Mem %d.%d ?", mem_to_delete/10,mem_to_delete%10);

    if (  mem_to_delete>10000)
    {
        sprintf(string_Last_Order,"a Mem to be deleted > to 1000");
    }
    else
    {
        if(MemoiresExistantes[mem_to_delete]==1)
        {
            MemoiresExistantes[mem_to_delete]=0;
            MemoiresDetruites[mem_to_delete]=1;
            sprintf(string_Last_Order,"Mem %d.%d deleted", mem_to_delete/10,mem_to_delete%10);
        }
        else if (MemoiresExistantes[mem_to_delete]==0)
        {
            sprintf(string_Last_Order,"Mem %d.%d do not exist", mem_to_delete/10,mem_to_delete%10);
        }
    }

    return(0);
}
