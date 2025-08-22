//1463: 1로 만들기(다이나믹 프로그래밍)
#include<stdio.h>
int main(void){
    int i;
    int n; scanf("%d", &n);
    int size = n + (6 - n % 6) + 1;
    int arr[size];
    arr[0] = 0;     
    arr[1] = 0;     //1
    arr[2] = 1;     //2 - 1
    arr[3] = 1;     //3 / 3
    arr[4] = 2;     //4
    arr[5] = 3;     //5
    arr[6] = 2;     //6

    i = 7;    
    while(i < size){
        arr[i] = 1 + arr[i - 1];i++;
        arr[i] = (arr[i - 1] < arr[i / 2])?(arr[i - 1] + 1):(arr[i / 2] + 1);i++;    
        arr[i] = (arr[i - 1] < arr[i / 3])?(arr[i - 1] + 1):(arr[i / 3] + 1);i++;
        arr[i] = (arr[i - 1] < arr[i / 2])?(arr[i - 1] + 1):(arr[i / 2] + 1);i++;
        arr[i] = 1 + arr[i - 1];i++;
        arr[i] = (arr[i / 2] < arr[i / 3])?(arr[i / 2] + 1):(arr[i / 3] + 1);i++;
    }
    printf("%d", arr[n]);
}
