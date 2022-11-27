int Move_Autostop(int move_selected)
{
    if(move_auto_stop[move_selected][dock_move_actual_step[move_selected]]==0)
    {
        move_auto_stop[move_selected][dock_move_actual_step[move_selected]]=1;
    }
    else if (move_auto_stop[move_selected][dock_move_actual_step[move_selected]]==1)
    {
        move_auto_stop[move_selected][dock_move_actual_step[move_selected]]=0;
    }
    return(0);
}
