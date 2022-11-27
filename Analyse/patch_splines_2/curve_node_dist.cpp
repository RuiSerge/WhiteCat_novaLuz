fixed curve_node_dist(curve_node n1, curve_node n2)
{
#define SCALE  64

    fixed dx = itofix(n1.x - n2.x) / SCALE;
    fixed dy = itofix(n1.y - n2.y) / SCALE;

    return fixsqrt(fixmul(dx, dx) + fixmul(dy, dy)) * SCALE;
}
