// https://www.codingninjas.com/codestudio/problems/983635?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
vector<string> ans;
void solve(string s, vector<string> &dict, string str){
    int n = s.length();
    if(s == ""){
        ans.push_back(str.substr(1, n - 1));
        return;
    }
    string temp, f;
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        temp += c;
        for(auto x:dict){
            if(temp == x){
                solve(s.substr(i + 1, n - i - 1), dict, str + ' ' + temp);
            }
        }
    }
    
    return;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    ans.clear();
    solve(s, dictionary, "");
    return ans;
}