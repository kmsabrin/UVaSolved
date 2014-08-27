#include <stdio.h>

void main()
{
	long long a[80];
	int i;

	a[1] = 1;
	a[2] = 2;
	a[3] = 2;

	for ( i = 4; i <= 76; ++i )
	{
		a[i] = a[i - 2] + a[i - 3];
	}

	while ( scanf( "%d", &i ) != EOF )
	{
		printf( "%lld\n", a[i] );
	}
}