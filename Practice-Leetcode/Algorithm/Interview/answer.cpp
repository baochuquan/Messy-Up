#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;


vector<pair<int, int> > helper(int P, int Q){
    vector<pair<int, int> > ans;
    vector<int> A;
    vector<int> B;
    for(int i = 1; i <= P; i++){
        if(P % i == 0)
            A.push_back(i);
    }
    for(int i = 1; i <= Q; i++){
        if(Q % i == 0)
            B.push_back(i);
    }
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            ans.push_back(pair<int, int>(A[i], B[j]));
        }
    }
    return ans;
}

int main(){
    int P, Q;
    scanf("%d %d", &P, &Q);
    vector<pair<int, int> > ans;
    ans = helper(P, Q);

    for(int i = 0; i < ans.size(); i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
