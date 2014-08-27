#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char word[100001][11];
char str[21], tmp[21];
int count, total;
int n, max;
int value[21], str_val[21];
int max_len;

int comp( const void *a, const void *b )
{
	return strcmp( ( char * )a, ( char * )b );
}

int cmp( const void *a, const void *b )
{
	return *( char * )a - *( char * )b ;
}

void get_dictionary()
{
	int i, j;
	char s[21];

	max_len = 0;

	scanf( "%d", &n );

	for ( i = 0; i < n; ++i )
	{
		scanf( "%s", s );
		
		j = strlen( s );
		if ( j > max_len )
		{
			max_len = j;
		}

		qsort( s, j, sizeof( char ), cmp );
		strcpy( word[i], s );
	}
	
	qsort( word, n, sizeof( word[0] ), comp );
}

int get_value( int a[], int r )
{
	int i, j = 0;

	for ( i = 0; i < r; ++i )
	{
		j += value[a[i]];
	}

	return j;
}

void call( int s )
{
	int i, j;

	str[count] = tmp[s];
	str_val[count++] = s;

	// check word
	str[count] = 0;
	if ( bsearch( str, word, n, sizeof( word[0] ), comp )  != NULL )
	{
		j = get_value( str_val, count );

		if ( j > max )
		{
			max = j;
		}			
		//puts( str );
	}
	//puts( str );

	if ( count == max_len )
	{
		return;
	}
				
	for ( i = s + 1; i < total; ++i )
	{	
		call( i );
		--count;
	}

}

void generate_all()
{
	int i;

	for ( i = 0; i < total; ++i )
	{
		count = 0;
		call( i );
	}
}

int main()
{
	int i, j, t, m, p;
	char c, s[21];

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
		
	get_dictionary();

	scanf( "%d", &m );

	while ( m-- )
	{

		scanf( "%d\n", &p );
						
		for ( i = 0; i < p; ++i )
		{
			gets( s );
			tmp[i] = s[0];

			j = atoi( s + 1 );			
			value[i] = j;						
		}

		// BUBBLE SORT
		for ( i = 0; i < p - 1; ++i )
		{
			for ( j = 1; j < p - i; ++j )
			{
				if ( tmp[j] < tmp[j - 1] )
				{
					c = tmp[j]; tmp[j] = tmp[j - 1]; tmp[j - 1] = c;
					t = value[j]; value[j] = value[j - 1]; value[j - 1] = t;
				}
			}		
		}

		max = 0;
		total = p;
		generate_all();
				
		printf( "%d\n", max );
	}

	return 0;
}