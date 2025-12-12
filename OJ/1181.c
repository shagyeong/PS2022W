//1181: 단어 정렬(문자열, 정렬)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word{
    char spell[50];
    int length;
};
void mergesort(struct word* dict[], int l, int r);
void merge(struct word* dict[], int l, int m, int r);
int compare(int len, struct word* w0, struct word* w1);  //사전 순으로 앞서는 단어 리턴

int main(void){
    int n; scanf("%d", &n);
    struct word* dict[n];
    for(int i = 0; i < n; i++){
        struct word* neword = (struct word*)malloc(sizeof(struct word));
        scanf("%s", neword->spell);
        neword->length = strlen(neword->spell);
        dict[i] = neword;
    }
    mergesort(dict, 0, n - 1);
    
    //정답 출력
    printf("%s\n", dict[0]->spell);
    for(int i = 1; i < n; i++){
        if(strcmp(dict[i]->spell, dict[i - 1]->spell) != 0){
            printf("%s\n", dict[i]->spell);
        }
    }
}

void mergesort(struct word* dict[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(dict, l, m);
        mergesort(dict, m + 1, r);
        merge(dict, l, m, r);
    }
}
void merge(struct word* dict[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1;
    struct word* L[left];
    for(i = 0; i < left; i++){
        L[i] = dict[l + i];
    }
    int right = r - m;
    struct word* R[right];
    for(i = 0; i < right; i++){
        R[i] = dict[m + 1 + i];
    }
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i]->length == R[j]->length){
            if(compare(L[i]->length, L[i], R[j]) == 0){
                dict[k++] = L[i++];
            }
            else{
                dict[k++] = R[j++];
            }
        }
        else if(L[i]->length < R[j]->length){
            dict[k++] = L[i++];
        }
        else{
            dict[k++] = R[j++];
        }
    }
    while(i < left){
        dict[k++] = L[i++];
    }
    while(j < right){
        dict[k++] = R[j++];
    }
}
int compare(int len, struct word* w0, struct word* w1){
    for(int i = 0; i < len; i++){
        if(w0->spell[i] < w1->spell[i]){
            return 0;
        }
        else if(w0->spell[i] > w1->spell[i]){
            return 1;
        }
    }
    return 0;   //두 문자열이 같음
}
