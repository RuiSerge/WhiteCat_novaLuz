int draw_splines(int move_selected)
{
   int io;
     nodes[0] = dummy_node(nodes[node_count+1], nodes[node_count]);//node et previous
   for (io=1; io<node_count; io++)
   {
      nodes[io].x=(dock_move_xy[move_selected][io][0]+xmover_window+20);
      nodes[io].y=(dock_move_xy[move_selected][io][1]+ymover_window+20);
   }

   for (io=1; io<node_count-1; io++)
   {
    draw_spline(nodes[io], nodes[io+1]);
   }


  // goback to begin
  draw_spline(nodes[node_count], nodes[1]);

return(0);
}
