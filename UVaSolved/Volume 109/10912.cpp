#include <stdio.h>

int num, sum;
int store[27][352];

int call( int n )
{
	if ( num > 26 )
		return 0;

	if ( sum > 351 )
		return 0;

	++store[num][sum];

	for ( int i = n + 1; i <= 26; ++i )
	{
		++num;
		sum += i;

		call( i );

		--num;
		sum -= i;
	}

	return 0;
}

int main()
{
	int c = 0;
	int L, S, R;

	call( 0 );

	while ( scanf( "%d %d", &L, &S ) && L && S )
	{
		if ( L > 26 || S > 351 )
			R = 0;
		else
			R = store[L][S];

		printf( "Case %d: %d\n", ++c, R );
	}


	return 0;
}

