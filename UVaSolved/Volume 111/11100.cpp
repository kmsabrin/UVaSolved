#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int flg[1000000 + 1];

struct T
{
	int f;
	int n;
}	fr[10000 + 1];

int comp( const void *i, const void *j )
{
	T *p = (struct T*) i;
	T *q = (struct T*) j;
	
	return q->f - p->f;
}

void main()
{
	int i, j, k, n, p, q, min, f;
	
	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	f = 0;
	
	while ( scanf( "%d", &n ) && n )
	{
		if ( f )
		{
			printf( "\n" );
		}

		f = 1;

		memset( flg, -1, sizeof( flg ) );
		memset( fr, 0, sizeof( fr ) );

		j = 0;
		
		for ( i = 0; i  < n; ++i )
		{
			scanf( "%d", &k );
			
			if ( flg[k] != -1 )
			{
				++fr[flg[k]].f;
			}
			else				
			{
				flg[k] = j++;
				++fr[flg[k]].f;
				fr[flg[k]].n = k;
			}
		}
				
		qsort( fr, j, sizeof( fr[0] ), comp );
		
		/*for ( i = 0; i < j; ++i )
		{
			printf( "%d %d\n", fr[i].n, fr[i].f );
		}*/
				
		struct U
		{
			vector <int> v;
		}	rs[10000 + 1];

		min = fr[0].f;
		
		//printf( "min = %d\n", min );

		for ( i = 0; i < min; ++i )
		{
			rs[i].v.push_back( fr[0].n );
		}
		
		q = 0;
		
		for ( i = 1; i < j; ++i )
		{
			for ( p = 0; p < fr[i].f; ++p )
			{
				rs[q].v.push_back( fr[i].n );
				q = ( q + 1 ) % min;
			}
		}
		
		printf( "%d\n", min );
		
		for ( i = 0; i < min; ++i )
		{
			printf( "%d", rs[i].v[0] );

			for ( j = 1; j < rs[i].v.size(); ++j )
			{
				printf( " %d", rs[i].v[j] );
			}

			printf( "\n" );
		}
	}
}