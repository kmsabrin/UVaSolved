#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 0x7FFFFFF

struct node
{
	char str[21];
	int index;
	node *left, *right, *parent;
}	*root, *nil;

struct
{
	char n[11];
	int v;
}	road[101][101];

char junction[101][21];
char parent[101][101];

int search( char key[] )
{
	node *x = root;

	while ( x != nil )
	{
		if ( strcmp( key, x->str ) == 0 )
		{
			return x->index;
		}
		else if ( strcmp( key, x->str ) < 0 )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	return -1;
}

void insert( char str[], int index )
{
	node* y = nil;
	node* x = root;

	while ( x != nil )
	{
		y = x;

		if ( strcmp( str, x->str ) == 0 )
		{
			return;
		}
		else if( strcmp( str, x->str ) < 0 )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	node* z = ( node * )malloc( sizeof( node ) );
	z->parent = y;
	strcpy( z->str, str );
	z->index = index;
	z->left = z->right = nil;

	if ( y == nil )
	{
		root = z;
	}
	else
	{
		if ( strcmp( str, y->str ) < 0 )
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
	}
}

void print_path( int s, int d ) // s = source, d = destination
{
	if ( parent[s][d] != -1 )
	{
		print_path( s, parent[s][d] );			
		printf( "%-20s %-20s %-10s %5d\n", junction[parent[s][d]], junction[d], road[parent[s][d]][d].n, road[parent[s][d]][d].v  );
	}
}

void main()
{	
	char str[1000], *p;

	int u, v, cnt;

	int i, j, k, nNodes;

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	nil = ( node * ) malloc ( sizeof( node * ) );
	root = nil;

	cnt = 0;

	for ( i = 0; i < 101; ++i )
	{
		for ( j = 0; j < 101; ++j )
		{
			if ( i != j )
			{
				road[i][j].v = INF;
			}
			else
			{
				road[i][j].v = 0;
			}			

			parent[i][j] = -1;
		}
	}

	while ( gets( str ) && *str )
	{
		p = strtok( str, "," );

		u = search( p );

		if ( u == -1 )
		{
			insert( p, cnt );
			strcpy( junction[cnt], p );
			u = cnt++;
		}
		
		p = strtok( NULL, "," );
		
		v = search( p );

		if ( v == -1 )
		{
			insert( p, cnt );
			strcpy( junction[cnt], p );
			v = cnt++;
		}
		
		p = strtok( NULL, "," );
		
		char tmp[21];

		strcpy( tmp, p );

		p = strtok( NULL, "," );
		
		k = atoi( p );

		if ( road[u][v].v && k < road[u][v].v )
		{
			strcpy( road[u][v].n, tmp );

			road[u][v].v = k;

			road[v][u] = road[u][v];
				
			parent[u][v] = u;		

			parent[v][u] = v;		
		}
	}

	nNodes = cnt;	
	
	for ( k = 0; k < nNodes; ++k )
	{
		for ( i = 0; i < nNodes; ++i )
		{
			for ( j = 0; j < nNodes; ++j )
			{
				if ( road[i][k].v + road[k][j].v < road[i][j].v )
				{
					road[i][j].v = road[i][k].v + road[k][j].v;
					parent[i][j] = parent[k][j];
				}
			}
		}
	}

	while ( gets( str ) && *str )
	{
		p = strtok( str, "," );

		u = search( p );

		p = strtok( NULL, "," );
		
		v = search( p );

		printf( "\n\n" );
		printf( "From                 To                   Route      Miles\n" );
		printf( "-------------------- -------------------- ---------- -----\n" );

		print_path( u, v );
		
		printf( "%-53s-----\n", "" );
        printf( "%-42sTotal      %5d\n", "", road[u][v].v );				
	}
}


