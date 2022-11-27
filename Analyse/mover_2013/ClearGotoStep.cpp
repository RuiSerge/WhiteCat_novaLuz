int ClearGotoStep(int move_selected)
{
 GotoMoves[move_selected][dock_move_actual_step[move_selected]]=0;
 return(0);
}
