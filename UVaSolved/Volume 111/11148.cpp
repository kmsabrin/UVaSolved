#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int gcd( int a, int b )
{
	if ( !b )	
	{
		return a;	
	}

	return gcd( b, a % b );
}

int main()
{
	int i, j, k, p, q, r, a, b, t;

	char str[10000];

	//freopen( "a.in", "r", stdin );

	scanf( "%d\n", &t );

	while ( t-- )
	{
		gets( str );

		a = b = 1;

		for ( i = 0; str[i]; ++i )
		{
			if ( str[i] >= '0' && str[i] <= '9' )
			{			
				for ( j = i; ; ++j )
				{
					if ( !str[j] || str[j] == 32 )
					{
						k = 1;
						break;
					}
					else if ( str[j] == '/' )
					{
						k = 2;
						break;
					}
					else if ( str[j] == '-' )
					{
						k = 3;
						break;
					}
				}

				if ( k == 1 )
				{
					a *= atoi( str + i );
					
					while ( str[i] && str[i] != 32 )
					{
						++i;
					}
				}
				else if ( k == 2 )
				{
					a *= atoi( str + i );

					j = i + 1;

					while ( str[j] != '/' )
					{
						++j;
					}

					b *= atoi( str + j + 1 );

					while ( str[j] && str[j] != 32 )
					{
						++j;
					}

					i = j;
				}
				else if ( k == 3 )
				{
					p = atoi( str + i );

					j = i + 1;

					while ( str[j] != '-' )
					{
						++j;
					}
				
					q = atoi( str + j + 1 );

					while ( str[j] != '/' )
					{
						++j;
					}

					r = atoi( str + j + 1 );

					a *= ( p * r + q );

					b *= r;

					while ( str[j] && str[j] != 32 )
					{
						++j;
					}

					i = j;
				}
			}
		}

		//printf( "%d %d\n", a, b );

		k = gcd( a, b );
		
		a /= k;

		b /= k;

		if ( a % b == 0 ) 
		{
			printf( "%d\n", a / b );
		}
		else
		{
			if ( a < b )
			{
				printf( "%d/%d\n", a, b );
			}
			else
			{
				printf( "%d-%d/%d\n", a / b, a % b, b );
			}
		}
	}

	return 0;
}
