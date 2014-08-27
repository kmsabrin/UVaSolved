#include <stdio.h>

int count, r, col;

struct
{
	char ch;
	int val;
} a[10000];

char b[60][60], cr;

int call( int x, int y )
{
	//printf( "%d %d\n", x, y );

	if ( x < 0 || y < 0 || x >= r || y >= col )
		return 0;

	if ( b[x][y] != cr )
		return 0;

	++count;

	b[x][y] = 0;

	call( x + 1, y );
	call( x - 1, y );
	call( x, y + 1 );
	call( x, y - 1 );	

	return 0;

}

int main()
{

	int i, j, k, tc = 1;
	int p;
	char q;

	//freopen ( "a.in", "r", stdin );
	//freopen ( "a.out", "w", stdout );

	while ( scanf( "%d %d", &r, &col ) && r && col )
	{

	getchar();

	for ( i = 0; i < r; ++i )
		gets( b[i] );

	
	k = 0;
	
	for ( i = 0; i < r; ++i )
		for ( j = 0; j < col; ++j )		
			if ( b[i][j] != 0 && b[i][j] != '.' )
			{
				count = 0;								

				cr = b[i][j];

				call( i, j );

				a[k].ch = cr;
				a[k].val = count;

				

				++k;
			}
			


	for ( i = 1; i < k; ++i )
		for ( j = 1; j < k; ++j )
		{
			if ( a[j].val > a[j - 1].val || 
				 ( a[j].val == a[j - 1].val && a[j].ch < a[j - 1].ch )
			   )
			{
				p = a[j].val, q = a[j].ch;
				a[j].val = a[j - 1].val, a[j].ch = a[j - 1].ch;
				a[j - 1].val = p, a[j - 1].ch = q; 
				//printf( "%c ", a[j]. ch );
			}
		}

	printf( "Problem %d:\n", tc++ );
	for ( i = 0; i < k; ++i )
		printf( "%c %d\n", a[i].ch, a[i].val );

	}

	return 0;
}

