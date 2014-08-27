

/* @JUDGE_ID: 34556CP 10070 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 172.16.29.243 - CRC: B1D81411 **/
/** Date: 2003-11-15 10:02:30 +0100 **/


#include<stdio.h>

int strdiv(char a[],int b)
{
   int i,k;
   for(i=k=0;a[i];i++)
   {
      k=k*10+a[i]-48;
      k=k%b;
   }
   if(!k)
	return 1;
   else
	return 0;
}

int main()
{
     char s[100000];
     int i,j,k,a,b,c, B = 0;

     while(gets(s))
     {
		 if ( B )
		 {
			 printf( "\n" );
		 }

		 B = 1;
	a=b=c=0;
	i=strdiv(s,4);
	j=strdiv(s,100);
	k=strdiv(s,400);
	a=((i&&!j)||k);
	if(a)
	{
	   printf("This is leap year.\n");
	   if(strdiv(s,55))
		 c=1;
	}
	b=strdiv(s,15);
	if(b)
		printf("This is huluculu festival year.\n");
	if(c)
		printf("This is bulukulu festival year.\n");
	if(!a&&!b)
		printf("This is an ordinary year.\n");

     }
     return 0;
}



