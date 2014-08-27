#include <stdio.h>

int a_p[22] = { 2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991 };
int a[1000];

int main()
{
	int i, j, k, f;

	for ( j = 0; j < 22; ++j )
	{
		a[a_p[j]] = true;
	}

	while ( 1 )
	{
		scanf( "%d", &i );

		if ( i == 0 )
		{
			break;
		}

		k = 0;

		for ( j = i + 1; j < 992; ++j )
		{
			if ( a[j] == true )
			{
				k = j;
				break;
			}

			if ( j == 10 || j == 100 )
			{
				break;
			}
		}

		printf( "%d\n", k );
	}


	return 0;
}