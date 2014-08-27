#include <stdio.h>
#include <string.h>

bool EXIT;

int p[110];

int target;

int n;

char sequence[110];

char final[110];

char a[101][64001];

int call( int result, int index )
{
	if ( EXIT || result > 32000 || result < -32000 )
	{
		return 0;
	}
	
	if ( index == n )
	{
		if ( result == target )
		{
			memcpy( final, sequence, sizeof( final ) );

			EXIT = true;
		}

		return 0;
	}

	if ( result >= 0 )
	{
		if ( a[index][result] > 0 )
		{
			return 0;
		}
		else
		{
			++a[index][result];
		}
	}
	else
	{
		int temp = 32000 - result;

		if ( a[index][temp] > 0 )
		{
			return 0;
		}
		else
		{
			++a[index][temp];
		}
	}

	if ( !( result % p[index] ) )
	{
		sequence[index] = '/';

		call( result / p[index], index + 1 );
	}

	sequence[index] = '*';

	call( result * p[index], index + 1 );

	sequence[index] = '+';

	call( result + p[index], index + 1 );

	sequence[index] = '-';

	call( result - p[index], index + 1 );

	return 0;
}

int main()
{
	int i, t;

	//freopen( "a.in", "r", stdin );

	scanf( "%d", &t );

	while ( t-- )
	{
		scanf( "%d", &n );

		for ( i = 0; i <= n; ++i )
		{
			scanf( "%d", &p[i] );
		}

		EXIT = false;

		target = p[n];

		memset( a, 0, sizeof( a ) );

		call( p[0], 1 );

		if ( EXIT )
		{
			printf( "%d", p[0] );

			for ( i = 1; i < n; ++i )
			{
				printf( "%c%d", final[i], p[i] );
			}

			printf( "=%d\n", p[n] );
		}
		else
		{
			printf( "NO EXPRESSION\n" );
		}
	}

	return 0;
}