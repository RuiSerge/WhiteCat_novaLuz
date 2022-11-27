void curve_calc_tangents(void)
{

     //pas touche prepa tangentes OK pour sens en avant
   int i;

   curve_nodes[0] = dummy_curve_node(curve_nodes[1], curve_nodes[2]);
   curve_nodes[curve_node_count] = dummy_curve_node(curve_nodes[curve_node_count-1], curve_nodes[curve_node_count-2]);

   curve_node_count++;

  for (i=1; i<curve_node_count-1; i++)
      curve_nodes[i].tangent = fixatan2(itofix(curve_nodes[i+1].y - curve_nodes[i-1].y),
				  itofix(curve_nodes[i+1].x - curve_nodes[i-1].x));



}
