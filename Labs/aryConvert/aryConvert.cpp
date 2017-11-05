#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

int main(){
    int num;
    scanf("%d", &num);
    cout << "----++++----++++----++++----++++" << endl;
    cout << bitset<32>(num) << endl;

    return 0;
}
