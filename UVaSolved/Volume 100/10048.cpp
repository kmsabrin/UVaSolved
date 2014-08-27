#include <stdio.h>

int w[250][250];

int min( int i, int j )
{
	if ( i < j )
		return i;
	return j;
}

int max( int i, int j )
{
	if ( i > j )
		return i;
	return j;
}

int main()
{
	int c, s, q, t;
	int i, j, k;
	int tc = 0;
	int flg = 0;

	//freopen( "in.in", "r", stdin );
	
	while ( scanf( "%d %d %d", &c, &s, &q ) && c && s && q )
	{

		for ( i = 1; i <= c; ++i )
			for ( j = 1; j <= c; ++j )
				w[i][j] = 1111111;

		for ( i = 0; i < s; ++i )
		{
			scanf( "%d %d %d", &j, &k, &t );
			w[j][k] = w[k][j] = t;
		}
	
		for ( k = 1; k <= c; ++k )
			for ( i = 1; i <= c; ++i )
				for ( j = 1; j <= c; ++j )
					w[i][j] = min( w[i][j], max( w[i][k], w[k][j] ) );

		if ( flg )
			printf( "\n" );
		flg =1;

		printf( "Case #%d\n", ++tc );		
		for ( i = 0; i < q; ++i )
		{
			scanf( "%d %d", &j, &k );
			if ( w[j][k] == 1111111 )
				printf( "no path\n" );
			else
				printf( "%d\n", w[j][k] );
		}		

	}

	return 0;

}
