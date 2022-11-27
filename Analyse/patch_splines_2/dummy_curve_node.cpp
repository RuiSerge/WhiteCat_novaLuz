curve_node dummy_curve_node(curve_node curve_Node, curve_node prev)
{
    curve_node n;

    n.x = curve_Node.x - (prev.x - curve_Node.x) / 8;
    n.y = curve_Node.y - (prev.y - curve_Node.y) / 8;
    n.tangent = itofix(0);

    return n;
}
