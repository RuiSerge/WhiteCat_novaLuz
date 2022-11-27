int CounterClockWise ( double Pt0_X, double Pt0_Y, double Pt1_X, double Pt1_Y, double Pt2_X, double Pt2_Y )
{
 double dx1, dx2, dy1, dy2 ;
 /* Calcule les divers produits vectoriels */
 dx1 = Pt1_X - Pt0_X ;
 dy1 = Pt1_Y - Pt0_Y ;
 dx2 = Pt2_X - Pt0_X ;
 dy2 = Pt2_Y - Pt0_Y ;
 /* Verifie si les chiffres sont des zéros */
 if ( fabs(dx1) < ACCURACY_DOUBLE )
    dx1 = 0.0 ;
 if ( fabs(dx2) < ACCURACY_DOUBLE )
    dx2 = 0.0 ;
 if ( fabs(dy1) < ACCURACY_DOUBLE )
    dy1 = 0.0 ;
 if ( fabs(dy2) < ACCURACY_DOUBLE )
    dy2 = 0.0 ;
 /* Teste les conditions */
 if ( (dx1*dy2) > (dy1*dx2) )
     return (+1);
 if ( (dx1*dy2) < (dy1*dx2) )
     return (-1);
 if ( ((dx1*dx2) < 0.0) || ((dy1*dy2) < 0.0) )
     return (-1);
 if ( (dx1*dx1+dy1*dy1) < (dx2*dx2+dy2*dy2) )
     return (+1);
 return (0) ;
}
