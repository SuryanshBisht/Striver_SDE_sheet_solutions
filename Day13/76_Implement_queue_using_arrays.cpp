// https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
class Queue {
    int limit, l, r;
    int *q;
    
public:
    Queue() {
        limit = 5000;
        q = new int[5000];
        l = 0;
        r = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return l == r;
    }

    void enqueue(int data) {
        q[r] = data;
        r++;
    }

    int dequeue() {
        if(l == r) return -1;
        l++;
        return q[l - 1];
    }

    int front() {
        if(l == r) return -1;
        return q[l];
    }
};