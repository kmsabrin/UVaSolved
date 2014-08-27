#include <stdio.h>

#define MAX 1000001

char C[MAX + 1];

char P[200100 + 20];

int H[50100];

int N[MAX + 1];

int Q[50100];

void main()
{
	int i, j, k, n;

	for ( i = 5, j = 0; i <= 200100; i += 4 )
	{
		H[j++] = i;
	}

	n = j;

	for ( i = 0; i < n; ++i )
	{
		for ( j = 0; H[j] * H[j] <= H[i]; ++j )
		{
			if ( H[i] % H[j] == 0 )
			{
				P[H[i]] = 1;
				break;
			}
		}
	}
		
	for ( i = 5, j = 0; i < 200100; i += 4 )
	{
		if ( P[i] == 0 )
		{
			Q[j++] = i;
		}
	}
		
	for ( i = 0; Q[i] < 1001; ++i )
	{				
		for ( j = i; ; ++j )
		{						
			k = Q[i] * Q[j];

			if ( k > MAX )
			{
				break;
			}

			C[k] = 1;
		}
	}
		
	for ( i = 1; i <= MAX; ++i )
	{
		N[i] = N[i - 1] + C[i];
	}
	
	while ( scanf( "%d", &k ) && k )
	{
		printf( "%d %d\n", k, N[k] );
	}		
}
