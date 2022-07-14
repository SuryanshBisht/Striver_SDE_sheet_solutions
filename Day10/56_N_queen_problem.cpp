// https://leetcode.com/problems/n-queens/submissions/
class Solution {
    vector<vector<string>> boards;
    vector<string> board;
public:
    void nQueens(int row, int n){
        if(row == n){
            for(auto x:board){
                for(auto y:x) cout<<y<<' ';
                cout<<'\n';
            }
            boards.push_back(board);
            return;
        }
        string s = string(n, '.'); // important line as if its global, then previous row will be inherited by s
        // in next call

        for(int i = 0 ; i < n; i++){
            bool valid = true;
            for(int j = row - 1; j >= 0; j--){
                if(board[j][i] == 'Q'){
                    valid = false;
                    break;
                }
            }
            
            if(!valid) continue;
            
            int r = row - 1, c = i - 1;
            while(r >= 0 && c >= 0){
                if(board[r][c] == 'Q'){valid = false;break;}
                r--;
                c--;
            }
            
            if(!valid) continue;
            
            r = row - 1, c = i + 1;
            while(r >= 0 && c < n){
                if(board[r][c] == 'Q'){valid = false;break;}
                r--;
                c++;
            }
            
            if(!valid) continue;
            
            s[i] = 'Q';
            board.push_back(s);
            nQueens(row + 1, n);
            s[i] = '.';
            board.pop_back();
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        boards.clear();
        nQueens(0, n);
        return boards;
    }
};