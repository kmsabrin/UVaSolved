From apache@acm.uva.es Sat Sep  4 19:03:29 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i84H3TW05664
	for <judge@juez.localnet>; Sat, 4 Sep 2004 19:03:29 +0200
Received: by acm.localnet (Postfix)
	id 3B3E611242; Sat,  4 Sep 2004 19:03:29 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 37D3711240; Sat,  4 Sep 2004 19:03:29 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 10182
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040904170329.37D3711240@acm.localnet>
Date: Sat,  4 Sep 2004 19:03:29 +0200 (CEST)

/* @JUDGE_ID: 34556CP 10182 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.106 - CRC: 212E5372 **/
/** Date: 2004-09-04 19:03:29 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
//#include<conio.h>

int main()
{
	long i, j, k, x, y, p, q, r, n, f;

//	clrscr();
	while(scanf("%ld", &r) !=EOF)
	{
	if(r == 1) { printf("0 0\n"); continue; }
	x = 0; y = 0; f = 1; j = 0;
	for(i = 1, n = 1, k = 1;  ; i += j)
	{
			k++;
			++y;
//			printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }


			p = n - 1;      // SW
			while(p--)
			{
				--x; ++y; k++;
				if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }
//				printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			}
			if(f == 0) break;

			p = n;      //   NW
			while(p--)
			{
				--x; k++;
				if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }
//				printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			}
			if(f == 0) break;

			p = n;      // UP
			while(p--)
			{
				--y; k++;
				if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }
//				printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			}
			if(f == 0) break;

			p = n;       // NE
			while(p--)
			{
				++x; --y; k++;
				if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }
//				printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			}
			if(f == 0) break;

			p = n;      //  SE
			while(p--)
			{
				++x; k++;
				if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }
//				printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			}
			if(f == 0) break;

			p = n;       //down
			while(p--)
			{
				++y; k++;
				if(r == k) { printf("%ld %ld\n", x, y); f = 0; break; }
//				printf("k = %ld, x = %ld, y = %ld\n", k, x, y);
			}
			if(f == 0) break;

			j += 6; n++;
	}
	}
	return 0;
}
@END_OF_SOURCE_CODE
