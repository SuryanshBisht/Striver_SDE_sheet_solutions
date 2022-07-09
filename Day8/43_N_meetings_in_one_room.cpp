// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({end[i], start[i]});
        }
        
        sort(v.begin(), v.end());
        // for(auto x: v) cout<<x.first<<' '<<x.second<<endl;
        int i = 0, j = 0, meets = 0;
        while(i < n){
            meets++;
            while(v[j].second <= v[i].first){ // WTF just coz I didn't read that start and end times have to be different
                j++;
                if(j == n) {
                    break;
                }
            }
            i = j;
        }
        
        return meets;
    }
};