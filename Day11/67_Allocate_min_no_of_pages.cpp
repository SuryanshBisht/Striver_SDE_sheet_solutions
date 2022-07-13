// https://www.interviewbit.com/problems/allocate-books/
//quite the joke is that I did this q under 9 min on first attempt while on the second
// attempt, I had to struggle heavily on the same problem.
int Solution::books(vector<int> &v, int b) {
    int n = v.size();
    if(b > n) return -1;
    long long int sum = 0;
    for(auto x:v) sum += (long long)x;
    int mxe = *max_element(v.begin(), v.end());
    long long l = mxe, r = sum;
    while(l <= r){
        long long studs = 1, mid = (l + r) / 2;
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += v[i];
            if(sum > mid){
                studs++;
                sum = v[i];
            }
        }
        (studs > b) ? l = mid + 1:r = mid - 1;
    }
    // if(r < mxe) l =  -1; still don't understand why we don't do this
    return l;
}


// my previous solution, that I came up in 9 minutes !!
int Solution::books(vector<int> &v, int b) {
    long long int l = *max_element(v.begin(), v.end()), r = 1e10, ans = -1, n = v.size();
    // cout<<l<<endl;
    if(b > n){
        return -1;
    }
    while(l <= r){
        long long int sum = 0, days = 1, mid = (l + r) / 2;
        for(int i = 0; i<n;i++){
            if(sum + v[i] > mid){
                sum = v[i];
                days++;
            }
            else{
                sum += v[i];
            }
        }
        if(days > b){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }

    return ans;
}
