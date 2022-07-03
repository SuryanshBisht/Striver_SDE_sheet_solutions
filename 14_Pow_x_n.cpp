// don't underestimate
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1, base = x;
        if(base == 1) return base;
        long long int power = n; // to get rid of abs(INT_MIN) && 
        // not double to prevent other problems with operators
        power = abs(power);// to deal with -ve powers, yep they're in too
        while(power){
            if(power & 1){
                res *= base;
                power--;
            }
            else{
                base *= base;
                power /= 2;
            }
        }
        
        if(n >= 0)  return res;
        else return 1 / res;
    }
};