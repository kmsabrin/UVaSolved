

/* @JUDGE_ID: 34556CP 543 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.26.241 - CRC: 2B9E4700 **/
/** Date: 2004-02-19 10:48:51 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
#include<math.h>
const int MAX = 1000100;

int main()
{
	unsigned long i, j, n;
	char prime[MAX + 1];
	int flg1, flg2;

	for(i=0; i<=MAX; i++)
		prime[i] = 0;

	for(i=2; i<=sqrt(MAX); i++)
		if (!prime[i])
		{
			for(j=i*i; j <= MAX; j+=i)
				prime[j] = 1;
		}
	while(scanf("%lu", &n)==1 && n) {

		flg1 = 0,  flg2 = 0;
		for(i = 2; i <= n/2; i++)
			if(prime[i]==0 && prime[n-i]==0) {
				flg1 = 1;
				break;
			}
			if(flg1)
				printf("%lu = %lu + %lu\n", n, i, n-i);
			else printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}
@END_OF_SOURCE_CODE
