#include <stdio.h>

int main()
{
	int n, p, x, y, k, s, d;

	while ( scanf( "%d %d", &n, &p ) && n && p )
	{

		x = y = ( n + 1 ) / 2;

		if ( p <= 1 )
		{
			x = x; 
			y = y; 
			k = 1;
		}
		else if ( p <= 9 )
		{
			x = x + 1; 
			y = y; 
			k = 3;
		}
		else
		{
			x = x + 2; 
			y = y + 1;

			for ( k = 5;	; k = k + 2 )
			{
				if ( p <= k * k )
					break;
				else
				{
					x = x + 1; 
					y = y + 1;
				}	
			}
		}

		s = ( k - 2 ) * ( k - 2 ) + 1;

		while ( 1 )
		{
			if ( p <= s + ( k - 2 ) )
			{
				d = p - s; 
				x = x; 
				if ( p > 1 )
					y = y - d;
				break;
			}
			else
			{
				s = s + ( k - 2 ) + 1; 
				x = x - 1; 
				y = y - ( k - 2 );
			}

			if ( p <= s + ( k - 2 ) )
			{
				d = p - s; 
				x = x - d; 
				y = y;
				break;
			}
			else
			{
				s = s + ( k - 2 ) + 1; 
				x = x - ( k - 2 ); 
				y = y + 1;
			}
		
			if ( p <= s + ( k - 2 ) )
			{
				d = p - s; 
				x = x; 
				y = y + d;
				break;
			}
			else
			{
				s = s + ( k - 2 ) + 1; 
				x = x + 1; 
				y = y + ( k - 2 );
			}
	
			if ( p <= s + ( k - 2 ) )
			{
				d = p - s; 
				x = x + d; 
				y = y;
				break;
			}
			else
			{	
				s = s + ( k - 2 ) + 1; 
				x = x + ( k - 2 ); 
				y = y - 1;
			}
		}

		printf( "Line = %d, column = %d.\n", x, y );
	}

	return 0;
}