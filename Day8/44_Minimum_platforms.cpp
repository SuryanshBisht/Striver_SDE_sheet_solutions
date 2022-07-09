// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	queue<int> q;
        int res = 0;
        sort(arr, arr + n);
        sort(dep, dep + n);
        //could've done the non - queue implementation as well, duh
        for(int i = 0; i < n;i++){
            q.push(i);
            while(dep[q.front()] < arr[i]){
                q.pop();
            }
            if(res < q.size()) res = q.size();
        }
        
        return res;
    }
};