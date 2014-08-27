#include <stdio.h>

int main()
{
	int I[31], V[31], i;
	
	unsigned int j;

	V[1] = 2; I[1] = 0;

	V[2] = 4; I[2] = 0;

	V[3] = 7; I[3] = 1;

	V[4] = 13; I[4] = 3;

	for ( i = 5, j = 32; i < 31; ++i, j <<= 1 )
	{
		I[i] = 2 * I[i - 1] + V[i - 4];

		V[i] = j - I[i];
	}

	while ( scanf( "%d", &i ) && i )
	{
		printf( "%d\n", I[i] );
	}

	return 0;
}