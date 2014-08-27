#include <alloc.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Node {
	char str[15];
	char color;
	Node *left, *right, *parent;
} *Root, *Nil;

int fixup( Node *z );

int leftRotate( Node *x )
{
	Node *y;
	y = x->right;
	x->right = y->left;
	y->left->parent = x;
	y->parent = x->parent;

	if ( x->parent == Nil )
		Root = y;
	else if ( x == x->parent->left )
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
	return 0;
}

int rightRotate( Node *x )
{
	Node *y;

	y = x->left;
	x->left = y->right;
	y->right->parent = x;
	y->parent = x->parent;

	if ( x->parent == Nil )
		Root = y;
	else if ( x == x->parent->right )
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
	return 0;
}

int insert( char str[] )
{
	Node *x, *y, *z;

	y = Nil;
	x = Root;

	while ( x != Nil )
	{
		y = x;
		if ( strcmp( str, x->str ) == 0 )
			return 0;
		else if( strcmp( str, x->str ) < 0 )
			x = x->left;
		else
			x = x->right;
	}

	z = ( Node * )malloc( sizeof( Node ) );
	z->parent = y;
	strcpy( z->str, str );
	z->color = 'R';
	z->left = z->right = Nil;

	if ( y == Nil )
		Root = z;
	else
	{
		if ( strcmp( str, y->str ) < 0 )
			y->left = z;
		else
			y->right = z;
	}

	fixup( z );
	return 0;
}

int fixup( Node *z )
{
	Node *y;

	while ( z->parent->color == 'R' )
	{
		if ( z->parent == z->parent->parent->left )
		{
			y = z->parent->parent->right;

			if ( y->color == 'R' )
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else
			{
				if ( z == z->parent->right )
				{
					z = z->parent;
					leftRotate( z );
				}

				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				rightRotate( z->parent->parent );
			}
		}
		else
		{
			y = z->parent->parent->left;

			if ( y->color == 'R' )
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else
			{
				if ( z == z->parent->left )
				{
					z = z->parent;
					rightRotate( z );
				}
				z->parent->color = 'B';
				z->parent->parent->color = 'R';
				leftRotate( z->parent->parent );
			}
		}
	}

	Root->color = 'B';
	return 0;
}

int inOrder( Node *n )
{
	if ( n == Nil )
		return 0;
	inOrder( n->left );
	puts( n->str );
	inOrder( n->right );
	return 0;
}

int main()
{
	int j, k;
	char tmp[201], str[15];

	Nil = ( Node * )malloc( sizeof( Node ) );
	Nil->color = 'B';
	Root = Nil;

	while ( gets( tmp ) )
	{
		j = 0;
		while ( tmp[j] )
		{
			while ( !isalpha( tmp[j] ) && tmp[j] )
				j++;
			k = 0;
			if ( isalpha( tmp[j] ) )
			{
				while ( isalpha( tmp[j] ) && tmp[j] )
					str[k++] = tolower( tmp[j++] );
				str[k] = 0;
				insert( str );
			}
		}
	}
	inOrder( Root );
	return 0;
}