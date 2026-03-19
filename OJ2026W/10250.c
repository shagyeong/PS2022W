// B3 10250: ACM 호텔()
#include<stdio.h>

int main(void){
    int _; scanf("%d",&_);
    int r; int c; int n;
    while(_-->0){
        scanf("%d %d %d",&r,&c,&n);
        printf("%d",((n%r)==0)?(r):(n%r));
        if(((n%r==0)?(n/r):(n/r+1))<=9){printf("0");}
        printf("%d\n",((n%r==0)?(n/r):(n/r+1)));
    }
}