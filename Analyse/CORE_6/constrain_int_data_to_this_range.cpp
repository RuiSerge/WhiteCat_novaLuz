int constrain_int_data_to_this_range(int data, int min, int max)
{
    if(data<min)
    {
        data=min;
    }
    if(data>max)
    {
        data=max;
    }
    return(data);
}
