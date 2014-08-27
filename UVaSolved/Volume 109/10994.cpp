#include <stdio.h>

#define _int64 long long

_int64 digit( _int64 n, _int64 m )
{
	_int64 r;

	while ( m )
	{ 
		r = n % 10;
		n /= 10;
		--m;
	}

	return r;
}


int main()
{
	_int64 i, a, b, c, p, q, w, s;
	

	while ( scanf( "%lld %lld", &p, &q ) )
	{
		if ( p < 0 && q < 0 )
			break;

		w = 10;
		i = 1;
		s = 0;

		while ( 1 )
		{
			a = p - ( p % w );
			b = q - ( q % w );

			s += ( ( b - a ) / w ) * 45;
			//printf( "%d\t", s ); 
			
			if ( i == 1 )
			{
				c = digit( p, i );
				if ( c > 0 )
					s -= ( ( c - 1 ) * c ) / 2;
			}
			else
			{
				c = digit( p, i );
				if ( c > 0 )
				{
					if ( p % ( w / 10 ) != 0 )
						++c;
					s -= ( ( c - 1 ) * c ) / 2;
				}
			}

			c = digit( q, i );
			s += ( c * ( c + 1 ) ) / 2;
				
			
			w *= 10;
			++i;

			if ( b - a == 0 )
				break;
		}

		printf( "%lld\n", s ); 

		/*
		s = 0;
		for ( i = p; i <= q; ++i )
			s += lnd( i );
		printf( "%d\n", s ); 
		*/
	
	}

	return 0;
}

