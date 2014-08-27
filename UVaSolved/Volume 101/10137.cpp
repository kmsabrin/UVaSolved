// AD HOC

#include <math.h> 
#include <stdio.h> 

long double round( long double x, int precision ) 
{ 
	return floor( x * pow( 10.0, ( long double )precision ) + 0.5 ) / pow( 10.0, ( long double )precision ); 
} 

int main( void ) 
{ 
	int no, ii; 
	long double total, above, below, right, student[1000]; 
	
	while ( 1 ) 
	{ 
		scanf( "%d\n", &no ); 
		if ( !no ) 
			break; 
		for ( ii = total = 0; ii < no; ++ii ) 
		{ 
			scanf( "%Lf\n", &student[ii] ); 
			total += student[ii]; 
		} 
		right = round( ( total / no ), 2 ); 
		
		above = below = 0; 
		for ( ii = 0; ii < no; ++ii ) 
		{ 
			if ( student[ii] < right ) 
				below += right - student[ii]; 
			if ( student[ii] > right ) 
				above += student[ii] - right; 
		} 
		
		printf( "$%.2Lf\n", round( ( ( below < above ) ? below : above ), 2 ) ); 
	} 
	return 0; 
} 
