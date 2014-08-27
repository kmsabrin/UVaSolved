#include <stdio.h>

void main()
{
	int n;

	unsigned long long m;

	while ( scanf( "%d", &n ) != EOF )
	{
		m = ( n + 1 ) / 2;

		m = 2 * m * m - 1;

		printf( "%llu\n", m + m - 2 + m - 4 );
	}
}