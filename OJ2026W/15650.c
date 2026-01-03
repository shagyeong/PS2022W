// S3 15650: N과 M (2)(재귀,백트래킹)
#include<stdio.h>

unsigned char a[9];
unsigned char n;
unsigned char m;
void backtrack(unsigned char d,unsigned char s);

int main(void){
    scanf("%hhu %hhu",&n,&m);
    backtrack(0,1);
}

void backtrack(unsigned char d,unsigned char s){
    unsigned char j; // loop variable
    if(d==m){
        for(j=0;j<m;j++){printf("%u ",a[j]);}
        printf("\n");
    }
    else{
        for(j=s;j<=n;j++){
            a[d]=j;
            backtrack(d+1,j+1);
        }
    }
}

// 재귀 호출 흐름: n=5, m=3
// f(0,1)
//     a[0]=1 f(1,2)
//         a[1]=2 f(2,3)
//             a[2]=3 f(3,4) ans: 1 2 3
//             a[2]=4 f(3,5) ans: 1 2 4
//             a[2]=5 f(3,6) ans: 1 2 5
//         a[1]=3 f(2,4)
//             a[2]=4 f(3,4) ans: 1 3 4
//             a[2]=5 f(3,6) ans: 1 3 5
//         a[1]=4 f(2,5)
//             a[2]=5 f(3,6) ans: 1 4 5
//         a[1]=5 f(2,6)
//     a[0]=2 f(1,3)
//     a[0]=3 f(1,4)
//     a[0]=4 f(1,5)
//     a[0]=5 f(1,6)