class Solution {
public:
    void sortColors(vector<int>& v) {
        int zero = 0, two = 0;
        for(int  i = 0 ; i < v.size() ; i++){
            if(v[i] == 2) two++;
            if(v[i] == 0) zero++;
        }
        
        for(int i = 0; i < v.size(); i++){
            if(i < zero){
                v[i] = 0;
            }
            // else if(i > v.size() - two - 1){ why does this doesn't works??
            else if(i >= v.size() - two){
                v[i] = 2;
            }
            else{
                v[i] = 1;
            }
        }
        
    }
};