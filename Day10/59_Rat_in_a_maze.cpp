// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
// PERSONIFICATION OF BEAUTY ITSELF! 
class Solution{
    public:
    vector<string> ans;
    string s;
    int a[4] = {1, -1, 0, 0}, b[4] = {0, 0, 1, -1};
    char c[4] = {'D','U', 'R', 'L'};
    bool canPass(vector<vector<int>> &v,vector<vector<int>> &visited, int x, int y, int n){
        if(v[x][y] == 0) return false;
        if(x == n - 1 && y == n - 1){
            ans.push_back(s);
            return true;
        }
        bool flag = 0;
        for(int i = 0; i < 4; i++){
            if(x + a[i] < n && x + a[i] >= 0 && y + b[i] < n && 
                y + b[i] >= 0 && !visited[x + a[i]][y + b[i]])
            {
                // cout<<x + a[i]<< ' '<<y + b[i]<<'\n';
                visited[x + a[i]][y + b[i]] = 1;
                s += c[i];
                if(canPass(v, visited, x + a[i], y + b[i], n)) flag = 1;
                visited[x + a[i]][y + b[i]] = 0;
                s.pop_back();
            }
        }
        
        return flag;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
        vector<vector<int>> visited(n, vector<int> (n));
        visited[0][0] = 1;
        if(canPass(m,visited, 0, 0, n)) return ans;
        return {"-1"};
    }
};
