#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>

int main()
{
	char str[10000], operators[1000], variable[10];
	double operands[1000];
	int i, j, n, f, p, q = 0;
	double k;
	//freopen("a.in", "r", stdin); 
	// clrscr();
	while(gets(str))
	{

	i = strlen( str );

	str[i] = 32; str[i + 1] = '='; str[i + 2] = 32; str[i + 3] = 65; str[i + 4] = 0;

	//if(q == 1) printf("\n"); q = 1;
	i = j = 0;


	while(1)
	{
		while(str[i] == ' ') ++i;
		operands[j] = atof(str + i);
		++i;

		while(str[i] != '+' && str[i] != '-' &&
		      str[i] != '*' && str[i] != '/' && str[i] != '=') ++i;

		if(str[i] == '=') { j++; break; }

		operators[j++] = str[i];
		++i;
	}
	n = j;
	++i;
	while(str[i] == ' ') ++i;
	j = 0;
	while(str[i] && str[i] != ' ') variable[j++] = str[i++];
	variable[j] = 0;

	/*
	for(i = 0; i < n; ++i)
	{
		if(i == n - 1)
			printf("%ld = ", operands[i]);
		else
			printf("%ld %c ",operands[i], operators[i]);
	}
	puts(variable);*/



	while(1)
	{
		for( i = f = 0; i < n - 1; ++i )
			if(operators[i] == '*' || operators[i] == '/')
			{
				f = 1;
				break;
			}
		if(f == 0) break;

		for(i = 0; i < n - 1; ++i)
		{
			if(operators[i] == '*' || operators[i] == '/')
			{
				if(operators[i] == '*')
					k = operands[i] * operands[i+1];
				else
					k = operands[i] / operands[i+1];
				break;
			}
		}
		operands[i] = k;
		j = i;
		for( ++i; i < n; ++i)
			operands[i] = operands[i+1];
		for( ; j < n - 1; ++j)
			operators[j] = operators[j+1];

		--n;
		/*
		for(i = 0; i < n; ++i)
		{
			if(i == n - 1)
				printf("%ld = ", operands[i]);
			else
				printf("%ld %c ",operands[i], operators[i]);
		}
		puts(variable);
		*/

	}

	p = n - 1;
	while(p--)
	{
		i = 0;
		if(operators[i] == '+') k = operands[i] + operands[i+1];
		else k = operands[i] - operands[i+1];
		operands[i] = k;
		j = i;
		for( ++i; i < n; ++i)
			operands[i] = operands[i+1];
		for( ; j < n - 1; ++j)
			operators[j] = operators[j+1];

		--n;
		/*
		for(i = 0; i < n; ++i)
		{
			if(i == n - 1)
				printf("%ld = ", operands[i]);
			else
				printf("%ld %c ",operands[i], operators[i]);
		}
		puts(variable);
		*/
	}

	printf( "%.3lf\n", operands[0] );
	}
	return 0;
}

