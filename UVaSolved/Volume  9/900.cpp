#include <stdio.h>

void main()
{
	long long a[51];
	int i;

	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 5;

	for ( i = 5; i <= 50; ++i )
	{
		a[i] = a[i - 1] + a[i - 2];
	}

	while ( scanf( "%d", &i ) && i )
	{
		printf( "%lld\n", a[i] );
	}
}

18446744073709551615