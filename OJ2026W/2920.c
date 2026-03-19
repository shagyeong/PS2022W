// B2 2920: 음계()
#include<stdio.h>

int main(void){
    int a; int b; int c; int d; scanf("%d %d %d %d",&a,&b,&c,&d);
    int e; int f; int g; int h; scanf("%d %d %d %d",&e,&f,&g,&h);
    if((a==1)&&(b==2)&&(c==3)&&(d==4)&&(e==5)&&(f==6)&&(g==7)&&(h==8)){printf("ascending"); return 0;}
    if((a==8)&&(b==7)&&(c==6)&&(d==5)&&(e==4)&&(f==3)&&(g==2)&&(h==1)){printf("descending"); return 0;}
    printf("mixed"); return 0;
}