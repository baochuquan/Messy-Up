class Solution {
public:
    int numTrees(int n) {
        if(n == 0 && n == 1)
            return 1;
        vector<int> opt(n+1, 0);
        opt[0] = 1;
        opt[1] = 1;
        opt[2] = 2;
        for(int i = 3; i <= n; i++){
            for(int j = 0; j <= i; j++){
                opt[i] += opt[j] * opt[i-j-1];
            }
        }
        return opt[n];
    }
};
