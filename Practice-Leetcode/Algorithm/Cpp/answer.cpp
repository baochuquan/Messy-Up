//The answer for Leetcode
//----------------------------------
//NO.1: Two Sum
//----------------------------------
struct Node {
    int num,pos;
};

bool cmp(Node a, Node b) {
    return a.num < b.num;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<Node> number;
        int i,j;
        for(i = 0; i < nums.size(); i++){
            Node temp;
            temp.num = nums[i];
            temp.pos = i + 1;
            number.push_back(temp);
        }
        sort(number.begin(),number.end(),cmp);
        for(i = 0, j = number.size()-1; i != j;){
            int sum = number[i].num + number[j].num;
            if(sum == target){
                if(number[j].pos < number[i].pos) {
                    result.push_back(number[j].pos);
                    result.push_back(number[i].pos);

                } else {

                    result.push_back(number[i].pos);
                    result.push_back(number[j].pos);
                }
                break;
            }
            else {
                if(sum < target)
                    i++;
                else
                    j--;
            }
        }
        return result;

    }
};

//----------------------------------
//NO.2 Add Two Sum
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(0);
        ListNode* result = ptr;

        int carry = 0;
        while(l1 != NULL || l2 != NULL){

            int val1 = 0;
            if(l1 != NULL){
                val1 = l1->val;
                l1 = l1->next;
            }

            int val2 = 0;
            if(l2 != NULL){
                val2 = l2->val;
                l2 = l2->next;
            }

            int temp = val1 + val2 + carry;
            carry = temp/10;
            ptr->next = new ListNode(temp % 10);
            ptr = ptr->next;
        }
        if(carry == 1){
            ptr->next = new ListNode(1);
        }
        return result->next;
    }
};

//----------------------------------
// No.3 Longest Substring Without Repeating Characters
//----------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int L, R;
        L = R = 0;
        int max = 0;
        int tmp = 0;
        unordered_map<char, int> count;
        for(int i = 0; i < n; i++){
            if(count.find(s[R]) != count.end()){
                for(; L <= R; L++){
                    if(s[L] != s[R]){
                        count.erase(s[L]);
                        tmp--;
                    } else {
                        L++;
                        R++;
                        break;
                    }
                }
            } else {
                count[s[R]] = 1;
                R++;
                tmp++;
                max = max > tmp ? max : tmp;
            }
        }
        return max;
    }
};

//----------------------------------
// No.4 Median of Two Sorted Array
//----------------------------------
class Solution {
public:

/* solution 1
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> newNums;
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                newNums.push_back(nums1[i]);
                i++;
            } else {
                newNums.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1){
            newNums.push_back(nums1[i]);
            i++;
        }
        while(j < n2){
            newNums.push_back(nums2[j]);
            j++;
        }
        return (n1+n2)%2 == 1 ? newNums[(n1+n2)/2] : (newNums[(n1+n2)/2] + newNums[(n1+n2)/2-1])*0.5;
    }
*/

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if((m+n)%2 == 1)
            return getKthNum(nums1.begin(), m, nums2.begin(), n, (m+n)/2+1);
        else
            return ( getKthNum(nums1.begin(), m, nums2.begin(), n, (m+n)/2) +
                getKthNum(nums1.begin(), m, nums2.begin(), n, (m+n)/2+1) ) * 0.5;
    }
    double getKthNum(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k){
        if(m > n) return getKthNum(B, n, A, m, k);
        if(m == 0) return *(B+k-1);
        if(k == 1) return min(*B, *A);

        int ia = min(k/2, m), ib = k-ia;
        if(*(A+ia-1) < *(B+ib-1)){
            return getKthNum(A+ia, m-ia, B, n, k-ia);
        } else if(*(A+ia-1) > *(B+ib-1)){
            return getKthNum(A, m, B+ib, n-ib, k-ib);
        } else {
            return A[ia-1];
        }
    }
};

//----------------------------------
// No.5 Longest Palindromic Substring
//----------------------------------
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return NULL;

        int maxlength = 0;
        int pos = 0;
        int len = s.size();
        int i = 0;
        while(i < len){
            int oddlength = 1;
            int left = i-1;
            int right = i+1;
            while(right < len && left >= 0 && s[left] == s[right]){
                left--;
                right++;
                oddlength += 2;
            }
            if(oddlength >= maxlength){
                maxlength = oddlength;
                pos = i;
            }

            int evenlength = 0;
            left = i;
            right = i+1;
            while(right < len && left >= 0 && s[left] == s[right]){
                left--;
                right++;
                evenlength += 2;
            }
            if(evenlength >= maxlength){
                maxlength = evenlength;
                pos = i;
            }
            i++;
        }
        int begin;
        if(maxlength%2 == 0){
            begin = pos - (maxlength/2 - 1);
        }
        else {
            begin = pos - maxlength/2;
        }
        string res = s.substr(begin, maxlength);
        return res;
    }
};

//----------------------------------
// No.6 ZigZag Conversion
//----------------------------------
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if(numRows == 1) return s;
        string result;
        int x = 0;
        int interval = numRows*2 - 2;
        for(int i = 0; i < len; i += interval){
            result.push_back(s[i]);
        }
        for(int j = 1; j < numRows-1; j++){
            int inter = j*2;
            for(int i = j; i < len; i += inter){
                result.push_back(s[i]);
                inter = interval - inter;
            }
        }
        for(int i = numRows-1; i < len; i += interval){
            result.push_back(s[i]);
        }
        return result;
    }
}

//----------------------------------
//No.8 String to Integer(atoi)
//----------------------------------
class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int i = 0;
        int sign = 1;
        int n = str.length();
        while(str[i] == ' ' && i < n){
            i++;
        }
        if(str[i] == '+'){
            i++;
        } else if(str[i] == '-'){
            i++;
            sign = -1;
        }
        while(i < n){
            if(str[i] < '0' || str[i] > '9')
                break;
            if(num > INT_MAX/10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX%10))
                return sign == -1 ? INT_MIN : INT_MAX;
            num = num * 10 + str[i] - '0';
            i++;
        }
        return num * sign;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int volumn = 0;
        for(int i = 0; i < n; i++){
            int maxL = 0;
            int maxR = 0;
            for(int L = i-1; L >= 0; L--){
                if(height[L] > maxL)
                    maxL = height[L];
            }
            for(int R = i+1; R < n; R++){
                if(height[R] > maxR)
                    maxR = height[R];
            }
            volumn += (min(maxL, maxR) > height[i] ? min(maxL, maxR)-height[i] : 0);
        }
        return volumn;
    }
};

//----------------------------------
//No.10 Regular Expression Matching
//----------------------------------
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
    bool helper(string s, string p, int i, int j){
        if(j == p.length()){
            return i == s.length();
        }

        //if(i==s.length()|| s[i]!=p[j] && p[j]!='.') {
        if(j == p.length()-1 || p[j+1] != '*'){
            if(s[i] != p[j] && p[j] != '.'){
                return false;
            } else {
                return helper(s, p, i+1, j+1);
            }
        }
        //p[j+1] == '*'
        while(i < s.length() && (p[j] == '.' || s[i] == p[j])){
            if(helper(s,p,i,j+2))
                return true;
            i++;
        }
        return helper(s,p,i,j+2);
    }
};

//----------------------------------
//No.11 Container With Most Water
//----------------------------------
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> res;
        int len = height.size();
        int left, right;
        int maxVolumn = 0;
        int i,j;
        for(i = 0, j = len-1; i <= j;){
            int tmpHeight = height[i] < height[j] ? height[i] : height[j];
            int tmpVolumn = tmpHeight * (j-i);
            if(tmpVolumn > maxVolumn){
                maxVolumn = tmpVolumn;
                left = i;
                right = j;
            }
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return maxVolumn;
    }
};

//----------------------------------
//No.12 Integer to Roman
//----------------------------------
class Solution {
public:
    string intToRoman(int num) {
        vector<string> symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        vector<int> number = {1000,900,500, 400,100, 90, 50, 40,   10,  9,  5,   4,  1};
        int sum = 0;
        string res;
        for(int i = 0; i < 13; i++){

            while((sum+number[i]) <= num){
                res += symbol[i];
                sum += number[i];
            }
        }
        return res;
    }
}

//----------------------------------
//No.13 Roman to Integer
//----------------------------------
class Solution {
public:
    int romanToInt(string s) {
        if(s.length() < 1)
            return 0;
        int result = 0;
        int sub = getRomanValue(s[0]);
        int lastv = sub;
        for(int i = 1; i < s.length(); ++i){
            int curc = s[i];
            int curv = getRomanValue(curc);
            if(lastv == curv){
                sub += curv;
            }
            else if(lastv < curv){
                sub = curv - sub;
            } else {
                result += sub;
                sub = curv;
            }
            lastv = curv;
        }
        result += sub;
        return result;

    }
    int getRomanValue(char s){
        switch(s){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
};

//----------------------------------
//No.14 Longest Common Prefix
//----------------------------------
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string prefix = strs[0];
        int i,j;
        for(i = 1; i < strs.size(); i++){
            if(prefix.length() == 0 || strs[i].length() == 0){
                return "";
            }
            int len = prefix.length() < strs[i].length() ? prefix.length() : strs[i].length();
            for(j = 0; j < len; j++){
                if(strs[i][j] != prefix[j])
                    break;
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
}

//----------------------------------
//No.15 3Sum
//----------------------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for(int k = 0; k < len; k++){
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            int i = k+1;
            int j = len-1;
            while(i < j){
                if(i>k+1 && nums[i] == nums[i-1]){
                    i++;
                    continue;
                }
                if(j<len-1 && nums[j] == nums[j+1]){
                    j--;
                    continue;
                }
                int sum = nums[k] + nums[i] + nums[j];
                if(sum == 0){
                    vector<int> tmp;
                    tmp.push_back(nums[k]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    res.push_back(tmp);
                    i++;
                }
                if(sum<0){
                    i++;
                }
                if(sum>0){
                    j--;
                }
            }
        }
        return res;
    }
};

//----------------------------------
//No.16 3Sum Closest
//----------------------------------
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /* n2 + nlgn*/

        if(nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        int len = nums.size();
        int min = INT_MAX;
        int res;
        int sum;
        int low,high;
        for(int k = 0; k < len - 2; k++){
            low = k + 1;
            high = len - 1;
            while(low < high){
                int sum = nums[k] + nums[low] + nums[high];
                if( abs(target - sum) < min ){
                    min = abs(target - sum);
                    res = sum;
                }
                if(min == 0) return target;
                if(sum < target)
                    low++;
                else
                    high--;
            }
        }
        return res;
    }
}

//----------------------------------
//No.17 Letter Combinations of a Phone Number
//----------------------------------
class Solution {
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return ans;
        if(!test(digits))
            return ans;
        vector<string> str;
        str.push_back("0");
        str.push_back("0");
        str.push_back("abc");
        str.push_back("def");
        str.push_back("ghi");
        str.push_back("jkl");
        str.push_back("mno");
        str.push_back("pqrs");
        str.push_back("tuv");
        str.push_back("wxyz");
        int n = digits.length();
        string tmp(n, '0');
        helper(str, tmp, digits, 0);
        return ans;
    }
    bool test(string& a){
        int n = a.length();
        for(int i = 0; i < n; i++){
            if(a[i] == '0' || a[i] == '1')
                return false;
        }
        return true;
    }

    void helper(vector<string> str, string tmp, string digits, int pos){
        if(pos == tmp.length()){
            ans.push_back(tmp);
            return ;
        }
        int index = digits[pos] - '0';
        for(int i = 0; i < str[index].length(); i++){
            tmp[pos] = str[index][i];
            helper(str, tmp, digits, pos+1);
        }
    }
};

//----------------------------------
//No.18 4Sum
//----------------------------------
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int x,y;
        for(int i = 0; i < len-3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < len-2; j++){

                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                x = j + 1;
                y = len - 1;
                while(x < y){
                    if(y < len-1 && nums[y] == nums[y+1]){
                        y--;
                        continue;
                    }
                    if(x > j+1 && nums[x] == nums[x-1]){
                        x++;
                        continue;
                    }

                    if(nums[i] + nums[j] + nums[x] + nums[y] == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[x]);
                        tmp.push_back(nums[y]);
                        res.push_back(tmp);
                        x++;
                    }
                    else {
                        if(nums[i] + nums[j] + nums[x] + nums[y] < target){
                            x++;
                        } else{
                            y--;
                        }
                    }
                }
            }
        }
        return res;
    }
};

//----------------------------------
//No.19 Remove Nth Node From the End of List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* tail = head;
        ListNode* ptr = head;
        while(tail != NULL){
            tail = tail->next;
            total++;
        }
        int len = total - n;
        if(len == 0){
            ptr = ptr->next;
            return ptr;
        }
        while(--len){
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};

//----------------------------------
//No.20 Valid Parentheses
//----------------------------------
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        int len = s.length();
        for(int  i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                str.push(s[i]);
            } else {
                if(str.size() == 0) return false;
                switch(s[i]){
                    case ')':
                        if(str.top() == '(') str.pop();
                        else return false;
                        break;
                    case '}':
                        if(str.top() == '{') str.pop();
                        else return false;
                        break;
                    case ']':
                        if(str.top() == '[') str.pop();
                        else return false;
                        break;
                }
            }
        }
        if(str.size() != 0) return false;
        return true;
    }
};

//----------------------------------
//No.21 Merge Two Sorted Lists
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        int min = 0;
        while(l1 != NULL || l2 != NULL){
            int val1 = 0;
            char f1 = 'N';
            if(l1 != NULL){
                val1 = l1->val;
                f1 = 'Y';
            }

            int val2 = 0;
            char f2 = 'N';
            if(l2 != NULL){
                val2 = l2->val;
                f2 = 'Y';
            }
            if(f1 == 'Y' && f2 == 'Y'){
                min = val1 < val2 ? val1 : val2;
                if(val1 < val2){
                    l1 = l1->next;
                }else{
                    l2 = l2->next;
                }
            }
            else{
                if(f1 == 'Y') {
                    min = val1;
                    l1 = l1->next;
                }
                if(f2 == 'Y') {
                    min = val2;
                    l2 = l2->next;
                }
                if(f1 == 'N' && f2 == 'N') continue;
            }
            ptr->next = new ListNode(min);
            ptr = ptr->next;
        }
            ptr = l1;
        if(l2 != NULL){
            ptr = l2;
        }
        return head->next;
    }
};

//----------------------------------
//No.22 Generate Parenetheses
//----------------------------------
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        int len = n;
        generate(len,len,s,res);
        return res;
    }
    void generate(int left, int right, string s, vector<string> &res){
        if(left == 0 && right == 0){
            res.push_back(s);
        }
        if(left > 0){
            generate(left-1, right, s+'(', res);
        }
        if(right > 0 && right > left){
            generate(left, right-1, s+')', res);
        }
    }
};

//----------------------------------
//No.23 Merge K Sorted Lists
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*solution one*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        return helper(lists, 0, lists.size()-1);
    }
private:
    ListNode* helper(vector<ListNode*>& list, int l, int r){
        if(l < r){
            int m = (l+r)/2;
            return mergeSort(helper(list,l,m), helper(list,m+1,r));
        }
        return list[l];
    }
private:
    ListNode* mergeSort(ListNode * l1, ListNode * l2){
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                res->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                res->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            res = res->next;
        }
        if(l1 != NULL){
            res->next = l1;
        }
        if(l2 != NULL){
            res->next = l2;
        }
        return ans->next;
    }
};
/*solution two*/
struct cmp {
    bool operator ()(const ListNode *a, const ListNode *b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(int i = 0; i < len; i++){
            if(lists[i] != NULL)
            heap.push(lists[i]);
        }
        while(heap.size() != 0){
            ListNode *tmp = heap.top();
            if(heap.top() != NULL){
                heap.pop();
                res->next = tmp;
                res = res->next;
            }
            if(tmp->next != NULL){
                heap.push(tmp->next);
            }
        }
        return ans->next;
    }
};
//----------------------------------
//No.24 Swap Nodes in Pairs
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL)
            return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* res = head->next;
        ListNode* tmp = right->next;
        ListNode* ptr = head;

        while(left != NULL && right != NULL){
            ptr->next = right;
            right->next = left;
            left->next = tmp;
            ptr = left;

            if(tmp == NULL)
                break;
            else {
                left = tmp;
            }
            if(tmp->next == NULL)
                break;
            else {
                right = tmp->next;
                tmp = right->next;
            }
        }
        return res;
    }
};

//----------------------------------
//No.25 Reverse Nodes in k-Group
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;

        ListNode* ptr = head;
        ListNode* start;
        ListNode* ans = new ListNode(0);
        ListNode* tmp = ans;
        ListNode* R;
        while(ptr != NULL){
            start = ptr;
            int count = 0;
            for(int i = 0; i < k; i++){
                if(ptr != NULL){
                    ptr = ptr->next;
                    count++;
                }
            }
            if(count == k){
                tmp->next = helper(start, count);
            } else {
                tmp->next = start;
            }
            tmp = start;
        }
       return ans->next;
    }
    ListNode* helper(ListNode* head, int count){
        if(head == NULL)
            return NULL;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* sPtr = ans->next;
        ListNode* ptr = head;
        while(count--){
            ans->next = ptr;
            ptr = ptr->next;
            ans->next->next = sPtr;
            sPtr = ans->next;
        }
        head->next = NULL;
        return ans->next;
    }
};

//----------------------------------
//No.26 Remove Duplicates from Sorted Array
//----------------------------------
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int res = 1;
        int ptr = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[i-1]){
                res++;
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return res;
    }
};

//----------------------------------
//No.28 Implement strStr()
//----------------------------------
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() == 0 && needle.length() == 0) return 0;
        else {
            if(haystack.length() == 0 && needle.length() != 0) return -1;
            if(haystack.length() != 0 && needle.length() == 0) return 0;
            else{
                int total = haystack.size();
                int len = needle.size();
                int index = -1;
                int tmp;

                for(int i = 0; i < total-len+1; i++){
                    tmp = i;
                    for(int j = 0; j < len; j++){
                        if(haystack[i+j] != needle[j]){
                            tmp = INT_MAX;
                            break;
                        }
                    }
                    if(tmp == i){
                        index = tmp;
                        return index;
                    }
                }
                return index;
            }
        }
    }
};

//----------------------------------
//No.29 Divide Two  Integers
//----------------------------------
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        int res = 0;
        while(a >= b){
            int count = 0;
            while(a >= (b<<(count+1))) count++;
            res += 1 << count;
            a -= (b<<count);
        }

        int ans = (dividend >> 31)^(divisor >> 31) ? -res :res;
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        return ans;
    }
};

//----------------------------------
//No.30 Substring with Concatenation of All Words
//----------------------------------
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int nS = s.length();
        int nW = words.size();
        int wL = words[0].length();
        int tL = nW * wL;
        vector<int> ans;
        if(nS == 0 || nW == 0 || tL > nS)
            return ans;

        unordered_map<string, int> hash;
        for(int i = 0; i < nW; i++){
                hash[words[i]]++;
        }
        for(int i = 0; i < nS-tL+1; i++){
            if(checkSubstring(hash, i, s, nW, wL)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool checkSubstring(unordered_map<string, int>& hash, int start, string s, int nW, int wL){
        unordered_map<string, int> count;

        for(int i = 0; i < nW; i++){
            string tmp = s.substr(start+i*wL, wL);
            if(hash.find(tmp) == hash.end())
                return false;
            count[tmp]++;
            if(count[tmp] > hash[tmp])
                return false;
        }
        return true;
    }
};

//----------------------------------
//No.31 Next Premutation
//----------------------------------
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*first solution
        next_permutation(nums.begin(), nums.end());
        */
        /*second solution*/
        int length = nums.size() - 1;
        while(length > 0){
            if(nums[length-1] < nums[length])
                break;
            length--;
        }
        if(length == 0){
            sort(nums.begin(), nums.end());
            return ;
        }
        int k = nums.size() - 1;
        for(; k >= length; k--){
            if(nums[length-1] < nums[k])
                break;
        }
        swap(nums[k],nums[length-1]);
        sort(nums.begin()+length, nums.end());
        return ;
    }
};

//----------------------------------
//No.32 Longest Valid Parenthess
//----------------------------------
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len == 0)
            return 0;

        int res = 0;
        int start = 0;
        stack<int> stk;
        for(int i = 0; i < len; i++){
            if(s[i] == '(')
                stk.push(i);
            else
                if(stk.empty()){
                    start = i+1;
                } else {
                    stk.pop();
                    res = stk.empty() ? max(res, i-start+1) : max(res, i-stk.top());
                }
        }
        return res;
    }
};

//----------------------------------
//No.33 Search in Rotated Sorted Array
//----------------------------------
class Solution {
public:
    /*solution 2*/
    int search(vector<int>& nums, int target){
        if(nums.size() == 0)
            return -1;
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(l <= r){
            m = (l+r)/2;
            if(nums[m] == target)
                return m;
            if(nums[l] <= nums[m]){
                if(nums[l] <= target && target < nums[m])
                    r = m-1;
                else
                    l = m+1;
            } else {
                if(nums[m] < target && target <= nums[r])
                    l = m+1;
                else
                    r = m-1;
            }
        }
        return -1;
    }
    /*solution 1*/
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target)
                return i;
        }
        return -1;
    }
};

//----------------------------------
//No.34 Search for a Range
//----------------------------------
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.size() == 0) return res;

        int left = 0;
        int right = nums.size() - 1;
        int middle = right;
        if(nums[left] == target) middle = left;
        while(left < middle){
            if(nums[middle] == target) break;
            if(nums[middle] > target){
                right = middle;
                middle = (left+right)/2;
            } else {
                left = middle;
                middle = (left+right)/2;
            }
        }
        for(int i = middle; i >=0; i--){
            if(nums[i] == target){
                res[0] = i;
            } else {
                break;
            }
        }
        for(int i = middle; i < nums.size(); i++){
            if(nums[i] == target){
                res[1] = i;
            } else {
                break;
            }
        }
        return res;
    }
};

//----------------------------------
//No.35 Search Insert Position
//----------------------------------
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int index;
        for(int i = 0; i < len; i++){
            if(nums[i] == target){
                index = i;
                return index;
            } else {
                if(nums[i] > target){
                    index = i;
                    return index;
                }
            }
        }
    }
};

//----------------------------------
//----------------------------------

//----------------------------------
//No.36 Valid Sudoku
//----------------------------------
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<bool> used(9, false);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int index = board[i][j] - '0';
                if(used[index] == false)
                    used[index] = true;
                else
                    return false;
            }
        }
        for(int i = 0; i < 9; i++){
            vector<bool> used(9, false);
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                int index = board[j][i] - '0';
                if(used[index] == false)
                    used[index] = true;
                else
                    return false;
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                vector<bool> used(9, false);
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        if(board[i*3 + x][j*3 + y] == '.') continue;
                        int index = board[i*3 + x][j*3 + y] - '0';
                        if(used[index] == false)
                            used[index] = true;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

//----------------------------------
//No.37 Sudoku Solver
//----------------------------------
class Solution {
private:
    vector<char> cTable = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }

    bool helper(vector<vector<char>>& board, int x, int y){
        if(y >= 9){
            x++;
            y = 0;
        }
        if(x >= 9)
            return true;
        while(board[x][y] != '.'){
            y++;
            if(y >= 9){
                x++;
                y = 0;
                if(x >= 9)
                    return true;
            }
        }

        for(int i = 0; i < 9; i++){
            char c = cTable[i];
            if(judge(c, x, y, board)){
                board[x][y] = c;
                if(helper(board, x, y+1)){
                    return true;
                }
            }
            board[x][y] = '.';
        }
        return false;
    }

    bool judge(char c, int x, int y, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(c == board[x][i])
                return false;
        }
        for(int i = 0; i < 9; i++){
            if(c == board[i][y])
                return false;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(c == board[x/3*3+i][y/3*3+j]){
                    return false;
                }
            }
        }
        return true;
    }
};

//----------------------------------
//No.38 Count and Say
//----------------------------------
class Solution {
public:
    string countAndSay(int n) {
        string res = string(1,'1');
        int i = 1;
        while(i < n){
            res = deal(res);
            i++;
        }
        return res;
    }
private:
    string deal(string res){
        string ans;
        int count = 1;
        char pre = res[0];
        for(int i = 1; i < res.size(); i++){
            if(pre == res[i]){
                count++;
            } else {
                ans.push_back(count+'0');
                ans.push_back(pre);
                pre = res[i];
                count = 1;
            }
        }
        ans.push_back(count+'0');
        ans.push_back(pre);
        return ans;
    }
};

//----------------------------------
//No.39 Combination Sum
//----------------------------------
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        helper(candidates, tmp, 0, 0, target);
        return ans;
    }
    void helper(vector<int> candidates, vector<int> tmp, int sum, int pos, int target){
        if(sum == target){
            ans.push_back(tmp);
            return ;
        }
        for(int i = pos; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            if(sum + candidates[i] <= target){
                helper(candidates, tmp, sum+candidates[i], i, target);
            }
            tmp.pop_back();
        }
        return ;
    }
};

//----------------------------------
//No.40 Combination Sum II
//----------------------------------
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        helper(tmp, candidates, 0, target, 0);
        return ans;
    }
    void helper(vector<int> tmp, vector<int>& candidates, int index, int target, int sum){
        if(sum == target){
            ans.push_back(tmp);
            return ;
        }
        if(sum > target)
            return ;

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            helper(tmp, candidates, i+1, target, sum+candidates[i]);
            tmp.pop_back();
        }
        return ;
    }
};

//----------------------------------
//No.41 First Missing Positive
//----------------------------------
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]-1){
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]){
                    continue;
                } else {
                    int tmp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = tmp;
                    i--;
                }
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]-1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

//----------------------------------
//No.42 Trapping Rain Water
//----------------------------------
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int volumn = 0;
        for(int i = 0; i < n; i++){
            int maxL = 0;
            int maxR = 0;
            for(int L = i-1; L >= 0; L--){
                if(height[L] > maxL)
                    maxL = height[L];
            }
            for(int R = i+1; R < n; R++){
                if(height[R] > maxR)
                    maxR = height[R];
            }
            volumn += (min(maxL, maxR) > height[i] ? min(maxL, maxR)-height[i] : 0);
        }
        return volumn;
    }
};

//----------------------------------
//No.43 Multiply Strings
//----------------------------------
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')){
            string ans(1, '0');
            return ans;
        }
        vector<int> res(len1+len2, 0);
        for(int i = 0; i < len2; i++){
            int index = i+1;
            for(int j = 0; j < len1; j++){
                res[index] += (num1[j]-'0')*(num2[i]-'0');
                index++;
            }
        }
        int carry = 0;
        for(int i = len1+len2-1; i >= 0; i--){
            int tmp = res[i] + carry;
            res[i] = tmp%10;
            carry = tmp/10;
        }
        string ans;
        int start;
        start = res[0] != 0 ? 0 : 1;
        for(int i = start; i < len1+len2; i++){
            ans.push_back(res[i]+'0');
        }
        return ans;
    }
};

//----------------------------------
//No.44 Wildcard Matching
//----------------------------------
class Solution {
public:
    bool isMatch(string s, string p){
        int len = s.length();
        vector<bool> f(len+1, false);
        f[0] = true;
        for(int j = 0; j < p.length(); j++){
            if(p[j] != '*'){
                for(int i = len; i >= 0; i--){
                    f[i+1] = (s[i] == p[j] || p[j] == '?') && f[i];
                }
            } else {
                int i = 0;
                while(i <= len && !f[i]){
                    i++;
                }
                for(; i <= len; i++){
                    f[i] = true;
                }
            }
            f[0] = f[0]&&p[j] == '*';
        }
        return f[len];
    }

/* solution 1: time limit exceeded
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
    bool helper(string s, string p, int i, int j){
        if(j == p.length())
            return i == s.length();

        //p[j+1] != '*'
        if(j == p.length()-1 || p[j] != '*'){
            if(s[i] != p[j] || p[j+1] != '?')
                return false;
            else
                helper(s, p, i+1, j+1);
        }
        //p[j+1] == '*'
        while(i < s.length()){
            if(helper(s, p, i, j+2))
                return true;
            i++;
        }
        return helper(s, p, i, j+2);
    }
    */
};

//----------------------------------
//No.45 Jump Game II
//----------------------------------
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> step(n, INT_MAX);
        step[0] = 0;
        int curglobal = nums[0];
        int curpos = 0;
        int maxpos = 0;
        int maxglobal = nums[0];

        int i = 0;
        while(i < n){
            if(maxglobal < nums[i]+i){
                maxglobal = nums[i]+i;
                maxpos = i;
            }
            step[i] = min(step[curpos]+1, step[i]);
            i++;
            if(i > curglobal){
                curglobal = maxglobal;
                curpos = maxpos;
            }
        }
        return step[n-1];
    }
};

//----------------------------------
//No.46 Permutations
//----------------------------------
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int> > ret;
        if(N == 1) {
            ret.push_back(nums);
            return ret;
        }
        vector<int> tmp;
        vector<vector<int> > post;
        vector<int> cur;
        for(int i = 0; i < N; i++){
            cur = nums;
            cur.erase(cur.begin()+i);
            post = permute(cur);
            for(int j = 0; j < post.size(); j++){
                tmp = post[j];
                tmp.insert(tmp.begin(), nums[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
/*solution 2*/
class Solution {
    vector<vector<int> > res;
    int N;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        perm(nums, 0);
        return res;
    }
private:
    void perm(vector<int>& nums, int i){
        if(i == N){
            res.push_back(nums);
            return ;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[j],nums[i]);
            perm(nums, i+1);
            swap(nums[i],nums[j]);
        }
    }
};

//----------------------------------
//No.47 Permutation II
//----------------------------------
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        vector<int> tmp(nums.size(), 0);
        vector<bool> visit(nums.size(), false);
        helper(nums, tmp, visit, 0);
        return ans;
    }
    void helper(vector<int>& nums, vector<int>& tmp, vector<bool>& visit, int pos){
        if(pos == tmp.size()){
            ans.push_back(tmp);
            return ;
        }
        int pre = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(visit[i] || nums[i] == pre)
                continue;
            else{
                pre = nums[i];
                tmp[pos] = nums[i];
                visit[i] = true;
                helper(nums, tmp, visit, pos+1);
                visit[i] = false;
            }
        }
        return ;
    }
};

//----------------------------------
//No.48 Rotate Image
//----------------------------------
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size()-1; i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//----------------------------------
//No.49 Group Anagrams
//----------------------------------
bool cmp(string a, string b){
    return a.compare(b) < 0;
}
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        vector<vector<string> > ans;
        vector<string> keys;
        unordered_map<string, vector<string>> hash;

        int n = strs.size();
        for(int i = 0; i < n; i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            if(hash.find(tmp) == hash.end()){
                keys.push_back(tmp);
            }
            hash[tmp].push_back(strs[i]);
        }
        int hn = keys.size();
        for(int i = 0; i < hn; i++){
            ans.push_back(hash[keys[i]]);
        }
        return ans;
    }
};

//----------------------------------
//No.50 Pow(x, n)
//----------------------------------
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        double half = myPow(x, n/2);
        if(n%2 == 0){
            return half * half;
        } else if(n > 0){
            return half * half * x;
        } else {
            return (half/x)*half;
        }
    }
};

//----------------------------------
//No.51 N-Queens
//----------------------------------
class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n, string(n, '.'));
        helper(cur, 0);
        return ans;
    }

    void helper(vector<string> cur, int row){
        if(row == cur.size()){
            ans.push_back(cur);
            return ;
        }
        for(int col = 0; col < cur[row].length(); col++){
            if(judge(cur, row, col)){
                cur[row][col] = 'Q';
                helper(cur, row+1);
                cur[row][col] = '.';
            }

        }
    }

    bool judge(vector<string> target, int row, int col){
        for(int i = row-1; i >= 0; i--){
            if(target[i][col] == 'Q')
                return false;
            if(col+row-i < target[row].length() && target[i][col+(row-i)] == 'Q')
                return false;
            if(col-row+i >= 0 && target[i][col-(row-i)] == 'Q')
                return false;
        }
        return true;
    }
};

//----------------------------------
//No.52 N-Queens II
//----------------------------------
class Solution {
    int count = 0;
public:
    int totalNQueens(int n) {
        vector<string> cur(n, string(n,'.'));
        helper(cur, 0);
        return count;
    }
    void helper(vector<string> cur, int row){
        if(row == cur.size()){
            count += 1;
            return ;
        }
        for(int col = 0; col < cur[row].length(); col++){
            cur[row][col] = 'Q';
            if(judge(cur, row, col)){
                helper(cur, row+1);
            }
            cur[row][col] = '.';
        }
    }

    bool judge(vector<string> target, int row, int col){
        for(int i = row-1; i >= 0; i--){
            if(target[i][col] == 'Q')
                return false;
            if(col+row-i < target[row].length() && target[i][col+row-i] == 'Q')
                return false;
            if(col-row+i >= 0 && target[i][col-row+i] == 'Q')
                return false;
        }
        return true;
    }
};

//----------------------------------
//No.53 Maximum Subarray
//----------------------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*solution 1*//*
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxsum){
                maxsum = sum;
            }
            if(sum < 0)
                sum = 0;
        }
        return maxsum;
        */
        /*solution 2*/
        int maxsum = nums[0];
        int optPre = nums[0];
        int optCur;
        for(int i = 1; i < nums.size(); i++){
            optCur = max(optPre+nums[i], nums[i]);
            if(maxsum < optCur){
                maxsum = optCur;
            }
            optPre = optCur;
        }
        return maxsum;
    }
};

//----------------------------------
//No.54 Spiral Matrix
//----------------------------------
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;

        int m = matrix.size();
        int n = matrix[0].size();
        int level = m > n ? n/2 : m/2;
        int min = m < n ? m : n;
        int round=0;
        int i,j;
        for(; round < level; round++){
            i = round;
            j = round;
            for(; i < n-round-1; i++){
                ans.push_back(matrix[j][i]);
            }
            for(; j < m-round-1; j++){
                ans.push_back(matrix[j][i]);
            }
            for(; i > round; i--){
                ans.push_back(matrix[j][i]);
            }
            for(; j > round; j--){
                ans.push_back(matrix[j][i]);
            }
        }
        if(min%2 == 1){
            if(m > n){
                for(i = round, j = round; j < m-round; j++){
                    ans.push_back(matrix[j][i]);
                }
            } else {
                for(i = round, j = round; i < n-round; i++){
                    ans.push_back(matrix[j][i]);
                }
            }
        }
        return ans;
    }
};

//----------------------------------
//No.55 Jump Game
//----------------------------------
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int global = 0;
        for(int i = 0; i < nums.size() && i <= global; i++){
            global = max(global, i+nums[i]);
        }
        if(global < (nums.size()-1))
            return false;
        else
            return true;
    }
};

//----------------------------------
//No.56 Merge Intervals
//----------------------------------
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a, Interval b){
    if(a.start < b.start)
        return true;
    else if(a.start == b.start)
        return a.end < b.end;
    else return false;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0)
            return res;

        sort(intervals.begin(), intervals.end(), comp);
        Interval tmp = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(tmp.end >= intervals[i].start){
                tmp.end = tmp.end < intervals[i].end ? intervals[i].end : tmp.end;
            } else {
                res.push_back(tmp);
                tmp = intervals[i];
            }
        }
        res.push_back(tmp);

        return res;
    }
};

//----------------------------------
//No.57 Insert Interval
//----------------------------------
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        vector<Interval> ans;
        if(len == 0){
            ans.push_back(newInterval);
            return ans;
        }
        //bool hasPush = false;
        int i = 0;
        for(; i < len; i++){
            if(intervals[i].end < newInterval.start){
                ans.push_back(intervals[i]);
            } else if(newInterval.end < intervals[i].start){
                //hasPush = true;
                ans.push_back(newInterval);
                break;
            } else {
                newInterval.start = newInterval.start < intervals[i].start ? newInterval.start : intervals[i].start;
                newInterval.end = newInterval.end > intervals[i].end ? newInterval.end : intervals[i].end;
            }
        }
        if(i < len){
            for(; i < len; i++){
                ans.push_back(intervals[i]);
            }
        } else {
            ans.push_back(newInterval);
        }
        return ans;
    }
};

//----------------------------------
//No.58 Length of Last Word
//----------------------------------
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int begin = -1;
        int end = len-1;
        for(int i = len-1; i >= 0; i--){
            if(s[end] == ' '){
                end--;
                continue;
            } else {
                if(s[i] != ' '){
                    continue;
                } else {
                    begin = i;
                    break;
                }
            }
        }
        if(end == -1) return 0;
        if(begin == -1) return end-begin;
        else return end-begin;
    }
};

//----------------------------------
//No.59 Spiral Matrix II
//----------------------------------
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n,vector<int>(n));
        int i, j;
        int round;
        int count = 1;
        for(round = 0; round < n/2; round++){
            i = round;
            j = round;
            for(; i < n-round-1; i++){
                ans[j][i] = count++;
            }
            for(; j < n-round-1; j++){
                ans[j][i] = count++;
            }
            for(; i > round; i--){
                ans[j][i] = count++;
            }
            for(; j > round; j--){
                ans[j][i] = count++;
            }
        }
        if(n%2 == 1){
            ans[n/2][n/2] = count;
        }
        return ans;
    }
};

//----------------------------------
//No.60 Permutation Sequence
//----------------------------------
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int factor = 1;
        for(int i = 0; i < n; i++){
            nums[i] = i+1;
            factor *= (i+1);
        }

        k--;
        string ans;
        for(int i =0; i< n; i++){
            factor = factor/ (n-i);
            int index = k / factor;
            ans.push_back(nums[index] + '0');
            //restruct nums since one num has been picked
            for(int j = index; j< n-i; j++)  {
                nums[j]=nums[j+1];
            }
            k = k%factor;
        }
        return ans;
    }
};

//----------------------------------
//No.61 Rotate List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* end = ans->next   ;
        int count = 1;
        while(end->next != NULL){
            end = end->next;
            count++;
        }
        k %= count;
        if(k == 0) return head;
        ListNode* ptr = ans->next;
        for(int i = 1; i < count-k; i++){
            ptr = ptr->next;
        }
        head = ptr->next;
        end->next = ans->next;
        ptr->next = NULL;
        return head;
    }
};

//----------------------------------
//No.62 Unique Paths
//----------------------------------
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> opt(n,1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    opt[j] = 1;
                } else {
                    opt[j] = opt[j]+opt[j-1];
                }
            }
        }
        return opt[n-1];
    }
};

//----------------------------------
//No.63 Unique Paths II
//----------------------------------
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<int> opt(col+1, 0);
        opt[col-1] = 1;
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                opt[j] = obstacleGrid[i][j] == 1 ? 0 : (opt[j]+opt[j+1]);
            }
        }
        return opt[0];
    }
};

//----------------------------------
//No.64 Minimum Path Sum
//----------------------------------
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> opt(n,0);

        for(int i = m-1; i >=0 ; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1){
                    opt[j] = grid[i][j];
                } else {
                    if(i == m-1){
                        opt[j] = opt[j+1] + grid[i][j];
                    } else {
                        if(j == n-1) {
                            opt[j] = opt[j] + grid[i][j];
                        } else {
                            opt[j] = opt[j] < opt[j+1] ? opt[j]+grid[i][j] : opt[j+1]+grid[i][j];
                        }
                    }
                }
            }
        }
        return opt[0];
    }
};

//----------------------------------
//No.65 Valid Number
//----------------------------------
class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
            INVALID,    //0
            SPACE,      //1
            SIGN,       //2
            DIGIT,      //3
            DOT,        //4
            EXPONENT,   //5
            NUM_INPUTS  //6
        };
        int transitionTable[][NUM_INPUTS] = {
            -1,  0,  3,  1,  2, -1,
            -1,  8, -1,  1,  4,  5,
            -1, -1, -1,  4, -1, -1,
            -1, -1, -1,  1,  2, -1,
            -1,  8, -1,  4, -1,  5,
            -1, -1,  6,  7, -1, -1,
            -1, -1, -1,  7, -1, -1,
            -1,  8, -1,  7, -1, -1,
            -1,  8, -1, -1, -1, -1
        };
        int state = 0;
        for(int i = 0; i < s.length(); i++){
            InputType inputType = INVALID;
            if(s[i] == ' ')
                inputType = SPACE;
            else if(s[i] == '+' || s[i] == '-')
                inputType = SIGN;
            else if(s[i] >= '0' && s[i] <= '9')
                inputType = DIGIT;
            else if(s[i] == '.')
                inputType = DOT;
            else if(s[i] == 'e' || s[i] == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];
            if(state == -1)
                return false;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

//----------------------------------
//No.66 Plus One
//----------------------------------
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carryIn = 1;
        for(int i = len-1; i >= 0; i--){
            if(digits[i] + carryIn == 10){
                digits[i] = 0;
                carryIn = 1;
            } else {
                digits[i] += 1;
                carryIn = 0;
                break;
            }
        }
        if(carryIn == 0) return digits;
        else {
            vector<int> res(len+1, 0);
            res[0] = 1;
            return res;
        }
    }
};

//----------------------------------
//No.67 Add Binary
//----------------------------------
class Solution {
public:
    string addBinary(string a, string b) {
        int flag = 0;
        int lena = a.length();
        int lenb = b.length();
        int len = abs(lena - lenb);
        string c;
        c.resize(len, '0');
        if(lena > lenb){
            b = c + b;
        } else {
            a = c + a;
        }
        string res(a.length(), '0');
        for(int i = a.length()-1; i >= 0; i--){
            int cur = (a[i]-'0') ^ (b[i]-'0') ^ flag;
            if((a[i]-'0') + (b[i]-'0') + flag > 1){
                flag = 1;
            } else {
                flag = 0;
            }
            res[i] = cur+'0';
        }
        if(flag == 1){
            res = '1' + res;
        }
        return res;
    }
};

//----------------------------------
//No.68 Text Justification
//----------------------------------
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> ans;
        int n = words.size();
        if(n == 0) return ans;

        int i = 0;
        while(i < n){
            int len = words[i].length();
            int j = i + 1;
            while(j < n && len + words[j].length() + 1 <= maxWidth){
                len += words[j].length() + 1;
                j++;
            }

            string line = words[i];
            if(j == n){ // the last line
                for(int k = i+1; k < n; k++){
                    line += " " + words[k];
                }
                while(line.length() < maxWidth){
                    line += " ";
                }
            } else {
                int extraWhite = maxWidth - len;
                int whiteNum = j - i - 1;
                if(whiteNum == 0){//only one word
                    while(line.length() < maxWidth){
                        line += " ";
                    }
                } else {
                    for(int k = i+1; k < j; k++){
                        line += " ";
                        for(int l = 0; l < extraWhite/whiteNum; l++){
                            line += " ";
                        }
                        if(k - i <= extraWhite%whiteNum){
                            line += " ";
                        }
                        line += words[k];
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};

//----------------------------------
//No.69 Sqrt(X)
//----------------------------------
class Solution {
public:
    int mySqrt(int x) {
        return helper(x, 0, x);
    }

    int helper(int x, int L, int R){
        long long root = (L + R)/2;
        if(L > R)
            return R;
        if(root * root == x)
            return root;
        if(root * root > x){
            return helper(x, L, root-1);
        }
        else {
            return helper(x, root+1, R);
        }
    }
};

//----------------------------------
//No.70 Climbing Stairs
//----------------------------------
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int pre_1 = 1;
        int pre_2 = 2;
        int cur;
        for(int i = 3; i <= n; i++){
            cur = pre_1 + pre_2;
            pre_1 = pre_2;
            pre_2 = cur;
        }
        return cur;
    }
};

//----------------------------------
//No.71 Simplify Path
//----------------------------------
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        stack<string> stk;
        string ans = "";

        for(int i = 0; i < len; i++){
            if(path[i] == '/'){
                if(stk.empty() || (!stk.empty() && stk.top() != "/"))
                    stk.push("/");
            } else {
                int start = i;
                string tmp = "";
                while(i+1 < len && path[i+1] != '/'){
                    i++;
                }
                tmp = path.substr(start, i-start+1);
                if(tmp == ".."){
                    int count = 2;
                    while(count--){
                        if(stk.empty()){
                            stk.push("/");
                            break;
                        } else {
                            stk.pop();
                        }
                    }
                } else if(tmp == "."){
                    continue;
                } else {
                    stk.push(tmp);
                }
            }
        }
        if(stk.size() > 1 && stk.top() == "/")
            stk.pop();
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};

//----------------------------------
//No.72 Edit Distance
//----------------------------------
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 == 0)
            return len2;
        if(len2 == 0)
            return len1;
        vector<vector<int> > dp(len2+1, vector<int>(len1+1, 0));
        for(int i = 0; i <= len2; i++)
            dp[i][0] = i;
        for(int j = 0; j <= len1; j++)
            dp[0][j] = j;
        for(int i = 1; i <= len2; i++){
            for(int j = 1; j <= len1; j++){
                if(word1[j-1] != word2[i-1]){
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                } else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[len2][len1];
    }
};

//----------------------------------
//No.73 Set Matrix Zeros
//----------------------------------
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(row[i] == true){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(col[j] == true){
                for(int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        return ;
    }
};

//----------------------------------
//No.74 Search a 2D Matrix
//----------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int mStart = 0;
        int mEnd = m-1;
        int mMiddle = (mStart + mEnd) / 2;
        while(mStart <= mEnd){
            if(matrix[mMiddle][0] < target){
                mStart = mMiddle+1;
            } else if(matrix[mMiddle][0] > target){
                mEnd = mMiddle-1;
            } else {
                return true;
            }
            mMiddle = (mStart + mEnd) / 2;
        }

        int row;
        if(mStart>0) row = mStart-1;
        else row = mEnd+1;

        int nStart = 0;
        int nEnd = n-1;
        int nMiddle = (nStart + nEnd) / 2;
        while(nStart <= nEnd){
            if(matrix[row][nMiddle] < target){
                nStart = nMiddle+1;
            } else if(matrix[row][nMiddle] > target){
                nEnd = nMiddle-1;
            } else {
                return true;
            }
            nMiddle = (nStart + nEnd) / 2;
        }
        if(matrix[row][nStart] == target)
            return true;
        else
            return false;
    }
};

//----------------------------------
//No.75 Sort Color
//----------------------------------
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int red = 0;
        int blue = len-1;
        for(int i = 0; i <= blue;){
            switch(nums[i]){
                case 0:
                    swap(nums[red], nums[i]);
                    red++;
                    i++;
                    break;
                case 1:
                    i++;
                    continue;
                    break;
                case 2:
                    swap(nums[blue], nums[i]);
                    blue--;
                    break;
            }
        }
    }
};

//----------------------------------
//No.76 Minimum Window Substring
//----------------------------------
class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        int nS = s.length();
        int nT = t.length();
        if(nS == 0 || nT == 0)
            return ans;

        ans = s+"#";

        unordered_map<char, int> hash;
        unordered_map<char, int> count;
        for(int i = 0; i < nT; i++){
            hash[t[i]]++;
            count[t[i]] = 0;
        }

        vector<int> index;
        for(int i = 0; i < nS; i++){
            if(hash.find(s[i]) != hash.end()){
                index.push_back(i);
            }
        }

        int n = index.size();
        int L = 0, R = 0;
        int tip = 0;
        bool changeR = true;
        while(R < n && L <= R){
            if(changeR){
                if(count[ s[index[R]] ] < hash[ s[index[R]] ]){
                    count[ s[index[R]] ]++;
                    if(count[ s[index[R]] ] >= hash[ s[index[R]] ])
                        tip++;
                } else {
                    count[ s[index[R]] ]++;
                }
            }

            if(tip == hash.size()){
                string tmp = s.substr(index[L], index[R]-index[L]+1);
                ans = ans.length() < tmp.length() ? ans : tmp;
                L++;
                changeR = false;
                if(count[ s[index[L-1]] ] >= hash[ s[index[L-1]] ]){
                    count[ s[index[L-1]] ]--;
                    if(count[ s[index[L-1]] ] < hash[ s[index[L-1]] ]){
                        tip--;
                    }
                } else {
                    count[ s[index[L-1]] ]--;
                }
            } else {
                R++;
                changeR = true;
            }
        }
        return ans.length() > nS ? "" : ans;
    }
};

//----------------------------------
//No.77 Combinations
//----------------------------------
class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur(k, 0);
        helper(cur, 0, n, k);
        return ans;
    }
    void helper(vector<int> cur, int pos, int n, int k){
        if(pos == k){
            ans.push_back(cur);
            return ;
        }
        for(int i = 0; i < n; i++){
            cur[pos] = i+1;
            if(judge(cur, pos)){
                helper(cur, pos+1, n, k);
            }
        }
        return ;
    }
    bool judge(vector<int> target, int pos){
        if(pos == 0)
            return true;
        else {
            for(int i = 0; i < pos; i++){
                if(target[i] >= target[pos])
                    return false;
            }
        }
        return true;
    }
};
//----------------------------------
//No.78 Subsets
//----------------------------------
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int n = 0; n <= len; n++){
            vector<int> tmp(n, 0);
            helper(nums, tmp, 0, n);
        }
        return ans;
    }

    void helper(vector<int> nums, vector<int> tmp, int pos, int count){
        if(pos == count){
            ans.push_back(tmp);
            return ;
        }
        for(int i = pos; i < nums.size(); i++){
            tmp[pos] = nums[i];
            if(pos == 0 || tmp[pos-1] < tmp[pos]){
                helper(nums, tmp, pos+1, count);
            }
        }
    }
};

//----------------------------------
//No.79 Word Search
//----------------------------------
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool> > visit(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(helper(visit, i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }

    bool helper(vector<vector<bool>>& visit, int i, int j, int pos, vector<vector<char>>& board, string& word){
        if(pos == word.length())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visit[i][j] || board[i][j] != word[pos])
            return false;

        visit[i][j] = true;
        if(helper(visit, i-1, j, pos+1, board, word)
            || helper(visit, i+1, j, pos+1, board, word)
            || helper(visit, i, j-1, pos+1, board, word)
            || helper(visit, i, j+1, pos+1, board, word)){
                visit[i][j] = false;
                return true;
            }
        visit[i][j] = false;
        return false;
    }
};

//----------------------------------
//No.80 Remove Duplicates from Sorted Array II
//----------------------------------
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return len;
        int left = 1;
        int i = 2;
        for(; i < len; i++){
            if(nums[i] != nums[left-1]) {
                nums[left+1] = nums[i];
                left++;
            }
        }
        return left+1;
    }
};

//----------------------------------
//No.81 Search in Rotated Sorted Array II
//----------------------------------
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(l <= r){
            m = (l+r)/2;
            if(nums[m] == target)
                return true;
            if(nums[l] < nums[m]){
                if(nums[l] <= target && target < nums[m]){
                    r = m-1;
                } else {
                    l = m+1;
                }
            } else if(nums[l] > nums[m]){
                if(nums[m] < target && target <= nums[r]){
                    l = m+1;
                } else {
                    r = m-1;
                }
            } else {
                l++;
            }

        }
        return false;
    }
    /*solution 1*/
    bool search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size()-1, target);
    }
    bool helper(vector<int>& nums, int L, int R, int target){
        if(L <= R){
            int mid = (L+R)/2;
            if(nums[mid] == target)
                return true;
            bool left = helper(nums, L, mid-1, target);
            bool right = helper(nums, mid+1, R, target);
            if(left || right)
                return true;
            else
                return false;
        } else {
            return false;
        }
    }
};

//----------------------------------
//No.82 Remove Duplicates from Sorted List II
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        bool duplicate = false;
        ListNode* begin = new ListNode(0);
        begin->next = head;
        ListNode* pre = begin;
        ListNode* cur = head;

        while(cur){
            if(cur->next && cur->next->val == cur->val){
                duplicate = true;
                cur->next = cur->next->next;
            } else if(duplicate){
                pre->next = cur->next;
                cur = pre->next;
                duplicate = false;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return begin->next;
    }
};

//----------------------------------
//No.83 Remove Duplicates from Sorted Array
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* res = head;
        ListNode* left = head;
        ListNode* right = head->next;
        while(right != NULL){
            if(right->val == left->val){
                left->next = right->next;
                right = right->next;
            } else {
                left = left->next;
                right = right->next;
            }
        }
        return res;
    }
};

//----------------------------------
//No.84 Largest Rectangle in Histogram
//----------------------------------
class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int len = heights.size();
        if(len == 0)
            return 0;
        stack<int> stk; //store index
        int maxArea = 0;
        for(int i = 0; i < len; i++){
            while(!stk.empty() && heights[i] <= heights[stk.top()]){
                int index = stk.top();
                stk.pop();
                int curArea = stk.empty() ? i*heights[index] : heights[index]*(i-stk.top()-1);
                maxArea = maxArea > curArea ? maxArea : curArea;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int index = stk.top();
            stk.pop();
            int curArea = stk.empty() ? len*heights[index] : (len-stk.top()-1)*heights[index];
            maxArea = maxArea > curArea ? maxArea : curArea;
        }
        return maxArea;
    }

/* Time limit error
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0)
            return 0;

        int maxArea = 0;
        int L, R;
        for(int i = 0; i < len; i++){
            L = R = i;
            while(L >= 0 && heights[L] >= heights[i]){
                L--;
            }
            while(R < len && heights[R] >= heights[i]){
                R++;
            }
            int tmpArea = heights[i] * (R-L-1);
            maxArea = tmpArea > maxArea ? tmpArea : maxArea;
        }
        return maxArea;
    }
    */
};

//----------------------------------
//No.85 Maximal Rectangle
//----------------------------------
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        vector<int> histogram(matrix[0].size(), 0);
        int maximal = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '1'){
                    histogram[j] += 1;
                } else {
                    histogram[j] = 0;
                }
            }
            int tmp = helper(histogram);
            maximal = maximal < tmp ? tmp : maximal;
        }
        return maximal;
    }

    int helper(vector<int> histogram){
        int len = histogram.size();
        if(len == 0)
            return 0;
        stack<int> stk;
        int maxArea = 0;
        for(int i = 0; i < len; i++){
            while(!stk.empty() && histogram[i] < histogram[stk.top()]){
                int index = stk.top();
                stk.pop();
                int curArea = stk.empty() ? i*histogram[index] : (i-stk.top()-1)*histogram[index];
                maxArea = curArea > maxArea ? curArea : maxArea;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int index = stk.top();
            stk.pop();
            int curArea = stk.empty() ? len*histogram[index] : (len-stk.top()-1)*histogram[index];
            maxArea = curArea > maxArea ? curArea : maxArea;
        }
        return maxArea;
    }
};

//----------------------------------
//No.86 Partition List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* Low = new ListNode(0);
        ListNode* High = new ListNode(0);
        ListNode* ptr = head;
        ListNode* ptr1 = Low;
        ListNode* ptr2 = High;
        while(ptr){
            if(ptr->val < x){
                ptr1->next = ptr;
                ptr1 = ptr1->next;
            } else {
                ptr2->next = ptr;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        ptr2->next = NULL;
        ptr1->next = High->next;
        return  Low->next;
    }
};

//----------------------------------
//No.87 Scramble String
//----------------------------------
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 == 0 || len2 == 0)
            return false;
        if(len1 != len2)
            return false;
        if(len1 == 1 && len2 == 1)
            return s1 == s2;
        string stmp1 = s1;
        string stmp2 = s2;
        sort(stmp1.begin(), stmp1.end());
        sort(stmp2.begin(), stmp2.end());
        if(stmp1 != stmp2)
            return false;

        bool res = false;
        for(int i = 1; i < len1; i++){
            string s1L, s1R, s2L, s2R;
            s1L = s1.substr(0, i);
            s1R = s1.substr(i, len1-i);
            s2L = s2.substr(0, i);
            s2R = s2.substr(i, len2-i);
            res = isScramble(s1L, s2L) && isScramble(s1R, s2R);
            if(!res){
                s2L = s2.substr(0, len2-i);
                s2R = s2.substr(len2-i, i);
                res = isScramble(s1L, s2R) && isScramble(s1R, s2L);
            }
            if(res)
                return res;
        }
        return res;
    }
};

//----------------------------------
//No.88 Merge Sorted Array
//----------------------------------
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int x = m-1;
        int y = n-1;
        for(int i = m+n-1; i >=0; i--){
            if(x != -1 && (n == 0 || y == -1 || nums1[x] >= nums2[y])){
                nums1[i] = nums1[x];
                x--;
            } else {
                nums1[i] = nums2[y];
                y--;
            }
        }
        return ;
    }
};

//----------------------------------
//No.89 Gray Code
//----------------------------------
class Solution {
public:
    vector<int> grayCode(int n) {
        int len = pow(2, n);
        vector<int> ans(len, 0);
        for(int i = 0; i < n; i++){
            int count = pow(2, i);
            int x, y;
            for(x = count, y = count-1; y >= 0; y--, x++){
                ans[x] = ans[y] | (1 << i);
            }
        }
        return ans;

    }
};

//----------------------------------
//No.90 Subsets II
//----------------------------------
class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        for(int i = 0; i <= nums.size(); i++){
            tmp.resize(i, 0);
            helper(nums, tmp, 0, 0);
        }
        return ans;
    }
    void helper(vector<int> nums, vector<int> tmp, int pos, int index){
        if(pos == tmp.size()){
            ans.push_back(tmp);
            return ;
        }
        int pre;
        for(int i = index; i < nums.size()-(tmp.size()-pos-1); i++){
            if(nums[i] != pre){
                tmp[pos] = nums[i];
                pre = nums[i];
                helper(nums, tmp, pos+1, i+1);
            }
        }
        return ;
    }
};

//----------------------------------
//No.91 Decode ways
//----------------------------------
class Solution {

public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0 || s[0] == '0')
            return 0;
        vector<int> opt(len+1, 1);

        for(int i = 1; i < s.length(); i++){
            if(opt[i] == 0){
                opt[i+1] = 0;
            } else {
                if(judge(s, i, i+1)){
                    opt[i+1] = opt[i];
                } else {
                    opt[i+1] = 0;
                }
                if(judge(s, i-1, i+1)){
                    opt[i+1] += opt[i-1];
                }
            }
        }
        return opt[len];
    }

    bool judge(string s, int start, int end){
        if(end > s.length() || s[start] == '0')
            return false;
        int num = stoi(s.substr(start, end-start));
        if(num >= 1 && num <= 26)
            return true;
        else
            return false;
    }
};

//----------------------------------
//No.92 Reverse Linked List II
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* start;
        ListNode* end;
        ListNode* L;
        ListNode* R;
        ListNode* ptr = ans;
        int i = 0;
        for(int i = 0; i <= n; i++){
            if(i == m-1)
                start = ptr;
            if(i == m)
                L = ptr;
            if(i == n)
                R = ptr;
            ptr=ptr->next;
        }
        end = ptr;

        ListNode* END = end;
        while(L != END){
            ptr = L->next;
            L->next = end;
            end = L;
            L = ptr;
        }
        start->next = R;
        return ans->next;
    }
};

//----------------------------------
//No.93 Restore IP Address
//----------------------------------
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length() > 12)
            return ans;
        string subAns = "";
        helper(s, 0, 0, ans, subAns);
        return ans;
    }
    void helper(string &s, int n, int pos, vector<string> &ans, string &subAns){
        if(n == 3){
            string end = s.substr(pos);
            if(end == "" || stoi(end) > 255)
                return ;
            else {
                if(end.length() > 1 && s[pos] == '0')
                    return ;
                ans.push_back(subAns+end);
                return ;
            }
        }
        string pre = subAns;
        for(int i = pos+1; i < s.length(); i++){
            string cur = s.substr(pos, i-pos);
            if(cur == "") continue;
            else {
                if(stoi(cur) > 255)
                    return ;
                else {
                    subAns += cur;
                    subAns += ".";
                    helper(s, n+1, i, ans, subAns);
                    subAns = pre;
                    if(s[pos] == '0')
                        return ;
                }
            }
        }
    }
};

//----------------------------------
//No.94 Binary Tree Inorder Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
private:
    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL) return ;

        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
};

//----------------------------------
//No.95 Unique Binary Search Trees II
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0)
            return ans;
        vector<int> nums;
        for(int i = 0; i < n; i++){
            nums.push_back(i+1);
        }
        ans = helper(nums, 0, n-1);
        return ans;
    }
    vector<TreeNode*> helper(vector<int> nums, int L, int R){
        vector<TreeNode*> res;
        if(L > R){
            res.push_back(NULL);
            return res;
        }
        for(int i = L; i <= R; i++){
            vector<TreeNode*> leftList  = helper(nums, L, i-1);
            vector<TreeNode*> rightList = helper(nums, i+1, R);
            for(int j = 0; j < leftList.size(); j++){
                for(int k = 0; k < rightList.size(); k++){
                    TreeNode* root = new TreeNode(nums[i]);
                    root->left = leftList[j];
                    root->right = rightList[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

//----------------------------------
//No.96 Unique Binary Search Trees
//----------------------------------
class Solution {
public:
    int numTrees(int n) {
        if( n == 0 ) return 0;
        vector<int> opt(n+1, 0);
        opt[0] = 1;
        opt[1] = 1;
        opt[2] = 2;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= n; j++){
                opt[i] += opt[j-1] * opt[i-j];
            }
        }
        return opt[n];
    }
};

//----------------------------------
//No.97 Interleaving String
//----------------------------------
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3){
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3)
            return false;
        if(len1 == 0)
            return s2 == s3;
        if(len2 == 0)
            return s1 == s3;

        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len1; i++){
            if(s1[i-1] == s3[i-1])
                dp[i][0] = true;
            else
                break;
        }
        for(int i = 1; i <= len2; i++){
            if(s2[i-1] == s3[i-1])
                dp[0][i] = true;
            else
                break;
        }

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i-1] == s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;
                if(s2[j-1] == s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
            }
        }
        return dp[len1][len2];
    }

/*
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3)
            return false;

        return helper(s1, s2, s3, 0, 0, 0);
    }
    bool helper(string s1, string s2, string s3, int ptr1, int ptr2, int ptr3){
        if(ptr3 == s3.length())
            return true;
        if(ptr1 == s1.length())
            return s2.substr(ptr2, s2.length()-ptr2) == s3.substr(ptr3, s3.length()-ptr3);
        if(ptr2 == s2.length())
            return s1.substr(ptr1, s1.length()-ptr1) == s3.substr(ptr3, s3.length()-ptr3);

        if(s1[ptr1] == s3[ptr3] && s2[ptr2] == s3[ptr3])
            return helper(s1, s2, s3, ptr1+1, ptr2, ptr3+1) || helper(s1, s2, s3, ptr1, ptr2+1, ptr3+1);
        else if(s1[ptr1] == s3[ptr3])
            return helper(s1, s2, s3, ptr1+1, ptr2, ptr3+1);
        else if(s2[ptr2] == s3[ptr3])
            return helper(s1, s2, s3, ptr1, ptr2+1, ptr3+1);
        else
            return false;

            /*
            /*
        if(ptr1 < s1.length() && s1[ptr1] == s3[ptr3] && helper(s1, s2, s3, ptr1+1, ptr2, ptr3+1)){
            return true;
        } else if(ptr2 < s2.length() && s2[ptr2] == s3[ptr3] && helper(s1, s2, s3, ptr1, ptr2+1, ptr3+1)){
            return true;
        } else
            return false;
            */
    //}
};

//----------------------------------
//No.98 Validate Binary Search Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long leftVal, long rightVal){
        if(root == NULL) return true;

        return leftVal < root->val && root->val < rightVal && check(root->left, leftVal, root->val)
            && check(root->right, root->val, rightVal);
    }
};

//----------------------------------
//No.99 Recover Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> sortedNum;
public:
    void recoverTree(TreeNode* root) {
        int reverseCount = 0;
        if(root == NULL)
            return ;
        helper(root);

        int start, end;
        int len = sortedNum.size();
        for(int i = 1; i < len; i++){
            if(sortedNum[i] < sortedNum[i-1]){
                reverseCount++;
                if(reverseCount == 1){
                    start = i-1;
                    end = i;
                } else {
                    end = i;
                }
            }
        }
        int count = 0;
        recover(root, start, end, count, sortedNum[start], sortedNum[end]);
    }

    void helper(TreeNode* root){
        if(root == NULL)
            return ;
        helper(root->left);
        sortedNum.push_back(root->val);
        helper(root->right);
    }

    void recover(TreeNode* root, int start, int end, int &count, int startNum, int endNum){
        if(root == NULL)
            return ;
        recover(root->left, start, end, count, startNum, endNum);
        if(count == start){
            root->val = endNum;
        }
        if(count == end){
            root->val = startNum;
        }
        count++;
        recover(root->right, start, end, count, startNum, endNum);
    }
};

//----------------------------------
//No.100 Same Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else {
            if(p == NULL || q == NULL) return false;
            else
                return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

//----------------------------------
//No.101 Symmetric Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left, root->right);
    }
    bool isSym(TreeNode* lt, TreeNode* rt){
        if(lt == NULL && rt == NULL) return true;
        if(lt == NULL || rt == NULL) return false;
        else {
            return (rt->val == lt->val) && isSym(lt->left, rt->right) && isSym(lt->right, rt->left);
        }
    }
};

//----------------------------------
//No.102 Binary Tree Level Order Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int numL = 1;
        int numR = 0;
        vector<int> tmp;
        while(!q.empty()){
            TreeNode* ptr;
            if(numL != 0){
                ptr = q.front();
                if(ptr->left != NULL){
                    q.push(ptr->left);;
                    numR++;
                }
                if(ptr->right != NULL){
                    q.push(ptr->right);
                    numR++;
                }
                tmp.push_back(ptr->val);
                q.pop();
                numL--;
            }
            if(numL == 0){
                numL = numR;
                numR = 0;
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};

//----------------------------------
//No.103 Binary Tree Zigzag Level Order Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> Q;
        stack<int> S;
        int L = 1;
        int Lcount, Rcount;
        Q.push(root);
        Lcount = 1;
        Rcount = 0;
        vector<int> LtoR;
        while(!Q.empty()){
            TreeNode* ptr = Q.front();
            if(ptr->left){
                Q.push(ptr->left);
                Rcount++;
            }
            if(ptr->right){
                Q.push(ptr->right);
                Rcount++;
            }

            if(L==0){
                S.push(ptr->val);
            } else {
                LtoR.push_back(ptr->val);
            }
            Q.pop();
            Lcount--;
            if(Lcount == 0){
                //deal
                if(L == 0){
                    vector<int> RtoL;
                    while(!S.empty()){
                        RtoL.push_back(S.top());
                        S.pop();
                    }
                    ans.push_back(RtoL);
                } else {
                    ans.push_back(LtoR);
                    LtoR.clear();
                }
                Lcount = Rcount;
                Rcount = 0;
                L ^= 1;
            }
        }
        return ans;
    }
};

//----------------------------------
//No.104 Maximum Depth of Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int len1 = maxDepth(root->left)+1;
        int len2 = maxDepth(root->right)+1;

        return len1 > len2 ? len1 : len2;
    }
};

//----------------------------------
//No.105 Construct Binary Tree from Preorder and Inorder Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, int s0, int e0, vector<int>& inorder, int s1, int e1){
        if(s1 > e1)
            return NULL;

        int target = preorder[s0];
        int pos;
        for(int i = s1; i <= e1; i++){
            if(inorder[i] == target){
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(target);
        root->left  = helper(preorder, s0+1, s0+pos-s1, inorder, s1, pos-1);
        root->right = helper(preorder, s0+pos-s1+1, e0, inorder, pos+1, e1);
        return root;
    }
};

//----------------------------------
//No.106 Construct Binary Tree from Inorder and Postorder Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1){
        if(s0 > e0 )
            return NULL;
        int target = postorder[e1];
        int pos;
        for(int i = s0; i <= e0; i++){
            if(inorder[i] == target){
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(target);
        root->left  = helper(inorder, s0, pos-1, postorder, s1, s1+(pos-s0-1));
        root->right = helper(inorder, pos+1, e0, postorder, s1+(pos-s0), e1-1);
        return root;
    }
};

//----------------------------------
//No.107 Binary Tree Level Order Tranversal II
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int lenR = 0;
        int lenL = 1;
        while(!q.empty()){
            vector<int> tmp;
            for(int i = 0; i < lenL; i++){
                TreeNode* ptr = q.front();
                if(ptr->left != NULL){
                    q.push(ptr->left);
                    lenR++;
                }
                if(ptr->right != NULL){
                    q.push(ptr->right);
                    lenR++;
                }
                tmp.push_back(ptr->val);
                q.pop();
            }
            lenL = lenR;
            lenR = 0;
            ans.push_back(tmp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//----------------------------------
//No.108 Convert Sorted Array to Binary Search Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return addNode(nums, 0, nums.size()-1);
    }
private:
    TreeNode* addNode(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int middle = (start+end)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = addNode(nums, start, middle-1);
        root->right = addNode(nums, middle+1, end);
        return root;
    }
};

//----------------------------------
//No.109 Convert Sorted List to Binary Search Tree
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    ListNode* nodePtr;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<int> value;
        ListNode* ptr = head;
        int count = 0;

        while(ptr){
             ptr = ptr->next;
             count++;
        }
        nodePtr = head;
        return helper(0, count-1);
    }
    TreeNode* helper(int L, int R){
        if(L > R)
            return NULL;
        int M = (L + R) / 2;
        TreeNode* left = helper(L, M-1);
        TreeNode* res = new TreeNode(nodePtr->val);
        nodePtr = nodePtr->next;
        res->left = left;
        res->right = helper(M+1, R);
        return res;
    }
};

//----------------------------------
//No.110 Balanced Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int depL = 0;
        int depR = 0;
        depL = depth(root->left);
        depR = depth(root->right);
        if(abs(depL - depR) > 1) return false;
        else isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root){
        if(root == NULL) return 0;

        int depL = 0;
        int depR = 0;
            depL = depth(root->left);
            depR = depth(root->right);
        return depL > depR ? depL+1 : depR+1;
    }
};

//----------------------------------
//No.111 Minimum Depth of Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*solution 2*/
    int minDepth(TreeNode* root) {
        return helper(root, false);
    }
    int helper(TreeNode* root, bool hasBro) {
        if(!root) return hasBro ? INT_MAX : 0;
        return 1 + min(helper(root->left, root->right != NULL), helper(root->right, root->left != NULL));
    }

    /*solution 1*/
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int lenR = 0;
        int lenL = 1;
        int min = 1;
        while(!q.empty()){
            for(int i = 0; i < lenL; i++){
                TreeNode* ptr = q.front();
                if(ptr->left == NULL && ptr->right == NULL) return min;
                if(ptr->left != NULL){
                    q.push(ptr->left);
                    lenR++;
                }
                if(ptr->right != NULL){
                    q.push(ptr->right);
                    lenR++;
                }
                q.pop();
            }
            min++;
            lenL = lenR;
            lenR = 0;
        }
    }
};

//----------------------------------
//No.112 Path Sum
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool ans = false;
    int Sum;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        Sum = sum;
        SUM(root, 0);
        return ans;
    }
private:
    void SUM(TreeNode* root, int value){
        if(root->left == NULL && root->right == NULL){
            if(value+root->val == Sum)
                ans = true;
            return ;
        }
        if(root->left != NULL)
            SUM(root->left, value+root->val);
        if(root->right != NULL)
            SUM(root->right, value+root->val);
    }
};

//----------------------------------
//No.113 Path Sum II
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        ans = helper(root, 0, sum);

    }
    vector<vector<int>> helper(TreeNode* root, int cursum, int sum){
        vector<vector<int>> res;
        if(root->left == NULL && root->right == NULL){
            if((cursum + root->val) == sum){
                vector<int> tmp;
                tmp.push_back(root->val);
                res.push_back(tmp);
            }
            if((cursum + root->val) > sum)
                return res;
            return res;
        }
        vector<vector<int>> Left;
        vector<vector<int>> Right;
        if(root->left)
            Left  = helper(root->left,  cursum+root->val, sum);
        if(root->right)
            Right = helper(root->right, cursum+root->val, sum);
        for(int i = 0; i < Left.size(); i++){
            vector<int> tmp = Left[i];
            tmp.insert(tmp.begin(), 1, root->val);
            res.push_back(tmp);
        }
        for(int i = 0; i < Right.size(); i++){
            vector<int> tmp = Right[i];
            tmp.insert(tmp.begin(), 1, root->val);
            res.push_back(tmp);
        }
        return res;
    }
};

//----------------------------------
//No.114 Flatten Binary Tree to Linked List
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<TreeNode*> nodes;
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        helper(root);

        TreeNode* ptr;
        for(int i = 0; i < nodes.size(); i++){
            nodes[i]->left = NULL;
            nodes[i]->right = i+1 < nodes.size() ? nodes[i+1] : NULL;
        }
        root = nodes[0];
        return ;
    }
    void helper(TreeNode* root){
        if(root == NULL){
            return ;
        }
        nodes.push_back(root);
        helper(root->left);
        helper(root->right);

        return ;
    }
};

//----------------------------------
//No.115 Distinct Subsequences
//----------------------------------
class Solution {
public:
    int numDistinct(string s, string t){
        int lenS = s.length();
        int lenT = t.length();
        if(lenS == 0)
            return 0;
        else if(lenT == 0)
            return 1;
        vector<vector<int> > dp(lenS+1, vector<int>(lenT+1, 0));
        for(int i = 0; i <= lenS; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= lenS; i++){
            for(int j = 1; j <= lenT; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[lenS][lenT];
    }

/*
    int numDistinct(string s, string t) {
        helper(s, t, 0, 0);
        return count;
    }
    void helper(string &s, string &t, int posS, int posT){
        if(posT == t.length()){
            count++;
            return ;
        }
        for(int i = posS; i < s.length(); i++){
            if(s[i] == t[posT]){
                helper(s, t, i+1, posT+1);
            }
        }
    }
*/
};

//----------------------------------
//No.116 Populating Next Right Pointers in Each Node
//----------------------------------
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return ;
        TreeLinkNode* ptr = root;
        TreeLinkNode* first = root->left;
        while(ptr){
            if(first == NULL) return ;

            if(ptr->left){
                ptr->left->next = ptr->right;
            } else {
                break;
            }

            if(ptr->next){
                if(ptr->right)
                    ptr->right->next = ptr->next->left;
                else
                    ptr->right->next = NULL;

                ptr = ptr->next;
                continue;
            } else {
                ptr = first;
                first = ptr->left;
            }
        }
    }
};

//----------------------------------
//No.117 Populating Next Right Pointers in Each Node II
//----------------------------------
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return ;
        TreeLinkNode head(-1);
        for(TreeLinkNode* cur = root, *prev = &head; cur != NULL; cur = cur->next){
            if(cur->left != NULL){
                prev->next = cur->left;
                prev = prev->next;
            }
            if(cur->right != NULL){
                prev->next = cur->right;
                prev = prev->next;
            }
        }
        connect(head.next);
    }
};

//----------------------------------
//No.119 Pascal's Triangle II
//----------------------------------
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > ans;

        for(int i = 0; i <= rowIndex; i++){
            vector<int> tmp(rowIndex+1, 1);
            for(int j = 1; j < i; j++){
                tmp[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(tmp);
        }
        return ans[rowIndex];
    }
};

//----------------------------------
//No.120 Triangle
//----------------------------------
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<int> opt(col, INT_MAX);
        opt[0] = triangle[0][0];

        for(int i = 1; i < row; i++){
            vector<int> tmp(col, INT_MAX);
            for(int j = 0; j < col; j++){
                int L = j-1>=0 ? opt[j-1] : INT_MAX;
                int M = j<=i-1 ? opt[j] : INT_MAX;
                //int R = j+1<=i-1 ? opt[j+1] : INT_MAX;
                tmp[j] = min(L, M) + triangle[i][j];
            }
            opt = tmp;
        }
        int MIN = INT_MAX;
        for(int i = 0; i < col; i++){
            if(MIN > opt[i])
                MIN = opt[i];
        }
        return MIN;
    }
};

//----------------------------------
//No.121 Best Time to Buy and Sell Stock
//----------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return NULL;
        int len = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < len; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

//----------------------------------
//No.122 Best Time to Buy and Sell Stock II
//----------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return NULL;
        int len = prices.size();
        int buy = prices[0];
        int sell = prices[0];
        int profit = 0;
        for(int i = 1; i < len; i++){
            if(buy < prices[i]){
                sell = prices[i];
            } else {
                buy = prices[i];
                sell = prices[i];
            }
            if(sell < prices[i]){
                sell = prices[i];
            } else {
                profit += (sell - buy);
                buy = prices[i];
                sell = prices[i];
            }
        }
        return profit;
    }
};

//----------------------------------
//No.123 Best Time to Buy and Sell Stock III
//----------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        int n = prices.size();
        vector<int> opt(n, 0);
        opt[0] = 0;
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
            opt[i] = maxProfit;
        }

        int maxPrice = prices[n-1];
        maxProfit = 0;
        int ans = opt[n-1];
        for(int i = n-2; i >= 0; i--){
            maxPrice = max(maxPrice, prices[i]);
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            opt[i] += maxProfit;
            if(ans < opt[i])
                ans = opt[i];
        }
        return ans;
    }
};

//----------------------------------
//No.124 Binary Tree Maximum Path Sum
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int maxPath = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        int tmp = helper(root);
        return maxPath;
    }
    int helper(TreeNode* root){
        if(root == NULL)
            return 0;
        int L = helper(root->left);
        int R = helper(root->right);
        int M = root->val;
        int tmp = 0;
        tmp = L >= 0 ? tmp+L : tmp;
        tmp = R >= 0 ? tmp+R : tmp;
        tmp += M;
        maxPath = maxPath > tmp ? maxPath : tmp;
        if(max(L, R) >= 0){
            return M + max(L, R);
        } else {
            return M;
        }
    }
};

//----------------------------------
//No.125 Valid Palindrome
//----------------------------------
class Solution {
public:
    bool isPalindrome(string s) {
        int left,right;
        left = 0;
        right = s.size() - 1;
        while(left < right){
            while(left < s.size() && !isalnum(s[left])) left++;
            while(right >= 0 && !isalnum(s[right])) right--;
            if(left > right) return true;
            if(tolower(s[left]) == tolower(s[right])){
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
}

//----------------------------------
//No.127 Word Ladder
//----------------------------------
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> Q;
        Q.push(beginWord);
        Q.push("");
        int ans = 1;
        while(!Q.empty()){
            string str = Q.front();
            Q.pop();
            if(str != ""){

                for(int i = 0; i < beginWord.length(); i++){
                    for(int j = 0; j < 26; j++){
                        string tmp = str;
                        tmp[i] = 'a'+j;
                        if(tmp[i] == str[i])
                            continue;
                        if(tmp == endWord)
                            return ans+1;
                        if(wordList.find(tmp) != wordList.end()){
                            Q.push(tmp);
                            wordList.erase(tmp);
                        }
                    }
                }
            } else {
                if(!Q.empty()){
                    ans++;
                    Q.push("");
                }
            }
        }
        return 0;
    }
};

//----------------------------------
//No.128 Longest Consecutive Sequence
//----------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) == set.end()){
                set.insert(nums[i]);
            }
        }

        int ans = 0;
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) != set.end()){
                max = 1;
                set.erase(nums[i]);
                int valL = nums[i]-1;
                int valR = nums[i]+1;
                while(set.find(valL) != set.end()){
                    set.erase(valL);
                    max++;
                    valL--;
                }
                while(set.find(valR) != set.end()){
                    set.erase(valR);
                    max++;
                    valR++;
                }
                ans = ans > max ? ans : max;
            } else {
                continue;
            }
        }
        return ans;
    }
};

//----------------------------------
//No.129 Sum Root to Leaf Numbers
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;

        int sum = helper(root, 0);
        return sum;
    }
    int helper(TreeNode* root, int num){
        if(root->left == NULL && root->right == NULL)
            return num*10 + root->val;

        int num1 = 0;
        int num2 = 0;
        if(root->left != NULL){
            num1 = helper(root->left, root->val+num*10);
        }
        if(root->right != NULL){
            num2 = helper(root->right, root->val+num*10);
        }
        return num1+num2;
    }
};

//----------------------------------
//No.130 Surrounded Regions
//----------------------------------
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row < 2)
            return ;
        int col = board[0].size();
        if(col < 2)
            return ;
        int i, j;
        for(i = 0, j = 0; j < col; j++){
            if(board[i][j] == 'O')
                helper(row, col, i, j, board);
        }
        for(i = row-1, j = 0; j < col; j++){
            if(board[i][j] == 'O')
                helper(row, col, i, j, board);
        }
        for(i = 0, j = 0; i < row; i++){
            if(board[i][j] == 'O')
                helper(row, col, i, j, board);
        }
        for(i = 0, j = col-1; i < row; i++){
            if(board[i][j] == 'O')
                helper(row, col, i, j, board);
        }

        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
        return ;
    }
    void helper(int row, int col, int i, int j, vector<vector<char>>& board){
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O')
            return ;
        if(board[i][j] == 'O')
            board[i][j] = '#';
        if(i > 1)
            helper(row, col, i-1, j, board);
        if(i < row-1)
            helper(row, col, i+1, j, board);
        if(j > 1)
            helper(row, col, i, j-1, board);
        if(j < col-1)
            helper(row, col, i, j+1, board);
        return ;
    }
};

//----------------------------------
//No.131 Palindrome Partitioning
//----------------------------------
class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> subAns;
        helper(0, s, s.length(), subAns);
        return ans;
    }
    void helper(int startPos, string s, int n, vector<string>& subAns){
        if(startPos == n){
            ans.push_back(subAns);
            return ;
        }

        for(int i = startPos+1; i <= n; i++){
            string tmp = s.substr(startPos, i-startPos);
            if(judge(tmp)){
                subAns.push_back(tmp);
                helper(i, s, n, subAns);
                subAns.pop_back();
            }
        }
    }

    bool judge(string s){
        int n = s.length();
        int L, R;
        if(n%2 == 0){
            L = n/2-1;
            R = n/2;
        } else {
            L = n/2;
            R = n/2;
        }
        while(L >= 0 && R < n){
            if(s[L] == s[R]){
                L--;
                R++;
            } else {
                return false;
            }
        }
        return true;
    }
};

//----------------------------------
//No.132 Palindrome Partitioning II
//----------------------------------
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        vector<vector<bool> > P(len, vector<bool>(len, false));
        vector<int> D(len+1, 0);
        for(int i = 0; i < len+1; i++)
            D[i] = len - i;

        for(int i = len-2; i >= 0; i--){
            for(int j = i; j < len; j++){
                if(s[i] == s[j] && (j-i < 2 || P[i+1][j-1])){
                    P[i][j] = true;
                    D[i] = min(D[i], D[j+1]+1);
                }
            }

        }
        return D[0]-1;
    }
};

//----------------------------------
//No.133 Clone Graph
//----------------------------------
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashmap;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        hashmap[node] = nodeCopy;

        while(!q.empty()){
            UndirectedGraphNode* curNode = q.front();
            q.pop();
            for(int i = 0; i < curNode->neighbors.size(); i++ ){
                UndirectedGraphNode* subneighbor = curNode->neighbors[i];
                if(hashmap.find(subneighbor) == hashmap.end()){
                    UndirectedGraphNode* subCopy = new UndirectedGraphNode(subneighbor->label);
                    hashmap[subneighbor] = subCopy;     //add to hashmap
                    q.push(curNode->neighbors[i]);
                    hashmap[curNode]->neighbors.push_back(subCopy);
                } else {
                    hashmap[curNode]->neighbors.push_back(hashmap[subneighbor]);
                }
            }
        }
        return nodeCopy;
    }
};

//----------------------------------
//No.134 Gas Station
//----------------------------------
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int index = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                index = i + 1;
            }
            total += gas[i] - cost[i];
        }
        if(total < 0)
            return -1;
        return index;
    }
};

//----------------------------------
//No.135 Candy
//----------------------------------
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 0)
            return 0;

        vector<int> dp1(len, 0);
        dp1[0] = 1;
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i-1])
                dp1[i] = dp1[i-1] + 1;
            else
                dp1[i] = 1;
        }
        vector<int> dp2(len, 0);
        dp2[len-1] = 1;
        for(int i = len-2; i >=0; i--){
            if(ratings[i] > ratings[i+1])
                dp2[i] = dp2[i+1] + 1;
            else
                dp2[i] = 1;
        }
        int res = 0;
        for(int i = 0; i < len; i++){
            res += max(dp1[i], dp2[i]);
        }
        return res;
    }
};

//----------------------------------
//No.138 Copy List with Random Pointer
//----------------------------------
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;

        vector<RandomListNode*> init;
        RandomListNode* res = NULL;
        RandomListNode* ptr = head;

        while(ptr != NULL){
            init.push_back(ptr);
            ptr = ptr->next;
        }

        int len = init.size();
        for(int i = 0; i < len; i++){
            init[i]->next = new RandomListNode(init[i]->label);
            init[i]->next->random = init[i];
        }
        for(int i = 0; i < len; i++){
            init[i]->next->random = init[i]->next->random->random == NULL ? NULL : init[i]->next->random->random->next;
        }

        res = init[0]->next;
        for(int i = 0; i < len-1; i++){
            init[i]->next->next = init[i+1]->next;
            init[i]->next = init[i+1];
        }
        init[len-1]->next->next = NULL;
        init[len-1]->next = NULL;

        return res;
    }
};

//----------------------------------
//No.139 Word Break
//----------------------------------
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        vector<bool> opt(len+1, false);
        opt[0] = true;
        for(int i = 0; i < len; i++){

            string tmp = s.substr(0, i+1);
            for(int j = 0; j <= i; j++){
                if(opt[j] && (wordDict.find(tmp.substr(j, i-j+1)) != wordDict.end())){
                    opt[i+1] = true;
                    break;
                }
            }
        }
        return opt[len];
    }
};

//----------------------------------
//No.140 Word Break II
//----------------------------------
class Solution {
    vector<bool> dp;
    vector<string> ans;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        if(n == 0)
            return ans;
        dp.resize(n+1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            string tmp = s.substr(0, i+1);
            for(int j = 0; j <= i; j++){
                if(dp[j] && wordDict.find(tmp.substr(j, i-j+1)) != wordDict.end()){
                    dp[i+1] = true;
                    break;
                }
            }
        }
        if(!dp[n])
            return ans;
        helper(s, wordDict, 0, "", "");
        return ans;
    }
    void helper(string s, unordered_set<string>& wordDict, int pos, string sentence, string str){
        if(pos == s.length()){
            if(str == s){
                ans.push_back(sentence.substr(0, sentence.length()-1));
            }
            return ;
        }
        if(!dp[pos])
            helper(s, wordDict, pos+1, sentence, str);

        string senTmp = sentence;
        string strTmp = str;
        for(int i = pos; i < s.length(); i++){
            if(dp[i+1] && wordDict.find(s.substr(pos, i-pos+1)) != wordDict.end()){
                sentence = sentence + s.substr(pos, i-pos+1) + ' ';
                str = str + s.substr(pos, i-pos+1);
                helper(s, wordDict, i+1, sentence, str);
                sentence = senTmp;
                str = strTmp;
            }
        }
    }

    /* time limit
    vector<string> ans;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        helper(s, wordDict, 0, "", "");
        return ans;
    }
    void helper(string s, unordered_set<string>& wordDict, int pos, string sentence, string str){
        if(pos == s.length()){
            if(str == s){
                ans.push_back(sentence.substr(0, sentence.length()-1));
            }
            return ;
        }
        string senTmp = sentence;
        string strTmp = str;
        for(int i = pos; i < s.length(); i++){
            if(wordDict.find(s.substr(pos, i-pos+1)) != wordDict.end()){
                sentence = sentence + s.substr(pos, i-pos+1) + ' ';
                str = str + s.substr(pos, i-pos+1);
                helper(s, wordDict, i+1, sentence, str);
                sentence = senTmp;
                str = strTmp;
            }
        }
    }
    */
};

//----------------------------------
//No.141 Linked List Cycle
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if( head == NULL || head->next == NULL){
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

//----------------------------------
//No.142 Linked List Cycle II
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        else {
            ListNode* ptr = head;
            while(slow != ptr){
                slow = slow->next;
                ptr = ptr->next;
            }
            return ptr;
        }
    }
};

//----------------------------------
//No.143 Reorder List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return ;
        ListNode* fast;
        ListNode* slow;
        fast = slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* L = head;
        ListNode* R = slow->next;
        slow->next = NULL;
        R = reverse(R);

        ListNode* ptrL = L;
        ListNode* ptrR = R;

        ListNode* tmpL;
        ListNode* tmpR;
        while(ptrL != NULL && ptrR != NULL){
            tmpL = ptrL->next;
            tmpR = ptrR->next;
            ptrL->next = ptrR;
            ptrR->next = tmpL;
            ptrL = tmpL;
            ptrR = tmpR;
        }
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL) return NULL;
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* ptr = head->next;
        ListNode* pre = ans->next;
        ListNode* end = pre;
        while(ptr != NULL){
            end->next = ptr->next;
            ans->next = ptr;
            ptr->next = pre;
            pre = ptr;
            ptr = end->next;
        }
        return ans->next;
    }
};

//----------------------------------
//No.144 Binary Tree Preorder Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    void helper(TreeNode* root){
        if(root == NULL) return;
        ans.push_back(root->val);
        helper(root->left);
        helper(root->right);
        return ;
    }
};

//----------------------------------
//No.145 Binary Tree Postorder Traversal
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    void helper(TreeNode* root){
        if(root == NULL) return ;
        helper(root->left);
        helper(root->right);
        ans.push_back(root->val);
        return ;
    }
};

//----------------------------------
//No.146 LRU Cache
//----------------------------------
class LRUCache{
struct cacheEntry {
    int key;
    int value;
    cacheEntry(int k, int v): key(k), value(v){}
};

private:
    int NUM;
    unordered_map<int, list<cacheEntry>::iterator> hash;
    list<cacheEntry> q;
public:
    LRUCache(int capacity) {
        NUM = capacity;
    }

    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        moveToHead(key);
        return hash[key]->value;
    }

    void set(int key, int value) {
        if(hash.find(key) == hash.end()){
            cacheEntry newItem(key, value);
            if(q.size() >= NUM){
                hash.erase(q.back().key);
                q.pop_back();
            }
            q.push_front(newItem);
            hash[key] = q.begin();
            return ;
        }
        hash[key]->value = value;
        moveToHead(key);
        return ;
    }
    void moveToHead(int key){
        cacheEntry newItem = *hash[key];
        q.erase(hash[key]);
        q.push_front(newItem);
        hash[key] = q.begin();
    }
};

//----------------------------------
//No.147 Insertion Sort List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* ans = new ListNode(0);
        ans->val = INT_MIN;
        ans->next = head;

        ListNode* pre = ans;
        ListNode* cur = head->next;
        pre->next->next = NULL;

        while(cur != NULL){
            pre = ans;
            while(pre->next != NULL){
                if(pre->next->val >= cur->val){
                    break;
                }
                pre = pre->next;
            }
            ListNode* tmp = pre->next;
            pre->next = cur;
            cur = cur->next;
            pre->next->next = tmp;
        }
        return ans->next;
    }
};

//----------------------------------
//No.148 Sort List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        ListNode* L;
        ListNode* R;
        L = sortList(head);
        R = sortList(slow);
        return merge(L, R);
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* ans;
        ListNode* ptr;
        if(head1->val <= head2->val) {
            ans = head1;
            head1 = head1->next;
        } else {
            ans = head2;
            head2 = head2->next;
        }
        ptr = ans;

        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                ptr->next = head1;
                head1 = head1->next;
            } else {
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }
        if(head1 != NULL){
            ptr->next = head1;
        }
        if(head2 != NULL){
            ptr->next = head2;
        }
        return ans;
    }
};

//----------------------------------
//No.149 Max Points on a  line
//----------------------------------
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n < 3) return n;
        int maxCount = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int sign = 0;
                int a, b, c;
                if(points[i].x == points[j].x) sign = 1;
                else{
                    a = points[i].x - points[j].x;
                    b = points[i].y - points[j].y;
                    c = a * points[i].y - b * points[i].x;
                }
                int count = 0;
                for(int k = 0; k < n; k++){
                    if((sign == 0 && c == a*points[k].y - b*points[k].x) || (sign == 1 && points[k].x == points[i].x)){
                        count++;
                    }
                }
                maxCount = maxCount < count ? count : maxCount;
            }
        }
        return maxCount;
    }
};

//----------------------------------
//No.150 Evaluate Reverse Polish Notation
//----------------------------------
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if(n == 0)
            return 0;
        stack<int> num;
        for(int i = 0; i < n; i++){
            if(isOp(tokens[i])){
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                int res = getRes(a, b, tokens[i]);
                num.push(res);
            } else {
                num.push(stoi(tokens[i]));
            }
        }
        return num.top();
    }
    bool isOp(string s){
        if(s == "+" || s == "/" || s == "*" || s == "-")
            return true;
        return false;
    }
    int getRes(int a, int b, string s){
        if(s == "+")
            return a + b;
        if(s == "/")
            return a / b;
        if(s == "*")
            return a * b;
        if(s == "-")
            return a - b;
    }
};

//----------------------------------
//No.151 Reverse Words in a String
//----------------------------------
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        if(n == 0)
            return ;

        stack<string> stk;
        string tmp = "";
        for(int i = 0; i < n; i++){
            if(s[i] != ' ')
                tmp += s[i];
            else {
                if(tmp != "")
                    stk.push(tmp);
                tmp = "";
            }

        }
        if(tmp != "")
            stk.push(tmp);
        s = "";
        while(!stk.empty()){
            s += stk.top();
            s += " ";
            stk.pop();
        }
        s = s.substr(0, s.length()-1);
    }
};

//----------------------------------
//No.152 Maximum Product Subarray
//----------------------------------
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> proMin(n);
        vector<int> proMax(n);
        proMin[0] = nums[0];
        proMax[0] = nums[0];
        int res = proMax[0];
        for(int i = 1; i < n; i++){
            proMin[i] = min(min(proMin[i-1]*nums[i], proMax[i-1]*nums[i]), nums[i]);
            proMax[i] = max(max(proMin[i-1]*nums[i], proMax[i-1]*nums[i]), nums[i]);
            res = res > proMax[i] ? res : proMax[i];
        }
        return res;
    }
};

//----------------------------------
//No.153 Find Minimum in Rotated Sorted Array
//----------------------------------
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int L = 0;
        int R = len - 1;
        int min = helper(nums, L, R);
        return min;

    }
    int helper(vector<int>& nums, int L, int R){
        if(L == R) return nums[L];

        int left = helper(nums, L, (L+R)/2);
        int right = helper(nums, (L+R)/2+1, R);
        return left < right ? left : right;
    }
};

//----------------------------------
//No.154 Find Minimum in Rotated Sorted Array II
//----------------------------------
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = helper(nums, 0, n-1);
    }
    int helper(vector<int>& nums, int start, int end){
        if(start >= end)
            return nums[start];
        int middle = (start + end) / 2;
        int tmp1 = helper(nums, start, middle);
        int tmp2 = helper(nums, middle+1, end);
        return tmp1 < tmp2 ? tmp1 : tmp2;
    }
};

//----------------------------------
//No.155 Min Stack
//----------------------------------
class MinStack {
    stack<int> stk;
    stack<int> minstk;
public:
    void push(int x) {
        stk.push(x);
        if(!minstk.empty()){
            if(minstk.top() >= x) minstk.push(x);
        } else {
            minstk.push(x);
        }
    }

    void pop() {
        if(stk.top() == minstk.top()){
            minstk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};

//----------------------------------
//No.160 Intersection of Two Linked Lists
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen = 0;
        int blen = 0;
        ListNode* ptr = headA;
        while(ptr != NULL){
            alen++;
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr != NULL){
            blen++;
            ptr = ptr->next;
        }
        int gap = abs(alen-blen);
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        if(alen > blen){
            for(int i = 0; i < gap; i++){
                ptrA = ptrA->next;
            }
        } else if(alen < blen) {
            for(int i = 0; i < gap; i++){
                ptrB = ptrB->next;
            }
        }
        while(ptrA){
            if(ptrA == ptrB)
                return ptrA;
            else {
                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }
        }
        return NULL;
    }
};

//----------------------------------
//No.162 Find Peak Element
//----------------------------------
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] > nums[i]){
                index =  i - 1;
                return index;
            }
        }
        index = n - 1;
        return index;
    }
};

//----------------------------------
//No.164 Maximum Gap
//----------------------------------
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        int max = INT_MIN;
        int min = INT_MAX;
        for(int i = 0; i < n; i++){
            max = max < nums[i] ? nums[i] : max;
            min = min > nums[i] ? nums[i] : min;
        }
        int len = (max-min)%(n-1) == 0 ? (max-min)/(n-1) : (max-min)/(n-1)+1;
        if(len == 0)
            return 0;

        int arrayLen = ((max-min)%len == 0 ? (max-min)/len : (max-min)/len+1) + 1;
        //int arrayLen = (max-min)/len+1;

        vector<int> numMax(arrayLen, INT_MIN);
        vector<int> numMin(arrayLen, INT_MAX);
        vector<int> flag(arrayLen, false);

        for(int i = 0; i < n; i++){
            int index = (nums[i]-min)%len == 0 ? (nums[i]-min)/len : (nums[i]-min)/len+1;
            numMax[index] = numMax[index] < nums[i] ? nums[i] : numMax[index];
            numMin[index] = numMin[index] > nums[i] ? nums[i] : numMin[index];
            flag[index] = true;
        }
        int ans = 0;
        int gap = 0;
        for(int i = 0; i < arrayLen-1; i++){
            if(flag[i]){
                for(int j = i+1; j < arrayLen; j++){
                    if(flag[j]){
                        gap = numMin[j] - numMax[i];
                        ans = gap > ans ? gap : ans;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

//----------------------------------
//No.165 Compare Version Numbers
//----------------------------------
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> A = convert(version1);
        vector<int> B = convert(version2);
        int len = min(A.size(), B.size());
        int i = 0;
        for(; i < len; i++){
            if(A[i] < B[i])
                return -1;
            if(A[i] > B[i])
                return 1;
        }
        if(A.size() > B.size()){
            for(; i < A.size(); i++){
                if(A[i] != 0)
                    return 1;
            }
        }
        if(A.size() < B.size()){
            for(; i < B.size(); i++){
                if(B[i] != 0)
                    return -1;
            }
        }
        return 0;
    }
    vector<int> convert(string target){
        vector<int> ans;
        int len = target.length();
        string tmp = "";
        for(int i = 0; i < len; i++){
            if(target[i] == '.'){
                ans.push_back(stoi(tmp));
                tmp = "";
            } else {
                tmp = tmp + target[i];
            }
        }
        ans.push_back(stoi(tmp));
        return ans;
    }
};

//----------------------------------
//No.166 Fraction to Recurring Decimal
//----------------------------------
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(numerator == 0) return "0";
        if(numerator < 0 ^ denominator < 0)
            res += "-";
        long long int n = numerator, d = denominator;
        n = abs(n);
        d = abs(d);
        res += to_string(n/d);
        long long int r = n % d;
        if(r == 0)
            return res;
        else
            res += '.';

        unordered_map<int, int> hash;
        while(r){
            if(hash.find(r) != hash.end()){
                res.insert(hash[r], 1, '(');
                res += ")";
                break;
            }
            hash[r] = res.size();
            r *= 10;
            res += to_string(r/d);
            r %= d;
        }
        return res;
    }
};

//----------------------------------
//No.168 Excel Sheet Column Title
//----------------------------------
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            ans = (char)((n-1)%26 + 'A') + ans;
            n = (n-1)/26;
        }
        return ans;
    }
};

//----------------------------------
//No.169 Majority Element
//----------------------------------
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        map<int, int> count;
        for(int i = 0; i < len; i++){
            if(count.find(nums[i]) != count.end()) count[nums[i]]++;
            else count[nums[i]] = 1;
        }
        int j = 0;
        while(count[nums[j]] <= len/2){
            j++;
        }
        return nums[j];
    }
};

//----------------------------------
//No.171 Excel Sheet Column Number
//----------------------------------
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();

        int num = 0;
        for(int i = 0; i < len; i++){
            num = (num*26 + (s[i]-'A'+1));
        }
        return num;
    }
};

//----------------------------------
//No.172 Factorial Trailing Zeroes
//----------------------------------
class Solution {
public:
    int trailingZeroes(int n) {

        long long sum = 0;
        long long factor = 5;
        while(factor <= n){
            sum += floor(n/factor);
            factor *= 5;
        }
        return sum;
    }
};

//----------------------------------
//No.173 Binary Search Tree Iterator
//----------------------------------
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> m_stack;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* ptr = root;
        while(ptr != NULL){
            m_stack.push(ptr);
            ptr = ptr->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return m_stack.empty() ? false : true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp =  m_stack.top();
        int ans = tmp->val;
        m_stack.pop();
        if(tmp->right != NULL){
            TreeNode* ptr = tmp->right;
            while(ptr != NULL){
                m_stack.push(ptr);
                ptr = ptr->left;
            }
        }
        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

//----------------------------------
//No.174 Dungeon Game
//----------------------------------
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(m == 1 && n == 1)
            return dungeon[0][0] < 0 ? 1-dungeon[0][0] : 1;
        vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));
        vector<vector<int> > newdg(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                newdg[i][j] = dungeon[i][j] < 0 ? 1-dungeon[i][j] : 1;
            }
        }

        dp[m-1][n-1] = dungeon[m-1][n-1] < 0 ? 1-dungeon[m-1][n-1] : 1;
        for(int i = m-1; i >= 0; i--){
            int j = i == m-1 ? n-2 : n-1;
            for(; j >= 0; j--){
                if(dungeon[i][j]+newdg[i][j] >= min(dp[i+1][j], dp[i][j+1])){
                    dp[i][j] = newdg[i][j];
                } else {
                    dp[i][j] = newdg[i][j] + (min(dp[i+1][j], dp[i][j+1]) - (dungeon[i][j] + newdg[i][j]));
                }
            }
        }
        return dp[0][0];
    }
};

//----------------------------------
//No.179 Largest Number
//----------------------------------
bool cmp(int a, int b){
    string L = to_string(a) + to_string(b);
    string R = to_string(b) + to_string(a);
    return L > R;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        int n = nums.size();
        string ans = "";
        if(nums[0] == 0){
            ans = '0';
            return ans;
        }
        for(int i = 0; i < n; i++){

            ans += to_string(nums[i]);
        }
        return ans;
    }
};

//----------------------------------
//No.187 Repeated DNA Sequences
//----------------------------------
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int len = s.length();
        if(len <= 10)
            return ans;
        unordered_map<int, int> Hash;
        unordered_map<char, int> cti;
        cti['A'] = 0;
        cti['C'] = 1;
        cti['G'] = 2;
        cti['T'] = 3;
        int itc[] = {'A', 'C', 'G', 'T'};
        for(int i = 0; i < len-9; i++){
            int tmp = 0;
            for(int j = 0; j < 10; j++){
                tmp = tmp << 2;
                tmp = tmp | cti[s[i+j]];
            }
            if(Hash.find(tmp) != Hash.end()){
                Hash[tmp]++;
                if(Hash[tmp] == 2){
                    string tmpS = "";
                    int n = 0;
                    for(int i = 0; i < 10; i++){
                        n = tmp & 0xC0000;
                        n = n >> 18;
                        tmpS += itc[n];
                        tmp = tmp << 2;
                    }
                    ans.push_back(tmpS);
                }
            } else {
                Hash[tmp] = 1;
            }
        }
        return ans;
    }
};

//----------------------------------
//No.188 Best Time to Buy and Sell Stock IV
//----------------------------------
class Solution {
public:
/*
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int days = prices.size();
        if (k >= days) return maxProfit2(prices);

        vector<vector<int> > local(days, vector<int>(k+1, 0));
        vector<vector<int> > global(days, vector<int>(k+1, 0));

        for (int i = 1; i < days ; i++) {
            int diff = prices[i] - prices[i - 1];

            for (int j = 1; j <= k; j++) {
                local[i][j] = max(global[i - 1][j - 1], local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
             }
        }
        return global[days - 1][k];
    }
    */

    int maxProfit2(vector<int> prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 0 || k == 0)
            return 0;
        if(k >= len)
            return maxProfit2(prices);

        vector<int> local(k+1, 0);
        vector<int> global(k+1, 0);

        for(int i = 0;i < len-1; i++)  {
            int diff = prices[i+1]-prices[i];
            for(int j = k; j >= 1; j--){
                local[j] = max(global[j-1]+(diff>0?diff:0), local[j]+diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }

};

//----------------------------------
//No.198 House Robber
//----------------------------------
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int opYes = 0;
        int opNo = 0;
        int max = 0;
        for(int i = 0; i < len; i++){
            opYes = opNo + nums[i];
            opNo = max;
            max = opYes > opNo ? opYes : opNo;
        }
        return max;
    }
};

//----------------------------------
//No.199 Binary Tree Right Side View
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> Q;
        Q.push(root);

        TreeNode* L;
        int countP = 1;
        int countS = 0;
        while(!Q.empty()){
            L = Q.front();

            if(L->left != NULL){
                Q.push(L->left);
                countS++;
            }
            if(L->right != NULL){
                Q.push(L->right);
                countS++;
            }
            Q.pop();
            countP--;
            if(countP == 0){
                ans.push_back(L->val);
                countP = countS;
                countS = 0;
            }
        }
        return ans;
    }
};

//----------------------------------
//No.200 Number of Islands
//----------------------------------
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        if(col == 0)
            return 0;

        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] != '1')
                    continue;
                ans++;
                helper(grid, i, j, row, col);
            }
        }
        return ans;
    }

    void helper(vector<vector<char>>& grid, int i, int j, int row, int col){
        if(i < 0 || i >= row || j < 0 || j >= col)
            return ;
        if(grid[i][j] == '1'){
            grid[i][j] = '2';
            helper(grid, i-1, j, row, col);
            helper(grid, i+1, j, row, col);
            helper(grid, i, j-1, row, col);
            helper(grid, i, j+1, row, col);
        }
    }
};

//----------------------------------
//No.201 Bitwise AND of Numbers Range
//----------------------------------
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m != n){
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        return m << count;
    }
};

//----------------------------------
//No.202 Happy Number
//----------------------------------
class Solution {
public:
    bool isHappy(int n) {

        map<int, int> store;
        while(n != 1){
            int sum = 0;
            while(n > 0){
                sum += ((n%10) * (n%10));
                n /= 10;
            }
            n = sum;
            if(store.find(n) != store.end())
                break;
            else
                store[n] = 1;
        }
        return n == 1;
    }
};

//----------------------------------
//No.203 Remove Linked List Elements
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* ptr = ans;
        while(ptr->next != NULL){
            if(ptr->next->val == val){
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return ans->next;
    }
};

//----------------------------------
//No.204 Count Primes
//----------------------------------
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        bool flag[n];
        for(int i = 2; i < n; i++){
            flag[i] = true;
        }

        for(int i = 2; i*i <= n; i++){
            for(int j = i; j*i <= n; j++){
                flag[j*i] = false;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(flag[i] == true)
                sum++;
        }
        return sum;
    }
};

//----------------------------------
//No.205 Isomorphic Strings
//----------------------------------
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        int map1[256] = {0}, map2[256] = {0};
        for(int i = 0; i < len; i++){
            if(map1[s[i]] != map2[t[i]]) return false;
            map1[s[i]] = i+1;
            map2[t[i]] = i+1;
        }
        return true;
    }
};

//----------------------------------
//No.206
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* tmpL = NULL;
        ListNode* ptr = head;
        ListNode* tmpR = head->next;
        while(ptr != NULL){
            ptr->next = tmpL;
            tmpL = ptr;
            ptr = tmpR;
            if(tmpR != NULL)
                tmpR = tmpR->next;
        }
        return tmpL;
    }
};

//----------------------------------
//No.207 Course Schedule
//----------------------------------
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> course(numCourses, -1);
        int n = prerequisites.size();
        for(int i = 0; i < n; i++){
            int self = prerequisites[i].first;
            int index = prerequisites[i].second;
            while(course[index] != self && course[index] != -1){
                index = course[index];
            }
            if(course[index] == self)
                return false;
            else
                course[self] = prerequisites[i].second;
        }
        return true;
    }
};

//----------------------------------
//No.208 Implement Trie (Prefix Tree)
//----------------------------------
class TrieNode {
public:
    bool isKey;
    TrieNode *children[26];
    // Initialize your data structure here.
    TrieNode() {
        isKey = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->isKey = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->children[word[i]-'a'])
                node = node->children[word[i]-'a'];
            else
                return false;
        }
        return node->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(node->children[prefix[i]-'a'])
                node = node->children[prefix[i]-'a'];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

//----------------------------------
//No.209 Minimum Size Subarray Sum
//----------------------------------
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int sum = nums[0];
        int ans = INT_MAX;
        int count = 1;
        int L = 0, R = 0;

        while(R < nums.size() && L <= R){
            while(sum < s){

                R++;
                if(R < nums.size()){
                    count++;
                    sum += nums[R];
                } else {
                    return ans == INT_MAX ? 0 : ans;
                }
            }
            ans = ans > count ? count : ans;
            count--;
            sum -= nums[L];
            L++;
            if(sum >= s){
                ans = ans > count ? count : ans;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//----------------------------------
//No. House Robber II
//----------------------------------
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int Max = 0;
        int n = nums.size();
        vector<int> opt(n, 0);
        opt[0] = nums[0];
        opt[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n-1; i++){
            opt[i] = max(opt[i-2] + nums[i], opt[i-1]);
        }
        Max = opt[n-2];

        opt[0] = 0;
        opt[1] = nums[1];
        for(int i = 2; i < n; i++){
            opt[i] = max(opt[i-2] + nums[i], opt[i-1]);
        }
        if(Max < opt[n-1])
            Max = opt[n-1];
        return Max;
    }
};

//----------------------------------
//No.211 Add and Search Word - Data structure design
//----------------------------------
class TrieNode {
public:
    bool isKey;
    TrieNode *children[26];
    TrieNode() {
        isKey = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};
class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary(){
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new TrieNode();
            }
            node = node->children[word[i]-'a'];
        }
        node->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* node = root;
        return helperSearch(node, word, 0);
    }
private:
    bool helperSearch(TrieNode* node, string &word, int pos){
        if(word.length() == pos){
            if(node->isKey)
                return true;
            else
                return false;
        }

        if(word[pos] != '.'){
            if(node->children[word[pos]-'a'] == NULL)
                return false;
            else {
                return helperSearch(node->children[word[pos]-'a'], word, pos+1);
            }
        } else {
            bool hasOne = false;
            for(int i = 0; i < 26; i++){
                if(node->children[i] != NULL){
                    hasOne = helperSearch(node->children[i], word, pos+1) || hasOne;
                    if(hasOne)
                        return true;
                }
            }
            return false;
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

//----------------------------------
//No.215 Kth Largest Element in an Array
//----------------------------------
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0;
        int R = nums.size() - 1;
        int K = nums.size() - k;
        int index = quickSort(nums, L, R, K);
        return nums[index];
    }
    int quickSort(vector<int> &nums, int l, int r, int k){
        int index = l;
        if(l < r){
            int i = l, j = r, X = nums[i];
            while(i < j){
                while(i<j && nums[j] >= X)
                    j--;
                if(i<j){
                    nums[i] = nums[j];
                    i++;
                }
                while(i<j && nums[i] < X)
                    i++;
                if(i<j){
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = X;

            if(i == k){
                index = i;
                return index;
            }
            else {
                if(i > k){
                    index = quickSort(nums, l, i-1, k);
                } else {
                    index = quickSort(nums, i+1, r, k);
                }
            }
        }
        return index;
    }
};

//----------------------------------
//No.216 Combination Sum III
//----------------------------------
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp(k, 0);
        helper(tmp, 0, 0, n);
        return ans;
    }
    void helper(vector<int>& tmp, int pos, int sum, int n){
        if(pos == tmp.size()){
            if(sum == n)
                ans.push_back(tmp);
            return ;
        }
        int start = pos > 0 ? tmp[pos-1]+1 : 1;
        for(int i = start; i <= 9; i++){
            tmp[pos] = i;
            if(sum + tmp[pos] <= n){
                helper(tmp, pos+1, sum+tmp[pos], n);
            }
        }
        return ;
    }
};

//----------------------------------
//No.217 Contains Duplicates
//----------------------------------
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};

//----------------------------------
//No.218 The Skyline Problem
//----------------------------------
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > heights, skyline;
        for(int i = 0; i < buildings.size(); i++){
            heights.push_back({buildings[i][0], -buildings[i][2]});
            heights.push_back({buildings[i][1],  buildings[i][2]});
        }
        sort(heights.begin(), heights.end());
        multiset<int> m;
        int preMax = 0;
        m.insert(0);
        for(int i = 0; i < heights.size(); i++){
            if(heights[i].second < 0){
                m.insert(-heights[i].second);
            } else {
                m.erase(m.find(heights[i].second));
            }
            int curMax = *m.rbegin();
            if(curMax != preMax){
                skyline.push_back({heights[i].first, curMax});
                preMax = curMax;
            }
        }
        return skyline;
    }
};

//----------------------------------
//No.219 Contains Duplicate II
//----------------------------------
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> index;
        for(int i = 0; i < n; i++){
            if(index.find(nums[i]) != index.end()){
                if(i - index[nums[i]] <= k)
                    return true;
            }
            index[nums[i]] = i;
        }
        return false;
    }
};

//----------------------------------
//No.220 Contains Duplicate III
//----------------------------------
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if(len == 0) return false;
        if(k == 0) return false;
        int L, R;
        L = 0;
        R = L+1;
        long num1, num2;
        for(; L < len; L++){
            if(L == R)
                R = L+1;
            for(; R-L <= k && R < len; R++){
                num1 = nums[L];
                num2 = nums[R];
                if(abs(num1 - num2) <= t)
                    return true;
            }
            R--;
        }
        return false;
    }
};

//----------------------------------
//No.221 Maximal Square
//----------------------------------
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        vector<vector<int> > opt(row+1, vector<int>(col+1, 0));
        int ans = 0;
        for(int i = 1; i < row+1; i++){
            for(int j = 1; j < col+1; j++){
                if(matrix[i-1][j-1] == '1'){
                    opt[i][j] = min(min(opt[i-1][j], opt[i][j-1]), opt[i-1][j-1]) + 1;
                    if(opt[i][j] > ans)
                        ans = opt[i][j];
                }
            }
        }
        return ans*ans;
    }
};

//----------------------------------
//No.222 Count Complete Tree Nodes
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int level = 0;
    int empty = 0;
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int L = getL(root);
        int R = getR(root);
        if(L == R){
            return pow(2, L+1)-1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int getL(TreeNode* root){
        int count = 0;
        while(root->left){
            count++;
            root = root->left;
        }
        return count;
    }

    int getR(TreeNode* root){
        int count = 0;
        while(root->right){
            count++;
            root = root->right;
        }
        return count;
    }
};

//----------------------------------
//No.223 Rectangle Area
//----------------------------------
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A) * (D-B) + (G-E) * (H-F);
        if(A > G || C < E || D < F || B > H) return area;

        int top = min(D,H);
        int bottom = max(B,F);
        int left = max(A,E);
        int right = min(C,G);
        return area - (top-bottom)*(right-left);
    }
};

//----------------------------------
//No.224 Basic Calculator
//----------------------------------
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0;
        int sign = 1;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ')
                continue;
            if('0' <= s[i] && s[i] <= '9'){
                int cur = s[i] - '0';
                while( '0' <= s[i+1] && s[i+1] <= '9' && i+1 < s.length() ){
                    cur = cur * 10 + s[i+1] - '0';
                    i++;
                }
                res = res + sign * cur;
            } else if(s[i] == '+'){
                sign = 1;
            } else if(s[i] == '-'){
                sign = -1;
            } else if(s[i] == '('){
                stk.push(res);
                res = 0;
                stk.push(sign);
                sign = 1;
            } else if(s[i] == ')'){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                res = b * res + a;
                sign =1;
            }
        }
        return res;
    }
};

//----------------------------------
//No.225 Implement Stack using Queue
//----------------------------------
class Stack {
    queue<int> stdQ;
    queue<int> assQ;
public:
    // Push element x onto stack.
    void push(int x) {
        stdQ.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(stdQ.size() > 1){
            assQ.push(stdQ.front());
            stdQ.pop();
        }
        stdQ.pop();
        while(!assQ.empty()){
            stdQ.push(assQ.front());
            assQ.pop();
        }
    }

    // Get the top element.
    int top() {
        while(stdQ.size() > 1){
            assQ.push(stdQ.front());
            stdQ.pop();
        }
        int ans = stdQ.front();
        assQ.push(stdQ.front());
        stdQ.pop();
        while(!assQ.empty()){
            stdQ.push(assQ.front());
            assQ.pop();
        }
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(stdQ.size() == 0 && assQ.size() == 0) return true;
        else return false;
    }
};

//----------------------------------
//No.226 Invert Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        helper(root);
        return root;
    }
    void helper(TreeNode* root){
        swap(root->left, root->right);
        if(root->left != NULL)
            helper(root->left);
        if(root->right != NULL)
            helper(root->right);
        return ;
    }
};

//----------------------------------
//No.227 Basic Calculator II
//----------------------------------
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int temp_res = 0;
        char op = '+';
        char ch;

        for(int pos = 0; pos < s.length(); pos++){
            ch = s[pos];
            if(ch == ' ')
                continue;
            if(ch >= '0' && ch <= '9'){
                int cur = ch - '0';
                while(pos+1 < s.length() && s[pos+1] >= '0' && s[pos+1] <= '9'){
                    cur = cur * 10 + s[pos+1] - '0';
                    pos++;
                }
                switch(op){
                    case '+':
                        temp_res += cur;
                        break;
                    case '-':
                        temp_res -= cur;
                        break;
                    case '*':
                        temp_res *= cur;
                        break;
                    case '/':
                        temp_res /= cur;
                        break;
                }
            } else {
                if(ch == '+' || ch == '-'){
                    res += temp_res;
                    temp_res = 0;
                }
                op = s[pos];
            }
        }
        return res + temp_res;
    }
};

//----------------------------------
//No.228 Summary Ranges
//----------------------------------
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int len = nums.size();
        int i = 0;
        while(i < len){
            int j = 1;
            while(i+j < len && nums[i+j] == nums[i]+j) j++;
            ans.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i+j-1]));
            i += j;
        }
        return ans;
    }
};

//----------------------------------
//No.229 Majority Element II
//----------------------------------
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int A = 0;
        int B = 0;
        int countA = 0;
        int countB = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == A){
                countA++;
            } else if(nums[i] == B){
                countB++;
            } else if(countA == 0){
                A = nums[i];
                countA = 1;
            } else if(countB == 0){
                B = nums[i];
                countB++;
            } else {
                countA--;
                countB--;
            }
        }
        countA = 0;
        countB = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == A){
                countA++;
            }
            if(nums[i] == B){
                countB++;
            }
        }
        if(countA > nums.size()/3)
            ans.push_back(A);
        if(countB > nums.size()/3 && A != B)
            ans.push_back(B);
        return ans;
    }
};

//----------------------------------
//No.230 Kth Smallest Element in a BST
//----------------------------------
class Solution {
    int count = 0;
public:
    int totalNQueens(int n) {
        vector<string> cur(n, string(n,'.'));
        helper(cur, 0);
        return count;
    }
    void helper(vector<string> cur, int row){
        if(row == cur.size()){
            count += 1;
            return ;
        }
        for(int col = 0; col < cur[row].length(); col++){
            cur[row][col] = 'Q';
            if(judge(cur, row, col)){
                helper(cur, row+1);
            }
            cur[row][col] = '.';
        }
    }

    bool judge(vector<string> target, int row, int col){
        for(int i = row-1; i >= 0; i--){
            if(target[i][col] == 'Q')
                return false;
            if(col+row-i < target[row].length() && target[i][col+row-i] == 'Q')
                return false;
            if(col-row+i >= 0 && target[i][col-row+i] == 'Q')
                return false;
        }
        return true;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
            return 0;
        int ans;
        int count = 0;
        helper(root, k, count, ans);
        return ans;
    }
    void helper(TreeNode* root, int k, int &count, int &ans){
        if(root == NULL)
            return ;
        helper(root->left, k, count, ans);
        count++;
        if(count == k){
            ans = root->val;
            return ;
        }
        helper(root->right, k, count, ans);
    }
};

//----------------------------------
//No.231 Power of Two
//----------------------------------
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(long long i = 1; i != n; i = i << 1){
            if(i > n) return false;
        }
        return true;
    }
};

//----------------------------------
//No.232 Implement Queue using Stacks
//----------------------------------
class Queue {
    stack<int> stdStack;
    stack<int> revStack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!revStack.empty()){
            stdStack.push(revStack.top());
            revStack.pop();
        }
        stdStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!stdStack.empty()){
            revStack.push(stdStack.top());
            stdStack.pop();
        }
        revStack.pop();
    }

    // Get the front element.
    int peek(void) {
        while(!stdStack.empty()){
            revStack.push(stdStack.top());
            stdStack.pop();
        }
        return revStack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if(revStack.empty() && stdStack.empty()) return true;
        else return false;
    }
};

//----------------------------------
//No.233 Number of Digit One
//----------------------------------
class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for(long m = 1; m <= n; m *= 10){
            long a = n/m, b = n%m;
            ans += (a + 8) / 10 * m;
            if(a % 10 == 1){
                ans += b + 1;
            }
        }
        return ans;
    }
};

//----------------------------------
//No.234 Palindrome Linked List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        ListNode* M = head;
        ListNode* E = head->next;
        while(E != NULL && E->next != NULL){
            M = M->next;
            E = E->next->next;
        }
        ListNode* ptr = M;
        ListNode* L = ptr->next;
        ListNode* R = ptr->next->next;
        M->next = NULL;
        while(L){
            L->next = ptr;
            ptr = L;
            L = R;
            if(R)
                R = R->next;
        }
        ListNode* left = head;
        while(left != M){
            if(left->val != ptr->val)
                return false;
            left = left->next;
            ptr = ptr->next;
        }
        if(left->val == ptr->val)
            return true;
        else
            return false;
    }
};

//----------------------------------
//No.235 Lowest Common Ancestor of a Binary Search Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(max(p->val, q->val) < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(min(p->val, q->val) > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

//----------------------------------
//No.236 Lowest Common Ancestor of a Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool test = false;
        test = helper(root, p, q);
        return ans;
    }
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->left == NULL && root->right == NULL){
            if(root == p || root == q)
                return true;
            else
                return false;
        }
        bool getL = false;
        bool getR = false;
        if(root->left != NULL)
            getL = helper(root->left, p, q);
        if(root->right != NULL)
            getR = helper(root->right, p, q);
        if(getL && getR)
            ans = root;
        if((root == p || root == q) && (getL || getR))
            ans = root;
        return (root == p || root == q) ? true : (getL || getR);
    }
};

//----------------------------------
//No.237 Delete Node in a Linked List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr = node->next;
        node->val = ptr->val;
        node->next = ptr->next;
        delete ptr;
    }
};

//----------------------------------
//No.238 Product of Array Except Self
//----------------------------------
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);

        for(int i = 1; i < len;  i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int tmpsum = 1;
        for(int i = len-1; i >= 0; i--){
            ans[i] *= tmpsum;
            tmpsum = tmpsum * nums[i];
        }
        return ans;
    }
};

//----------------------------------
//No.239 Sliding Window Maximum
//----------------------------------
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0)
            return ans;
        int Max = nums[0];
        int maxPos = 0;
        for(int i = 0; i < k; i++){
            if(Max < nums[i]){
                Max = nums[i];
                maxPos = i;
            }
        }
        ans.push_back(Max);

        for(int i = k; i < n; i++){
            if(maxPos > i-k){
                if(Max < nums[i]){
                    Max = nums[i];
                    maxPos = i;
                }
            } else {
                Max = nums[i-k+1];
                maxPos = i-k+1;
                for(int j = maxPos; j <= i; j++){
                    if(Max < nums[j]){
                        Max = nums[j];
                        maxPos = j;
                    }
                }
            }
            ans.push_back(Max);
        }
        return ans;
    }
};

//----------------------------------
//No.240 Search a 2D Matrix II
//----------------------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int i, j;
        for(i = 0, j = col-1; i < row && j >= 0;){
            if(matrix[i][j] < target)
                i++;
            else {
                if(matrix[i][j] > target)
                    j--;
                else
                    return true;
            }
        }
        return false;
    }
};

//----------------------------------
//Different Ways to Add Parentheses
//----------------------------------
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        vector<char> op;
        vector<int> num;
        int i = 0;
        if(input[0] == '-'){
            op.push_back('-');
            num.push_back(0);
            i = 1;
        }
        for(; i < input.length(); i++){
            if('0' <= input[i] && input[i] <= '9'){
                int cur = input[i] - '0';
                while('0' <= input[i+1] && input[i+1] <= '9' && i+1 < input.length()){
                    cur = cur * 10 + input[i+1] - '0';
                    i++;
                }
                num.push_back(cur);
            } else {
                op.push_back(input[i]);
            }
        }
        int opN = op.size();

        ans = helper(num, op, 0, opN-1);
        return ans;

    }
    vector<int> helper(vector<int> num, vector<char> op, int L, int R){
        vector<int> res;
        if(L > R){
            res.push_back(num[L]);
            return res;
        }
        for(int i = L; i <= R; i++){
            vector<int> res1 = helper(num, op, L, i-1);
            vector<int> res2 = helper(num, op, i+1, R);
            for(int x = 0; x < res1.size(); x++){
                for(int y = 0; y < res2.size(); y++){
                    res.push_back(cal(res1[x], op[i], res2[y]));
                }
            }
        }
        return res;
    }

    int cal(int a, char op, int b){
        int res = 0;
        switch(op){
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
        }
        return res;
    }
};

//----------------------------------
//No.242 Valid Anagram
//----------------------------------
ass Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 != len2) return false;
        vector<int> count(26, 0);

        for(int i = 0; i < len1; i++){
            count[s[i]-'a']++;
        }
        for(int i = 0; i < len2; i++){
            if(--count[t[i]-'a'] < 0) return false;
        }
        return true;
    }
};
//----------------------------------
//No.257 Binary Tree Paths
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return ans;
        string tmp;
        helper(root, tmp);
        return ans;
    }
    void helper(TreeNode* root, string str){
        str += str == "" ? to_string(root->val) : "->"+to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            int len = str.length();
            ans.push_back(str);
            return ;
        }

        if(root->left != NULL){
            helper(root->left, str);
        }
        if(root->right != NULL){
            helper(root->right, str);
        }
    }
};

//----------------------------------
//No.258 Add Digits
//----------------------------------
class Solution {
public:
    int addDigits(int num) {
        while(num / 10 != 0){
            int sum = 0;
            while(num > 0){
                sum += (num%10);
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

//----------------------------------
//No.260 Single Number III
//----------------------------------
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorVal = nums[0];
        for(int i = 1; i < nums.size(); i++){
            xorVal = xorVal ^ nums[i];
        }
        int j = 0;
        while(!((xorVal>>j)&1))
            j++;
        vector<int> A;
        vector<int> B;
        for(int k = 0; k < nums.size(); k++){
            if((nums[k]>>j)&1)
                A.push_back(nums[k]);
            else
                B.push_back(nums[k]);
        }
        vector<int> ans;
        int a = A[0];
        for(int x = 1; x < A.size(); x++){
            a = a ^ A[x];
        }
        ans.push_back(a);
        a = B[0];
        for(int x = 1; x < B.size(); x++){
            a = a ^ B[x];
        }
        ans.push_back(a);
        return ans;
    }
};

//----------------------------------
//No.263 Ugly Number
//----------------------------------
class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num%2 == 0){
            num /= 2;
        }
        while(num%3 == 0){
            num /= 3;
        }
        while(num%5 == 0){
            num /= 5;
        }
        return num == 1;
    }
};

//----------------------------------
//No.264 Ugly Number II
//----------------------------------
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(1, 1);
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while(ans.size() < n){
            int tmp2 = ans[i2]*2;
            int tmp3 = ans[i3]*3;
            int tmp5 = ans[i5]*5;
            int mn = min(tmp2, min(tmp3, tmp5));
            if(mn == tmp2) i2++;
            if(mn == tmp3) i3++;
            if(mn == tmp5) i5++;
            ans.push_back(mn);
        }
        return ans.back();
    }
};

//----------------------------------
//No.268 Missing Number
//----------------------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
        }
        return 0.5*len*(1+len) - sum;
    }
};

//----------------------------------
//No.273 Integer to English Words
//----------------------------------
class Solution {
    string lessThan20[20] = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string moreThan20[8] = {"Twenty ", "Thirty ", "Forty ","Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string magnitude[3] = {"Thousand ", "Million ", "Billion "};

public:
    string numberToWords(int num) {
        string ans = "";
        if(num == 0){
            ans = "Zero";
            return ans;
        }

        int loop = 0;
        while(num % 1000 || num / 1000){
            string tmp = "";
            int threeBits = num % 1000;
            if(threeBits/100)
                tmp += (lessThan20[threeBits/100] + "Hundred ");
            int twoBits = num % 100;
            if(twoBits){
                if(twoBits < 20 && twoBits > 0){
                    tmp += lessThan20[twoBits];
                } else {
                    tmp += moreThan20[twoBits/10-2];
                    if(twoBits%10)
                        tmp += lessThan20[twoBits%10];
                }
            }
            if(tmp != ""){
                switch(loop){
                    case 1:
                        tmp += "Thousand ";
                        break;
                    case 2:
                        tmp += "Million ";
                        break;
                    case 3:
                        tmp += "Billion ";
                        break;
                    default:
                        break;
                }
            }
            ans = tmp + ans;
            loop++;
            num /= 1000;
        }
        int len = ans.length();
        ans = ans.substr(0, len-1);
        return ans;
    }
};

//----------------------------------
//No.274 H-Index
//----------------------------------
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int max = 0;
        for(int i = 0; i < n; i++){
            if(citations[i] >= n-i){
                max = n-i;
                break;
            }
        }
        return max;
    }
};

//----------------------------------
//No.275 H-Index
//----------------------------------
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max=0;
        int n = citations.size();
        for(int i = 0; i < n; i++){
            if(citations[i] >= n-i){
                max = n-i;
                break;
            }
        }
        return max;
    }
};

//----------------------------------
//No.278 First Bad Version
//----------------------------------
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
    int index;
public:
    int firstBadVersion(int n) {
        index = n;
        helper(1, n);
        return index;
    }
    void helper(long long L, long long R){
        if(L > R)
            return ;
        long long M = (L + R) / 2;
        if(isBadVersion(M)){
            if(M < index)
                 index = M;
            helper(L, M-1);
        } else {
            helper(M+1, R);
        }
    }


//----------------------------------
//No.279 Perfect Squares
//----------------------------------
class Solution {
public:
    int numSquares(int n) {
        vector<int> opt(n+1, INT_MAX);
        for(int i = 1; i*i <= n; i++){
            opt[i*i] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; i+j*j <= n; j++){
                opt[i+j*j] = min(opt[i]+1, opt[i+j*j]);
            }
        }
        return opt[n];
    }
};

//----------------------------------
//No.282 Expression Add Operators
//----------------------------------
class Solution {
    vector<string> ans;
    vector<char> ops = {'+', '-', '*'};
public:
    vector<string> addOperators(string num, int target) {
        helper(num, "", target, 0, 0, 0);
        return ans;
    }

    void helper(string num, string tmp, int target, long long curRes, long long preNum, int start){
        if(start == num.length() && target == curRes){
            ans.push_back(tmp);
            return ;
        }

        long long curNum;
        char curOp;
        string curNumStr;

        for(int i = start+1; i <= num.length(); i++){
            curNumStr = num.substr(start, i-start);
            curNum = stoll(curNumStr);

            if(curNumStr.length() > 1 && curNumStr[0] == '0'){
                return;
            }
            if(start != 0){
                helper(num, tmp+"*"+curNumStr, target, curRes-preNum+preNum*curNum, preNum*curNum, i);
                helper(num, tmp+"-"+curNumStr, target, curRes-curNum, -curNum, i);
                helper(num, tmp+"+"+curNumStr, target, curRes+curNum,  curNum, i);
            } else {
                helper(num, tmp+curNumStr, target, curRes+curNum, curNum, i);
            }
        }
    }
};

//----------------------------------
//No.283 Move Zeros
//----------------------------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int i, j;

        for(i = 0, j = 0; i < len; i++){
            if(nums[i]){
                swap(nums[i], nums[j++]);
            }
        }
    }
};

//----------------------------------
//No.284 Peeking Iterator
//----------------------------------
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool _flag;
    int _value;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        _flag = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(!_flag){
            _value = Iterator::next();
            _flag = true;
        }
        return _value;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(!_flag){
            return Iterator::next();
        } else {
            _flag = false;
            return _value;
        }
    }

    bool hasNext() const {
        if(_flag)
            return true;
        else {
            return Iterator::hasNext();
        }
    }
};

//----------------------------------
//No.287 Find the Duplicate Number
//----------------------------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 1;
        int end = n-1;
        int mid;
        while(start <= end){
            mid = ( start + end ) / 2;
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    count++;
                }
            }
            if(count <= mid){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return start;
    }
};

//----------------------------------
//No.289 Game of List
//----------------------------------
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int count = 0;
                for(int x = i-1; x <= i+1; x++){
                    for(int y = j-1; y <= j+1; y++){
                        if(x<0 || x>=row || y<0 || y>=col)
                            continue;
                        if(x == i && y == j)
                            continue;
                        if(preState(board[x][y]))
                            count++;
                    }
                }
                if(board[i][j]%2){
                    if(count < 2 || count > 3)
                        board[i][j] = 2;
                    else {
                        board[i][j] = 1;
                    }

                } else {
                    if(count == 3)
                        board[i][j] = 3;
                    else
                        board[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                board[i][j] = board[i][j]%2;
            }
        }
    }
    int preState(int state){
        int status;
        switch(state){
            case 0:
            case 3:
                status = 0;
                break;
            case 1:
            case 2:
                status = 1;
                break;
        }
        return status;
    }
};

//----------------------------------
//No.290 Word Pattern
//----------------------------------
class Solution {
private:
    vector<string> split(string& str,const char* c){
        char *cstr, *p;
        vector<string> res;
        cstr = new char[str.size()+1];
        strcpy(cstr,str.c_str());
        p = strtok(cstr,c);
        while(p!=NULL)
        {
            res.push_back(p);
            p = strtok(NULL,c);
        }
        return res;
    }

public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str, " ");

        if(pattern.length() != words.size()) return false;

        map<char, string> forward;
        map<string, char> reverse;

        for(int i = 0; i < pattern.length(); i++){
            if( forward.find(pattern[i]) != forward.end() ){
                if( forward[pattern[i]] != words[i] ){
                    return false;
                }
            } else {
                forward[pattern[i]] = words[i];
            }
        }

        for(int i = 0; i < words.size(); i++){
            if(reverse.find(words[i]) != reverse.end()){
                if(reverse[words[i]] != pattern[i])
                    return false;
            } else {
                reverse[words[i]] = pattern[i];
            }
        }
        return true;
    }
};

//----------------------------------
//No.292 Nim Game
//----------------------------------
class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 != 0) return true;
        else return false;
    }
};

//----------------------------------
//No.Serialize and Deserialize Binary Tree
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
private:
    void serializeHelper(TreeNode* root, ostringstream& out){
        if(root){
            out << root->val << " ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        } else {
            out << "# ";
        }
    }
    TreeNode* deserializeHelper(istringstream& in){
        string val;
        in >> val;
        if(val == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left  = deserializeHelper(in);
        root->right = deserializeHelper(in);
        return root;
    }
};

/*solution 2*/
class Codec {
public:
    // ENcodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp){
                out << tmp->val << " ";
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                out << "# ";
            }
        }
        return out.str();
    }
    TreeNode* deserialize(string data){
        if(data.empty())
            return NULL;
        istringstream in(data);
        queue<TreeNode*> q;
        string val;
        in >> val;
        TreeNode* root = new TreeNode(stoi(val));
        TreeNode* cur = root;
        q.push(cur);
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(!(in >> val))
                break;
            if(val != "#"){
                cur = new TreeNode(stoi(val));
                t->left = cur;
                q.push(cur);
            }
            if(!(in >> val))
                break;
            if(val != "#"){
                cur = new TreeNode(stoi(val));
                t->right = cur;
                q.push(cur);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//----------------------------------
//No.295 Find Median from Data Stream
//----------------------------------
class MedianFinder {
private:
    priority_queue<long> small, large;

public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(large.size() == 0 || num < large.top()){
            large.push(num);
            if(large.size() - small.size() >= 2){
                small.push(-large.top());
                large.pop();
            }
        } else if(small.size() == 0 || num > -small.top()){
            small.push(-num);
            if(small.size() - large.size() >= 2){
                large.push(-small.top());
                small.pop();
            }
        } else {
            if(small.size() > large.size()){
                large.push(num);
            } else {
                small.push(-num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if((small.size()+large.size())%2 == 0){
            return (-small.top() + large.top())*0.5;
        } else {
            return small.size() > large.size() ? -small.top() : large.top();
        }
    }
};

//----------------------------------
//No.299 Bulls and Cows
//----------------------------------
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        map<char, int> count;
        string ges = "";
        int num = 0;
        int A = 0;
        int B = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                A++;
            } else {
                if(count.find(secret[i]) != count.end()){
                    count[secret[i]]++;
                } else {
                    count[secret[i]] = 1;
                }
                ges = ges + guess[i];
            }
        }
        for(int i = 0; i < n-A; i++){
            if(count.find(ges[i]) != count.end()){
                B++;
                count[ges[i]]--;
                if(count[ges[i]] <= 0){
                    count.erase(ges[i]);
                }
            }
        }
        string ans = "";
        ans = to_string(A) + "A" + to_string(B) + "B";
        return ans;
    }
};

//----------------------------------
//No.300 Longest Increasing Subsequence
//----------------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;
        int maximum = 1;
        vector<int> opt(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    opt[i] = max(opt[i], opt[j]+1);
                    if(maximum < opt[i])
                        maximum = opt[i];
                }
            }
        }
        return maximum;
    }
};

//----------------------------------
//No.301 Remove Invalid Parentheses
//----------------------------------
class Solution {
    unordered_set<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string > res;
        if(s.length() == 0){
            res.push_back("");
            return res;
        }
        dfs(ans, s, 0);
        for(unordered_set<string>::iterator it = ans.begin(); it != ans.end(); ++it){
            res.push_back(*it);
        }
        return res;
    }

    void dfs(unordered_set<string> &ans, string s, int pos){
        int min = unmatch(s);
        int len = s.length();
        if(min == 0){
            if(ans.find(s) == ans.end()){
                ans.insert(s);
            } else {
                return ;
            }
        }

        for(int i = pos; i < len; i++){
            string tmp = s.substr(0,i-0) + s.substr(i+1, len-i-1);
            if(unmatch(tmp) < min){
                dfs(ans, tmp, i);
            }
        }
    }

    int unmatch(string s){
        int L = 0;
        int R = 0;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '(':
                    L++;
                    break;
                case ')':
                    L--;
                    break;
                default:
                    break;
            }
            R = L < 0 ? R+1 : R;
            L = max(L, 0);
        }
        return R + L;
    }
};

//----------------------------------
//No.303 Range Sum Query - Immutable
//----------------------------------
class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        sum.resize(len, 0);
        for(int i = 0; i < len; i++){
            sum[i] = (i==0 ? nums[0] : sum[i-1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return (i == 0 ? sum[j] : sum[j] - sum[i-1]);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

//----------------------------------
//No.304 Range Sum Query 2D - Immutable
//----------------------------------
class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0) return ;
        int row = matrix.size();
        int col = matrix[0].size();
        sum = matrix;
        sum.resize(row+1);
        for(auto &it : sum){
            it.resize(col+1);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

//----------------------------------
//No.306 Additive Number
//----------------------------------
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 0; i < num.size(); i++){
            for(int j = i+1; j < num.size(); j++){
                string a = num.substr(0, i);
                string b = num.substr(i, j-i);
                if((a[0] == '0' && a.length() > 1) || (b[0] == '0' && b.length() > 1))
                    continue;
                long long numa = atoll(a.c_str());
                long long numb = atoll(b.c_str());
                string next = to_string(numa + numb);
                string now = a + b + next;
                while(now.size() <num.size()){
                    numa = numb;
                    numb = atoll(next.c_str());
                    next = to_string(numa + numb);
                    now = now + next;

                }
                if(now == num)
                    return true;
            }
        }
        return false;
    }
};

//----------------------------------
//No.307 Range Sum Query - Mutable
//----------------------------------
class NumArray {
    vector<int> c;
    vector<int> m_nums;
public:
    NumArray(vector<int> &nums) {
        c.resize(nums.size()+1);
        m_nums = nums;
        for(int i = 0; i < nums.size(); i++){
            add(i+1,nums[i]);
        }
    }
    int lowbit(int pos){
        return pos&(-pos);
    }
    void add(int pos, int value){
        while(pos < c.size()){
            c[pos] += value;
            pos += lowbit(pos);
        }
    }
    int sum(int pos){
        int res = 0;
        while(pos > 0){
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    void update(int i, int val) {
        int ori = m_nums[i];
        int delta = val - ori;
        m_nums[i] = val;
        add(i+1,delta);
    }

    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

//----------------------------------
//No.309 Best Time to Buy ans Sell Stock with Cooldown
//----------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return NULL;

        vector<int> delta(n,0);
        int pricePre = 0;
        for(int i = 0; i < n; i++){
            delta[i] = prices[i] - pricePre;
            pricePre = prices[i];
        }
        vector<int> buys(n,0);
        vector<int> sell(n,0);
        buys[0] = -prices[0];
        sell[0] = 0;

        int maxProfit = 0;
        for(int i = 1; i < n; i++){
            sell[i] = max(buys[i-1] + prices[i], sell[i-1] + delta[i]);
            if(sell[i] > maxProfit)
                maxProfit = sell[i];
            if(i > 1)
                buys[i] = max(sell[i-2] - prices[i], buys[i-1] - delta[i]);
            else
                buys[i] = buys[i-1] - delta[i];
        }
        return maxProfit;
    }
};

//----------------------------------
//No.310 Minimum Height Trees
//----------------------------------
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> d(n, 0);
        queue<int> q;
        vector<int> res;
        if(edges.size() == 0){
            res.push_back(0);
            return res;
        }
        for(int i = 0; i < edges.size(); i++){
            g[edges[i].first].push_back(edges[i].second);
            d[edges[i].first]++;
            g[edges[i].second].push_back(edges[i].first);
            d[edges[i].second]++;
        }
        for(int i = 0; i < n; i++){
            if(d[i] == 1)
                q.push(i);
        }
        while(n > 2){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int t = q.front();
                q.pop();
                n--;
                for(int j = 0; j < g[t].size(); j++){
                    d[g[t][j]]--;
                    if(d[g[t][j]] == 1)
                        q.push(g[t][j]);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

//----------------------------------
//No.312 Burst Balloons
//----------------------------------
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<int> num(len+2, 0);
        int n = 1;
        for(int i = 0; i < len; i++){
            num[n++] = nums[i];
        }
        num[0] = num[n++] = 1;

        vector<vector<int> > dp(n, vector<int>(n));
        int l, r, m, k;
        for(k = 2; k < n; k++){
            for(l = 0; l < n-k; l++){
                r = l + k;
                for(m = l+1; m < r; m++){
                    dp[l][r] = max(dp[l][r], num[l]*num[m]*num[r] + dp[l][m] + dp[m][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};

//----------------------------------
//No.313 Super Ugly Number
//----------------------------------
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int> num = primes;
        vector<int> index(len, 0);
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++){

            int min = INT_MAX;
            int minpos = 0;
            for(int j = 0; j < len; j++){
                if(min > num[j]){
                    min = num[j];
                    minpos = j;
                }
            }
            ans[i] = min;
            for(int j = 0; j < len; j++){
                if(num[j] == min){
                    num[j] = ans[index[j]+1] * primes[j];
                    index[j] += 1;
                }
            }
        }
        return ans[n-1];
    }
};

//----------------------------------
//No.315 Count of Smaller Numbers After Self
//----------------------------------
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        vector<int> sortNum;
        if(nums.size() == 0)
            return ans;

        for(int i = nums.size()-1; i >= 0; i--){
            int L = 0;
            int R = sortNum.size()-1;
            int M = (L+R)/2;
            int pos = L;
            while(L < R){
                if(nums[i] <= sortNum[M]){
                    R = M-1;
                } else {
                    L = M+1;
                }
                M = (L+R)/2;
            }
            pos = L;
            if(sortNum.size() != 0 && sortNum[L] < nums[i])
                pos = L + 1;

            sortNum.insert(sortNum.begin()+pos, nums[i]);
            ans.push_back(pos);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//----------------------------------
//No.316 Remove Duplicate Letters
//----------------------------------
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        int len = s.length();
        if(len == 0)
            return ans;
        unordered_map<char, int> count;
        unordered_map<char, bool> flag;
        stack<char> q;
        for(int i = 0; i < len; i++){
            if(count.find(s[i]) != count.end()){
                count[s[i]]++;
            } else {
                count[s[i]] = 1;
                flag[s[i]] = false;
            }
        }
        q.push(s[0]);
        flag[s[0]] = true;
        for(int i = 1; i < len; i++){
            if(flag[s[i]]){//if has been in the stack
                count[s[i]]--;
                continue;
            }
            while(!q.empty() && q.top() >= s[i] && count[q.top()] > 1){
                count[q.top()]--;
                flag[q.top()] = false;
                q.pop();
            }
            q.push(s[i]);
            flag[s[i]] = true;
        }
        while(!q.empty()){
            ans = q.top() + ans;
            q.pop();
        }
        return ans;
    }
};

//----------------------------------
//No.318 Maximum Product of Word Lengths
//----------------------------------
bool comp(string &a, string &b){
    return a.length() > b.length();
}

class Solution {
private:
    int convert(string &str){
        int ans = 0;
        int n = str.length();
        for(int i = 0; i < n; i++){
            ans = ans | (1 << ((int)(str[i]) - 97));
        }
        return ans;
    }

public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n < 2) return 0;
        sort(words.begin(), words.end(), comp);
        int max = 0;
        int i, j;
        for(i = 0; i < n; i++){
            int a = convert(words[i]);
            int alen = words[i].length();
            for(j = i+1; j < n; j++){
                int b = convert(words[j]);
                if((a | b) == (a ^ b)){
                    int blen = words[j].length();
                    max = max > alen*blen ? max : alen * blen;
                    break;
                }
            }
        }
        return max;
    }
};

//----------------------------------
//No.319 Bulb Switcher
//----------------------------------
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};

//----------------------------------
//No.321 Create Maximum Number
//----------------------------------
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int>ans(k, 0);
        for(int i = 0; i <= k; i++){
            if(i <= m && k-i <= n){
                vector<int> tmp = merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
                if(greater(tmp, 0, ans, 0))
                    ans = tmp;
            }
        }
        return ans;
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int>res(k, 0);
        for(int i = 0, j = 0, r = 0; r < k; r++) {
            res[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return res;
    }
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while(i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        return (j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]));
    }
    vector<int> maxArray(vector<int> nums, int k) {
        vector<int> res(k, 0);
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(j > 0 && nums.size() - i + j > k && nums[i] > res[j - 1])
                j--;
            if(j < k)
                res[j++] = nums[i];
        }
        return res;
    }
};

//----------------------------------
//No.322 Coin Change
//----------------------------------
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> opt(amount+1, INT_MAX-1);
        opt[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] >= 0){
                    opt[i] = min(opt[i-coins[j]] + 1, opt[i]);
                }
            }
        }
        return opt[amount] == INT_MAX-1 ? -1 : opt[amount];
    }
};

//----------------------------------
//No.324 Wiggle Sort II
//----------------------------------
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return ;
        vector<int> num1, num2;
        sort(nums.begin(), nums.end());
        int mid = len%2 == 0 ? len/2 : len/2+1;
        for(int i = 0; i < len; i++){
            if(i < mid){
                num1.push_back(nums[i]);
            } else {
                num2.push_back(nums[i]);
            }
        }
        for(int i = 0; i < len; i++){
            if(i%2){
                nums[i] = num2[num2.size()-1-i/2];
            } else {
                nums[i] = num1[num1.size()-1-i/2];
            }
        }
    }
};

//----------------------------------
//No.326 Power of Three
//----------------------------------
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n <= 0 ? false : n == pow(3, round(log(n) / log(3)));
    }
};

//----------------------------------
//No.328 Odd Even Linked List
//----------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* head1 = head;
        ListNode* head2 = head->next;
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;

        while(ptr1 && ptr2){
            if(ptr2->next)
                ptr1->next = ptr2->next;
            else {
                ptr1->next = head2;
                break;
            }

            ptr1 = ptr1->next;
            if(ptr1){
                ptr2->next = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        if(ptr2 == NULL){
            ptr1->next = head2;
        }
        return head1;
    }
};

//----------------------------------
//No.329 Longest Increasing Path in a Matrix
//----------------------------------
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row, col;
        row = matrix.size();
        if(row == 0) return NULL;
        col = matrix[0].size();

        vector<vector<int>> opt(row, vector<int>(col, 0));
        int ans = INT_MIN;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ans = max(ans, helper(matrix, opt, i, j, row, col));
            }
        }
        return ans;
    }
    int helper(vector<vector<int> >& nums, vector<vector<int> >& opt, int i, int j, int row, int col){
        if(opt[i][j])
            return opt[i][j];
        int Max = 1;
        vector<vector<int> > para = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int n = 0; n < 4; n++){
            int x = i + para[n][0];
            int y = j + para[n][1];
            if(x < 0 || x >= row || y < 0 || y >= col || nums[x][y] <= nums[i][j])
                continue;
            int len = 1 + helper(nums, opt, x, y, row, col);
            Max = max(Max, len);
        }
        opt[i][j] = Max;
        return Max;
    }
};

//----------------------------------
//No.330 Patching Array
//----------------------------------
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1, res = 0, i = 0;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i++];
            } else {
                miss += miss;
                res++;
            }
        }
        return res;
    }
};

//----------------------------------
//No.331 Verify Preorder Serialization of a Binary Tree
//----------------------------------
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<char> deal = splitString(preorder);
        int n = deal.size();
        vector<char> stk;
        for(int i = 0; i < n; i++){
            stk.push_back(deal[i]);
            while(stk.size() >= 3 && stk[stk.size()-1] == '#' && stk[stk.size()-2] == '#' && stk[stk.size()-3] != '#'){
                stk.resize(stk.size()-3);
                stk.push_back('#');
            }
        }
        return stk.size() == 1 && stk[0] == '#';
    }
    vector<char> splitString(string preorder){
        vector<char> res;
        int len = preorder.length();
        string tmp;
        bool isNum = true;
        for(int i = 0; i < len; i++){
            if(preorder[i] == '#')
                isNum = false;
            else if(preorder[i] == ','){
                if(isNum)
                    res.push_back('N');
                else
                    res.push_back('#');
            } else {
                isNum = true;
                continue;
            }
        }
        isNum == true ? res.push_back('N') : res.push_back('#');
        return res;
    }
};

//----------------------------------
//No.332 Reconstruct Itinerary
//----------------------------------
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        unordered_map<string, map<string, int>> m;
        for(auto t : tickets){ //sum of every tickets
            m[t.first][t.second]++;
        }
        string start = "JFK";
        ans.push_back(start);
        helper(start, tickets.size()+1, m, ans);
        return ans;
    }

    bool helper(string cur, const int &n, unordered_map<string, map<string, int>> &m, vector<string> &ans){
        if(ans.size() == n)
            return true;
        for(auto ticket = m[cur].begin(); ticket != m[cur].end(); ticket++){
            if(ticket->second){
                ticket->second--;
                ans.push_back(ticket->first);
                if(helper(ticket->first, n, m, ans))
                    return true;
                ans.pop_back();
                ticket->second++;
            }
        }
        return false;
    }
};

//----------------------------------
//No.334 Increasing Triplet Subsequence
//----------------------------------
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(a == INT_MAX || a >= nums[i])
                a = nums[i];
            else if(b == INT_MAX || b >= nums[i])
                b = nums[i];
            else
                return true;
        }
        return false;
    }
};
//----------------------------------
//No.335 Self Crossing
//----------------------------------
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        for(int i = 0; i < n; i++){
            if(i >= 3 && x[i] >= x[i-2] && x[i-1] <= x[i-3])
                return true;
            if(i >= 4 && x[i]+x[i-4] >= x[i-2] && x[i-1] == x[i-3])
                return true;
            if(i >= 5 && x[i]+x[i-4] >= x[i-2] && x[i-1]+x[i-5] >= x[i-3] && x[i-1] <= x[i-3] && x[i-2] >= x[i-4])
                return true;
        }
        return false;
    }
};

//----------------------------------
//No.337 House Robber III
//----------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int maxValue = 0;
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode* root){
        vector<int> res(2, 0); // 0: select, 1: not select
        if(root == NULL)
            return res;

        vector<int> left  = helper(root->left);
        vector<int> right = helper(root->right);
        res[0] = root->val + left[1] + right[1];
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
};

//----------------------------------
//No.338 Counting Bits
//----------------------------------
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        if(num < 0) return ans;
        for(int i = 0 ; i <= num; i++){
            ans.push_back(NumberOfSetBits(i));
        }
        return ans;
    }
    int NumberOfSetBits(int i){
         // Java: use >>> instead of >>
         // C or C++: use uint32_t
         i = i - ((i >> 1) & 0x55555555);
         i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
         return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
};

//----------------------------------
//No.342 Power of Four
//----------------------------------
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num-1)) == 0) && ((num-1)%3 == 0);
    }
};

//----------------------------------
//No.343 Integer Break
//----------------------------------
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++){
            dp[i] = max(dp[i/2]*dp[i-i/2], max(dp[i-2]*dp[2], dp[i-3]*dp[3]));
        }
        return dp[n];
    }
};

//----------------------------------
//No.344 Reverse String
//----------------------------------
class Solution {
public:
    string reverseString(string s) {
        string ans;
        for(int i = 0; i < s.length(); i++){
            ans = s[i] + ans;
        }
        return ans;
    }
};

//----------------------------------
//No.345 Reverse Vowels of a String
//----------------------------------
class Solution {
public:
    string reverseVowels(string s) {
        if(s == "")
            return "";
        int n = s.length();

        int ptrL = 0, ptrR = n-1;
        while(ptrL < ptrR){
            while(ptrL < ptrR && s[ptrL] != 'a' && s[ptrL] != 'e' && s[ptrL] != 'u' && s[ptrL] != 'o' && s[ptrL] != 'i' && s[ptrL] != 'A' && s[ptrL] != 'E' && s[ptrL] != 'U' && s[ptrL] != 'O' && s[ptrL] != 'I'){
                ptrL++;
            }
            while(ptrL < ptrR && s[ptrR] != 'a' && s[ptrR] != 'e' && s[ptrR] != 'u' && s[ptrR] != 'o' && s[ptrR] != 'i' &&
                s[ptrR] != 'A' && s[ptrR] != 'E' && s[ptrR] != 'U' && s[ptrR] != 'O' && s[ptrR] != 'I'){
                ptrR--;
            }
            char tmp = s[ptrL];
            s[ptrL++] = s[ptrR];
            s[ptrR--] = tmp;
        }
        return s;
    }
};

//----------------------------------
//No.347 Top K Frequent Elements
//----------------------------------
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(hash.find(nums[i]) != hash.end()){
                hash[nums[i]]++;
            } else {
                hash[nums[i]] = 1;
            }
        }
        priority_queue<pair<int, int>> heap;
        for(unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++){
           heap.push({(*it).second, (*it).first});
        }
        for(int i = 0; i < k; i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};

