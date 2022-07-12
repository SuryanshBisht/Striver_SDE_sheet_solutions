// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
static bool cmp(Job &a, Job &b){
    return a.dead < b.dead;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr, arr + n, cmp);
        int t = arr[n - 1].dead, profit = 0, jobs = 0;
        priority_queue<int> pq;
        int i = n - 1;
        while(i >= 0){
            if(arr[i].dead != t){
                int dur = t - arr[i].dead;
                t = arr[i].dead;
                while(dur-- && !pq.empty()){
                    profit += pq.top();
                    pq.pop();
                    jobs++;
                }
            }
            else{
                pq.push(arr[i].profit);
                i--;
            }
        }
        
        while(!pq.empty() && t > 0){
            profit += pq.top();
            pq.pop();
            jobs++;
            t--;
        }
        
        return {jobs, profit};
    } 
};