// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1
#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
bool cmp(pii a, pii b){return a.ff > b.ff;}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pii, vector<pii> , greater<pii>> minH;
    vector<int> ind(k, 0), res;
    for(int i = 0; i < k; i ++){
        minH.push(make_pair(kArrays[i][0], i));
    }
    
    while(!minH.empty()){
        int arrNo = minH.top().ss, value = minH.top().ff;
        minH.pop();
        res.push_back(value);
        ind[arrNo]++;
        if(ind[arrNo] < kArrays[arrNo].size()){
            minH.push(make_pair(kArrays[arrNo][ind[arrNo]], arrNo));
        }
    }
    return res;
}
