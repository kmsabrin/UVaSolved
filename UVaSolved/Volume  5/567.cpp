

/* @JUDGE_ID: 34556CP 567 C++ "Submitted by Cd-Man's automatic submission tool ver 0.9" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.52 - CRC: 6E1A4EDA **/
/** Date: 2004-11-21 03:37:24 +0100 **/


#include <stdio.h>

#define max 21

int min( int a, int b )
{
	if ( a < b )
		return a;
	return b;
}

int main()
{
	int a[max][max];
	int i, j, k, e, t, test = 1;

	//freopen("a.in", "r", stdin ); 

	for ( i = 1; i <= 20; ++i )
		for ( j = 1; j <= 20; ++j )
			a[i][j] = 11111;

	// INPUT

	while ( scanf("%d", &e ) != EOF )
	{

	for ( j = 1; j <= e; ++j )
	{
		scanf ( "%d", &k );
		a[1][k] = a[k][1] = 1;
	}

	for ( i = 2; i <= 19; ++i )
	{
		// A PATH EXITS BETWEEN j & k WITH WEIGHT w
		scanf ( "%d", &e );
		for ( j = 1; j <= e; ++j )
		{
			scanf ( "%d", &k );
			a[i][k] = a[k][i] = 1;
		}
	}

	for ( k = 1; k <= 20; ++k )
		for ( i = 1; i <= 20; ++i )
			for ( j = 1; j <= 20; ++j )
				a[i][j] = min( a[i][j], a[i][k] + a[k][j] );


	printf("Test Set #%d\n", test++);
	scanf( "%d", &t );
	while ( t-- )
	{
		scanf( "%d %d", &i, &j );
		printf("%2d to %2d: %d\n", i, j, a[i][j]);
	}

	printf("\n");

	for ( i = 1; i <= 20; ++i )
		for ( j = 1; j <= 20; ++j )
			a[i][j] = 11111;

	}

	return 0;
}

