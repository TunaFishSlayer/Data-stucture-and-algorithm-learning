#include<stdio.h>
int main()
{
	char v;
	int t;
	float m;
	printf("What is the type of vehicle will be parking here(C is car, B is bus, T is truck): ");
	scanf("%c",&v);
	printf("How long will you park here in hours: ");
	scanf("%d",&t);
	switch(v){
		case 'C':
			if (t <= 2 )
			   m=t*0.7;
			else m=1.4+(t-2)*2.5;  
			break;
		case 'B':	
		    if (t <= 2 )
			   m=t*1.5;
			else m=5+(t-2)*2;  
			break;
		case 'T':
		    m=2.5+(t-1)*3.25;  
			break;	
	}
	printf("%2g",m);
}
