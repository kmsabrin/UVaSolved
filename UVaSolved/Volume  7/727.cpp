#include <stdio.h>

int preceed[128];

int isOperand( char c )
{
	if ( c >= 48 && c <= 57 )
		return 1;
	return 0;
}

int isOperator( char c )
{
	if ( c == '+' || c == '-' || c == '*' || c == '/' )
		return 1;
	return 0;
}

int setPrecedence()
{
	preceed['('] = 1;

	preceed['+'] = 2;
	preceed['-'] = 2;

	preceed['*'] = 3;
	preceed['/'] = 3;

	//preceed['^'] = 4;

	return 0;
}

int isLower( char a, char b )
{
	if ( preceed[a] < preceed[b] )
		return 1;
	return 0;
}

int main()
{
	char p[100], s[100], str[2];
	int i, pi, si, f, t;
	char c, d;

	//freopen( "a.in", "r", stdin );

	setPrecedence();

	scanf( "%d", &t );
	getchar();
	getchar();

	while ( t-- )
	{			
		si = 0;
		pi = 0;

		s[si++] = '(';

		f = 1;

		while ( 1 ) 
		{
			if ( !gets( str ) || !str[0] )
			{
				f = 0;
				c = ')';
			}
			else
				c = str[0];

			if ( isOperand( c ) )
				p[pi++] = c;

			else if ( c == '(' )
				s[si++] = c;

			else if ( isOperator( c ) )
			{
				while ( 1 ) 
				{
					d = s[--si];

					if ( isLower( d, c ) )
					{
						s[si++] = d;
						s[si++] = c;
						break;
					}
					else
						p[pi++] = d;
				}
			}

			else
			{
				while ( 1 )
				{
					d = s[--si];

					if ( d == '(' || si == 0 )
						break;
					else
						p[pi++] = d;
				}
			}

			if ( f == 0 )
				break;				
		}

		for ( i = 0; i < pi; ++i )
			printf( "%c", p[i] );
		printf( "\n" );

		if ( t )
			printf( "\n" );
	}

	return 0;
	
}



