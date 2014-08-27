//#include <conio.h>
#include <stdio.h>
#include <string.h>

struct
{
	int num;
	int colindex;
	int eleindex;
	int col[50];
	int elem[50];
}	sp[10000 + 1];


int main()
{
//	clrscr();
	int i, j, k, m, n, ele;
	int t1[1000], t2[1000];

//	freopen( "a.in", "r", stdin );
//	freopen( "a.out", "w", stdout );

	while ( scanf( "%d %d", &m, &n ) != EOF )
	{
		memset( sp, 0, sizeof( sp ) );

		for ( k = 1; k <= m; ++k )
		{
			scanf( "%d", &ele );

		 //	printf( "DEBUG1 %d %d %d\n", m, n, ele );

			for ( i = 1; i <= ele; ++i )
				scanf( "%d", &t1[i] );

			for ( i = 1; i <= ele; ++i )
				scanf( "%d", &t2[i] );

			for ( i = 1; i <= ele; ++i )
			{
				sp[ t1[i] ].num++;
				sp[ t1[i] ].col[ sp[ t1[i] ].colindex++ ] = k;
				sp[ t1[i] ].elem[ sp[ t1[i] ].eleindex++ ] = t2[i];
			}
		 }
		 //	printf( "DEBUG2: %d %d %d\n", sp[1].num, sp[1].colindex, sp[1].eleindex );


		 printf( "%d %d\n", n, m );
		 for ( i = 1; i <= n; ++i )
		 {
			printf( "%d", sp[i].num );
			if ( sp[i].num )
			{
				for ( j = 0; j < sp[i].num; ++j )
					printf( " %d", sp[i].col[j] );
				printf( "\n" );

				printf( "%d", sp[i].elem[0] );

				for ( j = 1; j < sp[i].num; ++j )
					printf( " %d", sp[i].elem[j] );

				printf( "\n" );
			}
			else
				printf( "\n\n" );
		}
	}
	return 0;
}