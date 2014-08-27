

/* @JUDGE_ID: 34556CP 576 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.29.251 - CRC: B9F168AD **/
/** Date: 2003-12-01 05:33:36 +0100 **/


#include<stdio.h>
#include<string.h>

int main(){
	char a[10000],c,c1[]="e/o/i";
   int i,p,q,r;
   while(gets(a)){
   	if(!strcmp(a,c1))
      	break;

      for(i=p=0;a[i]!='/';i++)
      	if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y') && (a[i-1]!='a'&&a[i-1]!='e'&&a[i-1]!='i'&&a[i-1]!='o'&&a[i-1]!='u'&&a[i-1]!='y'))
         	p++;

      if(p!=5){
      	printf("1\n");
         continue;
      }

      for(i=i+1,p=0;a[i]!='/';i++)
      	if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y') && (a[i-1]!='a'&&a[i-1]!='e'&&a[i-1]!='i'&&a[i-1]!='o'&&a[i-1]!='u'&&a[i-1]!='y'))
         	p++;

      if(p!=7){
      	printf("2\n");
         continue;
      }

      for(i=i+1,p=0;a[i];i++)
      	if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y') && (a[i-1]!='a'&&a[i-1]!='e'&&a[i-1]!='i'&&a[i-1]!='o'&&a[i-1]!='u'&&a[i-1]!='y'))
         	p++;

      if(p!=5){
      	printf("3\n");
         continue;
      }

      printf("Y\n");
      }
      return 0;
   }


