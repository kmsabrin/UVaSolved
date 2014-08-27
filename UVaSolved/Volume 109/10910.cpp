#include <stdio.h>

long long nCr( int n, int r )
{
	int i, j, k;
	long long p;

	if ( n - r > r )
		k = j = r;			
	else 
		k = j = n - r;

	i = n; 
	p = 1;
	while ( k-- )
	{
		p *= i--;
		if ( j && p % j == 0 )
			p /= j--;		
	}

	while ( j )
		p /= j--;
	
	return p;
}

int main()
{
	int t, r, n;
	int N, T, P;

	//freopen( "in.in", "r", stdin );

	scanf( "%d", &t );
	
	while ( t-- )
	{
		scanf( "%d %d %d", &N, &T, &P );

		r = T - N * P;
		n = N;

		printf( "%lld\n", nCr( n + r - 1, r ) );
	}

	return 0;
}