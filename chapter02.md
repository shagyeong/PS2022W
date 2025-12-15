# 2장 기본 자료구조
## 2.1 선형리스트
### 2.1.1 선형리스트
#### 선형리스트
```C
#include<stdio.h>

int main(void){
    unsigned char i;
    unsigned char a[3]={1,2,3};
    for(i=0;i<3;i++){printf("%u\n",a[i]);}
}
```
#### 선형리스트 저장 순서
```C
#include<stdio.h>

int main(void){
    unsigned char i;
    unsigned char j;
    unsigned char a[2][3]={
        {1,2,3},
        {4,5,6}
    };
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%u: %p\t", a[i][j],&a[i][j]);
        }printf("\n");
    }
}
```
```
$ ./test
1: 0x7ffd0ba2b852       2: 0x7ffd0ba2b853       3: 0x7ffd0ba2b854
4: 0x7ffd0ba2b855       5: 0x7ffd0ba2b856       6: 0x7ffd0ba2b857
```



<!-- ## 2.2 연결리스트 -->
<!-- ### 2.2.1 연결리스트 -->
<!-- #### 연결리스트 -->
<!-- ### 2.2.2 원형 연결리스트 -->
<!-- #### 원형 연결리스트 -->
<!-- ### 2.2.3 양방향 연결리스트 -->
<!-- #### 양방향 연결리스트 -->



<!-- ## 2.3 스택 -->
<!-- ## 2.4 큐 -->
