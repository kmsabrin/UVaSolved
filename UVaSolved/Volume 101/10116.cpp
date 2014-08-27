// AD HOC

#include<stdio.h>

int check( int n, int m, int r, int c )
{
	if( n >= 0 && n < r && m >= 0 && m < c)
		return 1;
	return 0;
}

int main()
{
	char a[11][11], p;
	int  b[11][11];
	int i, j, k, r, c, s, n , m, f;
	
	while(scanf( "%d %d %d", &r, &c, &s ) && r )
	{
		getchar();
		
		for ( i = 0; i < 11; i++)
			for ( j = 0; j < 11; j++)
				b[i][j] = 0;
			
			for ( i = 0; i < r; i++)
				gets( a[i] );
			
			n = 0;
			m = s - 1;
			i = 0;
			while( 1 )
			{
				if( check ( n, m, r, c) )
				{
					if ( b[n][m] )
					{
						j = b[n][m] - 1;
						k = i + 1 - b[n][m];
						f = 2;
						break;
					}
					else
						b[n][m] = ++i;
				}
				else
				{
					f = 1;
					break;
				}
				p = a[n][m];
				
				if      ( p == 'N' )  n--;
				else if ( p == 'S' )  n++;
				else if ( p == 'E' )  m++;
				else if ( p == 'W' )  m--;
			}
			if( f == 1 )
				printf("%d step(s) to exit\n", i);
			if( f == 2 )
				printf("%d step(s) before a loop of %d step(s)\n", j, k);
	}
	return 0;
}


