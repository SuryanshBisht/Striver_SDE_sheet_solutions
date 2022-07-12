// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
bool cmp(Item &a, Item&b){
    double wa = a.weight, wb = b.weight, va = a.value, vb = b.value;
    return (va / wa > vb / wb);
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        double value = 0, left = W;
        int i = 0;
        while(true){
            double v = arr[i].value;
            if(arr[i].weight <= left){
                value += v;
            }
            else break;
            left -= arr[i].weight;
            i++;
            if(i == n) break;
        }
        if(left && i < n){
            double v = arr[i].value, weight = arr[i].weight;
            value += (v * left) / weight;
        }
        return value;
    }
        
};