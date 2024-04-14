#include<stdio.h>
#include<stdlib.h>
void swap(int *n,int *m){
	int t=*n;*n=*m;*m=t;
}
int main() {
	FILE *fi;
	FILE *fo;
	int n,m,i,j;
	fi =fopen("C:\\Users\\Admin\\Downloads\\dothi.txt","r");
	fscanf(fi,"%d%d",&n,&m);
	int a[m][2];
	int count[n+1];
	int c[n+1];
	int mau[n];
	for (i=0;i<n;i++) {count[i]=0;c[i]=i;}
	for (i=0;i<m;i++){
		fscanf(fi,"%d%d",&a[i][0],&a[i][1]);
		count[a[i][0]]++;
		count[a[i][1]]++;}                   		
	fclose(fi);
	/*fo =fopen("output.txt","w+");
		for (i=0;i<m;i++) {
		fprintf(fo,"  %d -- %d;\n",a[i][0],a[i][1]);
		fprintf(fo,"%d",count[i+1]);}                         		
	fclose(fo);*/
	for (i=0;i<n;i++) {                           //Sap xep dinh theo bac giam dan
		for (j=i+1;j<=n;j++){
			if (count[i]<count[j]){
				swap(&count[i],&count[j]);    
				swap(&c[i],&c[j]);
		    }           
		}
	}	
	int t=1;
	for (i=0;i<n;i++)
}

	

