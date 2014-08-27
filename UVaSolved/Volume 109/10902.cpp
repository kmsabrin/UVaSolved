#include <math.h>
#include <stdio.h>
#include <string.h>

#define EPS 0.000001

struct point
{
	double x, y;
};

struct line
{
	double a, b, c;
};

struct segment
{
	point p, q;
	int flg;
};

double min( double a, double b )
{
	if ( a < b )
	{
		return a;
	}
	return b;
}

double max( double a, double b )
{
	if ( a > b )
	{
		return a;
	}
	return b;
}

void pointsToLine( point p, point q, line &l )
{
		if ( fabs( p.x - q.x ) < EPS )
		{
			l.a = 1; 
			l.b = 0; 
			l.c = -p.x;
		}
		else
		{
			l.b = 1;
			l.a = -( p.y - q.y ) / ( p.x - q.x );
			l.c = -( l.a * p.x ) - ( l.b * p.y );
		}		
}
	
bool parallelLine( line l1, line l2 )
{
	return ( fabs( l1.a - l2.a ) <= EPS ) && ( fabs( l1.b - l2.b ) <= EPS );
}

bool sameLine( line l1, line l2 )
{
	return parallelLine( l1, l2 ) && ( fabs( l1.c - l2.c ) <= EPS );
}

void intersectionPoint( line l1, line l2, point &p )
{
	p.x = ( l2.b * l1.c - l1.b * l2.c ) / ( l2.a * l1.b - l1.a * l2.b );

	if ( fabs( l1.b ) > EPS )
	{
		p.y = -( l1.a * p.x + l1.c ) / l1.b;
	}
	else
	{
		p.y = -( l2.a * p.x + l2.c ) / l2.b;
	}
}

bool pointInBox( point p, point b1, point b2 )
{
	return ( p.x >= min( b1.x, b2.x ) ) && ( p.x <= max( b1.x, b2.x ) )
		&& ( p.y >= min( b1.y, b2.y ) ) && ( p.y <= max( b1.y, b2.y ) );
}

bool segmentIntersection( segment s1, segment s2 )
{
	line l1, l2;
	point p;

	pointsToLine( s1.p, s1.q, l1 );
	pointsToLine( s2.p, s2.q, l2 );

	if ( sameLine( l1, l2 ) )
	{
		return pointInBox( s1.p, s2.p, s2.q ) || pointInBox( s1.q, s2.p, s2.q )
			|| pointInBox( s2.p, s1.p, s1.q ) || pointInBox( s2.q, s1.p, s1.q ) ;
	}

	if ( parallelLine( l1, l2 ) )
	{
		return false;
	}

	intersectionPoint( l1, l2, p );

	return pointInBox( p, s1.p, s1.q ) && pointInBox( p, s2.p, s2.q );
}

int main()
{
	int i, j, n;	
	segment s[100001];
	
	
	//freopen( "a.in", "r", stdin );
	
	while ( scanf ( "%d", &n ) && n )
	{

		memset( s, 0, sizeof( s ) );

		for ( i = 0; i < n; ++i )
		{
			scanf( "%lf %lf %lf %lf", &s[i].p.x, &s[i].p.y, &s[i].q.x, &s[i].q.y );			
		}
	
		/*
		for ( i = 0; i < n; ++i )
		{
			for ( j = 0; j < i; ++j )
			{
				if ( !s[j].flg && segmentIntersection( s[i], s[j] ) )
				{
					s[j].flg = 1;
				}
			}
		}
		*/

		
		for ( i = n - 2; i >= 0; --i )
		{
			for ( j = i + 1; j < n; ++j )
			{
				if ( segmentIntersection( s[i], s[j] ) )
				{
					s[i].flg = 1;
					break;
				}
			}
		}
		

		
		printf( "Top sticks: ");
		
		for ( i = 0; i < n - 1; ++i )
		{
			if ( !s[i].flg )
			{
				printf( " %d,", i + 1 );
			}
		}

		printf( " %d.\n", n );
		
	}

	return 0;
}