#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX1 11000010
#define MAX2 40000

char expr[150];
char periodic[MAX1];

long N;
long store[MAX2];

long long stack[150];

long long f( long n )
{
	long i;
	long ptr;

	for ( i = 0, ptr = -1; expr[i] != 'N'; i += 2 )
	{
		if ( isdigit( expr[i] ) )
		{
			stack[++ptr] = atol( expr + i - 1 );

			while ( expr[++i] != ' ' )
			{
				;
			}
			--i;
		}
		else if ( expr[i] == 'x' )
		{
			stack[++ptr] = n;
		}
		else if ( expr[i] == '+' )
		{
			stack[ptr - 1] = ( stack[ptr - 1] + stack[ptr] ) % N;
			--ptr;
		}
		else if ( expr[i] == '*' )
		{
			stack[ptr - 1] = ( stack[ptr - 1] * stack[ptr] ) % N;
			--ptr;
		}
	}

	return stack[0];
}

int main()
{
	char str[150];
	char *p;

	long i;
	long long j;
	long k;
	long n;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		gets( str );

		if ( str[0] == '0' )
		{
			break;
		}

		p = strtok( str, " " );
		N = atol( p );

		p = strtok( NULL, " " );
		n = atol( p );

		while ( *(++p) )
			;
		strcpy( expr, p + 1 );

		memset( periodic, 0, sizeof( periodic ) );


		j = f( n );
		periodic[j] = 1;
		store[1] = j;

		for ( i = 2;	; ++i )
		{
		     j = f( j );

		     if ( periodic[j] )
		     {
			for ( k = 1;	; ++k )
			{
				if ( store[k] == j )
				{
					printf( "%ld\n", i - k );
					break;
				}
			}
			break;
		     }

		     periodic[j] = 1;
		     store[i] = j;
		}
	}

	return 0;
}