#include <stdio.h>
#include <string.h>

int sum, deg, f;

int sumOfDigits( int n )
{
	int k = 0;
	while ( n )
	{
		k += n % 10;
		n /= 10;
	}
	return k;
}


int call()
{
	if ( sum < 10 )
	{
		if ( sum % 9 == 0 )
			f = 1;
	}
	else
	{
		sum = sumOfDigits( sum );
		++deg;
		call();		
	}

	return 0;
}




int main()
{
	char str[1111];

	while ( gets( str ) )
	{
		if ( str[0] == '0' )
			break;

		f = 0;
		deg = 1;
		sum = 0;
		if ( strlen( str ) == 1 )
		{			
			sum = str[0] - 48;
			if ( sum % 9 == 0 )
				f = 1;
		}
		else
		{
			for ( int i = 0; str[i]; ++i )
				sum += str[i] - 48;
			call();

		}

		if ( f )
			printf( "%s is a multiple of 9 and has 9-degree %d.\n", str, deg );
		else
			printf( "%s is not a multiple of 9.\n", str );
	}

	return 0;
}
