
/* @JUDGE_ID: 34556CP 394 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.71 - CRC: F7677007 **/
/** Date: 2004-05-05 12:03:02 +0200 **/


#include <stdio.h>
//#include <conio.h>
#include <string.h>

int main()
{
	struct
	{
		char name[11];
		int base;
		int size;
		int dimension;
		int c[11];
		int lo[11];
		int up[11];
	}	array[50];
	
	int n, m, i, j, k, r, s, f;
	char str[11];
	//	clrscr();
	//	freopen("always.in","r",stdin);
	
	scanf("%d %d",&n, &m);
	for(i=0; i<n; i++)
	{
		scanf("%s", array[i].name);
		scanf("%d %d %d", &array[i].base, &array[i].size, &array[i].dimension);
		for(j=1; j <= array[i].dimension; j++)
			scanf("%d %d", &array[i].lo[j], &array[i].up[j]);
		k = array[i].dimension;
		array[i].c[k] = array[i].size;
		--k;
		while(k != 0)
		{
			array[i].c[k] = array[i].c[k+1] * (array[i].up[k+1] - array[i].lo[k+1] + 1);
			--k;
		}
		array[i].c[0] = array[i].base;
		s = 1;
		while( s <= array[i].dimension)
		{
			array[i].c[0] -= array[i].c[s] * array[i].lo[s];
			s++;
		}
		
		/* check point */
		/*
		printf("%d %d %d\n", array[i].base, array[i].size, array[i].dimension);
		for(s=0; s<= array[i].dimension; s++)
		printf("dim=%d  c=%d l=%d u=%d, ",s, array[i].c[s], array[i].lo[s], array[i].up[s]);
		printf("\n");
		*/
	}
	f = 0;
	for(i=0; i<m; i++)
	{
		//if(f == 1) 
			
		//f = 1;
		scanf("%s", str);
		for(j=0; j<n; j++)
			if( ! strcmp( str, array[j].name ) )
				break;
			s = array[j].c[0];
			printf("%s[",str);
			for(k=1; k<= array[j].dimension; k++)
			{
				scanf("%d", &r);
				s += r * array[j].c[k];
				if(k == 1)
					printf("%d",r);
				else
					printf(", %d",r);
			}
			printf("] = %d",s);
			printf("\n");
	}
	return 0;
}



