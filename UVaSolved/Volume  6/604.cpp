#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[1800][5] , arr1[1800][5], arr2[1800][5], board[5][5], board1[5][5], board2[5][5], used[5][5];
char tmp[5];
int count, wc, wc1, wc2;
int vowel[100];

int comp( const void *i, const void *j )
{
	return strcmp( ( char * )i, ( char * )j );
}

int is_word( char tmp[] )
{
	int i, j;

	for ( i = j = 0; i < ( int )strlen( tmp ); ++i )
	{
		if( vowel[tmp[i]] )
		{
			++j;
		}
	}

	if ( j == 2 )
	{
		return 1;
	}

	return 0;
}

int call( int p, int q )
{
	if ( p < 0 || q < 0 || p > 3 || q > 3 || used[p][q] )
	{
		return 0;
	}

	tmp[count++] = board[p][q];

	used[p][q] = 1;

	if ( count > 3 )
	{
		tmp[count] = 0;
		if ( is_word( tmp ) )
		{
			strcpy( arr[wc++], tmp );
		}
	}
	else
	{
		call( p + 1, q );
		call( p - 1, q );
		call( p, q + 1 );
		call( p, q - 1 );
		call( p + 1, q + 1 );
		call( p - 1, q + 1 );
		call( p + 1, q - 1 );
		call( p - 1, q - 1 );
	}

	used[p][q] = 0;
	--count;

	return 0;
}

int main()
{
	int i, j, k, f = 0;

	vowel['A'] = vowel['E'] = vowel['I'] = vowel['O'] =vowel['U'] = vowel['Y'] = 1; 

	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );

	while ( 1 )
	{
		for ( i = j = 0; i < 4; ++i )
		{
			gets( tmp );

			if ( tmp[0] == '#' )
			{
				return 0;
			}
		
			board1[j][0] = tmp[0]; board1[j][1] = tmp[2]; 
			board1[j][2] = tmp[4]; board1[j][3] = tmp[6]; board1[j][4] = 0;

			board2[j][0] = tmp[11]; board2[j][1] = tmp[13]; 
			board2[j][2] = tmp[15]; board2[j][3] = tmp[17]; board2[j][4] = 0;

			++j;
		}
		gets( tmp );

		if ( f )
		{
			printf( "\n" );
		}
		f = 1;
		

		
		count = wc = 0;
		memset( used, 0, sizeof( used ) );
		memcpy( board, board1, sizeof( board ) );

		for ( i = 0; i < 4; ++i )
		{
			for ( j = 0; j < 4; ++j )
			{
				call( i, j );
			}
		}

		qsort( arr, wc, sizeof( arr[0] ), comp );
		memcpy( arr1, arr, sizeof( arr ) );
		wc1 = wc;

	
		count = wc = 0;
		memset( used, 0, sizeof( used ) );
		memcpy( board, board2, sizeof( board ) );

		for ( i = 0; i < 4; ++i )
		{
			for ( j = 0; j < 4; ++j )
			{
				call( i, j );
			}
		}

		qsort( arr, wc, sizeof( arr[0] ), comp );
		memcpy( arr2, arr, sizeof( arr ) );
		wc2 = wc;

	
		/*
		for ( i = 0; i < wc; ++i )
			printf( "%s\n", arr1[i] );

		printf( "\n\n\n\n\n\n\n" );

		for ( i = 0; i < wc; ++i )
			printf( "%s\n", arr2[i] );
		*/
	
	
		k = 0;

		for ( i = 0; i < wc1; ++i )
		{
			if ( i > 0 && !strcmp( arr1[i], arr1[i - 1] ) )
			{
				continue;
			}

			if ( bsearch( arr1[i], arr2, wc2, sizeof( arr2[0] ), comp )  != NULL )
			{
				puts( arr1[i] );
				++k;
			}
		}

		if ( k == 0 )
		{
			puts( "There are no common words for this pair of boggle boards." );
		}		

		//printf( "%d %d\n", wc1, wc2 );

	}
	
	return 0;
}

