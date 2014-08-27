#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp( const void *i, const void *j )
{
	return *( char * )i - *(char * )j;
}

char str[] = "abcdefghijklmnopqrstuvwxyz";
char table[100000][6];
char hold[100000][6];
char tmp[6];
int len, table_len, tmp_len;
int c_len;

void call( int s )
{
	int i;

	tmp[len++] = str[s];		
	
	if ( len == c_len )
	{
		tmp[len] = 0;		
		strcpy( hold[tmp_len++], tmp );
		--len;
		return;
	}	

	for ( i = s + 1; i < 26; ++i )
	{
		call( i );
	}

	--len;
}

int my_strcmp( char a[], char b[] )
{
	int i = strlen( a );
	int j = strlen( b );

	if ( i < j )
	{
		return -1;
	}
	else if ( i > j )
	{
		return 1;
	}
	else
	{
		return strcmp( a, b );
	}
}

int binary_search( char a[] )
{
	int i, j, k, mid;

	i = 0; j = table_len; mid = ( i + j ) / 2;

	while( i <= j )
	{
				
		//printf( "i = %d, j = %d, mid = %d\n", i, j, mid );

		k = my_strcmp( a, table[mid] );		

		//printf( "a = %s, mid = %s, so k = %d\n", a, table[mid], k );

		if ( k == 0 )
		{
			break;
		}
		else if ( k < 0 )
		{
			j = mid - 1;
		}
		else
		{
			i = mid + 1;
		}

		mid = ( i + j ) / 2;
	}

	return mid + 1;
}

int main()
{
	int i, j;
	char str[6];
		
	table_len = 0;

	for ( i = 1; i <= 5; ++i )
	{
		tmp_len = 0;
		c_len = i;

		for ( j = 0; j < 26; ++j )
		{
			len = 0;			
			call( j );
		}

		for ( j = 0; j < tmp_len; ++j )
		{
			strcpy( table[table_len++], hold[j] );			
		}		
	}
			
	while( gets( str ) )
	{
		strcpy( tmp, str );

		qsort( str, strlen( str ), sizeof( char ), comp );

		if ( strcmp( str, tmp ) == 0 )
		{
			printf( "%d\n", binary_search( str ) );
		}
		else
		{
			printf( "0\n" );
		}
	}



	return 0;
}