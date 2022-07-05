// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

typedef long long ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> v;
    ll diff = 0, sum = 0, linSum = 0 , sqSum = 0, n = A.size();
    for(int i = 0; i < n; i ++){
        ll x = A[i];
        linSum += x;
        sqSum += x * x;
    }
    
    diff = (n * (n + 1)) / 2  - linSum;
    sum = (((n * (n + 1) * (2 * n + 1)) / 6) - sqSum) / diff;
    
    
    
    v.push_back( (sum - diff) / 2);
    v.push_back( (sum + diff) / 2);
    
    
    return v;
}
