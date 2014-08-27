From apache@acm.uva.es Sun Apr 11 14:03:52 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i3BC3qW00826
	for <judge@juez.localnet>; Sun, 11 Apr 2004 14:03:52 +0200
Received: by acm.localnet (Postfix)
	id 2C29B109C7; Sun, 11 Apr 2004 14:03:52 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 2A8F6109C4; Sun, 11 Apr 2004 14:03:52 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 539
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040411120352.2A8F6109C4@acm.localnet>
Date: Sun, 11 Apr 2004 14:03:52 +0200 (CEST)

/* @JUDGE_ID: 34556CP 539 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.92 - CRC: 1556A776 **/
/** Date: 2004-04-11 14:03:52 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
#include<math.h>
//#include<conio.h>

int edge[26][26];
int path[26][26];
int n, m, max, count;

int call(int start)
{
	int i,hold;
	if(count > max) max = count;
	hold = count;
	for(i=0; i<n; i++)
	{
		if(edge[start][i] == 1 && path[start][i] == 0)
		{
		path[start][i] = path[i][start] = 1;
		count++;
		call(i);
		path[start][i] = path[i][start] = 0;
		}
		count = hold;
	}
	return 0;
}

int main()
{
	int i,j,k;
//	clrscr();
//	freopen("always.in","r",stdin);
	while(scanf("%d %d", &n, &m))
	{
	if(n==0 && m==0) break;
	for(i=0; i<26; i++)
		for(j=0; j<26; j++)
			edge[i][j] = 0;

	for(i=0; i<m; i++)
	{
		scanf("%d %d",&j,&k);
		edge[j][k] = edge[k][j] = 1;
	}

	max = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<26; j++)
			for(k=0; k<26; k++)
				path[j][k] = 0;

		count = 0;
		call(i);
	}
	printf("%d\n", max);
	}
	return 0;
}



@END_OF_SOURCE_CODE
