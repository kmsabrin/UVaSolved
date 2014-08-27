#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char str[500];
	node *left, *right, *parent;
} *root, *nil;

node* search( char key[] )
{
	node *x = root;

	while ( x != nil )
	{
		if ( strcmp( x->str, key ) == 0 )
		{
			return nil;
		}
		else if ( strcmp( x->str, key ) < 0 )
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	return x;
}

node* tree_successor( node* x )
{
	if ( x->right != nil )
	{
		while ( x->left != nil )
		{
			x = x->left;
		}

		return x;
	}

	node* y = x->parent;

	while ( y != nil && x == y->right )
	{
		x = y;
		y = y->parent;
	}

	return y;
}

void insert_key( char str[] )
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

void delete_key( char key[] )
{
	node *x, *y;

	node* z = search( key );

	if ( z->left == nil || z->right == nil )
	{
		y = z;
	}
	else
	{
		tree_successor( z );
	}

	if ( y->left != nil )
	{
		x = y->left;
	}
	else
	{
		x = y->right;
	}

	if ( x != nil )
	{
		x->parent = y->parent;
	}

	if ( y->parent == nil )
	{
		root = x;
	}
	else
	{
		if ( y == y->parent->left )
		{
			y->parent->left = x;
		}
		else
		{
			y->parent->right = x;
		}
	}

	if ( y != z )
	{
		strcpy( z->str, y->str ); // copy all other data if present
	}
}

void in_order_walk( node *n )
{
	if ( n == nil )
	{
		return;
	}

	in_order_walk( n->left );

	puts( n->str ); // may also, free( n->str );

	in_order_walk( n->right );
}

int main()
{	
	int k, flg, f; 
	char c, tmp[500];

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	nil = ( node * ) malloc ( sizeof( node * ) );
	root = nil;

	flg = 1;

	while ( flg )
	{
		k = 0;

		f = 0;

		while ( 1 )
		{
			if ( ( c = getchar() ) == EOF )
			{
				flg =0 ;
				break;
			}

			if ( c == '\n' && k == 0 )
			{
				break;
			}

			if ( c == '\n' && f )
			{
				f = 0;
				continue;
			}

			if ( ( c =='\n' && !f ) | ( c != '-' && !isalpha( c ) ) )
			{
				break;
			}

			if ( f )
			{
				tmp[k++] = '-';
				f = 0;
			}

			if ( isalpha( c ) )
			{
				c = tolower( c );
				tmp[k++] = c;
			}

			if ( c == '-' )
			{
				f = 1;
			}
		}

		tmp[k] = 0;

		if ( k )
		{
			insert_key( tmp );
		}
	}

	in_order_walk( root );

	return 0;
}


