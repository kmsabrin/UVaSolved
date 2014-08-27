From apache@acm.uva.es Mon Mar  8 14:35:05 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i28DZ5W23564
	for <judge@juez.localnet>; Mon, 8 Mar 2004 14:35:05 +0100
Received: by acm.localnet (Postfix)
	id 59FA8FFDE; Mon,  8 Mar 2004 14:35:05 +0100 (CET)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 560E3FF80; Mon,  8 Mar 2004 14:35:05 +0100 (CET)
To: judge@acm.uva.es
Subject: Problem 514
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040308133505.560E3FF80@acm.localnet>
Date: Mon,  8 Mar 2004 14:35:05 +0100 (CET)

/* @JUDGE_ID: 34556CP 514 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.40 - CRC: 33B81544 **/
/** Date: 2004-03-08 14:35:05 +0100 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>


int main()
{
	int a[1010], b[1010], i, j, f, n;

	while(scanf("%d",&n) && n)
	{
	while(scanf("%d", &a[1]))
	{
	if(a[1] == 0) break;

	i = 2;
	while(i <= n)
	{
		scanf("%d",&a[i]);
		i++;
	}

	for(i=1; i<1010; i++)
		b[i] = 0;
	b[0] = 1;
	f = 1;

	for(i=1; i<=n; i++)
	{
		for(j=n; j>a[i]; j--)
			if(b[j] == -1)
			{
			      f = 0;
			      break;
			}
		for(j=a[i]-1; j>=1; j--)
			if(b[j] == 0)
				b[j] = -1;
		b[a[i]] = a[i];
	}
	if(f) printf("Yes\n");
	else  printf("No\n");
	}
	printf("\n");
	}
	return 0;
}
@END_OF_SOURCE_CODE
