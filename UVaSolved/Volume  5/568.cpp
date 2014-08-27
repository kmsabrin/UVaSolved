#include<stdio.h>

int main()
{
	unsigned long i,j,k,n;

	while(scanf("%lu",&n)!=EOF)
	{
		j = 1; 
		k = n;

		for ( i = 2; n > 1; n--, i++ )
		{
			j *= i;

			if ( j > 9999 ) 
			{
				while ( !( j % 10 ) ) 
				{
					j /= 10;
				}
				j = j % 100000;
			}
		}

		while ( !( j % 10 ) ) 
		{
			j /= 10;
		}

		i = j % 10;

		printf( "%5lu -> %lu\n", k, i );
	}

  	return 0;
}
