From apache@acm.uva.es Sun Sep 19 03:40:31 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i8J1eVW08086
	for <judge@juez.localnet>; Sun, 19 Sep 2004 03:40:31 +0200
Received: by acm.localnet (Postfix)
	id 5596F10F9C; Sun, 19 Sep 2004 03:40:31 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 5390410F98; Sun, 19 Sep 2004 03:40:31 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 583
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040919014031.5390410F98@acm.localnet>
Date: Sun, 19 Sep 2004 03:40:31 +0200 (CEST)

/* @JUDGE_ID: 34556CP 583 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.106 - CRC: E8ADAD64 **/
/** Date: 2004-09-19 03:40:31 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>

#define max 100000

int main()
{
	char prime[max + 1];
	long i, j, x, y;

	for(i = 0; i < max; ++i) prime[i] = 1;
	prime[0] = 0; prime[1] = 1;
	for(i = 2; i * i < max; ++i)
		if(prime[i])
			for(j = i * i; j < max; j += i)
				if(prime[j])
					prime[j] = 0;

	while(scanf("%ld", &x) && x)
	{
		if(x < 0) { printf("%ld = -1 x ", x); x *= -1; }
		else	    printf("%ld = ", x);

		for( i = 2, y = 1; y && i < max; ++i)
		{
			if(x < max && prime[x])
			{
				printf("%ld", x);
				break;
			}
			if(prime[i])
			{
				while( x % i == 0)
				{
					if(x == 1)
					{
						printf("%ld", i);
						y = 0;
						break;
					}
					else if(x < max && prime[x])
					{
						printf("%ld",x);
						y = 0;
						break;
					}
					else
						printf("%ld x ",i);
					x /= i;
				}
			}
		}
		if( x > max) printf("%ld",x);
		printf("\n");
	}
	return 0;
}

@END_OF_SOURCE_CODE
