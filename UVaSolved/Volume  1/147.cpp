#include <stdio.h>

#define MAX 30001

long long nway[MAX];

int coin[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

int main()
{
	int i, j, c;

	double k;

	for ( nway[0] = 1, i = 0; i < 11; ++i )
	{
		c = coin[i];

		for ( j = c; j < MAX; ++j )
		{
			nway[j] += nway[j - c];
		}
	}

	while ( 1 )
	{
		scanf( "%lf", &k );

		i = ( int )( ( k * 100.0 ) + 0.5 );

		if ( i == 0 )
		{
			break;
		}

		printf( "%6.2lf%17lld\n", k, nway[i] );

	}

	return 0;

}
