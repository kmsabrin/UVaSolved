

/* @JUDGE_ID: 34556CP 408 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.73 - CRC: B5D3E76B **/
/** Date: 2003-08-28 02:50:48 +0200 **/


#include<stdio.h>

int main(){
   int i,j,k,a,b,d;
   char s1[20]="Bad Choice";
   char s2[20]="Good Choice";
   while(scanf("%d %d",&a,&b)!=EOF){
   j=(2+a)%b;
   i=j; k=b-1; d=1;
   while(k){
		i=(i+a)%b;
		if(i==j) { d=0; break; }
		k--;
		}

   if(d) printf("%10d%10d    %s\n\n",a,b,s2);
   else	 printf("%10d%10d    %s\n\n",a,b,s1);
   }
   return 0;
}


