#include <stdio.h>
#include <string.h>

char a[110][110];
int flag[110], tmp[110];
int s, e, d, c, l;

int main()
{
	int i, j ,k;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d %d", &c, &l ) && ( c || l ) )
	{

		memset ( a, 0, sizeof( a ) );

		for ( i = 0; i < l; ++i )
		{
			scanf( "%d %d", &j, &k );
			a[j][k] = a[k][j] = 1;
		}
		
		scanf( "%d %d %d", &s, &e, &d );

		for ( i = 1; i <= c; ++i )
		{
			flag[i] = tmp[i] = -1;
		}

		flag[s] = tmp[s] = 0;

		for ( i = 1; i <= d; ++i )
		{
			for ( j = 1; j <= c; ++j )
			{
				if ( flag[j] == i - 1 ) 
				{
					for ( k = 1; k <= c; ++k )
					{
						if ( a[j][k] )
						{
							tmp[k] = i;
						}
					}
				}
			}

			for ( k = 1; k <= c; ++k )
			{
				flag[k] = tmp[k];
			}
		}

		if ( flag[e] == d )
		{
			printf( "Yes, Teobaldo can travel.\n" );
		}
		else		
		{
			printf( "No, Teobaldo can not travel.\n" );
		}
		
		getchar(); 
		getchar();
	}

	return 0;
}


