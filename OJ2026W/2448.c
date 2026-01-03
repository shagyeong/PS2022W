// G4 2448: 별 찍기 - 11(재귀)
#include<stdio.h>
#include<string.h>

char a[3072][6143];

void draw(short n,short h, short w,short r,short c);

int main(void){
    short j; // loop variable
    short h; // height
    short w; // width
    short n; scanf("%hd",&n);
    h=n;
    w=2*n-1;
    memset(a,' ',sizeof(a));
    draw(n,h,w,0,w/2);
    for(j=0;j<h;j++){
        fwrite(a[j],sizeof(char),2*n-1,stdout);
        putchar('\n');
    }
}

void draw(short n,short h, short w,short r,short c){
    if(n==3){
        a[r  ][c  ]='*';
        a[r+1][c-1]='*';
        a[r+1][c+1]='*';
        a[r+2][c-2]='*';
        a[r+2][c-1]='*';
        a[r+2][c  ]='*';
        a[r+2][c+1]='*';
        a[r+2][c+2]='*';
        return;
    }
    else{
        draw(n/2,n/2,n-1,r,c);
        draw(n/2,n/2,n-1,r+(h/2),c+(w+1)/4);
        draw(n/2,n/2,n-1,r+(h/2),c-(w+1)/4);
    }
}