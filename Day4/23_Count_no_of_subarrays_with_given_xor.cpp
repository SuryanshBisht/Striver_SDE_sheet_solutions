// https://www.interviewbit.com/problems/subarray-with-given-xor/
//ans for this problem is
int Solution::solve(vector<int> &v, int k) {
    unordered_map<int,int> m;
    int xr = 0, res = 0;
    m[0]++;
    for(int i = 0; i < v.size(); i++){
        xr ^= v[i];
        res += m[xr ^ k];
        m[xr]++;
    }
    return res;
}

// accidently wrote the code for 'longest subseq with given xor'
int Solution::solve(vector<int> &v, int k) {
    unordered_map<int,int> m;
    int xr = 0, res = 0;
    for(int i = 0; i < v.size(); i++){
        xr ^= v[i];
        if(m[xr] == 0){
            m[xr] = i + 1;
        }
        if(m[xr ^ k]){
            res = max(res, i + 1 - m[xr ^ k]);
        }
        if(xr == k){
            res = max(res, i + 1);
        }
    }
    return res;
}
