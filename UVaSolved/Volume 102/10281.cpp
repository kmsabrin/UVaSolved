#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char str[20], time[20], *p;
	
	double d = 0, v, t, et, lt = -1;

	//freopen( "a.in", "r", stdin );

	while ( gets( str ) )
	{
		p = strtok( str, " " );

		strcpy( time, p );

		t = atoi( p ) * 3600.0 + atoi( p + 3 ) * 60.0 + atoi( p + 6 );

		if ( lt != - 1 )
		{
			et = t - lt;

			d += (double)( v * et ) / 3600.0;
		}

		lt = t;

		if ( p = strtok( NULL, " " ) )
		{
			v = atoi( p );
		}
		else
		{			
			printf( "%s %.2lf km\n", time, d );
		}
	}
}