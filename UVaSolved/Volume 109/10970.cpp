#include<stdio.h>

int main()
{
	int r, c;

	while ( scanf( "%d %d", &r, &c ) != EOF )	
		printf( "%d\n", r * c - 1  );

	return 0;
}