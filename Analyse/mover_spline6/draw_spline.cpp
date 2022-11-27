void draw_spline(NODE n1, NODE n2)
{
   int points[8];
   int i;

   get_control_points(n1, n2, points);
   spline(screen, points, makecol(0,200,0));
   if (show_control_points)
      for (i=1; i<=2; i++)
	 circlefill(screen, points[i*2], points[i*2+1], 2, makecol(0,0,0));
}
