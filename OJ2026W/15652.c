// S3 15652: N과 M (4)(재귀,백트래킹)
#include<stdio.h>

unsigned char a[9];
unsigned char n;
unsigned char m;
void backtrack(unsigned char d,unsigned char s);

int main(void){
    scanf("%hhu %hhu",&n,&m);
    backtrack(0,2);
}

void backtrack(unsigned char d,unsigned char s){
    unsigned char j; // loop variable
    if(d==m){
        for(j=0;j<m;j++){printf("%u ",a[j]);}
        printf("\n");
    }
    else{
        for(j=s-1;j<=n;j++){
            a[d]=j;
            backtrack(d+1,j+1);
        }
    }
}