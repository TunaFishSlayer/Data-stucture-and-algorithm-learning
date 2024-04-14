#include<stdio.h>
#include<strings.h>
int main()
{
	char s[10];
	char d;
    scanf("%s",&s);
	d = s[0];
	int i;
	for ( i = 1 ; i< strlen(s); i++)
	{
		if (s[i] <= d) { d = s[i]; }
	}
	printf("%c",d);
	return 0;
}

	 
