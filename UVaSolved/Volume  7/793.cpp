#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max;
int p[30001];

void InitializeSet( int n )
{
	for ( int i = 1; i <= n; ++i )
		p[i] = -1;
}

int CollapsingFind( int i )
{
	int r = i;
	while ( p[r] > 0 )
		r = p[r];

	while ( i != r )
	{
		int s = p[i];
		p[i] = r;
		i = s;
	}

	return r;
}

void WeightedUnion( int i, int j )
{	
	i = CollapsingFind( i );   // root of i
	j = CollapsingFind( j );   // root of j


	if ( i == j ) return;  // repitition check

	int tmp = p[i] + p[j];

	if ( p[i] > p[j] )
	{
		p[i] = j;
		p[j] = tmp;
	}
	else
	{
		p[j] = i;
		p[i] = tmp;
	}

}

int main()
{
	int tc, n, j, k;
	char str[20], *c;
	int win, lose;
	
//	freopen( "a.in", "r", stdin );

	scanf( "%d", &tc ); getchar(); 
	getchar();

	while ( tc-- )
	{
		scanf( "%d", &n ); getchar();

		InitializeSet( n );
		win = lose = 0;

		while ( gets( str ) && *str )
		{
			
			c = strtok( str, " " );					
			c = strtok( NULL, " " );
			j = atoi( c );
			c = strtok( NULL, " " );
			k = atoi( c );

			if ( str[0] == 'c' )
				WeightedUnion( j, k );
			else
			{
				j = CollapsingFind( j );   // root of i
				k = CollapsingFind( k );   // root of j
				if ( j == k )
					win++;
				else
					lose++;
			}
		}

		printf( "%d,%d\n", win, lose ); 
	}

	return 0;

}