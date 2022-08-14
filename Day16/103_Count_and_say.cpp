// https://leetcode.com/problems/count-and-say/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n - 1), res = "";
        
        s += 'a';
        int count = 1, len = s.length();
        for(int i = 1; i < len; i++){
            if(s[i] == s[i - 1]){
                count++;
                continue;
            }
            res += to_string(count);
            res += s[i - 1];
            count = 1;
        }
        return res;
    }
};