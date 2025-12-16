//1464: 뒤집기 3(자료 구조, 그리디 알고리즘, 덱)
#include<stdio.h>
int compare(char* s1, char* s2, int len);
int strlength(const char* s);

int main(void){
    char str[50]; scanf("%s", str);
    int length = strlength(str);
    char buf1[50];
    char buf2[50];

    // type1: 1234|5
    // type2: 4321|5
    // type3: 5|1234
    // type4: 5|4321
        

    for(int i = 1; i < length - 1; i++){
        //1234 vs 4321
        for(int j = 0; j < i + 1; j++){
            buf1[j] = str[i - j];
        }
        if(compare(str, buf1, i) == 1){
            for(int j = 0; j < i + 1; j++){
                buf2[j] = str[j];   //1234
            }
        }
        else{
            for(int j = 0; j < i + 1; j++){
                buf2[j] = buf1[j];  //4321
            }
        }
        if(str[i + 1] <=  buf2[0]){
            //5____
            str[0] = str[i + 1];    
            for(int k = 1; k < i + 2; k++){
                str[k] = buf2[k - 1];
            }
        }
        else{
            //____5
            for(int k = 0; k < i + 1; k++){
                str[k] = buf2[k];
            }
        }
    }
    printf("%s\n", str);
}
int compare(char* s1, char* s2, int len){
    char* p1 = s1;
    char* p2 = s2;
    for(int i = 0; i < len; i++){
        if(*p1 < *p2){
            return 1;
        }
        else if(*p2 < *p1){
            return 2;
        }
        p1++;
        p2++;
    }
    return 1;  //문자열 구성이 같은 경우 루프 탈출 - 어느 한 쪽을 리턴
}
int strlength(const char* s){
    int i = 0;
    for(int j = 0; j < 51; j++){
        if(*s == '\0'){
            return i;
        }
        s++;
        i++;
    }
}
