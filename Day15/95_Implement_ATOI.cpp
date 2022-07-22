// https://leetcode.com/problems/string-to-integer-atoi/submissions/
class Solution {
public:
    int myAtoi(string s) {
        int start = 0, end = 0, flag = 0;
        for(int i = 0; i < s.length(); i++){
            if(flag == 0){
                if(s[i] == '+' || s[i] == '-' || (s[i] <= '9' && s[i] >= '0')){
                    start = i;
                    end = i;
                    flag = 1;
                }
                else if(s[i] != ' ') break;
            }
            else if(flag && (s[i] <= '9' && s[i] >= '0')) {
                end = i;
            }
            else break;
        }
        
        bool neg = 0;
        // cout<<start<<' '<<end<<endl;
        if(s[start] == '-') {neg = 1;start++;}
        else if(s[start] == '+') {start++;}
        
        if(s[start] > '9' || s[start] < '0' ) return 0;
        cout<<start<<' '<<end<<endl;
        string a = s.substr(start, end - start + 1);
        cout<<a<<endl;

        long long int num = 0;
        for(int i = 0; i < a.length(); i++){
            num += a[i] - '0';
            if(!neg && num > (long long int)INT_MAX){
                return INT_MAX;
            }
            if(neg && -num < (long long int)INT_MIN) return INT_MIN;
            num *= 10;
        }
        
        num /= 10;
        if(neg) num = -num;
        int res = 0;        
        res = num;
        return res;
    }
};  