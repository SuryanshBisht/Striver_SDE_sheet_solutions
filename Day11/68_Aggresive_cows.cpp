// https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--)
    {
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i = 0; i < n;i++){ cin>>v[i]; }
    sort(v.begin(), v.end());

    int l = 1, r = v.back() - v[0];
    while(l <= r){
        int mid = (l + r)  / 2, cows = 1, ind = 0;

        for(int i = 1; i < n; i++){
            if(v[i] - v[ind] >= mid){
                ind = i;
                cows++;
            }
        }

        (cows >= c) ? l = mid + 1: r = mid - 1;
    }

    cout<<r<<'\n';
    }
    return 0;
}