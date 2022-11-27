int Prepare_Cross_Spline(int move_selected)
{
    int points[8];

    actual_step_node=dock_move_actual_step[move_selected];

    if(mover_params[0][0]!=(dock_move_xy[move_selected][actual_step_node][0]+xmover_window+20) || mover_params[1][0]!=(dock_move_xy[move_selected][actual_step_node][1]+ymover_window+20))
    {
        nodes[actual_step_node].x=mover_params[0][0]+xmover_window+20;
        nodes[actual_step_node].y=mover_params[1][0]+ymover_window+20;
    }



    next_step_node=next_step[move_selected];
    if(next_step_node>dock_moves_contains_steps[move_selected])
    {
        next_step_node=1;
    }
    nodes[next_step_node].x=(dock_move_xy[move_selected][next_step_node][0]+xmover_window+20);
    nodes[next_step_node].y=(dock_move_xy[move_selected][next_step_node][1]+ymover_window+20);


    //dans le cas d un goto
    if(GotoMoves[move_selected][actual_step_node]!=0 && index_move_forward==1)
    {
        numero_de_dock_goto_spline=GotoMoves[move_selected][actual_step_node];
        next_step_node=Moves_Inpoint[numero_de_dock_goto_spline];
        nodes[next_step_node].x=(dock_move_xy[numero_de_dock_goto_spline][next_step_node][0]+xmover_window+20);
        nodes[next_step_node].y=(dock_move_xy[numero_de_dock_goto_spline][next_step_node][1]+ymover_window+20);
        for(int ro=1; ro<dock_moves_contains_steps[numero_de_dock_goto_spline]; ro++)
        {
            if(ro!=actual_step_node)
            {
                nodes[ro].x=(dock_move_xy[numero_de_dock_goto_spline][ro][0]+xmover_window+20);
                nodes[ro].y=(dock_move_xy[numero_de_dock_goto_spline][ro][1]+ymover_window+20);
            }
        }
    }

    get_control_points(nodes[actual_step_node],nodes[next_step_node],points);


    if(index_move_back==1)
    {
        get_control_points_backward(nodes[actual_step_node],nodes[next_step_node],points);
    }
    calc_spline(points, SPLINE_MAX_RESOLUTION,  my_spline_path_X, my_spline_path_Y);

    actual_spline_tick=0.0;
    spline_tick_fraction=((float)SPLINE_MAX_RESOLUTION)/dock_time[dock_move_selected][(dock_move_actual_step[dock_move_selected])];
    return(0);
}
