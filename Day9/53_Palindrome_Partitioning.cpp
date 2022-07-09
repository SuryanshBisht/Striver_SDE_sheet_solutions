// https://leetcode.com/problems/palindrome-partitioning/submissions/
bool isPalindrome(string s){
    int l = 0, r = s.length() - 1;
    while(l < r){
        if(s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

void part(vector<vector<string>> &ans, vector<string> &v, string s, int i){
    int n = s.length();
    if(i == n){
        ans.push_back(v);
        return;
    }
    
    int j = i;
    string temp;
    while(j < n){
        temp += s[j];
        if(isPalindrome(temp)){ 
            v.push_back(temp);
            part(ans, v, s, j + 1);
            v.pop_back();
        }
        j++;
    }
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> v;
        part(ans, v, s, 0);
        return ans;
    }
};