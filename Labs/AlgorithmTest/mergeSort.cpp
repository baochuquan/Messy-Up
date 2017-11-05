#include<stdio.h>
void merge(int num[], int first, int middle, int last, int tmp[]);
void mergeSort(int num[], int first, int last, int tmp[]);

int main(){
    int array[] = {2,4,5,7,3,1,4,0,8,4,9,7,6};
    int tmp[13] = {0};
    mergeSort(array, 0, 12, tmp);
    for(int i = 0; i < 13; i++){
        printf("%d", array[i]);
    }
    return 0;
}

void merge(int num[], int first, int middle, int last, int tmp[]){
    int k = 0;
    int m = middle, n = last;
    int i = first, j = middle + 1;
    while(i <= m && j <= n){
        if(num[i] <= num[j]){
            tmp[k++] = num[i++];
        }else{
             tmp[k++]= num[j++];
        }
    }
    while(i <= m){
        tmp[k++] = num[i++];
    }
    while(j <= n){
        tmp[k++] = num[j++];
    }
    for(i = 0; i < k; i++){
        num[first+i] = tmp[i];
    }
}

void mergeSort(int num[], int first, int last, int tmp[]){
    if(first < last){
         int mid = (first + last) / 2;
         mergeSort(num, first, mid, tmp);
         mergeSort(num, mid+1, last, tmp);
         merge(num, first, mid, last, tmp);
    }
}
