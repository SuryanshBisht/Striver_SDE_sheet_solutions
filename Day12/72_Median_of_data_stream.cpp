// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
    priority_queue<double> maxH;
    priority_queue<double,vector<double>, greater<double>> minH;
public:
    MedianFinder() {// another better way is to just skip your own constructor,
        // as the simple work of initialiation of blanks is done by default contructor
        maxH.push(INT_MIN);
        minH.push(INT_MAX);
        maxH.pop();
        minH.pop();
    }
    
    void addNum(int num) {
        if(num < maxH.top()){
            maxH.push(num);
            while(maxH.size() - minH.size() > 1){
                minH.push(maxH.top());
                maxH.pop();
            }
        }
        else{
            minH.push(num);
            while(minH.size() - maxH.size() > 1){
                maxH.push(minH.top());
                minH.pop();
            }
        }
    }
    
    double findMedian() {
        if(minH.size() > maxH.size()) return minH.top();
        if(minH.size() < maxH.size()) return maxH.top();
        return (minH.top() + maxH.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */