#include <stdio.h>

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

	if ( tmp < max )
		max = tmp;

}

int main()
{
	int tc, n, m, i, j, k;
	
	scanf( "%d", &tc );

	while ( tc-- )
	{
		scanf( "%d %d", &n, &m );

		InitializeSet( n );
		max = 0;
		
		for ( i = 0; i < m; ++i )
		{
			scanf( "%d %d", &j, &k );

			WeightedUnion( j, k );
		}

		printf( "%d\n", -max );
	}

	return 0;
}