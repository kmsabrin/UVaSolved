#include <stdio.h>

unsigned int m[50];
unsigned int f[50];
unsigned int t[50];

int main()
{
	int i, n;
	
	m[0] = 0;
	f[0] = 1;
	t[0] = 1;

	for ( i = 1; i <= 50; ++i )
	{
		m[i] = t[i - 1];
		f[i] = m[i - 1] + 1;
		t[i] = m[i] + f[i];
	}

	while ( scanf( "%d", &n ) )		
	{
		if ( n == -1 )
		{
			break;
		}

		printf( "%u %u\n", m[n], t[n] );
	}

	return 0;

}