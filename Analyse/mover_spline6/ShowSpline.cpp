int ShowSpline(int move_selected)
{

    node_count=dock_moves_contains_steps[move_selected];
    curviness = ftofix(spline_ratio[move_selected]);
    calc_tangents();
    if(GotoMoves[move_selected][actual_step_node]==0 || index_move_back==1)
    {
        draw_splines(move_selected);
    }//l attribution des pas est fait dans drawsplines
    return(0);
}
