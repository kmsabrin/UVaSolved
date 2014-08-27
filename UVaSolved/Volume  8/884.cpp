#include <stdio.h>
#include <string.h>

#define MAX 1000000 + 1

bool p[MAX];
int prime[80000]; 
int factor[MAX];
int factorial[MAX];

void get_prime()
{
	int i, j;

	memset( p, true, sizeof( p ) );

	for ( i = 2; i * i < MAX; ++i )
	{
		if ( p[i] == true )
		{
			for ( j = i * i; j < MAX; j += i )
			{
				p[j] = false;
			}
		}
	}

	for ( i = 2, j = 0; i < MAX; ++i )
	{
		if ( p[i] == true )
		{
			prime[j++] = i;
		}
	}
	
}


int main()
{
	int i, j;

	get_prime();

	
	factor[2] = 1; factor[3] = 1;

	factorial[2] = 1; factorial[3] = 2;

	for ( i = 4; i < MAX; ++i )
	{
		
		if ( p[i] == true )
		{
			factor[i] = 1;
		}
		else
		{
			for ( j = 0; prime[j] * prime[j] <= i; ++j )
			{
				if ( i % prime[j] == 0 )
				{
					factor[i] = factor[i / prime[j]] + 1;
					break;
				}
			}
		}

		factorial[i] = factor[i] + factorial[i - 1];
	}

	while ( scanf( "%d", &i ) != EOF )
	{
		printf( "%d\n", factorial[i] );
	}
	

	return 0;
}

		

