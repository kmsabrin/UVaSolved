// MINIMUM SPANNING TREE

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 300000

struct edge
{
	int u, v, d;
} f[MAX];

int p[761];

void initialize_set( int n )
{
	for ( int i = 1; i <= n; ++i )
	{
		p[i] = -1;
	}
}

int collapsing_find( int i ) // finds the root of i
{
	int r = i;
	
	while ( p[r] > 0 )
	{
		r = p[r];
	}
	
	while ( i != r )
	{
		int s = p[i];
		p[i] = r;
		i = s;
	}
	
	return r;
}

int weighted_union( int i, int j ) // joins member i and j
{
	i = collapsing_find( i );   // root of i
	j = collapsing_find( j );   // root of j
	
	if ( i == j )     // repitition check, within the same set
	{
		return 0;
	}
	
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
	
	return 1;
}

int comp( const void *i, const void *j )
{
	struct edge *p = ( struct edge * )i;
	struct edge *q = ( struct edge * )j;
	return p->d - q->d;
}

int main()
{
	int tc, i, j, k, e, n, m, flg, c;
	int x[761], y[761];
	
	//	freopen( "a.in", "r", stdin );
	
	scanf( "%d", &tc );
	
	while ( tc-- )
	{
		scanf( "%d", &n );
		
		e = ( n * ( n - 1 ) ) / 2;
		
		for ( k = 0, i = 1; i <= n; ++i )
		{
			scanf( "%d %d", &x[i], &y[i] );
			
			for ( j = 1; j < i; ++j )
			{
				f[k].u = j;
				f[k].v = i;
				f[k].d = ( x[j] - x[i] ) * ( x[j] - x[i] )
					+ ( y[j] - y[i] ) * ( y[j] - y[i] );
				++k;
			}
		}
		
		qsort( f, e, sizeof( f[0] ), comp );
		
		initialize_set( n );
		
		scanf( "%d", &m );
		
		for ( i = flg = 0; i < m; ++i )
		{
			scanf( "%d %d", &j, &k );
			
			if ( weighted_union( j, k ) )
			{
				++flg;
			}
		}
		
		for ( i = c = 0; i < e; ++i )
		{
			if ( weighted_union( f[i].u, f[i].v ) )
			{
				c = 1;
				printf( "%d %d\n", f[i].u, f[i].v );
				++flg;
			}
			
			if ( flg == n - 1 )
			{
				break;
			}
		}
		
		if ( c == 0 )
		{
			printf( "No new highways need\n" );
		}
		if ( tc )
		{
			printf( "\n" );
		}
	}
	
	return 0;
}


