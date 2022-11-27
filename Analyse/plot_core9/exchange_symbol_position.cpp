int exchange_symbol_position(int calc,int pos_source, int pos_dest)
{


    int source_link_to=snapshot_symbol_is_linked_to[pos_source];
    int dest_link_to=snapshot_symbol_is_linked_to[pos_dest];

    copy_symbol_to_emply_slot(calc, pos_dest, pos_source);//(int calc, int empty, int filled)
    copy_symbol_to_emply_slot(calc, pos_source, pos_dest);

    symbol_is_linked_to[calc][pos_dest]=source_link_to;
    symbol_is_linked_to[calc][pos_source]=dest_link_to;



    snapshot_calc(calc);
    return(0);
}
