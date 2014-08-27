#include <stdio.h>

int A[101][101], B[101][101], S[101];

int sum( int i, int j )
{
	return S[j] - S[i - 1];
}

void main()
{
	int i, j, k, l, n, g, x, y, a, b;
	
	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &n ) && n )
	{		
		S[0] = 0;

		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d", &j );
			
			A[i][i] = j;
			
			B[i][i] = 0;						

			S[i] = S[i - 1] + j;
		}
		
		for ( l = 2; l <= n; ++l )
		{
			for ( i = 1; i <= n - l + 1; ++i )
			{
				j = i + l - 1;
								
				g = -0xFFFFFFF;
				
				for ( k = i; k <= j; ++k )
				{
					x = sum( i, k );

					if ( k < j )
					{
						x += B[k + 1][j];
					
						y = A[k + 1][j];
					}
					else
					{
						y = 0;
					}

					if ( x - y > g )
					{
						g = x - y;

						a = x;

						b = y;
					}

					if ( k < j )
					{
						x = B[i][k] + sum( k + 1, j );
										
						y = A[i][k];

						if ( x - y > g )
						{
							g = x - y;

							a = x;

							b = y;
						}
					}										
				}

				A[i][j] = a;

				B[i][j] = b;				
			}
		}
		
		printf( "%d\n", A[1][n] - B[1][n] );
	}
}