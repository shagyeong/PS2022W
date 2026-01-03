// S4 10997: 별 찍기 - 22(재귀)
#include<stdio.h>

char a[399][397];

void draw(short n,short h,short w,short r,short c);

int main(void){
    short j; // loop variable
    short k; // loop variable
    short h; // height
    short w; // width
    short n; scanf("%hd",&n);
    h=4*n-1;
    w=4*n-3;
    for(j=0;j<h;j++){for(k=0;k<w;k++){a[j][k]=' ';}}
    draw(n,h,w,0,0);

    if(n==1){
        printf("*\n");
    }else{
        a[h/2  ][w/2  ]='*';
        a[h/2+1][w/2  ]='*';
        for(j=0;j<h;j++){
            if(j==1){printf("*");}
            else{for(k=0;k<w;k++){printf("%c",a[j][k]);}}
            printf("\n");
        }
    }
}

void draw(short n,short h,short w,short r,short c){
    if(n==1){a[r][c]='*';return;}
    short j; // loop variable
    for(j=0;j<h;j++){
        a[r+j][c    ]='*';
        a[r+j][c+w-1]='*';
    }
    for(j=0;j<w;j++){
        a[r    ][c+j]='*';
        a[r+h-1][c+j]='*';
    }
    a[r+1][c+w-1]=' ';
    a[r+2][c+w-2]='*';
    draw(n-1,h-4,w-4,r+2,c+2);
}