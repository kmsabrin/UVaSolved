#include <math.h>
#include <stdio.h>

int start( int v, int* l )
{
	int i, s, e;

	s = 1; *l = 1;
	
	for ( i = 0; ; i += 4, ++(*l) )
	{
		s = s + i;
		e = s + ( i + 4 ) - 1;	
		if ( v >= s && v <= e )
			return s;
	}
}

int cartesian( int* m, int *n, int l, int s, int p )
{	
	int a, b, x, y;

	a = l - 1;
	x = 0 - a; y = 1;

	//printf( "%d %d\n", x, y );	
	while( 1 )
	{
		if ( p <= s + a )
		{
			b = p - s;
			x += b;
			y += b;
			break;
		}
		else
		{
			x += a;
			y += a;
			s += l;
		}
		

		++x; --y;
		//printf( "%d %d\n", x, y );
		if ( p <= s + a )
		{
			b = p - s;
			x += b;
			y -= b;
			break;
		}
		else
		{
			x += a; 
			y -= a;
			s += l;
		}
		

		--x; --y;
		//printf( "%d %d\n", x, y );
		if ( p <= s + a )
		{
			b = p - s;
			x -= b;
			y -= b;
			break;
		}
		else
		{
			x -= a;
			y -= a;
			s += l;
		}
		

		--x; ++y;
		//printf( "%d %d\n", x, y );		
		if ( p <= s + a )
		{
			b = p - s;
			x -= b;
			y += b;
			break;
		}
		else
		{
			x -= a;
			y += a;
			s += l;
		}
	}


	*m = x; *n = y;

	return 0;
}

	

int main()
{
	int s1, s2, p, q, len1, len2;

	int x1, y1, x2, y2;

	while ( scanf( "%d %d", &p, &q ) )
	{
		if( p == -1 && q == -1 )
			break;
		
		if ( p != 0 )
		{
			s1 = start( p, &len1 );
			cartesian( &x1, &y1, len1, s1, p );
		}
		else
			x1 = y1 = 0;

		if ( q != 0 )
		{
			s2 = start( q, &len2 );		
			cartesian( &x2, &y2, len2, s2, q );
		}
		else
			x2 = y2 = 0;


		//printf( "RESULT\n%d %d\n%d %d\n\n", x1, y1, x2, y2 );
		printf( "%.2lf\n", sqrt( (double)( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) ) ) );
	}

	return 0;
}
