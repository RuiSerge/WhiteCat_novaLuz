void curve_get_control_points(curve_node n1, curve_node n2, int points[8])
{
    fixed dist = fixmul(curve_node_dist(n1, n2), curve_curviness);

    points[0] = n1.x;
    points[1] = n1.y;

    points[2] = n1.x + fixtoi(fixmul(fixcos(n1.tangent), dist));
    points[3] = n1.y + fixtoi(fixmul(fixsin(n1.tangent), dist));

    points[4] = n2.x - fixtoi(fixmul(fixcos(n2.tangent), dist));
    points[5] = n2.y - fixtoi(fixmul(fixsin(n2.tangent), dist));

    points[6] = n2.x;
    points[7] = n2.y;
}
