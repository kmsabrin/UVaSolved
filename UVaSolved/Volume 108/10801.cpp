#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 0x7fffffff
#define MAXFLOORS 101
#define MAXLIFTS 6

int a[MAXLIFTS][MAXFLOORS][MAXFLOORS]; 
bool r[MAXLIFTS][MAXFLOORS];
int distance[MAXLIFTS][MAXFLOORS];
int time[MAXLIFTS]; 
int lifts;	
int target; 

int heap[MAXFLOORS * MAXLIFTS];
int heap_size;

int value( int i )
{
	return distance[i / 100][i % 100];
}

void insert_heap( int item )
{
	int i = ++heap_size;

	while ( i > 1 && value( heap[i / 2] ) > value( item ) )
	{
		heap[i] = heap[i / 2];
		i = i / 2;
	}

	heap[i] = item;
}

int find_key( int item )
{
	for ( int i = 1; i <= heap_size; ++i )
	{
		if ( heap[i] == item )
		{
			return i;
		}
	}

	return -1;
}

void decrease_key( int item )
{
	int i = find_key( item );

	if ( i == -1 )
	{
		insert_heap( item );
	}

	while ( i > 1 && value( heap[i / 2] ) > value( item ) )
	{
		heap[i] = heap[i / 2];
		i = i / 2;
	}

	heap[i] = item;
}

void extract_min( int &p, int &q )
{
	p = heap[1] / 100;
	q = heap[1] % 100;
	
	int i = 2;
	int k = heap[heap_size];

	--heap_size;

	while ( i <= heap_size )
	{
		if ( i < heap_size && value( heap[i] ) > value( heap[i + 1] ) )
			i = i + 1;

		if ( value( k ) <= value( heap[i] ) )
			break;

		heap[i / 2] = heap[i];
		i = 2 * i;
	}

	heap[i / 2] = k;	
}

void dijkstra( int lift, int start )
{
	int i, l, v, pre;

	bool intree[MAXLIFTS][MAXFLOORS];

	memset( intree, false, sizeof( intree ) );

	distance[lift][start] = 0;
	
	heap[1] = lift * 100 + start;
	heap_size = 1;
	
	l = lift, v = start;

	while ( 1 )
	{
		if ( heap_size == 0 )
		{
			break;
		}
		
		extract_min( l, v );
		
		intree[l][v] = true;		
		
		for ( i = 0; i < MAXFLOORS; ++i )
		{
			if ( a[l][v][i] != -1 )
			{				
				if ( a[l][v][i] + distance[l][v] < distance[l][i] )
				{								
					pre = distance[l][i];

					distance[l][i] = a[l][v][i] + distance[l][v];

					if ( pre == INF )
					{
						insert_heap( l * 100 + i );
					}
					else
					{
						decrease_key( l * 100 + i );
					}					
				}				
			}
		}
		
		if ( v != 0 )
		{
			for ( i = 0; i < lifts; ++i )
			{		
				if ( r[i][v] == true && distance[l][v] + 60 < distance[i][v] )
				{
					pre = distance[i][v];

					distance[i][v] = distance[l][v] + 60;

					if ( pre == INF )
					{
						insert_heap( i * 100 + v );
					}
					else
					{
						decrease_key( i * 100 + v );
					}
					
				}
			}
		}						
	}			
}


bool take_input()
{
	char str[1000], *p;
	int i, j, k;
	int u, v;
	int floor[MAXLIFTS][MAXFLOORS];

	if ( scanf( "%d %d", &lifts, &target ) == EOF )
	{
		return false;
	}

	for ( i = 0; i < lifts; ++i )
	{
		scanf( "%d", &time[i] );
	}

	memset( floor, -1, sizeof( floor ) );
	memset( r, false, sizeof( r ) );

	getchar();	
	for ( i = 0; i < lifts; ++i )
	{
		j = 0;
		gets( str );
		
		p = strtok( str, " " );		
		k = atoi( p );
		floor[i][j++] = k;
		r[i][k] = true;
			
		while ( ( p = strtok( NULL, " " ) ) )
		{	
			k = atoi( p );
			floor[i][j++] = k;		
			r[i][k] = true;
		}		
	}
	
	memset( a, -1, sizeof( a ) );	

	for ( i = 0; i < lifts; ++i )
	{
		for ( j = 0; floor[i][j + 1] != -1; ++j )
		{
			u = floor[i][j]; 
			v = floor[i][j + 1]; 			
			a[i][u][v] = a[i][v][u] = ( v - u ) * time[i];
		}
	}

	return true;
}

int main()
{
	int i, j, m;

	freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while ( 1 )
	{
		if ( take_input() == false )
		{
			break;
		}

		for ( i = 0; i < MAXLIFTS; ++i )
		{
			for ( j = 0; j < MAXFLOORS; ++j )
			{				
				distance[i][j] = INF;
			}
		}

		for ( i = 0; i < lifts; ++i )
		{
			if ( r[i][0] == true )
			{
				dijkstra( i, 0 );		
			}
		}

		m = INF;
		for ( i = 0; i < lifts; ++i )
		{
			if ( distance[i][target] < m )
			{
				m = distance[i][target];
			}
		}

		if ( m != INF )
		{
			printf( "%d\n", m );
		}
		else
		{
			printf( "IMPOSSIBLE\n" );
		}
	}

	return 0;
}





