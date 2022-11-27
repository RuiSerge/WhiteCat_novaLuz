NODE dummy_node(NODE node, NODE prev)
{
    NODE n;

    n.x = node.x - (prev.x - node.x) / 8;
    n.y = node.y - (prev.y - node.y) / 8;
    n.tangent = itofix(0);

    return n;
}
