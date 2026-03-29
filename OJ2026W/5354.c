// B3 5354: J박스(구현)
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int _; scanf("%d",&_);
    int n;
    while(_-->0){
        scanf("%d",&n);
        if(n==1){printf("#\n");}
        else{
            for(j=0;j<n;j++){printf("#");} printf("\n");
            for(j=0;j<n-2;j++){
                printf("#");
                for(k=0;k<n-2;k++){printf("J");}
                printf("#\n");
            }
            for(j=0;j<n;j++){printf("#");} printf("\n");
        }
        if(_!=0){printf("\n");}
    }
}