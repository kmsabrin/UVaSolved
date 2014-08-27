//#include <conio.h>
#include <stdio.h>
#include <string.h>


int main()
{
	int n, i, j, k, num, m, s;
	char *p;
	int letter[200];
	char word[100], t2[100], tmp[1000];
	char str[1000][20];

//	clrscr();
//	freopen( "a.in", "r", stdin );
//	freopen( "a.out", "w", stdout );

	scanf( "%d\n", &n );

	for ( i = 0; i< n; ++i )
	{
		gets( tmp );

		s = 0;
		p = strtok( tmp,  " " );
		strcpy( str[s++], p );
		while ( ( p = strtok( NULL, " " ) ) != NULL )
			strcpy( str[s++], p );
		num = s;


//		for ( s = 0; s < num; ++s )
//			puts( str[s] );

		gets( word );

		memset( letter, 0, sizeof( letter ) ) ;
		for ( j = 0; j < 26; ++j )
		{
			strcpy( t2, word );
			for ( k = 0; t2[k]; ++k )
			{
				m = t2[k] + j;
				if ( m > 122 )
					m = m - 122 + 97 - 1;
				t2[k] = m;
			}
//			puts( t2 );

			for ( k = 0; k < num; ++k )
			{
				if ( !strcmp( str[k], t2 ) )
				{
					letter[j + 97] = 1;
					break;
				}
			}
		}
		for ( s = 97; s < 123; ++s )
			if ( letter[s] )
				printf( "%c", s );
		printf( "\n" );
	}
	return 0;
}

