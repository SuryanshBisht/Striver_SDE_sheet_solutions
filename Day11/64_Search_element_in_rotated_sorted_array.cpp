https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > nums.back()){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        int pivot = r;
        
        if(target > nums.back()){
            l = 0, r = pivot;
        }
        else{
            l = pivot + 1, r = nums.size() - 1;
        }
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return -1;
    }
    
};