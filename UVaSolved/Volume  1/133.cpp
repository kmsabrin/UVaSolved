
/* @JUDGE_ID: 34556CP 133 C "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.87 - CRC: 66A73F89 **/
/** Date: 2003-12-24 15:28:21 +0100 **/


#include<stdio.h>
int main(){
	int i,j,a,b,r,s,t,f,d[25];
   while(scanf("%d %d %d",&r,&s,&t)&&r&&s&&t){
   d[0]=1;
   for(i=1;i<=r;i++) d[i]=i;
   a=0;
   b=r+1;
   f=1;
   j=0;
   while(f){
      i=f=0;
      while(i!=s){
         if(a==r)
         	a=0;
         a++;
         if(d[a])
         	i++;
      }
      i=0;
      while(i!=t){
         if(b==1)
         	b=r+1;
         b--;
         if(d[b])
         	i++;
      }
      if(d[a]!=d[b]){
      	if(j==r-2)
      		printf("%3d%3d",a,b);
         else
         	printf("%3d%3d,",a,b);
         j+=2;
      }
      else{
      	if(j==r-1)
         	printf("%3d",a);
         else
         	printf("%3d,",a);
         j++;
      }

      d[a]=d[b]=0;
      for(i=1;i<r;i++) if(d[i]) f=1;
   }
   printf("\n");
   }
   return 0;
}

