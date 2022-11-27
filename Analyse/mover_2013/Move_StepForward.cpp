int Move_StepForward(int move_selected)
{
    if (dock_move_actual_step[move_selected]<dock_moves_contains_steps[move_selected])
    {
        dock_move_actual_step[move_selected]++;
    }
    else if (dock_move_actual_step[move_selected]==dock_moves_contains_steps[move_selected])
    {
        dock_move_actual_step[move_selected]=1;
    }
    Move_refresh_xy(move_selected);
    return(0);
}
