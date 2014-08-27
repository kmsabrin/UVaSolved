

/* @JUDGE_ID: 34556CP 424 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v6.00 **/
/** IP: 202.22.204.111 - CRC: D06324F4 **/
/** Date: 2003-09-25 06:40:29 +0200 **/


#include<stdio.h>
#include<string.h>

void strreverse(char a[]){
	int i,n; char c;
	n=strlen(a);
	for(i=0;i<n/2;i++){
		c=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=c;
		}
	}

int main(){
	char a[150],b[150],c[155];
	int i,j,k,large,small,carry;
	gets(a);
	while(gets(b)&&b[0]!='0')  {
	carry=0;
	for(i=0;i<=150;i++) c[i]='\0';
	strreverse(a);
	strreverse(b);
	i=strlen(a);
	j=strlen(b);
	if(i>j) { large=i; small=j; k=0;}
	else { small=i; large=j; k=1;}
	for(i=0;i<small;i++){
		j=a[i]+b[i]-96+carry;
		if(j>=10) { c[i]=(j%10)+'0'; carry=1; }
		else { c[i]=j+'0'; carry=0; }
		}
   if(i!=j){
		if(!k){
			for(i=small;i<large;i++){
				j=a[i]-48+carry;
				if(j>=10) { c[i]=(j%10)+'0'; carry=1; }
				else { c[i]=j+'0'; carry=0; }
				}
			}
		else{
			for(i=small;i<large;i++){
				j=b[i]-48+carry;
				if(j>=10) { c[i]=(j%10)+'0'; carry=1; }
				else { c[i]=j+'0'; carry=0; }
				}
			}
		}
	if(carry==1) c[i]='1';
	strreverse(c);
	strcpy(a,c);
	}
	for(i=0;c[i];i++) printf("%c",c[i]);

	printf( "\n" );
	return 0;
}


