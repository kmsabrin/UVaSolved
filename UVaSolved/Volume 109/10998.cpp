#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define E 0.0001

int main()
{
	char color[][8] = { "black", "white" }; 
	double H, V, h, v, x, y, tH, tV, p, q, tx, ty;
	int t, n, c = 0;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while ( scanf( "%lf %lf %lf %lf", &H, &V, &h, &v ) )
	{

		if ( fabs(H) < E && fabs(V) < E && fabs(h) < E && fabs(v) < E )
		{
			break;
		}
		
		scanf( "%d", &n );
	
		printf( "Case %d:\n", ++c );

		while ( n-- )
		{
			
			scanf( "%lf %lf", &p, &q );

			x = y = 0;
			tH = H, tV = V; 
			t = 0;
		
	
			while ( 1 )
			{
		
				tx = x + tH * h;		
				ty = y + tV * v;
		
				if ( ( p > tx && q < ty ) || ( p < tx && q > ty ) )
				{
					printf( "%s\n", color[t] );
					break;
				}
				else if ( p < tx && q < ty )
				{
					tH = tx - x;
					tV = ty - y;
				}
				else
				{
					tH = tH - ( tx - x );
					tV = tV - ( ty - y );
					x = tx;
					y = ty;
				}
						
				if ( t == 0 )
				{
					t = 1;
				}
				else
				{
					t = 0;
				}
				
			}
		}
	}

	return 0;
}

