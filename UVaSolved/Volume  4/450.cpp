#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 100

struct p
{
	char dept[size], title[size], first[size],
		 last[size], street[size], home[size],
		 work[size], mail[size];
} nlist[10000];

int comp( const void *i, const void *j )
{
	struct p* x = (struct p*)i;
	struct p* y = (struct p*)j;

	return strcmp( x->last, y->last );
}

void main()
{
	char str[10000], tmp[100], *p;

	int i, j, n;

	//freopen( "a.in", "r", stdin );

	while ( gets( str ) )
	{
		n = atoi( str );

		for ( j = i = 0; j < n; ++j )
		{
			gets( tmp );

			while ( gets( str ) && *str )
			{
				strcpy( nlist[i].dept, tmp );

				p = strtok( str, "," );

				strcpy( nlist[i].title, p );

				p = strtok( NULL, "," );

				strcpy( nlist[i].first, p ); 

				p = strtok( NULL, "," );

				strcpy( nlist[i].last, p ); 

				p = strtok( NULL, "," );

				strcpy( nlist[i].street, p ); 

				p = strtok( NULL, "," );

				strcpy( nlist[i].home, p ); 

				p = strtok( NULL, "," );

				strcpy( nlist[i].work, p ); 

				p = strtok( NULL, "," );

				strcpy( nlist[i].mail, p ); 

				++i;
			}
		}

		j = i;

		qsort( nlist, i, sizeof( nlist[0] ), comp );

		for ( i = 0; i < j; ++i )
		{
			printf( "----------------------------------------\n" );

			printf( "%s %s %s\n", nlist[i].title, nlist[i].first, nlist[i].last );

			printf( "%s\n", nlist[i].street );

			printf( "Department: %s\n", nlist[i].dept ); 

			printf( "Home Phone: %s\n", nlist[i].home ); 

			printf( "Work Phone: %s\n", nlist[i].work ); 

			printf( "Campus Box: %s\n", nlist[i].mail );
		}
	}
}