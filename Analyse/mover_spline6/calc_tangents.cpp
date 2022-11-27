void calc_tangents(void)
{

    //pas touche prepa tangentes OK pour sens en avant
    int i;

    nodes[0] = dummy_node(nodes[node_count+1], nodes[node_count]);//node et previous
    nodes[node_count+1] = dummy_node(nodes[node_count], nodes[0]);

    node_count++;

    for (i=1; i<node_count-1; i++)
        nodes[i].tangent = fixatan2(itofix(nodes[i+1].y - nodes[i-1].y),
                                    itofix(nodes[i+1].x - nodes[i-1].x));



}
