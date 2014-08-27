

/* @JUDGE_ID: 34556CP 537 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.119 - CRC: D3948A43 **/
/** Date: 2004-09-30 15:41:44 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int test, i, j, k = 1;
	char str[100000];
	float f[4];
//	freopen("a.in", "r", stdin); clrscr();
	scanf("%d", &test); getchar();
	while(test--)
	{
		for(i = 0; i < 4; ++i) f[i] = 0;
		gets(str);
		for(i = j = 0; str[i] && j < 2; ++i)
		{
			if(str[i] == 'I' && str[i+1] == '=')
			{
				i += 2;
				f[3] = atof(str + i);
				while((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
					i++;
				if(str[i] == 'm')
					f[3] /= 1000;
				else if(str[i] == 'k')
					f[3] *= 1000;
				else if(str[i] == 'M')
					f[3] *= 1000000;
				++j;
			}
			else if(str[i] == 'U' && str[i+1] == '=')
			{
				i += 2;
				f[2] = atof(str + i);
				while((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
					i++;
				if(str[i] == 'm')
					f[2] /= 1000;
				else if(str[i] == 'k')
					f[2] *= 1000;
				else if(str[i] == 'M')
					f[2] *= 1000000;
				++j;
			}
			else if(str[i] == 'P' && str[i+1] == '=')
			{
				i += 2;
				f[1] = atof(str + i);
				while((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
					i++;
				if(str[i] == 'm')
					f[1] /= 1000;
				else if(str[i] == 'k')
					f[1] *= 1000;
				else if(str[i] == 'M')
					f[1] *= 1000000;
				++j;
			}
		}
		printf("Problem #%d\n", k++);
		if(f[2] && f[3]) printf("P=%.2fW\n\n",f[2]*f[3]);
		else if(f[1] && f[3]) printf("U=%.2fV\n\n",f[1]/f[3]);
		else if(f[1] && f[2]) printf("I=%.2fA\n\n",f[1]/f[2]);
	}
	return 0;
}


@END_OF_SOURCE_CODE
