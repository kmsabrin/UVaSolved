#include <stdio.h>
#include <string.h>

char a[82][82];

char str[82];

int n;

int MCM()
{
	int i, j, k, l, m, p;

	char s1[82], s2[82];

	for ( l = 1; l <= n; ++l )
	{
		for ( i = 1; i <= n - l + 1; ++i )
		{
			j = i + l - 1;
			
			for ( k = i; k <= j - 1; ++k )
			{
				m = a[i][k] + a[k + 1][j];

				if ( m < a[i][j] )
				{
					a[i][j] = m;
				}
			}

			m = a[i][j];
			
			strcpy( s1, str + i );
			
			s1[l] = 0;
								
			for ( k = j + 1, p = j + l; p <= n;  )
			{								
				strcpy( s2, str + k );
				
				s2[l] = 0;
																				
				if ( !strcmp( s1, s2 ) )
				{
					if ( m < a[i][p] )
					{
						a[i][p] = m;
					}
					
					k = p + 1;
					p = k + l - 1;
				}
				else
				{
					break;
				}
			}
		}
	}

	return a[1][n];
}

void main()
{
	int i, j;

	//freopen( "a.in", "r", stdin );
				
	str[0] = '?';
	
	while ( scanf( "%s", str + 1 ) )
	{
		if ( str[1] == '*' )
		{
			break;
		}				
		
		n = strlen( str ) - 1;
		
		for ( i = 1; i <= n; ++i )
		{
			for ( j = i; j <= n; ++j )
			{
				a[i][j] = j - i + 1;
			}			
		}
		
		printf( "%d\n", MCM() );
	}
}