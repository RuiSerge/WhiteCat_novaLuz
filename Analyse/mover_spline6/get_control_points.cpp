void get_control_points(NODE n1, NODE n2, int points[8])
{
   fixed dist = fixmul(node_dist(n1, n2), curviness);

   points[0] = n1.x;
   points[1] = n1.y;

   points[2] = n1.x + fixtoi(fixmul(fixcos(n1.tangent), dist));
   points[3] = n1.y + fixtoi(fixmul(fixsin(n1.tangent), dist));

   points[4] = n2.x - fixtoi(fixmul(fixcos(n2.tangent), dist));
   points[5] = n2.y - fixtoi(fixmul(fixsin(n2.tangent), dist));

   points[6] = n2.x;
   points[7] = n2.y;
}
