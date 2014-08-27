#include <stdio.h>
#include <string.h>

#define MAX 50000 + 1

bool prime[MAX];
int phi[MAX], tmp[MAX];


int get_phi_value()
{
	int i, j;

	memset( prime, true, sizeof( prime ) );

	for ( i = 2; i < MAX; ++i )
	{
		phi[i] = tmp[i] = i;
	}

	for ( i = 2; i * i < MAX; ++i )
	{
		if ( prime[i] == true )
		{
			for ( j = i * i; j < MAX; j += i )
			{
				prime[j] = false;

				while ( tmp[j] % i == 0 )
				{
					tmp[j] /= i;
				}

				phi[j] /= i;
				phi[j] *= i - 1;
			}
			
		}
	}

	for ( i = 2; i < MAX; ++i )
	{
		if ( tmp[i] > 1 )
		{
			phi[i] /= tmp[i];
			phi[i] *= tmp[i] - 1;
		}
	}

	return 0;
}

int get_function_value()
{
	int i;

	tmp[1] = 1;

	for ( i = 2; i < MAX; ++i )
		tmp[i] = tmp[i - 1] + phi[i] * 2;

	return 0;
}

int main()
{
	int n;

	get_phi_value();

	get_function_value();

	while ( scanf( "%d", &n ) )
	{
		if ( n == 0 )
			break;

		printf( "%d\n", tmp[n] );
	}

	return 0;
}