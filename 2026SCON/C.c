#include<stdio.h>
#include<stdlib.h>

int main(void){
    int j; int k;
    int n; scanf("%d",&n);
    int i=0; // 'S' 등장 횟수
    int* a=(int*)malloc(sizeof(int)*n); // 'S' 등장 위치
    char* s=(char*)malloc(sizeof(char)*(n+1)); scanf("%s",s); s[n]='\0';
    for(j=0;j<n;j++){if(s[j]=='S'){a[++i]=j;}}
    a[0]=-1; // 이전 등장 위치+1~현재 등장 위치로 조작


    // for(j=0;j<=i;j++){printf("%d\t",a[j]);}

    int l; // left
    int r; // right
    int numberof_c; // cream
    int numberof_j; // jam

    int numberof_cj=0; // 크림-잼 스콘
    int numberof_jc=0; // 잼-크림 스콘

    for(j=1;j<=i;j++){
        l=a[j-1]+1;
        r=a[j];
        numberof_c=0;
        numberof_j=0;
        k=l; // 구간 오프셋

        if(s[k]=='C'){ // 크림-잼 스콘
            while(s[k]=='C'){numberof_c++; k++;}
            while(s[k]=='J'){numberof_j++; k++;}
            if((numberof_c>0)&&(numberof_j>0)&&(k==r)){numberof_cj++;}
        }
        else{ // 잼-크림 스콘
            while(s[k]=='J'){numberof_c++; k++;}
            while(s[k]=='C'){numberof_j++; k++;}
            if((numberof_c>0)&&(numberof_j>0)&&(k==r)){numberof_jc++;}
        }
    }
    printf("%d\n%d",numberof_cj,numberof_jc);

    free(a);
    free(s);
}