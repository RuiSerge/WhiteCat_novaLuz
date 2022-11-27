int curve_draw_splines()
{
    int io;
    curve_nodes[0] = dummy_curve_node(curve_nodes[curve_node_count+1], curve_nodes[curve_node_count]);//curve_node et previous
    for (io=1; io<curve_node_count-1; io++)
    {
        curve_nodes[io].x=(curve_ctrl_pt[curve_selected][io][0]+xpatch_window+30+455);
        curve_nodes[io].y=(curve_ctrl_pt[curve_selected][io][1]+ypatch_window+50);
        draw_curve_node(io);
    }

    return(0);
}
