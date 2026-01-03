// G4 17144: 미세먼지 안녕!(시뮬레이션)
#include<stdio.h>

int main(void){
    int d; // 먼지: 입력 더미->확산 먼지 더미->총량
    short j; short k; // loop variable
    short r; short c; // row, columns
    short y; short x=0; // 청정기 위치: y, y+1, 문제 조건: 반드시 column 0에 위치
    short t;
    short s; // 확장 방향 개수
    scanf("%hd %hd %hd",&r,&c,&t);
    short a[r][c]; // t
    short b[r][c]; // t+1

    // 과제 환경
    for(j=0;j<r;j++){
        for(k=0;k<c;k++){
            scanf("%d",&d);
            a[j][k]=d;
            b[j][k]=d;
            if(d==-1){y=j-1;} // 청정기 하부가 항상 나중에 탐색됨
        }
    }

    while(t--!=0){
    for(j=0;j<r;j++){
        for(k=0;k<c;k++){
            if(a[j][k]==-1){continue;}
            s=0;
            d=a[j][k]/5;
            if((j-1>=0)&&(a[j-1][k  ]!=-1)){b[j-1][k  ]+=d; s+=1;}
            if((j+1< r)&&(a[j+1][k  ]!=-1)){b[j+1][k  ]+=d; s+=1;}
            if((k-1>=0)&&(a[j  ][k-1]!=-1)){b[j  ][k-1]+=d; s+=1;}
            if((k+1< c)&&(a[j  ][k+1]!=-1)){b[j  ][k+1]+=d; s+=1;}
            b[j][k]-=d*s;
        }
    }
    for(j=0;j<r;j++){for(k=0;k<c;k++){a[j][k]=b[j][k];}}

    // 청정기 순환 row
    for(j=0;j<c-1;j++){
        b[0  ][j]=a[0  ][j+1];      // row 0: 최상단 행
        b[r-1][j]=a[r-1][j+1];      // row r-1: 최하단 행
        b[y  ][c-1-j]=a[y  ][c-2-j];// row y: 청정기 상단부 행
        b[y+1][c-1-j]=a[y+1][c-2-j];// row y+1: 청정기 하단부 행
    }

    // 청정기 상단 순환 column
    for(j=y;j>0;j--){
        b[j  ][0  ]=a[j-1  ][0  ];
        b[y-j][c-1]=a[y-j+1][c-1];
    }
    // 청정기 하단 순환 column
    for(j=y+1;j<r-1;j++){
        b[j  ][0  ]=a[j+1  ][0  ];
        b[j+1][c-1]=a[j][c-1];
    }

    // 청정기 값 순환 방지: -1 -> 0
    b[y  ][x+1]=0;
    b[y+1][x+1]=0;
    
    // 청정기 값 오염 방지
    b[y  ][x]=-1;
    b[y+1][x]=-1;
    for(j=0;j<r;j++){for(k=0;k<c;k++){a[j][k]=b[j][k];}}
    }
    // 먼지 총량
    d=0;
    for(j=0;j<r;j++){for(k=0;k<c;k++){d+=b[j][k];}}
    d+=2; // 청정기
    printf("%d",d);
}