#include <stdio.h>

#define MAX 30001

unsigned long long nway[MAX];

int coin[] = { 1, 5, 10, 25, 50 };

int main()
{
	int i, j, c;

	for ( nway[0] = 1, i = 0; i < 5; ++i )
	{
		c = coin[i];

		for ( j = c; j < MAX; ++j )
		{
			nway[j] += nway[j - c];
		}
	}

	while ( scanf( "%d", &i ) != EOF )
	{
		if ( nway[i] == 1 )
		{
			printf( "There is only 1 way to produce %d cents change.\n", i );
		}
		else
		{
			printf( "There are %llu ways to produce %d cents change.\n", nway[i], i );
		}

	}

	return 0;

}
