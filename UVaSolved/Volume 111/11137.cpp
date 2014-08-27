#include <stdio.h>

long long nway[10000 + 1];

int coin[21 + 1];

int main()
{	
	int i, j, n, v, c;

	for ( i = 1; i <= 21; ++i )
	{
		coin[i] = i * i * i;
	}

	nway[0] = 1;

	v = 21;

	n = 10000;

	for ( i = 1; i <= v; ++i )
	{
		c = coin[i];

		for ( j = c; j <= n; ++j )
		{
			nway[j] += nway[j - c];
		}
	}
	
	while ( scanf( "%d", &n ) != EOF )						
	{
		printf( "%lld\n", nway[n] );
	}
	
	return 0;
}


