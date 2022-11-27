int MoveAffectGoto(int move_from, int move_to)
{
    GotoMoves[move_from][dock_move_actual_step[move_from]]=move_to;
    index_goto_record=0;
    return(0);
}
