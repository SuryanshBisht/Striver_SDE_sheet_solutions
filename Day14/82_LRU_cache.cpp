// https://leetcode.com/problems/lru-cache/
class LRUCache {
    int v[10001], freq[10001];
    queue<int> q;
    int limit, qsize;
public:
    LRUCache(int capacity) {
        memset(v, -1, sizeof(v));
        // memset(v, 0, sizeof(freq)); DON'T FORGET THIS MISTAKE TILL YOUR GRAVE
        memset(freq, 0, sizeof(freq));
        // for(int i = 0;i <20 ; i++){
        //     cout<<v[i]<<' '<<freq[i]<<' ';
        // }cout<<endl;
        while(!q.empty()) q.pop();
        limit = capacity;
        qsize = 0;
    }
    
    // void makeLatest(int key){//workds in O(q.size()) :(
    //     queue<int> temp;
    //     while(q.size()){
    //         if(q.front() != key)  temp.push(q.front());
    //         q.pop();
    //     }
    //     q = temp;
    //     q.push(key);
    // }
    
    int get(int key) {
        // queue<int> temp = q;
        // while(!temp.empty()){ cout<<temp.front()<<' ';temp.pop();}cout<<endl;cout<<"si"<<qsize<<endl;
        if(v[key] == -1) return -1;
        //makeLatest();
        q.push(key);
        freq[key]++;
        return v[key];
    }
    
    void put(int key, int value) {
        // queue<int> temp = q;
        // while(!temp.empty()){ cout<<temp.front()<<' ';temp.pop();}cout<<endl;cout<<"si"<<qsize<<endl;
        // new value
        // cout<<"curr"<<v[key]<<endl;
        if(v[key] == -1){
            if(qsize < limit){
                // cout<<"wet\n";
                q.push(key);
                freq[key]++;
                v[key] = value;
                qsize++;
                return;
            }
            
        
            while(--freq[q.front()]){
                q.pop();
                // if(q.empty()) break;
            }

            v[q.front()] = -1;
            q.pop();
            // freq[q.front()]--;
            q.push(key);
            freq[key]++;
            v[key] = value;
            return;
        }
        
        //updating existing value
        v[key] = value;
        freq[key]++;
        q.push(key);
        // makeLatest(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */