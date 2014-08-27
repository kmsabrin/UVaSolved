#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 110

#define MAX( i, j ) ((i) > (j)) ? (i) : (j)

#define MIN( i, j ) ((i) < (j)) ? (i) : (j)

struct G
{
	int time;
	int value;
	int state;
}	gangster[SIZE];

int comp( const void *i, const void *j )
{
	struct G* p = (struct G*)i;
	struct G* q = (struct G*)j;
	
	if ( p->time != q->time )
	{
		return p->time - q->time;
	}
	
	if ( p->state != q->state )
	{
		return p->state - q->state;
	}
	
	return q->value - p->value;
}

void main()
{
	int n, k, t, T;
	int i, j;
	int m, M;
	int u, l;
	int index, nArrival;
	int arrival[SIZE];
	int table[SIZE][SIZE];
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &T );
	
	while ( T-- )
	{		
		scanf( "%d %d %d", &n, &k, &t );
		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &gangster[i].time );
		}
		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &gangster[i].value );
		}
		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &gangster[i].state );
		}
		
		qsort( gangster, n, sizeof( gangster[0] ), comp );
				
		arrival[0] = 0;	
		
		nArrival = 0;
		
		for ( i = 0; i < n; ++i )
		{
			if ( gangster[i].time != arrival[nArrival] )
			{
				arrival[++nArrival] = gangster[i].time;
			}
		}
		
		++nArrival;
		
		table[0][0] = 0;
		
		for ( i = 1; i <= k; ++i )
		{
			table[0][i] = -1;
		}
		
		index = 0;

		while ( index < n && gangster[index].time == 0 )
		{
			++index;
		}
		
		for ( i = 1; i < nArrival; ++i )
		{		
			for ( j = 0; j <= k; ++j )
			{
				l = MAX( 0, j - arrival[i] + arrival[i - 1] );
				
				u = MIN( k, j + arrival[i] - arrival[i - 1] );
				
				M = -1;
				
				for ( m = l; m <= u; ++m )
				{
					if ( table[i - 1][m] > M )
					{
						M = table[i - 1][m];
					}					
				}
								
				if ( index < n && gangster[index].time == arrival[i] && gangster[index].state == j )
				{	
					int y = M;

					if ( M > -1 )
					{
						M += gangster[index].value;
					}
					
					++index;
					
					while ( index < n && gangster[index].time == arrival[i] && gangster[index].state == j )
					{
						if ( y > -1 )
						{
							M += gangster[index].value;
						}

						++index;
					}
				}
				
				table[i][j] = M;			
			}
		}
					
		M = 0;
		
		for ( i = 0; i <= k; ++i )
		{
			if ( table[nArrival - 1][i] > M )
			{
				M = table[nArrival - 1][i];
			}
		}
		
		printf( "%d\n", M );
		
		if ( T )
		{
			printf( "\n" );
		}
	}	
}