#include <stdio.h>
#include <string.h>

struct S
{
	char variable_name[15];
	char operand_one[15];
	char operand_two[15];
	char operator_type;
}	sentence[55];

int n;

int find_index( char str[] )
{
	for ( int i = 0; i < n; ++i )
	{
		if ( !strcmp( sentence[i].variable_name, str ) )
		{
			return i;
		}
	}
	
	return -1;
}

int call( int index, char str[] )
{
	char expanded_array[10000];
	
	char received_array[10000];
	
	int temp;
	
	expanded_array[0] = 0;
	
	if ( sentence[index].operand_one[0] > 60 )
	{
		temp = find_index( sentence[index].operand_one );
		
		call( temp, received_array );
		
		if ( sentence[index].operator_type == '*' && sentence[temp].operator_type == '+' )
		{
			strcat( expanded_array, "(" );
			
			strcat( expanded_array, received_array );
			
			strcat( expanded_array, ")" );
		}
		else
		{
			strcat( expanded_array, received_array );
		}	
	}
	else
	{
		strcat( expanded_array, sentence[index].operand_one );
	}
	
	if ( sentence[index].operator_type == '+' )
	{
		strcat( expanded_array, "+" );
	}
	else
	{
		strcat( expanded_array, "*" );
	}

	
	if ( sentence[index].operand_two[0] > 60 )
	{
		temp = find_index( sentence[index].operand_two );
		
		call( temp, received_array );
		
		if ( sentence[index].operator_type == '*' || sentence[temp].operator_type == '+' )
		{
			strcat( expanded_array, "(" );
			
			strcat( expanded_array, received_array );
			
			strcat( expanded_array, ")" );
		}
		else
		{
			strcat( expanded_array, received_array );
		}			
	}
	else
	{
		strcat( expanded_array, sentence[index].operand_two  );
	}
	
	strcpy( str, expanded_array );
	
	return 0;
}

int main()
{
	char str[10000];
	
	char dummy[1000], temp[1000];
	
	int i, T;

	int kase = 0;
	
	//freopen( "a.in", "r", stdin );
	
	scanf( "%d", &T );
	
	while ( T-- )
	{
		scanf( "%d", &n );
		
		for ( i = 0; i < n; ++i )
		{
			scanf( "%s", sentence[i].variable_name );
			
			scanf( "%s", dummy );
			
			scanf( "%s", sentence[i].operand_one );
			
			scanf( "%s", temp );
			
			sentence[i].operator_type = temp[0];
			
			scanf( "%s", sentence[i].operand_two );					
		}
		
		call( n - 1, str );
		
		printf( "Expression #%d: ", ++kase );

		puts( str );
	}
	
	return 0;
}



