#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iterator>
#include <list>

using namespace std;

int main(){

    int n = a.length();
    int i;
    int count = 0;
    printf("N is: %d\n", n);
    for(i = 0; i < n; i++){
        if(a[i] != 'a'){
            printf("Diff: %c, the position is %d\n", a[i], i);
            count++;
        } 
    }
    if(count == 0){
        printf("All is a\n");
    } else {
        printf("Diff Count: %d\n", count);
    }
    return 0;
}
/*

class Solution {
public:


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 + len2 < k || k == 0)
            return res;
        res.resize(k, 0);
        stack<int> stk;
        int i = 0, j = 0;
        int count1, count2;
        vector<int> arr1;
        vector<int> arr2;
        vector<int> mergedArr;
        for(int i = 0; i <= k; i++){
            count1 = i;
            count2 = k-i;
            if(count1 <= len1 && count2 <= len2){
                arr1 = getArray(nums1, count1);
                arr2 = getArray(nums2, count2);
                printf("\n");
                mergedArr = mergeArray(arr1, arr2);
                for(int j = 0; j < k; j++){
                    if(res[j] == mergedArr[j])
                        continue;
                    if(res[j] < mergedArr[j]){
                        res = mergedArr;
                    }
                    break;
                }   
            }
        }
        return res;
        
    }
    vector<int> getArray(vector<int>& nums, int count){
        stack<int> stk;
        vector<int> ans;
        int i = 0;
        int tmpCount = nums.size();
        while(i < nums.size()){
            if(stk.empty()){
                stk.push(nums[i++]);
            }
            while(!stk.empty() && tmpCount > count && stk.top() < nums[i]){
                stk.pop();
                tmpCount--;
            }
            stk.push(nums[i++]);
        }
        while(!stk.empty()){
            if(stk.size() > count){
                stk.pop();
                continue;
            }
            ans.push_back(stk.top());
            printf("%d ", stk.top());
            stk.pop();
        }
        printf("\n");
        return ans;
    }
    
    vector<int> mergeArray(vector<int>& arr1, vector<int>& arr2){
        vector<int> res;
        int i = arr1.size()-1, j = arr2.size()-1;
        while(i >= 0 && j >= 0){
            if(arr1[i] > arr2[j]){
                res.push_back(arr1[i--]);
            } else if(arr1[i] < arr2[j]){
                res.push_back(arr2[j--]);
            } else {
                bool flag = true;
                int x = i, y = j;
                int std = arr1[i];
                while(x >= 0 && y >= 0 && min(arr1[x], arr2[y]) >= std){
                    if(arr1[x] == arr2[y]){
                        x--;
                        y--;
                        continue;
                    } else {
                        break;
                    }
                }
                if(x >= 0 && y >= 0){
                    flag = arr1[x] > arr2[y] ? true : false;
                } else if(x >= 0 && y < 0){
                    flag = arr1[x] > std ? true : false;
                } else if(x < 0 && y >= 0){
                    flag = arr2[y] > std ? false : true;
                }
                    
                if(flag){
                    res.push_back(arr1[i--]);
                } else {
                    res.push_back(arr2[j--]);
                }
            }
        }
        while(i >= 0){
            res.push_back(arr1[i--]);
        }
        while(j >= 0){
            res.push_back(arr2[j--]);
        }
        return res;
    }

};

/*
int main(){
    vector<string> inputs;
    string tmp;
    char *tm;
    scanf("%s", tm);
    tmp = to_string(tm);
    cout << tmp << endl;
    while(cin >> tmp){
        if(tmp.length() == 0)
            break;
        cout << tmp << endl;
        inputs.push_back(tmp);
    }
    printf("%d\n", inputs.size());
    return 0;
}
*/
 /*
int ans;

void quickSort(vector<int> &nums, int l, int r, int k){
    if(l >= r)
        return ;
    int X = nums[l];
    int i = l;
    int j = r;
    while(i < j){
        while(i < j && nums[j] >= X){
            j--;
        }
        if(j > i)
            nums[i++] = nums[j];
        while(i < j && nums[i] < X){
            i++;
        }
        if(j > i)
            nums[j--] = nums[i];
    }
    nums[i] = X;
    if(i == k){
        ans = X;
        return ;
    }
    if(i > k)
        quickSort(nums, l, i-1, k);
    else
        quickSort(nums, i+1, r, k);
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            nums.push_back(i*j);
        }
    }
    quickSort(nums, 0, nums.size()-1, k-1);
    printf("%d\n", nums[k-1]);
    return 0;
}
*/
/*
bool judge(string s){
    string flag = "RC";
    int i = 0;
    while(s[i] >= 'A' && s[i] <= 'Z'){
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9'){
        i++;
    }
    if(i != s.length())
        return true;
    return false;
}

string AtoB(string a){
    int i = 1;
    string numX = "";
    long long numY = 0;
    while( i < a.length() && a[i] >= '0' && a[i] <= '9'){
        numX += a[i];
        i++;
    }
    i++;
    while( i < a.length() && a[i] >= '0' && a[i] <= '9'){
        numY = numY*10 + (a[i]-'0');
        i++;
    }
    string tmp = "";
    while(numY/26 != 0){
        tmp += ('A'+numY/26-1);
        numY = numY%26;
    }
    tmp += ('A'+numY%26-1);
    string ans = tmp+numX;
    return ans;
}

string BtoA(string b){
    int i =0;
    string numX = "";
    string numY = "";
    long long tmp = 0;
    while(i < b.length() && b[i] >= 'A' && b[i] <= 'Z'){
        tmp = tmp*26 + (b[i]-'A'+1);
        i++;
    }
    numX = to_string(tmp);
    while(i < b.length()){
        numY += b[i];
        i++;
    }
    string ans = 'R' + numY + 'C' + numX;
    return ans;
}

int main(){
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        string input;
        cin >> input;
        if(judge(input)){
            string ans = AtoB(input);
            cout << ans << endl;
        } else {
            string ans = BtoA(input);
            cout << ans << endl;
        }
    }
    return 0;
}
*/
/*

int main(){
    string S = "dabcba";
    int n = S.length();
    vector<vector<bool> > f(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        f[i][i] = true;
        for(int j = 0; j < i; j++){
            if(S[j] == S[i] && i == j+1)
                f[j][i] = true;
            else if(S[i] == S[j] && f[j+1][i-1])
                f[j][i] = true; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << int(f[i][j]) << " ";
        }
        cout << endl;
    }
    return 0;
}

*/
/*
struct cacheEntry {
    int key;
    int val;
    cacheEntry(int k, int  v): key(k), val(v){}
};

int NUM;
list<cacheEntry> l;
unordered_map<int, list<cacheEntry>::iterator> hs;

void moveToHead(int key){
    cacheEntry newItem = *hs[key];
    l.erase(hs[key]);
    l.push_front(newItem);
    hs[key] = l.begin();
}

void set(int key, int val){
    if(hs.find(key) == hs.end()){
        cacheEntry newItem(key, val);
        if(l.size() >= NUM){
            hs.erase(l.back().key);
            l.pop_back();
        }
        l.push_front(newItem);
        hs[key] = l.begin();
        return ;
    } else {
        hs[key]->val = val;
        moveToHead(key);
        return ;
    }
}
int get(int key){
    if(hs.find(key) == hs.end())
        return -1;
    moveToHead(key);
    return hs[key]->val;
}

int main(){
    scanf("%d", &NUM);

    return 0;
}
*/

/*
struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x): val(x), left(NULL), right(NULL){}
};

TreeNode* helper(string preorder, int s0, int e0, string inorder, int s1, int e1){
    if(s0 > e0)
        return NULL;
    char target = preorder[s0];
    int pos;
    for(int i = s1; i <= e1; i++){
        if(target == inorder[i]){
            pos = i;
            break;
        }
    }
    TreeNode* root = new TreeNode(target);
    root->left = helper(preorder, s0+1, s0+pos-s1, inorder, s1, pos-1);
    root->right = helper(preorder, s0+pos-s1+1, e0, inorder, pos+1, e1);
    return root;
}

void post(TreeNode* root){
    if(root == NULL)
        return ;
    post(root->left);
    post(root->right);
    printf("%c", root->val);
}

int main(){ 
    string preorder;
    string inorder;
    while(cin >> preorder && cin >> inorder && preorder.length() != 0 && inorder.length() != 0){

        TreeNode* root = helper(preorder, 0, preorder.length()-1, inorder, 0, inorder.length()-1);
        post(root);
        cout << endl;
    }
    return 0;
}
*/



/*
void quickSort(int nums[], int l, int r){
    if(l >= r)
        return ;
    int X = nums[l];
    int i = l;
    int j = r;
    while(i < j){
        while(i < j && nums[j] >= X){
            j--;
        }
        if(j > i)
            nums[i++] = nums[j];
        while(i < j && nums[i] < X){
            i++;
        }
        if(j > i)
            nums[j--] = nums[i];
    }
    nums[i] = X;
    quickSort(nums, l, i-1);
    quickSort(nums, i+1, r);
}
*/
/*
void merge(int nums[], int l, int m, int r){
    vector<int> tmp;
    int i = l, j = m+1;
    while(i <= m && j <= r){
        if(nums[i] < nums[j])
            tmp.push_back(nums[i++]);
        else
            tmp.push_back(nums[j++]);
    }
    while(i <= m){
        tmp.push_back(nums[i++]);
    }
    while(j <= r){
        tmp.push_back(nums[j++]);
    }
    for(i = l, j = 0; i <= r; i++, j++){
        nums[i] = tmp[j];
    }
}

void mergeSort(int nums[], int l, int r){
    if(l >= r)
        return ;
    int mid = (l + r) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid+1, r);
    merge(nums, l, mid, r);
}
*/
/*
int main(){
    int nums[] = {5,2,7,1,9,8,3,6,4};
    for(int i = 0; i < 9; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");

    //quickSort(nums, 0, 8);
    mergeSort(nums, 0, 8);
    for(int i = 0; i < 9; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}

*/

/*

long helper(long N, long P, long W, long H, vector<long> &aI){
    long S = 0;
    long wPerLine;
    long limitLine;
    long totalLine;
    long tmp;

    do{
        S++;
        if(W/S <= 0 || H/S <= 0){
            return S-1;
        }
        wPerLine = W/S;
        limitLine = H/S * P;
        totalLine = 0;
        tmp = 0;
        for(int i = 0; i < aI.size(); i++){
            tmp = aI[i]%wPerLine == 0 ? aI[i]/wPerLine : aI[i]/wPerLine + 1;
            totalLine += tmp;
        }
    } while(totalLine <= limitLine);
    return S-1;
}

int main(){
    int caseNum;
    scanf("%d", &caseNum);

    vector<long> tmp;
    for(int i = 0; i < caseNum; i++){
        long N,P,W,H;
        scanf("%ld %ld %ld %ld", &N, &P, &W, &H);

        vector<long> a;
        for(int j = 0; j < N; j++){
            long aI;
            scanf("%ld", &aI);
            a.push_back(aI);
        }
        long res = helper(N, P, W, H, a);
        printf("%ld\n", res);
    }
    return 0;
}
*/

/*
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPalindrome(string s){
    if(s.length() == NULL)
        return 0;

    int maxLen = 0;
    int L, R;
    int i = 0;
    while(i < s.length()){
        //odd
        int oddLen = 1;
        L = i-1;
        R = i+1;
        while(L>=0 && R<s.length() && s[L] == s[R]){
            oddLen += 2;
            L--;
            R++;
        }
        maxLen = maxLen < oddLen ? oddLen : maxLen;

        //even
        int evenLen = 0;
        L = i;
        R = i+1;
        while(L>=0 && R<s.length() && s[L] == s[R]){
            evenLen += 2;
            L--;
            R++;
        }
        maxLen = maxLen < evenLen ? evenLen : maxLen;
        i++;
    }
    return maxLen;
}


int main(){
    vector<string> str;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string strTmp;
        cin >> strTmp;
        str.push_back(strTmp);
    }

    for(int i = 0; i < n; i++){
        int count = longestPalindrome(str[i]);
        cout << count << endl;
    }
    return 0;
}
*/