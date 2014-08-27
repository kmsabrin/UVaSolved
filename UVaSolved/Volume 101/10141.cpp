// AD HOC


#include<stdio.h>
#include<string.h>

int main()
{
	char str[100], tmp[100], bogus[100];
	int n, p, flg, tcase;
	int i, r, k, y;
	double j, x;
	flg = 0;
	tcase = 1;
	//freopen("always.in", "r", stdin);
	while(1)
	{
		scanf( "%d %d", &n, &p );
		getchar();
		if( n == 0 && p == 0 )
			break;
		x = y = 0;
		if( flg == 1 )
			printf( "\n\n" );
		flg = 1;
		
		for( i = 0; i < n; i++)
			gets( bogus );
		for( i = 0; i < p; i++)
		{
			gets( tmp );
			scanf( "%lf %d", &j, &k );
			getchar();
			for( r = 0; r < k; r++)
				gets( bogus );
			if( k > y )
			{
				strcpy( str, tmp );
				y = k;
				x = j;
			}
			else if( k == y )
			{
				if( j < x )
				{
					strcpy( str, tmp );
					y = k;
					x = j;
				}
			}
		}
		
		printf("RFP #%d\n", tcase);
		tcase++;
		printf( "%s", str );
	}
	return 0;
}
@END_OF_SOURCE_CODE
