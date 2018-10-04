#include <stdio.h>
#include <vector>

using namespace std;
/*
vector<int> mergeSort(vector<int> &num, int l, int r) {
  vector<int> C;
  if (l == r) {
    C.push_back(num[l]);
    return C;
  } else {
    int m = (l + r) / 2;
    vector<int> A = mergeSort(num, l, m);
    vector<int> B = mergeSort(num, m+1, r);
    int i = 0;
    int j = 0;
    while(i < A.size() && j < B.size()) {
      if (A[i] < B[j]) {
        C.push_back(A[i]);
        i++;
      } else {
        C.push_back(B[j]);
        j++;
      }
    }
    while(i < A.size()) {
      C.push_back(A[i]);
      i++;
    }
    while(j < B.size()) {
      C.push_back(B[j]);
      j++;
    }
  }
  return C;
}

void quickSort(vector<int> &num, int l, int r ) {
  if (l < r) {
    int i = l;
    int j = r;
    int x = num[i];
    while(i < j) {
      while(num[j] >= x && j > i) {
        j--;
      }
      if(j > i){
        num[i++] = num[j];
      }
      while(num[i] < x && i < j) {
        i++;
      }
      if(i < j) {
        num[j--] = num[i]; 
      }
    }
    num[i] = x;
    quickSort(num, l, i);
    quickSort(num, i+1, r);
  }
}
*/

void quickSort(vector<int> &nums, int l, int r) {
  if (l < r) {
    int i = l;
    int j = r;
    int x = nums[i];
    while(i < j) {
      while(i < j && nums[j] > x) 
        j--;
      if (i < j) 
        nums[i++] = nums[j];
      while(i < j && nums[i] < x)
        i++;
      if (i < j)
        nums[j--] = nums[i];
    }
    nums[i] = x;
    quickSort(nums, l, i-1);
    quickSort(nums, i+1, r);
  }
}

int main() {
  vector<int> num;
  num.push_back(4);
  num.push_back(5);
  num.push_back(1);
  num.push_back(7);
  num.push_back(3);
  num.push_back(8);
  num.push_back(2);
  num.push_back(9);
  num.push_back(6);
  num.push_back(0);
  vector<int> result = num;
  //result = mergeSort(num, 0, 9);
  quickSort(result, 0, 9);
  for(int i = 0; i < result.size(); i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
