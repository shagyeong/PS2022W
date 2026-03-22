// B1 2869: 달팽이는 올라가고 싶다()
#include<stdio.h>

int main(void){
    int a; int b; scanf("%d %d",&a,&b);
    int n; scanf("%d",&n);

    if((n-a)%(a-b)==0){printf("%d",(n-a)/(a-b)+1);}
    else              {printf("%d",(n-a)/(a-b)+2);}
}