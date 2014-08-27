#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0xFFFFFF

struct point
{
	int x, y;
} p[600], q[600], p0, *p1, *p2;

int comp( const void *i, const void *j )
{
	p1 = (struct point*) i;
	
	p2 = (struct point*) j;
	
	int d = ( p1->x - p0.x ) * ( p2->y - p0.y ) - ( p2->x - p0.x ) * ( p1->y - p0.y );
	
	return -d;
}

int direction( int i, int j )
{
	return ( p[i].x - p0.x ) * ( p[j].y - p0.y ) - ( p[j].x - p0.x ) * ( p[i].y - p0.y );
}

int further( int i, int j )
{
	int d1 = ( p[i].x - p0.x ) * ( p[i].x - p0.x ) + ( p[i].y - p0.y ) * ( p[i].y - p0.y );
	
	int d2 = ( p[j].x - p0.x ) * ( p[j].x - p0.x ) + ( p[j].y - p0.y ) * ( p[j].y - p0.y );
	
	if ( d1 > d2 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int minX, minY;

	int nPoints, i, j, k;

	int T;
		
	int bad[600];
	
	//freopen( "c.in", "r", stdin );
	
	scanf( "%d", &T );
	
	printf( "%d\n", T );

	while ( T-- )
	{		
		scanf( "%d", &nPoints );
		
		minX = minY = INF;
		
		for ( i = 0; i < nPoints; ++i )
		{
			scanf( "%d %d", &p[i].x, &p[i].y );
			
			if ( p[i].y < minY )
			{
				minY = p[i].y;
				minX = p[i].x;
				k = i;
			}
			else if ( p[i].y == minY )
			{
				if ( p[i].x < minX )
				{
					minX = p[i].x;
					k = i;
				}
			}
		}

		--nPoints;
		
		p0.x = minX;
		
		p0.y = minY;
		
		for ( i = k + 1; i < nPoints; ++i )
		{
			p[i - 1].x = p[i].x;
			p[i - 1].y = p[i].y;
		}
		
		--nPoints;
		
		memset( bad, 0, sizeof( bad ) );
		
		for ( i = 0; i < nPoints; ++i )
		{
			if ( bad[i] )
			{
				continue;
			}
			
			for ( j = i + 1; j < nPoints; ++j )
			{
				if ( !direction( i, j ) )
				{
					if ( further( i, j ) )
					{
						bad[i] = 1;
					}
					else
					{
						bad[j] = 1;
					}
				}
			}
		}
		
		for ( i = j = 0; i < nPoints; ++i )
		{
			if ( !bad[i] )
			{
				q[j++] = p[i];
			}
		}
		
		nPoints = j;
		
		qsort( q, nPoints, sizeof( q[0] ), comp );
						
		// use p as stack;
		
		p[0].x = p0.x; p[0].y = p0.y;
		
		p[1] = q[0];
		
		p[2] = q[1];
		
		int top = 2;
		
		for ( i = 2; i < nPoints; ++i )
		{
			while ( ( q[i].x - p[top - 1].x ) * ( p[top].y - p[top - 1].y ) - ( p[top].x - p[top - 1].x ) * ( q[i].y - p[top - 1].y ) >= 0 )
			{
				--top;
			}
			
			p[++top] = q[i];
		}
				
		p[top + 1].x = p0.x; p[top + 1].y = p0.y;

		++top;

		printf( "%d\n", top + 1 );

		for ( i = 0; i <= top; ++i )
		{
			printf( "%d %d\n", p[i].x, p[i].y );			
		}		

		if ( T )
		{
			scanf( "%d", &i );
			printf( "-1\n" );			
		}
		
	}
	
	return 0;
}