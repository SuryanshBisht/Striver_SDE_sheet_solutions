// https://leetcode.com/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        for(int i = 0; i + m - 1 < n; i++){
            int flag = 1;
            for(int j = i; j < i + m; j++){
                if(haystack[j] == needle[j - i]) continue;
                else flag = 0;
            }
            if(flag)  return i;
        }
        return -1;
    }
};