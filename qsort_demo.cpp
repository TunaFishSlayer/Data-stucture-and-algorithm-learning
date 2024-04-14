#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct student{
    int stt;
    char ten[50];
    char mssv[10];
    double diem;
} stud;

char* reverse(char *str) {
    int i = strlen(str) - 1;
    int start, end = i + 1;
    char* result = (char*)malloc((i+2) * sizeof(char));
    int pos = 0;

    while(i >= 0) {
        if(str[i] == ' ') {
            start = i + 1;
            while(start != end)
                result[pos++] = str[start++];
            result[pos++] = ' ';
            end = i;
        }
        i--;
    }
    start = 0;
    while(start != end)
        result[pos++] = str[start++];
    result[pos] = '\0'; 
    return result;
}


int sort_n(const void *a,const void *b){	
	stud *st1=(stud *)a;
	stud *st2=(stud *)b;
	char *revname1=reverse(st1->ten);
	char *revname2=reverse(st2->ten);
	int name=strcmp(revname1,revname2);
	free(revname1);
	free(revname2);
	if (name!=0) return name;
	return st1->stt - st2->stt;
}

int sort_g(const void *a,const void *b){	
	stud *st1=(stud *)a;
	stud *st2=(stud *)b;
	double point = st2->diem-st1->diem;
	if (point>0) return 1;
	if (point<0) return -1;
	if (point==0) return st1->stt - st2->stt;
}

int sort_c(const void *a,const void *b){	
	stud *st1=(stud *)a;
	stud *st2=(stud *)b;
	int id=strcmp(st1->mssv,st2->mssv);
	if (id!=0) return id;
	return st1->stt - st2->stt;
}

int main()
{
    int n,i;
    char mode;
    scanf("%d %c",&n,&mode);
    stud *a;
	a =(stud*)malloc(n * sizeof(stud));
    getchar();
    for (i=0;i<n;i++) {
        char input[80];
        fgets(input,80,stdin);
        input[strcspn(input, "\n")] = 0;
        char *token = strtok(input,"*");
        a[i].stt = atoi(token);
        token = strtok(NULL,"*");
        strcpy(a[i].ten,token);
        token = strtok(NULL,"*");
        strcpy(a[i].mssv,token);
        token = strtok(NULL,"*");
        a[i].diem = atof(token);
    }
    switch(mode){
    	case 'n': qsort(a,n,sizeof(stud),sort_n);break;
    	case 'g': qsort(a,n,sizeof(stud),sort_g);break;
    	case 'c': qsort(a,n,sizeof(stud),sort_c);break;
	}
    for (i=0;i<n;++i) {
        printf("%d*%s*%s*%.2lf\n",a[i].stt,a[i].ten,a[i].mssv,a[i].diem);}
    free(a);    
}

