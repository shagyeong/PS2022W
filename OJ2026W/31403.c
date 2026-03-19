// B4 31403: A+B-C()
#include<stdio.h>

int main(void){
    int a; int b; int c; scanf("%d %d %d",&a,&b,&c);
    int e=1;
    printf("%d\n",a+b-c); while(b/(e*=10)>0){a*=10;} a*=10;
    printf("%d\n",a+b-c);
}