#include <stdio.h>

struct point
{
	int x, y;
} p[60];

int direction( int i, int j, int k )
{
	return ( p[k].x - p[i].x ) * ( p[j].y - p[i].y ) - ( p[j].x - p[i].x ) * ( p[k].y - p[i].y );
}

int main()
{	
	int nPoints, i, CW, CCW;	
	
	//freopen( "b.in", "r", stdin );
		
	while ( scanf( "%d", &nPoints ) && nPoints )
	{										
		for ( i = 0; i < nPoints; ++i )
		{
			scanf( "%d %d", &p[i].x, &p[i].y );
		}
	
		p[nPoints++] = p[0];

		p[nPoints++] = p[1];

		for ( i = 2, CW = CCW = 0; i < nPoints; ++i )
		{
			if ( direction( i - 2, i - 1, i ) < 0 )
			{
				CCW = 1;
			}
			else
			{
				CW = 1;
			}
			
			if ( CW && CCW )
			{				
				break;
			}
		}
		
		if ( i < nPoints )
		{
			printf( "Yes\n" );
		}
		else
		{
			printf( "No\n" );
		}
	}
	
	return 0;
}


