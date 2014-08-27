#include <stdio.h>
#include <string.h>

#define MIN( a, b ) ((a) < (b)) ? (a) : (b)

#define MAX( a, b ) ((a) > (b)) ? (a) : (b)

#define INF 0xFFFFFFF

char state[1001][1001];

int len[1001][1001];

int success, Ca, Cb, N;

int step[10000];

char all_steps[][10] = {  "empty A", "empty B", "fill A", "fill B", "pour A B", "pour B A" };

int call( int Ha, int Hb, int index )
{
	if ( success || state[Ha][Hb] || len[Ha][Hb] < index )
	{
		return 0;
	}

	state[Ha][Hb] = 1;

	len[Ha][Hb] = index;

	if ( Ha == N || Hb == N )
	{
		for ( int i = 0; i < index; ++i )
		{
			puts( all_steps[step[i]] );
		}

		puts( "success" );

		success = 1;

		return 0;
	}
	
	// empty A
	
	step[index] = 0;

	call( 0, Hb, index + 1 );

	// empty B

	step[index] = 1;

	call( Ha, 0, index + 1 );

	// fill A

	step[index] = 2;

	call( Ca, Hb, index + 1 );

	// fill B

	step[index] = 3;

	call( Ha, Cb, index + 1 );

	// pour A B

	step[index] = 4;

	int v = MIN( Ha, Cb - Hb );

	call( Ha - v, Hb + v, index + 1 );

	// pour B A

	step[index] = 5;

	v = MIN( Hb, Ca - Ha );

	call( Ha + v, Hb - v, index + 1 );

	return 0;
}

int main()
{
	while ( scanf( "%d %d %d", &Ca, &Cb, &N ) != EOF )
	{
		success = 0;
	
		for ( int i = 0; i <= Cb; ++i )
		{
			for ( int j = 0; j <= Cb; ++j )
			{
				state[i][j] = 0;
				len[i][j] = INF;
			}
		}

		len[0][0] = 0;

		len[Ca][0] = 1; 
		
		len[0][Cb] = 1; 

		call( 0, 0, 0 );
	}

	return 0;
}