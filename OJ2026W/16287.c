// P5 16287: Parcel(DP,중간에서만나기)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    int j; int k;
    int w; int n; scanf("%d %d",&w,&n);
    int* a=(int*)malloc(sizeof(int)*n);
    char* t=(char*)malloc(sizeof(char)*(w+1)); memset(t,0b00000000,w+1);
    for(j=0;j<n;j++){scanf("%d",&a[j]);}

    // 점화식
    for(j=0;j<n;j++){
        for(k=j+1;k<n;k++){
            if((w-(a[j]+a[k])>0)&&(w-(a[j]+a[k])<=w)&&(t[w-(a[j]+a[k])]==1)){
                printf("YES");
                return 0;
            }
        }
        for(k=0;k<j;k++){if(a[j]+a[k]<=w){t[a[j]+a[k]]=1;}}
    }
    printf("NO");
    return 0;
}