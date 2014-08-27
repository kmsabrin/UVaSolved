

/* @JUDGE_ID: 34556CP 384 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.71 - CRC: 3D6D72F4 **/
/** Date: 2004-05-05 12:03:38 +0200 **/


#include<stdio.h>

char str[61], index, flg, num;

int slump()
{
	if( str[++index] != 'D' && str[index] != 'E' ) { flg=0; return 0; }

	if( str[++index] != 'F' ) { flg=0; return 0; }
	while( str[index] == 'F' ) index++;

	if( str[index] == 'G' ) return 0;
	else { --index; slump(); }

	return 0;
}

int slimp()
{
	int i;
	if( str[++index] != 'A') { flg = 0; return 0; }

	if     ( str[++index] == 'H' ) return 0;
	else if( str[index] == 'B' )  slimp();
	else  { --index; slump(); }

	if( str[++index] != 'C') { flg = 0; return 0; }

	return 0;
}


int main()
{
//	freopen("always.in","r",stdin);
	scanf("%d", &num);
	getchar();
	printf("SLURPYS OUTPUT\n");
	while( num-- )
	{
		gets(str);
		flg = 1;
		index = -1;
		slimp();
		slump();
		if( str[++index] ) flg = 0;
		if(flg)
			printf("YES\n");
		else
			printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}

