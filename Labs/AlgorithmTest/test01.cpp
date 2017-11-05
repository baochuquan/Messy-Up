
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int maxCoins(vector<int> &iNums) {
    vector<int> nums(iNums.size() + 2, 0);
    int n = 1;
    for (int i = 0; i < iNums.size(); i++)
        if (iNums[i] > 0) nums[n++] = iNums[i];
    nums[0] = nums[n++] = 1;

    vector<vector<int> > dp(n, vector<int>(n));
    for (int k = 2; k < n; ++k)
        for (int l = 0; l < n - k; ++l) {
            int r = l + k;
            for (int m = l + 1; m < r; ++m)
                dp[l][r] = max(dp[l][r], nums[l] * nums[m] * nums[r] + dp[l][m] + dp[m][r]);
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(10) << setfill(' ') << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[0][n - 1];
}

int main(){
    vector<int> iNums;
    iNums.push_back(3);
    iNums.push_back(1);
    //iNums.push_back(5);
    //iNums.push_back(2);
    //iNums.push_back(8);
    //iNums.push_back(4);
    int ans;

    ans = maxCoins(iNums);
    cout << " result: " << ans << endl;

    return 0;
}
