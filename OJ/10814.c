//10814: 나이순 정렬(정렬)
#include<stdio.h>
#include<stdlib.h>

struct member{
    unsigned char age;
    char name[100];
};
void mergesort(struct member* members[], int l, int r);
void merge(struct member* members[], int l, int m, int r);

int main(void){
    int n; scanf("%d", &n);
    int agebuf;
    struct member* members[n];
    for(int i = 0; i < n; i++){
        struct member* newmember = (struct member*)malloc(sizeof(struct member));
        scanf("%d %s", &agebuf, newmember->name);
        newmember->age = (unsigned char)agebuf;
        members[i] = newmember;
    }
    mergesort(members, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d %s\n", members[i]->age, members[i]->name);
    }
    return 0;
}
void mergesort(struct member* members[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(members, l, m);
        mergesort(members, m + 1, r);
        merge(members, l, m, r);
    }
}
void merge(struct member* members[], int l, int m, int r){
    int i, j, k;
    int left = m - l + 1;
    struct member* L[left];
    for(i = 0; i < left; i++){
        L[i] = members[l + i];
    }
    int right = r - m;
    struct member* R[right];
    for(i = 0; i < right; i++){
        R[i] = members[m + 1 + i];
    }
    i = 0; j = 0; k = l;
    while(i < left && j < right){
        if(L[i]->age <= R[j]->age){
            members[k++] = L[i++];
        }
        else{
            members[k++] = R[j++];
        }
    }
    while(i < left){
        members[k++] = L[i++];
    }
    while(j < right){
        members[k++] = R[j++];
    }
}
