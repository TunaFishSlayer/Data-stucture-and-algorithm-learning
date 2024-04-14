#include<stdio.h>

int main()
{
	float f;
	scanf("%f",&f);
	if ( 0 <= f && f < 89.999 )
	   {printf("%s","North");}
	if ( 90 <= f && f < 179.990 ) 
	   {printf("%s","East");}
	if (180 <= f && f < 269.999 )  
	   {printf("%s","South");} 
	if (270 <= f && f < 359.999 )
	   {printf("%s","West");}      
	
}

