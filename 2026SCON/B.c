#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j;
    int a; int b; int c; scanf("%d %d %d",&a,&b,&c);
    int h;               scanf("%d",&h);
    int min;

    int x[8]={0,0,0,0,0,0,0,0}; // 소모시간
    int y[8]; // 잔여 체력
    y[0]=h; y[1]=h; y[2]=h; y[3]=h; y[4]=h; y[5]=h; y[6]=h; y[7]=h;
    x[0]+=(a+b+c);
    x[1]+=(a+b+c/2); y[1]-=c/2;
    x[2]+=(a+b/2+c); y[2]-=b/2;
    x[3]+=(a/2+b+c); y[3]-=a/2;
    x[4]+=(a+b/2+c/2); y[4]-=(b/2+c/2);
    x[5]+=(a/2+b+c/2); y[5]-=(a/2+c/2);
    x[6]+=(a/2+b/2+c); y[6]-=(a/2+b/2);
    x[7]+=(a/2+b/2+c/2); y[7]-=(a/2+b/2+c/2);
    min=x[0];
    for(j=1;j<8;j++){
        if(y[j]>=1){
            if(x[j]<min){
                min=x[j];
            }
        }
    }
    printf("%d\n",min);    
}