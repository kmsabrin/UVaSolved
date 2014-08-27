#include <stdio.h>

int nway[8000];

int coin[] = { 1, 5, 10, 25, 50 };

int main()
{	
	int i, j, n, v, c;

	nway[0] = 1;

	v = 5;

	n = 7489;

	for ( i = 0; i < v; ++i )
	{
		c = coin[i];

		for ( j = c; j <= n; ++j )
		{
			nway[j] += nway[j - c];
		}
	}
	
	while ( scanf( "%d", &n ) != EOF )						
	{
		printf( "%d\n", nway[n] );
	}
	
	return 0;
}


