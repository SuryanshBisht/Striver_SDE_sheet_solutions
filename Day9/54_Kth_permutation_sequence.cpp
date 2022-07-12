// https://leetcode.com/problems/permutation-sequence/
// just repeating next perm k - 1 times on smallest string, O(nk) still better than 
// calculating all of 'em

// since n <= 9, in this case even using factorials(ie just implementing old math) works as well
string nextPerm(string s){
    int n = s.length();
    
    int i = n - 1;
    while(i > 0 && s[i] < s[i - 1]) i--;
    int ind = i - 1, j = i ;
    i = n - 1;
    while(i > 0 && s[ind] > s[i]) {
        i--;
    }
    swap(s[ind] ,s[i]);
    i = n - 1;
    while(j < i) {
        swap(s[j], s[i]);
        j++ , i--;
    }
    
    // cout<<s<<endl;
    return s;
    
}

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        for(int i = 0 ;i < n;i++){
            ans += char('0' + i + 1);
        }
        
        for(int i = 1; i < k;i++){
            ans = nextPerm(ans);
        }
        
        return ans;
    }
};