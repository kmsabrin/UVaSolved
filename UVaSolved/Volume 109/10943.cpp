#include <stdio.h>
#include <string.h>

int a[101][101];


int find( int n, int k )
{
	int i, j;

	if ( a[n][k] )
		return a[n][k] % 1000000;
	else
	{
		for ( i = j = 0; i <= n; ++i )
			j += find( i, k - 1 ) % 1000000;
		return j % 1000000;
	}

}

int main()
{
	int i, j, n, k;

	memset( a, 0, sizeof( a ) );

	for ( i = 0; i < 101; ++i )
	{
		a[0][i] = 1;		
		a[i][1] = 1;
		a[i][2] = i + 1;
	}

	for ( i = 0; i < 101; ++i )
		for ( j = 0; j < 101; ++j )
			a[i][j] = find( i, j );

	while ( scanf( "%d %d", &n, &k ) )
	{
		if ( !n && !k )
			break;
		
		printf( "%d\n", a[n][k] );

	}

	return 0;
}