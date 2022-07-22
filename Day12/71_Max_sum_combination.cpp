// https://www.interviewbit.com/problems/maximum-sum-combinations/
typedef pair<int,int> pii;
typedef pair<int, pii> ppi;
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<ppi> maxH;
    
    vector<int> v;
    int n = A.size();
    maxH.push({A.back() + B.back(), {n - 1, n - 1}});
    set<pii> s;
    s.insert({n - 1, n - 1});
    // unordered_map<int, pair<int,int>> ind;//same sum can occur multiple times so conflicts;
    // ind[(A.back() + B.back()),] = {n - 1, n - 1};
    while(C--){
        v.push_back(maxH.top().first);
        int x = maxH.top().second.first,  y = maxH.top().second.second;
        maxH.pop();
        if(y > 0 && x >= 0 && s.find({x, y - 1}) == s.end()) {
            maxH.push({A[x] + B[y - 1], {x, y - 1}});
            s.insert({x, y - 1});
            // ind[A[x] + B[y - 1]]  = {x, y - 1};
        }
        if(x > 0 && y >= 0 && s.find({x - 1, y}) == s.end()){ 
            maxH.push({A[x - 1] + B[y], {x - 1, y}});
            s.insert({x - 1, y});
            // ind[A[x - 1] + B[y]] = {x - 1, y};
        }
    }

    // for(auto x:v)cout<<x<<' ';cout<<endl;
    return v;
}

    // int freqA[2001], freqB[2001], heapfreq[2001];
    // memset(freqA, 0, sizeof(freqA));
    // memset(freqB, 0, sizeof(freqB));
    // memset(heapfreq, 0, sizeof(heapfreq));
    // int size = 0;
    // priority_queue<int,vector<int>, greater<int>> minH;
    // for(auto x:A) freqA[x]++;
    // for(auto x:B) freqB[x]++;
    // for(int sum = 2; sum <= 2e3; sum++){
    //     for(int x = 1; x < sum; x++){
    //         if(freqA[x] == 0 || freqB[sum - x] == 0) continue;
    //         if(heapfreq[sum] == 0) minH.push(sum);
    //         //wrong coz, if sum is already in heap, even after updating its heapfreq, 
    //         //its relative position doesn't changes
    //         heapfreq[sum] += freqA[x] * freqB[sum - x];
    //         size += freqA[x] * freqB[sum - x];
    //         while(size > C){
    //             if(heapfreq[minH.top()] > size - C){
    //                 heapfreq[minH.top()] -= size - C;
    //                 size = C;
    //             }
    //             else {
    //                 size -= heapfreq[minH.top()];
    //                 heapfreq[minH.top()] = 0;
    //                 minH.pop();
    //             }
    //         }
    //         cout<<heapfreq[minH.top()] <<' ';
    //         cout<<minH.top()<<' '<<size<<endl;
    //     }
    // }