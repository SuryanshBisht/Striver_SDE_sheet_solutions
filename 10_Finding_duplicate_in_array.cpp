//https://leetcode.com/problems/find-the-duplicate-number/submissions/
// basically we're trying to find the starting point of a loop, because
// at the starting point, there will be two elements which point to it therefore
// its the repeating number.
// this algo technically fails if zero is there in the array, as the loop starts from index 0
// there won't be a number from which we reach 0, we just start from there, 
// but surely that isn't the case with this q as numbers belong from [1, n];
// also note by pigeonhole principle there'll ALWAYS be REPETITIONS
class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = 0, fast = 0, slow1 = 0;
        
        while(v[fast] < v.size() && slow < v.size()){
            slow = v[slow];
            fast = v[v[fast]];
            if(slow == fast){
                while(slow != slow1){
                    slow = v[slow];
                    slow1 = v[slow1];
                }
                
                return slow;
            }
        }
        return -1;
    }
};

