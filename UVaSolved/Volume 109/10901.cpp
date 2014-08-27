#include <stdio.h>

struct S
{
	int time;
	int end;
	int index;
}	L[10001];

struct R
{
	int time;
	int end;
	int index;
}	R[10001];

int main()
{
	int n, T, m;
	
	char tmp[10];
	
	bool inLeft;
	
	int i, j, k, t, c;	
	
	int kase;
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &kase );
	
	while ( kase-- )
	{		
		scanf( "%d %d %d", &n, &T, &m );
		
		for ( i = j = k = 0; i < m; ++i )
		{
			scanf( "%d %s", &t, tmp );
			
			if ( tmp[0] == 'l' )
			{
				L[j].time = t;
				L[j].index = i;
				++j;
			}
			else
			{
				R[k].time = t;
				R[k].index = i;
				++k;
			}
		}

		L[j].time = R[k].time = 100000;
		
		t = j = k = c = 0;
		
		inLeft = true;
		
		while ( c < m )
		{		
			if ( inLeft )
			{
				i = 0;
				
				while ( i < n && L[j].time <= t )
				{
					L[j].end = t + T;
					++i;
					++j;
					++c;
				}
				
				if ( i )
				{
					t += T;
					inLeft = false;
				}
				else
				{
					if ( R[k].time <= t )
					{
						t += T;
						inLeft = false;
					}
					else
					{
						++t;
					}
				}
			}
			else
			{
				i = 0;
				
				while ( i < n && R[k].time <= t )
				{
					R[k].end = t + T;
					++i;
					++k;
					++c;
				}
				
				if ( i )
				{
					t += T;
					inLeft = true;
				}
				else
				{
					if ( L[j].time <= t )
					{
						t += T;
						inLeft = true;
					}
					else
					{						
						++t;
					}
				}
			}
		}				

		for ( i = j = k = 0; i < m; ++i )
		{
			if ( L[j].index == i )
			{
				printf( "%d\n", L[j].end );
				++j;
			}
			else
			{
				printf( "%d\n", R[k].end );
				++k;
			}
		}
		
		if ( kase )
		{
			printf( "\n" );
		}
	}
	
	return 0;
}




