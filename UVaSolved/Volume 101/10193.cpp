From apache@acm.uva.es Fri Oct 17 16:03:44 2003
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id h9HE3iV30132
	for <judge@juez.localnet>; Fri, 17 Oct 2003 16:03:44 +0200
Received: by acm.localnet (Postfix)
	id 2E301FF81; Fri, 17 Oct 2003 16:03:45 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id 22B88FF84; Fri, 17 Oct 2003 16:03:44 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 10193
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20031017140344.22B88FF84@acm.localnet>
Date: Fri, 17 Oct 2003 16:03:44 +0200 (CEST)

/* @JUDGE_ID: 34556CP 10193 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.65 - CRC: 8C0D2864 **/
/** Date: 2003-10-17 16:03:44 +0200 **/

@BEGIN_OF_SOURCE_CODE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char a[50],b[50],c[10];
	unsigned long i,j,k,f,p,q,r; long d;
	gets(c);
	d=atol(c);
	r=1;
	while(d){
		gets(a);
		gets(b);
		p=strlen(a);
		q=strlen(b);
		printf("Pair #%lu: ",r);
		if(!(a[p-1]-48) && !(b[q-1]-48)) printf("All you need is love!\n");
		else{
			j=k=0;
			for(i=0;i<p;i++) j=j*2+(a[i]-48);
			for(i=0;i<q;i++) k=k*2+(b[i]-48);
		/*	printf("%ld %ld",j,k);  */

			f=0; i=1;
			while(i){
				i=j%k;
				j=k;
				k=i;
				}  /*  printf("%ld\n",j); */
			if(j!=1) f=1;

			if(f) printf("All you need is love!\n");
			else printf("Love is not all you need!\n");
			}
		d--;
		r++;
		}
	return 0;
}
@END_OF_SOURCE_CODE
