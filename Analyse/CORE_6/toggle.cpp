int toggle (int index_to_toggle)
{
    switch(index_to_toggle)
    {
    case 0:
        index_to_toggle=1;
        break;
    case 1:
        index_to_toggle=0;
        break;
    default:
        index_to_toggle=0;
        break;
    }
    return(index_to_toggle);
}
