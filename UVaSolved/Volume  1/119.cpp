
#include<stdio.h>

#include<string.h>
#include<stdlib.h>

int main()
{
	char name[11][15];
	char temp[15];
	char why[250];
	int acc[11];
	int i,j,k,p,q,r,s,t;

	int B = 0;
	
	for(i=0; i<11; i++) acc[i] = 0;
	for(i=0; i<250; i++) why[i] = '\0';
	for(i=0; i<15; i++) temp[i] = '\0';
	for(i=0; i<11; i++) for(j=0; j<15; j++) name[i][j] = '\0';
	
	while(gets(temp))
	{
		if ( B )
		{
			printf( "\n" );
		}

		B = 1;
		
		p = atoi(temp);
		gets(why);
		r=0;
		for(i=0; why[i]; i++)
		{
			while(why[i] == ' ') i++;
			j=0;
			while(why[i] != ' ' && why[i])
			{
				name[r][j] = why[i];
				j++;
				i++;
			}
			name[r][j]='\0';
			r++;
		}
		//if(r!=p) printf("wrong");
		for(i=0; i<p; i++)
		{
			gets(why);
			for(j=0; why[j]!=' ' && why[j]; j++)
				temp[j]=why[j];
			temp[j]='\0';
			
			while(why[j] == ' ' && why[j]) j++;
			r=0;
			for( ; why[j]!=' ' && why[j]; j++)
				r = r*10 + why[j]-48;
			
			while(why[j] == ' ' &&why[j]) j++;
			s=0;
			for( ; why[j]!=' ' && why[j]; j++)
				s = s*10 + why[j]-48;
			//printf("%s %d %d\n",temp,r,s);
			if(s!=0)
				q = r/s;
			for(k=0; k<p; k++)
				if(!strcmp(temp,name[k]))
				{
					acc[k] -= r;
					acc[k] += r-(s*q);
					break;
				}
				//printf("%d(1)\n",acc[2]);
				for( ; why[j]; )
				{
					while(why[j] == ' ' && why[j]) j++;
					for(k=0; why[j]!=' ' && why[j]; j++,k++)
						temp[k] = why[j];
					temp[k]='\0';
					for(k=0; k<p; k++)
						if(!strcmp(temp,name[k]))
						{
							acc[k] += q;
							//printf(temp);
							break;
						}
				}
				for(t=0; t<250; t++) why[t] = '\0';
				//printf("%d(2)\n",acc[2]);
		}
		for(i=0; i<p; i++)
			printf("%s %d\n",name[i],acc[i]);
		
		
		for(i=0; i<11; i++) acc[i] = 0;
		for(i=0; i<250; i++) why[i] = '\0';
		for(i=0; i<15; i++) temp[i] = '\0';
		for(i=0; i<11; i++) for(j=0; j<15; j++) name[i][j] = '\0';
	}
	return 0;
}

