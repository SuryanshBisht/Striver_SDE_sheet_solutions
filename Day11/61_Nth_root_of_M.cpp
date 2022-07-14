// https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
double findNthRootOfM(int n, long long m) {
	double l = 0, r = double(m), decimal = 1e-7;
    while(l <= r){
        double mid = (l + r) / 2.0, product = 1.0;
//         cout<<mid<<'\n';
        for(int i = 0; i < n;i++){
            product *= mid;
        }
        (product < double(m)) ? l = mid + decimal:r = mid - decimal; 
    }
//     double x = r *1e6;
//     r *= 1e6;
//     x = floor(x);
//     x = r - x;
//     if(x >= 0.5) r++;
//     r *= 1e-6;
    return r;
}
