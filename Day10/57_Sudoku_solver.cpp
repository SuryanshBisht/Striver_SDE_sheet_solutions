// https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    bool solve(vector<vector<char>> &board, int x, int y){
        if(x == 9 && y == 0) return true;
        if(board[x][y] != '.'){
            if(y < 8){
                return (solve(board, x, y + 1));
            }
            else{
                return(solve(board, x + 1, 0));
            }
        }
        
        unordered_map<char,bool> used;
        int ix = 3 * (x / 3), iy = 3 * (y / 3);
        int jx = ix + 2, jy = iy + 2;
        
        for(int i = 0; i < 9; i++){
            (used[board[x][i]]) = 1;
        }
        
        for(int i = 0; i < 9; i++){
            (used[board[i][y]]) = 1;
        }
        
        for(int i = ix; i <= jx; i++){
            for(int j = iy; j <= jy; j++){
                used[board[i][j]] = 1;
            }
        }
        
        for(int i = 1; i <= 9; i++){
            if(!used['0' + i]){
                board[x][y] = '0' + i;
                if(y < 8){
                    if(solve(board, x, y + 1)) return true;
                }
                else{
                    if(solve(board, x + 1, 0)) return true;
                }
                board[x][y] = '.';
            }
        }
        
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};