// B3 10162: 전자레인지(그리디)
#include<stdio.h>

int main(void){
    int t; scanf("%d",&t);
    if(t%10!=0){printf("-1");}
    else{
        printf("%d ",t/300); t%=300;
        printf("%d ",t/60);  t%=60;
        printf("%d", t/10);
    }
}