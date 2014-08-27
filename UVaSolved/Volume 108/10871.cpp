#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000 + 1

char prime[MAX], str[3001];
int store[10011], dp[10011];

void GetPrime()
{
	int i, j;
	memset( prime, 1, MAX );
	prime[0] = prime[1] = 0;
	for ( i = 2; i * i < MAX; ++i )
		if ( prime[i] )
			for ( j = i * i; j < MAX; j += i )
				prime[j] = 0;
}

int main()
{
	int i, j, n, t, p;
	int start, end, from, len;
	
	//freopen( "a.in", "r", stdin );


	GetPrime();


	scanf( "%d", &t );
	while ( t-- )
	{
		scanf( "%d", &n );

		dp[0] = 0;		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &store[i] );
			dp[i + 1] = dp[i] + store[i];						
		}

		len = 2;
		from = -1;
		while( 1 )
		{
			if ( len > n )
				break;

			start = len;
			end = start - len;
			for ( ; start <= n; ++start, ++end )
			{
				p = dp[start] - dp[end];
				if ( prime[p] )
				{
					from = end;
					break;
				}
			}
			if ( from != -1 )
				break;

			++len;
		}

		if ( from == -1 )
			printf( "This sequence is anti-primed." );
		else
		{
			printf( "Shortest primed subsequence is length %d:", len );
			for ( i = from, j = 0; j < len; ++j, ++i )
				printf( " %d", store[i] );
		}
		printf( "\n" );
	}
	return 0;
}




