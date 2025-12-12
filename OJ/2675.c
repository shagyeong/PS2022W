//2675: 문자열 반복(구현, 문자열)
#include<stdio.h>

int main(void){
    int n, k, h; scanf("%d", &n);
    char s[20];
    for(int i = 0; i < n; i++){
        scanf("%d %s", &k, s);
        h = 0;
        while(s[h] != '\0'){
            for(int j = 0; j < k; j++){
                printf("%c", s[h]);
            }h++;
        }printf("\n");
    }
}
