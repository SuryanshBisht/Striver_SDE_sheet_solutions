// https://leetcode.com/problems/valid-anagram/submissions/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freqs, freqt;
        for(auto c:s) freqs[c]++;
        for(auto c:t) freqt[c]++;
        bool flag = 1;
        for(char c = 'a'; c <= 'z'; c++){
            if(freqs[c] == freqt[c]) continue;
            else flag = 0;
        }
        for(char c = 'A'; c <= 'Z'; c++){
            if(freqs[c] == freqt[c]) continue;
            else flag = 0;
        }
        return flag;
    }
};