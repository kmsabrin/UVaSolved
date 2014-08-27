#include <stdio.h>

int main()
{
	int i, a[201];

	a[0] = 0;

	a[1] = 1;

	for ( i = 2; i <= 200; ++i )
	{
		a[i] = a[i - 2] + 3;
	}

	while ( scanf( "%d", &i ) != EOF )
	{
		printf( "%d\n", a[i] );
	}

	return 0;
}


