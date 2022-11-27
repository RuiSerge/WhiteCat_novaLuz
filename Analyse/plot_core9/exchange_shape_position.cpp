int exchange_shape_position(int pos_source, int pos_dest)
{
copy_shape_to_emply_slot( pos_dest, pos_source);
copy_shape_to_emply_slot( pos_source, pos_dest);
return(0);
}
