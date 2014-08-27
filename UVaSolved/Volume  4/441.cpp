

/* @JUDGE_ID: 34556CP 441 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.80 - CRC: B76F977D **/
/** Date: 2004-02-25 02:59:42 +0100 **/


#include <stdio.h>

int main()
{
	int a[14], i, j, k, l, n, p, q, B = 0;
	
	while ( scanf( "%d", &n ) && n )
	{
		if ( B )
		{
			printf( "\n" );
		}

		B = 1;

		for ( i = 0; i < n; ++i )
		{
			scanf( "%d", &a[i] );
		}

		for ( i = 0; i < n; ++i )
		{
			for ( j = i + 1; j < n; ++j )
			{
				for ( k = j + 1; k < n; ++k )
				{
					for ( l = k + 1; l < n; ++l )
					{
						for ( p = l + 1; p < n; ++p )
						{
							for ( q = p + 1; q < n; ++q )
							{
								printf( "%d %d %d %d %d %d\n", a[i], a[j], a[k], a[l], a[p], a[q] );
							}
						}
					}
				}
			}
		}		
	}
	return 0;
}


