#include <stdio.h>
#include <string.h>

#define MAX 2000000 + 1

#define depth_phi tmp

#define sodp phi

bool  prime[MAX];

int  tmp[MAX], phi[MAX];

int get_relative_prime()
{
	int i, j;
	
	memset( prime, true, sizeof( prime ) );

	for ( i = 2; i < MAX; ++i )
		tmp[i] = phi[i] = i;

	for ( i = 2; i * i < MAX; ++i )
	{
		if ( prime[i] == true )
		{
			for ( j = i * i; j < MAX; j += i )
			{
				prime[j] = false;
				while ( !( tmp[j] % i ) )
					tmp[j] /=  i;
				phi[j] /=  i;
				phi[j] *= ( i - 1 );									
			}			
		}
	}

	for ( i = 2; i < MAX; ++i )
	{
		if ( tmp[i] > 1 )
		{
			phi[i] /= tmp[i];
			phi[i] *= ( tmp[i] - 1 );
		}
	}
	
	return 0;
}

int get_depth_phi()
{
	int i;

	depth_phi[1] = 0;

	for ( i = 2; i < MAX; ++i )
	{
		depth_phi[i] = depth_phi[phi[i]] + 1;
	}

	return 0;
}

int get_sodp()  // sodp = sum of depth of phi
{
	int i;

	sodp[1] = 0;

	for ( i = 2; i < MAX; ++i )
		sodp[i] = depth_phi[i] + sodp[i - 1];

	return 0;
}
		
int main()
{	
	int t, m, n;

	get_relative_prime();

	get_depth_phi();

	get_sodp();	
		
	scanf( "%d", &t );

	while ( t-- )
	{
		scanf( "%d %d", &m, &n );
		printf( "%d\n", sodp[n] - sodp[m - 1] );
	}
		
	return 0;
}


