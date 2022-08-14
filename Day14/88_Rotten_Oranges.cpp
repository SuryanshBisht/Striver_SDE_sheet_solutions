// https://leetcode.com/problems/rotting-oranges/
class Solution {
public:    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> days(n, vector<int>(m, -1));
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    days[i][j] = 0;
                }
            }
        }
        int xi[] = {1, -1, 0, 0}, yi[] = {0, 0, 1, -1};
        // int ans = 0;
        while(q.size()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4 ; i++){
                int X = x + xi[i], Y = y + yi[i];
                if(
                    X >= 0 && X < n && Y >= 0 && Y < m
                   && grid[X][Y] == 1 
                )
                {
                    if(days[X][Y] == -1) {
                        days[X][Y] = days[x][y] + 1;
                        q.push({X, Y});     
                    }
                    else if(days[X][Y] > days[x][y] + 1){
                        days[X][Y] = min(days[X][Y], days[x][y] + 1);
                        q.push({X, Y});
                    }
                
                }
            }
    
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ans = max(days[i][j], ans);
                    if(days[i][j] == -1) return -1;
                }
            }
        }
        
        return ans;
    }
};