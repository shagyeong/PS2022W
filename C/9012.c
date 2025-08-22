//9012: 괄호(자료 구조, 문자열, 스택)
#include<stdio.h>
void vps(char ps[51]);

int main(void){
    int n; scanf("%d", &n);
    char buf[n][51];
    for(int i = 0; i < n; i++){
        scanf("%s", buf[i]);
    }
    for(int i = 0; i < n; i++){
        vps(buf[i]);
    }
}
void vps(char ps[51]){
    int flag = 1;
    int l = 0; int r = 0;
    for(int i = 0; i < 51; i++){
        if(ps[i] == '\0'){
            if(l != r){
                flag = 0;
            }
            break;
        }
        if(ps[i] == '('){
            l++;
        }
        else{
            if(l == r){
                flag = 0;
                break;
            }
            else{
                r++;
            }
        }
    }
    if(flag == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
