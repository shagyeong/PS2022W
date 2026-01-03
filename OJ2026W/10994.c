// S4 10994: 별 찍기 - 19(재귀)
#include<stdio.h>

char a[397][397];

void draw(short n,short s,short r,short c);

int main(void){
    short j; // loop variable
    short k; // loop variable
    short s; // size
    short n; scanf("%hd",&n);
    s=4*n-3;
    for(j=0;j<s;j++){for(k=0;k<s;k++){a[j][k]=' ';}}
    draw(n,s,0,0);
    for(j=0;j<s;j++){for(k=0;k<s;k++){printf("%c",a[j][k]);}printf("\n");}
}

void draw(short n,short s,short r,short c){
    if(n==1){a[r][c]='*';return;}
    short j; // loop variable
    for(j=0;j<s;j++){
        a[r    ][c+j]='*';
        a[r+s-1][c+j]='*';
        a[r+j][c    ]='*';
        a[r+j][c+s-1]='*';
    }
    draw(n-1,s-4,r+2,c+2);
}