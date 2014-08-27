#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	double cost[202], f[202], unit, p, min;
	
	int k, i, j, nItem, size[202], kase = 0;

	char str[2000], *q;

	freopen( "a.in", "r", stdin );
	
	while ( scanf( "%lf %d", &unit, &nItem ) != EOF )
	{		
		for ( i = 0; i < nItem; ++i )
		{
			scanf( "%d %lf", &size[i], &cost[i] );
		}
		
		for ( i = 0, p = 0; i <= 201; ++i, p += unit )
		{
			f[i] = p;
		}
				
		for ( i = 1; i <= 201; ++i )
		{
			for ( j = 0; j < nItem; ++j )
			{
				if ( i >= size[j] )
				{				
					if ( cost[j] + f[i - size[j]] < f[i] )
					{
						f[i] = cost[j] + f[i - size[j]];
					}
				}
			}	
		}
		
		gets( str );
		gets( str );
		
		printf( "Case %d:\n", ++kase );
		
		q = strtok( str, " " );
		
		k = atoi( q );

		min = 10e12;
		
		for ( i = k; i <= 201; ++i )
		{
			if ( f[i] < min )
			{
				min = f[i];
			}
		}
		
		printf( "Buy %d for $%.2lf\n", k, min );
				
		while ( q = strtok( NULL, " " ) )
		{
			k = atoi( q );

			min = 10e12;
			
			for ( i = k; i <= 201; ++i )
			{
				if ( f[i] < min )
				{
					min = f[i];
				}
			}
			
			printf( "Buy %d for $%.2lf\n", k, min );
		}
	}
	
	return 0;
}