#include <stdio.h>
#include <string.h>

int N, M;
int a[1000], b[1000], c[1000];
int atop, btop, ctop;
int count;

int pop( int src )
{
	int tmp;
	
	if ( src == 1 )
	{
		tmp = a[atop];
		--atop;
	}
	else if ( src == 2 )
	{
		tmp = b[btop];
		--btop;
	}
	else
	{
		tmp = c[ctop];
		--ctop;
	}

	return tmp;
}

int push( int item, int des )
{
	if ( des == 1 )
	{
		++atop;
		a[atop] = item;
	}
	else if ( des == 2 )
	{
		++btop;
		b[btop] = item;
	}
	else
	{
		++ctop;
		c[ctop] = item;
	}

	return 0;
}

int printAll()
{
	int i;

	printf( "A=>" );
	if ( atop )
	{
		printf( "   " );
		for ( i = 1; i < atop; ++i )
			printf( "%d ", a[i] );
		printf( "%d", a[atop] );
	}
	printf( "\n" );

	printf( "B=>" );
	if ( btop )
	{
		printf( "   " );
		for ( i = 1; i < btop; ++i )
			printf( "%d ", b[i] );
		printf( "%d", b[btop] );
	}
	printf( "\n" );

	printf( "C=>" );
	if ( ctop )
	{
		printf( "   " );
		for ( i = 1; i < ctop; ++i )
			printf( "%d ", c[i] );
		printf( "%d", c[ctop] );
	}
	printf( "\n\n" );

	return 0;
}

int towerOfHanoi( int n, int src, int aux, int des )
{
	int t; 
	
	if ( n > 1 )	
		towerOfHanoi( n - 1, src, des, aux );
	if ( count >= M )
		return 0;

	t = pop( src );
	push( t, des );
	printAll();
	++count;

	if ( n > 1 )
		towerOfHanoi( n - 1, aux, src, des );

	if ( count >= M )
		return 0;

	return 0;
}

int main()
{
	int i, t = 0;

	//freopen( "a.out", "w", stdout );

	while ( scanf( "%d %d", &N, &M ) )
	{
		if ( !N && !M )
			break;

		printf( "Problem #%d\n\n", ++t );

		for ( i = 1; i <= N; ++i )
			a[i] = N - i + 1;

		memset( b, 0, sizeof( b ) );
		memset( c, 0, sizeof( c ) );

		atop = N;
		btop = ctop = count = 0;

		printAll();

		towerOfHanoi( N, 1, 2, 3 );

		//while ( ++count <= M )
		//	printAll();
	
	}
	return 0;
}	