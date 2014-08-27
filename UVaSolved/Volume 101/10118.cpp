#include <stdio.h>

int cost[41][41][41][41];

int pile1[41], pile2[41], pile3[41], pile4[41];

int n;

int call( int p1, int p2, int p3, int p4, int b[], int size )
{
	int c;
	
	if ( size == 5 )
	{
		cost[p1][p2][p3][p4] = 0;		
	}
	else if ( cost[p1][p2][p3][p4] == -1 )
	{
		cost[p1][p2][p3][p4] = 0;
		
		// pile 1
		
		if ( p1 < n )
		{
			if ( b[pile1[p1]] )
			{
				b[pile1[p1]] = 0;
				
				--size;
				
				c = 1 + call( p1 + 1, p2, p3, p4, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}			
				
				++size;
				
				b[pile1[p1]] = 1;
			}
			else
			{
				b[pile1[p1]] = 1;
				
				++size;
				
				c = call( p1 + 1, p2, p3, p4, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}
				
				--size;
				
				b[pile1[p1]] = 0;
			}
		}
		
		// pile 2
		
		if ( p2 < n )
		{	
			if ( b[pile2[p2]] )
			{
				b[pile2[p2]] = 0;
				
				--size;
				
				c = 1 + call( p1, p2 + 1, p3, p4, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}			
				
				++size;
				
				b[pile2[p2]] = 1;
			}
			else
			{
				b[pile2[p2]] = 1;
				
				++size;
				
				c = call( p1, p2 + 1, p3, p4, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}
				
				--size;
				
				b[pile2[p2]] = 0;
			}
		}
		
		// pile 3
		
		if ( p3 < n )
		{
			
			if ( b[pile3[p3]] )
			{
				b[pile3[p3]] = 0;
				
				--size;
				
				c = 1 + call( p1, p2, p3 + 1, p4, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}			
				
				++size;
				
				b[pile3[p3]] = 1;
			}
			else
			{
				b[pile3[p3]] = 1;
				
				++size;
				
				c = call( p1, p2, p3 + 1, p4, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}
				
				--size;
				
				b[pile3[p3]] = 0;
			}
		}
		
		// pile 4
		
		if ( p4 < n )
		{
			
			if ( b[pile4[p4]] )
			{
				b[pile4[p4]] = 0;
				
				--size;
				
				c = 1 + call( p1, p2, p3, p4 + 1, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}			
				
				++size;
				
				b[pile4[p4]] = 1;
			}
			else
			{
				b[pile4[p4]] = 1;
				
				++size;
				
				c = call( p1, p2, p3, p4 + 1, b, size );
				
				if ( c > cost[p1][p2][p3][p4] )
				{
					cost[p1][p2][p3][p4] = c;
				}
				
				--size;
				
				b[pile4[p4]] = 0;
			}
		}
	}
		
	return cost[p1][p2][p3][p4];
}

void main()
{
	int b[21];
	
	int i, j, k, l;
	
	//freopen( "a.in", "r", stdin );
	
	//freopen( "a.out", "w", stdout );
	
	while ( scanf( "%d", &n ) && n )
	{
		for ( i = 0; i < n; ++i )
		{
			scanf( "%d %d %d %d", &pile1[i], &pile2[i], &pile3[i], &pile4[i] ); 
		}
		
		for ( i = 0; i <= n; ++i )
		{
			for ( j = 0; j <= n; ++j )
			{
				for ( k = 0; k <= n; ++k )
				{
					for ( l = 0; l <= n; ++l )
					{
						cost[i][j][k][l] = -1;
					}
				}
			}
		}
		
		for ( i = 0; i < 21; ++i )
		{
			b[i] = 0;
		}
		
		printf( "%d\n", call( 0, 0, 0, 0, b, 0 ) );
	}
}