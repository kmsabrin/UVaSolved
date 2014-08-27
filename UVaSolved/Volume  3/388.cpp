#include <stdio.h>

#include <string.h>

#define MAXNODES 30

#define SIZE 1001 

char a[MAXNODES][MAXNODES];

char visited[MAXNODES];

int length[MAXNODES];

int nNodes;  

double w[MAXNODES];

int head, tail, count; 

struct
{
	int x; 
} q[SIZE + 10];

void init_queue()
{
	head = 0;
	tail = SIZE - 1;
	count = 0;
}

void push( int u )
{
	tail = ( tail + 1 ) % SIZE;
	q[tail].x = u;
	++count;
}

void pop( int &u )
{
	u = q[head].x;
	head = ( head + 1 ) % SIZE;
	--count;
}

int empty()
{
	if ( count == 0 )
	{
		return 1;
	}
	return 0;
}

void bfs( int s )
{
	int i, j, k;
	
	double tmp, max;
	
	init_queue();
	
	memset( visited, 0, sizeof( visited ) );
	
	memset( length, -1, sizeof( length ) );
	
	visited[s] = 1;
	
	length[s] = 0;
	
	push( s );
	
	while ( !empty() )
	{
		pop( s );
		
		for ( i = 0; i <= nNodes; ++i )
		{
			if ( a[s][i] && !visited[i] )
			{
				visited[i] = 1;
				
				length[i] = length[s] + 1;
				
				push( i );
			}
		}
	}
	
	max = 0;
	
	for ( i = 1; i <= nNodes; ++i )
	{
		if ( length[i] != -1 )
		{
			tmp = w[i];
			
			j = length[i] - 1;
			
			while ( j-- )
			{
				tmp = tmp - ( tmp * 0.05 );
			}
			
			if ( tmp > max )
			{
				max = tmp;
				
				k = i;
			}
		}
	}
	
	printf( "Import from %c\n", k + 64 );
}

void main()
{
	int i, j, s, r;
	
	double v;
	
	char s1[3], s2[50];

	//freopen( "a.in", "r", stdin );
	
	while ( scanf( "%d", &r ) != EOF )
	{		
		memset( a, 0, sizeof( a ) );

		for ( i = 0; i < r; ++i )
		{
			scanf( "%s %lf %s", s1, &v, s2 );
			
			s = s1[0] - 64;
			
			for ( j = 0; s2[j]; ++j )
			{
				if ( s2[j] == '*' )
				{
					a[0][s] = a[s][0] = 1;
				}
				else
				{
					a[s][s2[j] - 64] = a[s2[j] - 64][s] = 1;
				}
			}
			
			w[s] = v;
		}
		
		nNodes = 26;
		
		bfs( 0 );
	}
}
