#include <stdio.h>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> &num, int l, int r){
    vector<int> C;
    if(l == r){
        C.push_back(num[l]);
        return C;
    } else {
        int m = (l+r)/2;
        vector<int> A = mergeSort(num, l, m);
        vector<int> B = mergeSort(num, m+1, r);
        int i = 0;
        int j = 0;
        while(i < A.size() && j < B.size()){
            if(A[i] < B[j]){
                C.push_back(A[i]);
                i++;
            } else {
                C.push_back(B[j]);
                j++;
            }
        }
        while(i < A.size()){
            C.push_back(A[i++]);
        }
        while(j < B.size()){
            C.push_back(B[j++]);
        }
        return C;
    }
}

int main(){
    vector<int> num;
    num.push_back(4);
    num.push_back(1);
    num.push_back(5);
    num.push_back(3);
    num.push_back(6);
    num.push_back(8);
    num.push_back(2);
    num.push_back(7);
    num.push_back(9);
    vector<int> newNum;
    newNum = mergeSort(num, 0, 8);
    for(int i = 0; i < 9; i++){
         printf("%d ", newNum[i]);
    }
    printf("\n");
    return 0;
}
