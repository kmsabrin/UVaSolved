#include <stdio.h>
#include <string.h>

#define MAX 10000

int main()
{
	int i, j, k, tc;
	int f1[MAX], f2[MAX];
	char s1[MAX], s2[MAX], n1[MAX], n2[MAX];
	char c;

	//freopen( "a.in", "r", stdin );
	
	scanf( "%d\n", &tc );

	while ( tc-- )
	{

		gets( s1 );

		gets( s2 );

		memset( f1, 0, sizeof( f1 ) );

		memset( f2, 0, sizeof( f2 ) );

		for ( i = j = 0; i < ( int )strlen( s1 ); ++i )
		{			
			if ( f1[s1[i]] == 0 )
			{
				n1[j++] = s1[i];
			}

			f1[s1[i]]++;			
		}
		
		n1[j] = 0;
		
		for ( i = 0; i < j; ++i )
		{
			for ( k = 1; k < j; ++k )
			{
				if ( f1[n1[k]] > f1[n1[k - 1]] )
				{
					c = n1[k]; 
					n1[k] = n1[k - 1]; 
					n1[k - 1] = c;
				}
			}
		}

		//puts( n1 );





		for ( i = j = 0; i < ( int )strlen( s2 ); ++i )
		{			
			if ( f2[s2[i]] == 0 )
			{
				n2[j++] = s2[i];
			}

			f2[s2[i]]++;			
		}

		n2[j] = 0;

		for ( i = 0; i < j; ++i )
		{
			for ( k = 1; k < j; ++k )
			{
				if ( f2[n2[k]] > f2[n2[k - 1]] )
				{
					c = n2[k]; 
					n2[k] = n2[k - 1]; 
					n2[k - 1] = c;
				}
			}
		}

		//puts( n2 );

		for ( i = 0; i < ( int )strlen( s2 ); ++i )
		{
			for ( j = 0; ; ++j )
			{
				if ( s2[i] == n2[j] )
				{
					break;
				}
			}
			printf( "%c", n1[j] );
		}

		printf( "\n" );

		if ( tc )
		{
			getchar();
			printf( "\n" );
		}
	}

	return 0;
}



