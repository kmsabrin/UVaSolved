#include <stdio.h>

void main()
{
	int S, T, M, N;
	int i, j, k, r, l, c = 0;
	
	while ( scanf( "%d %d %d", &S, &T, &N ) )
	{		
		if ( !S && !T && !N )
		{
			break;
		}
		
		M = T + N * ( S + T );
		
		printf( "Case %d:\n", ++c );
		
		for ( i = 1; i <= T; ++i )
		{
			for ( j = 1; j <= M; ++j )		
			{						
				printf( "*" );
			}				
			printf( "\n" );
		}
		
		for ( r = 1; r <= N; ++r )
		{
			for ( i = 1; i <= S; ++i )
			{
				for ( j = 1; j <= T; ++j )
				{
					printf( "*" );
				}
				
				for ( j = 1; j <= N; ++j )
				{
					for ( k = 1; k <= S; ++k )
					{
						printf( "." );
					}
					
					for ( l = 1; l <= T; ++l )
					{
						printf( "*" );
					}
				}
				
				printf( "\n" );
			}
			
			for ( i = 1; i <= T; ++i )
			{
				for ( j = 1; j <= M; ++j )
				{
					printf( "*" );
				}
				
				printf( "\n" );
			}
		}
		
		printf( "\n" );
	}	
}