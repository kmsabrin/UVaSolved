#include <stdio.h>

#define MAX 1111111

int indv[11], order[11];
int item, combo, price, minprice;
int combpr[11][11];

int canTake( int s )
{
	int i;
	for ( i = 0; i <item; ++i )
	{
		if ( combpr[s][i] > order[i] )
			return 0;
	}
	return 1;
}

int take( int s )
{
	int i;
	for ( i = 0; i < item; ++i )
		order[i] -= combpr[s][i];
	price += combpr[s][item];
	return 0;
}

int untake( int s )
{
	int i;
	for ( i = 0; i < item; ++i )
		order[i] += combpr[s][i];
	price -= combpr[s][item];
	return 0;
}

int takeRemain()
{
	int hld, i;
	hld = price;
	for ( i = 0; i < item; ++i )
	{
		if ( order[i] )
			price += order[i] * indv[i];
	}
	if ( price < minprice )
		minprice = price;
	price = hld;
	return 0;
}

int call( int s )
{
	int i;
	for ( i = s; i < combo; ++i )
	{
		if ( canTake( i ) )
		{
			take( i );
			takeRemain();

			call( i );

			untake( i );
		}
	}
	return 0;
}

int main()
{
	int i, j, o;

	//freopen( "a.in", "r", stdin );

	while ( scanf( "%d", &item ) != EOF )
	{

		for ( i = 0; i < item; ++i )
			scanf( "%d", &indv[i] );

		scanf( "%d", &combo );

		for ( i = 0; i < combo; ++i )
			for ( j = 0; j <= item; ++j )
				scanf( "%d", &combpr[i][j] );

		scanf( "%d", &o );

		while ( o-- )
		{
			for ( i = 0; i < item; ++i )
				scanf( "%d", &order[i] );

			price = 0;
			minprice = MAX;
			takeRemain();
			call( 0 ) ;
			printf( "%d\n", minprice );
		}
	}
	return 0;
}