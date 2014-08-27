From apache@acm.uva.es Sun Sep 19 03:40:42 2004
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id i8J1efW08138
	for <judge@juez.localnet>; Sun, 19 Sep 2004 03:40:41 +0200
Received: by acm.localnet (Postfix)
	id DEFC210F9C; Sun, 19 Sep 2004 03:40:41 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id DCD7D10F98; Sun, 19 Sep 2004 03:40:41 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 536
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20040919014041.DCD7D10F98@acm.localnet>
Date: Sun, 19 Sep 2004 03:40:41 +0200 (CEST)

/* @JUDGE_ID: 34556CP 536 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.106 - CRC: 52C157EC **/
/** Date: 2004-09-19 03:40:41 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
//#include<conio.h>
#include<string.h>

char pre[30];

void call(char str[], int index)
{
	char left[30], right[30], c;
	int i, j, k;

	// find pre[index]
	c = pre[index];
	for(i = 0; str[i]; ++i)
		if(c == str[i])
			break;

	//calculate left
	for(j = 0; j < i; ++j)
		left[j] = str[j];
	left[j] = '\0';
	//printf("left is = %s\n",left);
	k = strlen(left);
	if(k == 0);
	else if(k == 1) printf("%c",left[0]);
	else call(left, index + 1);

	//calculate right
	for(j = i + 1, k = 0; str[j]; j++)
		right[k++] = str[j];
	right[k] = '\0';
	//printf("right is = %s\n",right);
	k = strlen(right);
	if(k == 0);
	else if(k == 1) printf("%c",right[0]);
	else call(right, strlen(left) + index + 1);

	//print root
	printf("%c",pre[index]);
}

int main()
{
	char in[30];
//	clrscr();
//	freopen("a.in","r",stdin);
	while(scanf("%s %s",pre,in) != EOF)
	{
		call(in, 0);
		printf("\n");
	}
	return 0;
}
@END_OF_SOURCE_CODE
