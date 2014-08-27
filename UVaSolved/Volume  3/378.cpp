

/* @JUDGE_ID: 34556CP 378 C++ "Submitted by Cd-Man's automatic submission tool ver 0.9" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.80.160.48 - CRC: BCD47B77 **/
/** Date: 2004-11-04 19:28:50 +0100 **/


#include<stdio.h>
#include<math.h>
//#include<conio.h>

#define EPSILON 0.000001

int main()
{
   double k, x1, x2, y1, y2, a1, b1, c1, a2, b2, c2, x, y;
//   freopen( "a.in", "r", stdin ); clrscr();

   scanf("%lf",&k);
   printf("INTERSECTING LINES OUTPUT\n");
   while ( k-- )
   {
	scanf( "%lf %lf %lf %lf", &x1, &y1, &x2, &y2 );
	if ( x1 == x2 ) {
		a1 = 1;
		b1 = 0;
		c1 = -x1;
	}
	else {
		a1 = - ( y2 - y1 ) / ( x2 - x1 );
		b1 = 1;
		c1 = - ( x1 * a1 ) - ( b1 * y1 );
	}

	scanf( "%lf %lf %lf %lf", &x1, &y1, &x2, &y2 );
	if ( x1 == x2 ) {
		a2 = 1;
		b2 = 0;
		c2 = -x1;
	}
	else {
		a2 = - ( y2 - y1 ) / ( x2 - x1 );
		b2 = 1;
		c2 = - ( x1 * a2 ) - ( b2 * y1 );
	}

	//printf("%.2lf %.2lf %.2lf\n%.2lf %.2lf %.2lf\n",a1,b1,c1,a2,b2,c2);

	if (
	     (fabs( a1 - a2 ) <= EPSILON) &&
	     (fabs( b1 - b2 ) <= EPSILON) &&
	     (fabs( c1 - c2 ) <= EPSILON) )
		printf("LINE\n");

	else if ( (fabs( a1 - a2 ) <= EPSILON) &&
	     (fabs( b1 - b2 ) <= EPSILON) )
		printf("NONE\n");

	else {
	     x = ( b2 * c1 - b1 * c2 ) / ( a2 * b1 - a1 * b2 );
	     if ( fabs( b1 ) > EPSILON )
		y = - ( a1 * x + c1 ) / b1;
	     else
		y = - ( a2 * x + c2 ) / b2;

		printf("POINT %.2lf %.2lf\n", x, y );
	}


   }
   printf("END OF OUTPUT\n");
   return 0;
}

