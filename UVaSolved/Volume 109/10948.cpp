#include <stdio.h>

#define MAX 1000000

char p[MAX + 1];

int main()
{
	int i, j, n, f;

	p[0] = p[1] = 1;
	for ( i = 2; i * i <= MAX; ++i )
		if ( p[i] == 0 )
			for ( j = i * i; j <= MAX; j += i )
				p[j] = 1;

	while ( scanf( "%d", &n ) && n )
	{
		
		printf( "%d:\n", n ); 

		f = 0;

		for ( i = 2; i < n; ++i )
			if ( p[i] == 0 && p[n - i] == 0 )
			{
				printf( "%d+%d\n", i, n - i );
				f = 1;
				break;
			}

		if ( f == 0 ) 
			printf( "NO WAY!\n" );
	}

	return 0;
}