// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while( l <= r){
            int mid = (l + r) / 2;
            if(matrix[mid / m][mid % m] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        if(l == m * n) return 0;
        return (target == matrix[l / m][l % m]);
    }
};