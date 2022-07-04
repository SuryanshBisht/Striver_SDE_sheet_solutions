

//implementing leftMax and rightMax by 2 pointers


//first solution O(n) time, O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = height[0], n = height.size(), water = 0;
        vector<int> rightMax(n);
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(height[i + 1], rightMax[i + 1]);
        }
        
        for(int i = 1 ; i < n; i++){
            water += max(0, min(leftMax, rightMax[i]) - height[i]);
            leftMax = max(leftMax, height[i]);
        }
        
        return water;
    }
};