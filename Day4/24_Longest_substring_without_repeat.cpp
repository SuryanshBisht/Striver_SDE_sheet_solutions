// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> index;
        
        int n = s.length(), ans = 0, j = 0;
        int i = 0;
        while(i < n){
            if(index[s[i]]){
                j = max(j, index[s[i]]);
            }
            index[s[i]] = i + 1;
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};