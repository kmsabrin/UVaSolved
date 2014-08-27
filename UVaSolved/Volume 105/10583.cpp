#include <stdio.h>

int p[50001];

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

int NumberOfSets( int n )
{
	int count = 0, i;
	for ( i = 1; i <= n; ++i )
		if ( p[i] < 0 )
			++count;
	return count;	
}

int main()
{
	int c = 0, n, m, i, j, k;

	while ( 1 )
	{
		scanf( "%d %d", &n, &m );

		if ( !n && !m )
			break;

		InitializeSet( n );
				
		for ( i = 0; i < m; ++i )
		{
			scanf( "%d %d", &j, &k );

			WeightedUnion( j, k );
		}

		printf( "Case %d: %d\n", ++c, NumberOfSets( n ) );
	}

	return 0;
}