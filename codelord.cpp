#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list1[100000],list2[100000];

int main(){
	int num1f=50000,num1b=num1f+1,num2f=num1f,num2b=num1f+1;
	char cmd[2];
	int l,value,i;
	while (1) {
		scanf("%s",cmd);
		if (strcmp(cmd,"#")==0) break;
		scanf("%d %d",&l,&value);
		if (l==1) {
			if (strcmp(cmd,"I")==0) {list1[num1f]=value;num1f--;}
			if (strcmp(cmd,"A")==0) {list1[num1b]=value;num1b++;}
		}
		if (l==2) {
			if (strcmp(cmd,"I")==0) {list2[num2f]=value;num2f--;}
			if (strcmp(cmd,"A")==0) {list2[num2b]=value;num2b++;}
		}
	//	printf("%s %d %d",cmd,l,value);
		if (strcmp(cmd,"#")==0) break;
	}
	int j=num2f+1;
	for(i=num1f+1;i<num1b;i++){
		printf("%d ",list1[i]);
		if (j<num2b) {
			printf("%d ",list2[j]);
			j++;
		}
	}
	while (j<num2b){
		printf("%d ",list2[j]);
		j++;
	}
}

