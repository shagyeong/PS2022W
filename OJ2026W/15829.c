// B2 15829: Hashing(해싱)
#include<stdio.h>
#include<stdlib.h>

#define R 31
#define D 1234567891

int main(void){
    unsigned long long int j;
    unsigned long long int l; scanf("%lld",&l);
    unsigned long long int h=0;
    unsigned long long int r=1; // R^i
    char* s=(char*)malloc(sizeof(char)*(l+1));
    scanf("%s",s);

    for(j=0;j<l;j++){
        h+=(((s[j]-'a'+1)*r)%D);
        h%=D;
        r*=R;
        r%=D;
    }
    printf("%lld",h);
}