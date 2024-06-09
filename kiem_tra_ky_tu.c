
#include <stdio.h>
#include <stdlib.h>

int ktrakytu(const char *str) {
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') ||
              (*str >= 'A' && *str <= 'Z') ||
              (*str >= '0' && *str <= '9') ||
              (*str == ' '))) {
            return 1;
        }
        str++;
    }
    return 0; 
}

int main(){
    char myString[20];
    scanf("%s", &myString);
    if (ktrakytu(myString)==1){
        printf("Xau co ky tu dac biet");
    }else {
        printf("Xau khong ky tu dac biet");
        }
        return 0;
}
