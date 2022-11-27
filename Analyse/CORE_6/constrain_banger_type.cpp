int constrain_banger_type(int lp)
{
    if(bangers_type[index_banger_selected][lp]>19)
    {
        bangers_type[index_banger_selected][lp]=0;
    }
    return(0);
}
