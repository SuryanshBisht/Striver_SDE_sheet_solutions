// https://leetcode.com/problems/trapping-rain-water/submissions/

//implementing leftMax and rightMax by 2 pointers
// can't believe my eyes, even the memory isn't different(I guess that's the reason it 
// got accepted with O(n) in the first place)
class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = height[0], maxRight = height.back(), n = height.size(), water = 0;
        int l = 0, r = n - 1;
        
        while(l < r){
            if(height[l] < height[r]){
                maxLeft = max(maxLeft, height[l]);
                water += maxLeft - height[l];
                l++;
            }
            
            else{
                maxRight = max(maxRight, height[r]);
                water += maxRight - height[r];
                r--;
            }
        }
        
        return water;
    }
};
// fadu explanation, 
// baadal pe baith jao, array me iterate karo aur varsha krte raho, 
// for each element you'll fill the share till you can ie. the max height you've encountered
// mathematically maxHeight - height[i]
// till now(that will act as wall to store water), only till you reach the tallest, from there 
// on things only go downhill, and so now you need to start filling from n - 1 to tallest
// 
// a COOL way to do this stuff is with two pointers as both pointers automatically meet at 
// the tallest building



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