#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
} *head, *tmp, *current;

void del( struct node *n )
{
	struct node *i;

	if ( n == head )
	{
		head = head->next;
		return;
	}
	
	i = head;
	while ( i != NULL && i->next != n )
		i = i->next;

	i->next = i->next->next;

	return;
}


int main()
{
	int n, i, j, count;
	int a[53];
	char s[53][3], str[21];

	//freopen ( "a.in", "r", stdin );

	while ( scanf( "%d", &n ) && n )
	{
		
		for ( i = 1; i <= n; ++i )
		{
			tmp = (struct node *)malloc( sizeof( struct node ) );
			tmp->value = i;
			tmp->next = NULL;

			if ( head == NULL )
				head =  current = tmp;
			else
			{
				current->next = tmp;
				current = tmp;
			}
		}

		count = 0;
		memset ( a, 0, sizeof( a ) );

		tmp = head;

		for ( i = 1; i <= n; ++i )
		{
			scanf( "%s %s", s[i], str );
			
			j = strlen( str );

			while ( --j )
			{
				tmp = tmp->next;
				if ( tmp == NULL )
					tmp = head;				
			}

			count = tmp->value;

			//printf( "%d\n", count) ;

			a[count] = i;

			current = tmp->next;
			del( tmp );
			tmp = current;
			if ( tmp == NULL )
				tmp = head;
			
		}

		printf( "%s", s[a[1]] );
		for ( i = 2; i <= n; ++i )		
			printf( " %s", s[a[i]] );
		printf( "\n" );

	}

	return 0;
}