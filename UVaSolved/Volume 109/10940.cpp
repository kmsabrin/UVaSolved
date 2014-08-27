#include <stdio.h>

int main()
{		
	int n;

	while( scanf( "%d", &n ) && n)
	{
		
		if ( n >= 262145 )
			n = ( n - 262144 ) * 2;
		else if ( n >= 131073 )
			n = ( n - 131072 ) * 2;
		else if ( n >= 65537 )
			n = ( n - 65536 ) * 2;
		else if ( n >= 32769 )
			n = ( n - 32768 ) * 2;
		else if ( n >= 16385 )
			n = ( n - 16384 ) * 2;
		else if ( n >= 8193 )
			n = ( n - 8192 ) * 2;	
		else if ( n >= 4097 )
			n = ( n - 4096 ) * 2;
		else if ( n >= 2049 )
			n = ( n - 2048 ) * 2;
		else if ( n >= 1025 )
			n = ( n - 1024 ) * 2;
		else if ( n >= 513 )
			n = ( n - 512 ) * 2;
		else if ( n >= 257 )
			n = ( n - 256 ) * 2;
		else if ( n >= 129 )
			n = ( n - 128 ) * 2;
		else if ( n >= 65 )
			n = ( n - 64 ) * 2;
		else if ( n >= 33 )
			n = ( n - 32 ) * 2;
		else if ( n >= 17 )
			n = ( n - 16 ) * 2;
		else if ( n >= 9 )
			n = ( n - 8 ) * 2;
		else if ( n >= 5 )
			n = ( n - 4 ) * 2;
		else if ( n >= 3 )
			n = ( n - 2 ) * 2;
		else if ( n >= 1 )
			n = n; 
	
		
	
	
	
		printf( "%d\n", n );

	}

	return 0;
}



		
		

		
		

