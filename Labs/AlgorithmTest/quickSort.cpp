#include<stdio.h>
int helper(int num[], int l, int r);
void quickSort(int num[], int l, int r);

void quickSort_2(int num[], int l, int r){
    if(l < r){
        int i = l, j = r, x = num[l];
        while(i < j){
            while(i < j && num[j] >= x)
                j--;
            if(i < j)
                num[i++] = num[j];
            while(i < j && num[i] < x)
                i++;
            if(i < j)
                num[j--] = num[i];
        }
        num[i] = x;
        quickSort_2(num, l, i-1);
        quickSort_2(num, i+1, r);
    }
}

int main(){
    int array[] = {6,7,3,4,5,1,2,7,8,6,9,0};
    quickSort_2(array, 0,11);
    for(int i = 0; i < 12; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}




void quickSort(int num[], int l, int r){
    if(l < r){
        int i = helper(num, l, r);
        quickSort(num, l, i-1);
        quickSort(num, i+1, r);
    }
}

int helper(int num[], int l, int r){
    int i = l, j = r;
    int X = num[l];
    while(i < j){
        while(i < j && num[j] >= X)
            j--;
        if(i < j)
            num[i++] = num[j];
        while(i < j && num[i] < X)
            i++;
        if(i < j)
            num[j--] = num[i];
    }
    num[i] = X;
    return i;
}
