#include <stdio.h>

void main()
{
	int a, b, c, d, e, f;

	int e1, e2;

	// unsigned long long s;

	int s;

	int m, n;

	//freopen( "a.in", "r", stdin );

	while ( 1 )
	{
		scanf( "%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f );

		if ( !a && !b && !c && !d && !e && !f )
		{
			break;
		}

		s = 0;

		e1 = 0;

		e2 = 0;


		// process f

		s += f;


		// process e

		e1 += e * 11;

		s += e;

		
		// process d

		e2 += d * 5;

		e1 += d * 20;

		s += d;
		

		// process c

		if ( c % 4 == 0 )
		{
			s += c / 4;
		}
		else
		{
			int t2[] = { 0, 1, 3, 5 };

			int t1[] = { 0, 9, 18, 27 };

			m = 4 - ( c % 4 );

			e2 += t2[m];

			e1 += t1[m];

			s += ( c / 4 ) + 1;
		}


		// process b

		if ( b > e2 )
		{
			e1 -= e2 * 4;

			b -= e2;
		}
		else
		{
			e1 -= b * 4;

			b = 0;
		}

		if ( b )
		{
			if ( b % 9 == 0 )
			{
				s += b / 9;
			}
			else
			{
				n = 9 - ( b % 9 );

				e1 += n * 4;

				s += ( b / 9 )  + 1;
			}
		}


		// process a

		if ( a > e1 )
		{
			a -= e1;
		}
		else
		{
			a = 0;
		}

		if ( a )
		{
			if ( a % 36 == 0 )
			{
				s += a / 36;
			}
			else
			{
				s += ( a / 36 ) + 1;
			}
		}

		// printf( "%llu\n", s );

		printf( "%d\n", s );
	}
}
