// B2 2292: 벌집(수학)
#include<stdio.h>

int main(void){
    int o=1; // offset
    int a=1; // ans;
    int b=0;
    int n; scanf("%d",&n);
    
    while(1){
        if(n<=o){printf("%d",a); return 0;}
        else{
            b+=6;
            o+=b;
            a+=1;
        }
    }
}