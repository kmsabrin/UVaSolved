#include <stdio.h>
#include <string.h>

char d_val[10];

char l_val[100];

char str[6][12];

int n, sum;

bool call( int p, int q )
{
	int i, k, h;
	
	if ( p < n - 1 && q >= (int)strlen( str[p] ) )
	{
		if ( call( p + 1, q ) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	if ( p == n - 1 && q >= (int)strlen( str[p] ) )
	{
		if ( l_val[str[p][q - 1]] == 0 )
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	if ( p == n - 1 )
	{
		k = sum % 10;
		
		sum = sum / 10;
		
		if ( l_val[str[p][q]] != -1 && l_val[str[p][q]] == k && d_val[k] != -1 && d_val[k] == str[p][q]  )
		{
			if ( call( 0, q + 1 ) )
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if ( l_val[str[p][q]] == -1 && d_val[k] == -1 )
		{
			l_val[str[p][q]] = k;
			
			d_val[k] = str[p][q];
			
			if ( call( 0, q + 1 ) )
			{
				return true;
			}
			else
			{						
				l_val[str[p][q]] = -1;
			
				d_val[k] = -1;			

				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if ( l_val[str[p][q]] != -1 )
		{
			h = sum;

			sum += l_val[str[p][q]];
			
			if ( call( p + 1, q ) )
			{
				return true;
			}
			else
			{
				sum = h;

				return false;
			}
		}
		else
		{
			for ( i = 0; i <= 9; ++i )
			{
				if ( d_val[i] == -1 )
				{
					l_val[str[p][q]] = i;
					
					d_val[i] = str[p][q];
					
					h = sum;

					sum += i;
					
					if ( call( p + 1, q ) )
					{
						return true;
					}

					sum = h;
					
					l_val[str[p][q]] = -1;
					
					d_val[i] = -1;
				}
			}
			
			return false;
		}
	}
}

void main()
{
	char tmp[12];
	
	int i, j, k, T;
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &T );
	
	while ( T-- )
	{		
		scanf( "%d", &n );
		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%s", tmp );
			
			for ( j = strlen( tmp ) - 1, k = 0; j >= 0; --j )
			{
				str[i][k++] = tmp[j];
			}
			
			str[i][k] = 0;	
		}

		sum = 0;

		memset( d_val, -1, sizeof( d_val ) );

		memset( l_val, -1, sizeof( l_val ) );
		
		call( 0, 0 );

		for ( i = 65; i <= 90; ++i )
		{
			if ( l_val[i] != -1 )
			{
				printf( "%c=%d", i, l_val[i] );
				break;
			}
		}

		for ( ++i; i <= 90; ++i )
		{
			if ( l_val[i] != -1 )
			{
				printf( " %c=%d", i, l_val[i] );				
			}
		}

		printf( "\n" );
	}
}

