#include <stdio.h>
#include <string.h>

char table[1000][10];
char match[10];

int index;
int f;

bool found( char s[] )
{
	for ( int i = 0; i < index; ++i )
	{
		if ( !strcmp( table[i], s ) )
		{
			return true;
		}
	}
	
	return false;
}

void call( char s[] )
{		
	if ( f )
	{
		return;
	}
	
	if ( found( s ) )
	{
		return;
	}
	
	if ( !strcmp( s, match ) )
	{
		f = 1;
		return;
	}

	strcpy( table[index++], s );
			
	char t[10];
				
	t[0] = s[0]; t[1] = s[2]; t[2] = s[4]; t[3] = s[1]; t[4] = s[3]; t[5] = s[5]; t[6] = 0;
	
	call( t );
	
	
	t[0] = s[0]; t[1] = s[3]; t[2] = s[1]; t[3] = s[4]; t[4] = s[2]; t[5] = s[5]; t[6] = 0;
	
	call( t );
	
	
	t[0] = s[4]; t[1] = s[0]; t[2] = s[2]; t[3] = s[3]; t[4] = s[5]; t[5] = s[1]; t[6] = 0;
	
	call( t );
	
	
	t[0] = s[1]; t[1] = s[5]; t[2] = s[2]; t[3] = s[3]; t[4] = s[0]; t[5] = s[4]; t[6] = 0;
	
	call( t );
}

void main()
{
	int i, j;
	
	char s[20], t[10];
	
	//freopen( "a.in", "r", stdin );

	//freopen( "a.out", "w", stdout );
	
	while ( scanf( "%s", s ) != EOF )
	{
		for ( i = 0; i < 6; ++i )
		{
			t[i] = s[i];
		}
		
		t[i] = 0;
		
		for ( i = 6, j = 0; s[i]; ++i )
		{
			match[j++] = s[i];
		}
		
		match[j] = 0;
		
		index = 0;
		
		f = 0;
		
		call( t );
				
		if ( f )
		{
			printf( "TRUE\n" );
		}
		else
		{
			printf( "FALSE\n" );
		}
	}
}


