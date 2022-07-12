// https://www.interviewbit.com/problems/matrix-median/
int minIndex(vector<int> &v, int x){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int maxIndex(vector<int> &v, int x){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
 
    return l;
}

int Solution::findMedian(vector<vector<int> > &v) {
    int n = v.size(), m = v[0].size();
    double mid1 = -1, mid2 = -1;
    // for(int i = 0; i < n; i++){
        //for some reason we just need this big loop in here to be fine
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2, flag = 0;
        int minInd = 0, maxInd = 0;
        for(int j = 0; j < n; j++){
            // if(j == i) continue;
            int mi = minIndex(v[j], mid), mx = maxIndex(v[j], mid);
            if(v[j][min(n - 1, mi)] == mid || v[j][max(0, mx - 1)] == mid) flag = 1;
            minInd += mi;
            maxInd += mx;
        }
        
        if(maxInd <= (m * n) / 2) l = mid + 1;
        else if(minInd > (m * n) / 2 ) r = mid - 1;
        else if(flag) return mid; // and also need to put it here only, time comp is pretty strict in here.
        else l = mid + 1;
    }
    
    if(mid1 != -1) return mid1;
    
    l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2, flag = 0;
        int minInd = 0, maxInd = 0;
        for(int j = 0; j < n; j++){
            // if(j == i) continue;
            int mi = minIndex(v[j], mid), mx = maxIndex(v[j], mid);
            if(v[j][min(n - 1, mi)] == mid || v[j][max(0, mx - 1)] == mid) flag = 1;
            minInd += mi;
            maxInd += mx;
        }
        
        if(maxInd <= (m * n) / 2) l = mid + 1;
        else if(minInd > (m * n) / 2 ) r = mid - 1;
        else if(flag) mid1 = mid;
        else r = mid - 1;
    }
    // if(mid1 != -1) break;
    // }
    
    if((m * n) & 1){
        return mid1;
    }
    
    //not needed in this q though
    l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2, flag = 0;
        int minInd = 0, maxInd = 0;
        for(int j = 0; j < n; j++){
            // if(j == i) continue;
            int mi = minIndex(v[j], mid), mx = maxIndex(v[j], mid);
            if(v[j][min(n - 1, mi)] == mid || v[j][max(0, mx - 1)] == mid) flag = 1;
            minInd += mi;
            maxInd += mx;
        }
        
        if(maxInd <= (m * n) / 2) l = mid + 1;
        else if(minInd > (m * n) / 2 ) r = mid - 1;
        else if(flag) mid2 = mid;
        else r = mid - 1;
    }
    
    if(mid2 != -1) return (mid1 + mid2) / 2;
    
    l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2, flag = 0;
        int minInd = 0, maxInd = 0;
        for(int j = 0; j < n; j++){
            // if(j == i) continue;
            int mi = minIndex(v[j], mid), mx = maxIndex(v[j], mid);
            if(v[j][min(n - 1, mi)] == mid || v[j][max(0, mx - 1)] == mid) flag = 1;
            minInd += mi;
            maxInd += mx;
        }
        
        if(maxInd <= (m * n) / 2) l = mid + 1;
        else if(minInd > (m * n) / 2 ) r = mid - 1;
        else if(flag) mid2 = mid;
        else r = mid - 1;
    }
    
    return (mid1 + mid2) / 2;
}

/*
old Solution
int Solution::findMedian(vector<vector<int> > &v) {
    int n = v.size(), m = v[0].size();
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2, low = 0, up = 0;
        for(int i = 0; i < n; i++){
            int a = 0, b = m - 1;
            while(a <= b){
                int mi = (a + b)  /2;
                if(v[i][mi] < mid){
                    a = mi + 1;
                }
                else{
                    b = mi - 1;
                }
            }
            low += b + 1;

            a = 0, b = m - 1;
            while(a <= b){
                int mi = (a + b)  / 2;
                if(v[i][mi] <= mid){
                    a = mi + 1;
                }
                else{
                    b = mi - 1;
                }
            }
            up += b + 1;
        }
        if(low <= n*m/2  && up >= n*m / 2 + 1){
            return mid;
        }
        if(up < n*m/ 2 + 1){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    
    return -1;
}
*/