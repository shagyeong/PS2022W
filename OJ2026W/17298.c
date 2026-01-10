// G4 17298: 오큰수(스택)
#include<stdio.h>
#include<stdlib.h>

int a[1000000];
int b[1000000];
int s[1000000];

int main(void){
    int j;
    int n; scanf("%d",&n);
    int t=-1; // top of stack

    for(j=0;j<n;j++){
        scanf("%d",&a[j]);
        b[j]=-1;
    }

    for(j=0;j<n;j++){
        while((t!=-1)&&(a[j]>a[s[t]])){
            b[s[t--]]=a[j]; // pop
        }
        s[++t]=j; // push
    }

    for(j=0;j<n;j++){printf("%d ",b[j]);}
}