#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int e;

int n;

int a[100000];

int index;

int call()
{
	int s, sum;

	s = a[index];

	sum = 0;

	for ( ++index; index < n; ++index )
	{
		if ( a[index] == -s )
		{
			return 0;
		}
		else if ( abs( a[index] ) >= -s || a[index] >= 0 )
		{
			e = 1;

			return -1;
		}
		else
		{
			sum += abs( a[index] );

			call();
		}

		if ( sum >= -s )
		{
			e = 1;

			return -1;
		}
	}

	e = 1;

	return -1;
}

char str[100000];

void main()
{
	char *p;

	int i;

	//freopen( "a.in", "r", stdin );

	while ( gets( str ) )
	{
		i = 0;

		p = strtok( str, " " );

		a[i++] = atoi( p );

		while ( p = strtok( NULL, " " ) )
		{
			a[i++] = atoi( p );
		}

		n = i;

		e = 0;

		index = 0;

		call();

		if ( e == 0 )
		{
			printf( ":-) Matrioshka!\n" );
		}
		else
		{
			printf( ":-( Try again.\n" );
		}
	}
}