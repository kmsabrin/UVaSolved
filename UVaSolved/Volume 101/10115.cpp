// AD HOC

#include <stdio.h>
#include <string.h>

int main(void)
{
	char old[10][80];
	char now[10][80];
	char str[1000];
	char temp[1000];
	char *add, *ptr;
	int len;
	int i, j, n;
	//freopen("always.in","r", stdin);
	while( scanf( "%d", &n ) && n )
	{
		getchar();
		for( i = 0; i < n; i++ )
		{
			gets( old[i] );
			gets( now[i] );
		}
		gets( str );
		for(i = 0; i < n; i++ )
		{
			//if( now[i][0] == NULL ) continue;
			while( 1 )
			{
				ptr = strstr(str, old[i]);
				if( ptr == NULL )
					break;
				len = strlen(old[i]);
				add = ptr;
				add = add + len;
				j = 0;
				while( *( add + j ) )
				{
					temp[j] = *( add + j );
					j++;
					
				}
				temp[j] = NULL;
				*( ptr ) = NULL;
				strcat( str, now[i] );
				strcat( str, temp );
			}
		}
		printf( "%s\n", str );
	}
	return 0;
}


