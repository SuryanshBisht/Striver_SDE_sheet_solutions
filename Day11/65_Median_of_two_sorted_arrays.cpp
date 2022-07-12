// https://leetcode.com/problems/median-of-two-sorted-arrays/
int minIndex(vector<int> &v, int x){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = (l + r)  /2;
        if(v[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int maxIndex(vector<int> &v, int x){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        int mid = (l + r)  /2;
        if(v[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

double middle(vector<int> &v, vector<int> &u, int n, int m){
    int l = 0, r = n - 1;
    double mid1 = -1, mid2 = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid + maxIndex(u, v[mid]) < (m + n) / 2) l = mid + 1;
        else if(mid + minIndex(u, v[mid]) > (m + n) / 2) r = mid - 1;
        else {
            mid1 = v[mid];
            break;
        }
    }
    l = 0, r = m - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid + maxIndex(v, u[mid]) < (m + n) / 2) l = mid + 1;
        else if(mid + minIndex(v, u[mid]) > (m + n) / 2) r = mid - 1;
        else {
            mid1 = u[mid];
            break;
        }
    }
    
    if((m + n) & 1) return mid1;
    l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid + maxIndex(u, v[mid]) < (m + n) / 2 - 1) l = mid + 1;
        else if(mid + minIndex(u, v[mid]) > (m + n) / 2 - 1) r = mid - 1;
        else {
            mid2 = v[mid];
            break;
        }
    }
    
    l = 0, r = m - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(mid + maxIndex(v, u[mid]) < (m + n) / 2 - 1) l = mid + 1;
        else if(mid + minIndex(v, u[mid]) > (m + n) / 2 - 1) r = mid - 1;
        else {
            mid2 = u[mid];
            break;
        }
    }
    
    return (mid1 + mid2) / 2;
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return middle(nums1, nums2, nums1.size(), nums2.size());
        else return middle(nums2, nums1, nums2.size(), nums1.size());
    }
};
