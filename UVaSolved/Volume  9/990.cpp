#include <stdio.h>
#include <string.h>

int c[31][1001]; // dynamic table array
bool t[31][1001]; // table to denote if a item is taken or not taken
int v[31]; // value of items
int w[31]; // weight of items;
int d[31];
int n; // number of items; // kept from array location 1
int m; // maximum weight(knapsack weight)
int i, j; // counters or temporary variables
int sum;

void items_taken( int n, int m, int p )
{
	if ( n == 0 || m == 0 )
	{
		return;
	}
	
	if ( t[n][m] == true )
	{
		items_taken( n - 1, m - w[n], p );

		if ( p )
		{
			printf( "%d %d\n", d[n], v[n] );
		}
		else
		{
			++sum;
		}		
	}
	else
	{
		items_taken( n - 1, m, p );
	}
}

void zero_one_knapsack()
{
	for ( i = 0; i <= n; ++i ) // initialization
	{
		c[i][0] = 0;
	}
	
	for ( j = 0; j <= m; ++j ) // initialization
	{
		c[0][j] = 0;
	}
	
	for ( i = 1; i <= n; ++i )
	{
		for ( j = 1; j <= m; ++j )
		{
			if ( w[i] > j )
			{
				c[i][j] = c[i - 1][j];
				t[i][j] = false;
			}
			else
			{
				if ( c[i - 1][j] < c[i - 1][j - w[i]] + v[i] )
				{
					c[i][j] = c[i - 1][j - w[i]] + v[i];
					t[i][j] = true;
				}
				else
				{
					c[i][j] = c[i - 1][j];
					t[i][j] = false;
				}
			}
		}
	}

	printf( "%d\n", c[n][m] );

	sum = 0;

	items_taken( n, m, 0 );

	printf( "%d\n", sum );

	items_taken( n, m, 1 );

	printf( "\n" );
}

void main()
{
	int l, i, f = 0;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d %d", &m, &l ) != EOF )
	{		
		if ( f )
		{
			printf( "\n" );
		}

		f = 1;

		scanf( "%d", &n );
		
		for ( i = 1; i <= n; ++i )
		{
			scanf( "%d %d", &d[i], &v[i] );
			
			w[i] = 3 * d[i] * l;						
		}
		
		zero_one_knapsack();
	}
}
