#include <stdio.h>
#include <ctype.h>

char c, p;

int cnt;

int a[31];

int main()
{		
	while ( 1 )
	{
		if ( ( c = getchar() ) == EOF )
		{
			break;
		}
		
		if ( c == '#' )
		{		
			for ( int i = 1; i <= 30; ++i )
			{
				if ( a[i] )
				{
					printf( "%d %d\n", i, a[i] );
				}
				
				a[i] = 0;
			}

			printf( "\n" );
			
			cnt = 0;
			
			continue;
		}
		
		if ( ( c == '\n' && p != '-' ) || c == ' ' || c == '?' || c == '.' || c == ',' || c == '!' )
		{
			++a[cnt];
			
			cnt = 0;
		}
		else if ( isalpha( c ) )
		{
			++cnt;
		}

		p = c;
	}
	
	return 0;
}