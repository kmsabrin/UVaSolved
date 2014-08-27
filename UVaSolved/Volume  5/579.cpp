From apache@acm.uva.es Thu Aug 28 02:51:28 2003
Received: from acm.localnet (web.localnet [192.168.10.200])
	by acm.uva.es (8.11.6/8.11.6) with ESMTP id h7S0pRV12418
	for <judge@juez.localnet>; Thu, 28 Aug 2003 02:51:27 +0200
Received: by acm.localnet (Postfix)
	id A94241008A; Thu, 28 Aug 2003 02:51:27 +0200 (CEST)
Delivered-To: judge@acm.uva.es
Received: by acm.localnet (Postfix, from userid 81)
	id A765F1008F; Thu, 28 Aug 2003 02:51:27 +0200 (CEST)
To: judge@acm.uva.es
Subject: Problem 579
From: nobody@nobody.acm.uva.es
Reply-To: nobody@nobody.acm.uva.es
Message-Id: <20030828005127.A765F1008F@acm.localnet>
Date: Thu, 28 Aug 2003 02:51:27 +0200 (CEST)

/* @JUDGE_ID: 34556CP 579 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.73 - CRC: 71710318 **/
/** Date: 2003-08-28 02:51:27 +0200 **/

@BEGIN_OF_SOURCE_CODE
/* @judge_id:34620CA 579 C */
#include<stdio.h>
int main(){
	 char a[10];
	 double c,d,i,j,k,r;
	 while(gets(a)&&(a[0]-'0')){
	 if(a[4]=='\0'){
		c=a[0]-'0';
		d=10*(a[2]-'0')+(a[3]-'0');
		}
	 else{
		c=10.0*(a[0]-'0')+(a[1]-'0');
		d=10.0*(a[3]-'0')+(a[4]-'0');
		}

		i=(5.0*c)+(d/12.0);
		if(i>=d){
			j=i-d;
			k=60.0-j;
			}
		else{
			j=d-i;
			k=60.0-j;
			}
		if(k<j) r=k*6.0;
		else     r=j*6.0;
	 printf("%.3lf\n",r);
	 }
 return 0;
}


@END_OF_SOURCE_CODE
