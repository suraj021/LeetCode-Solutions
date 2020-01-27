class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n= arr.size();
        int candidates[]= {arr[n/4], arr[n/2], arr[3*n/4]};
        
        for(int cand: candidates){
            auto lb= lower_bound(arr.begin(), arr.end(), cand);
            auto rb= upper_bound(arr.begin(), arr.end(), cand);
            
            if( 4*distance(lb, rb) > n)
                return cand;
        }
        
        return -1;
    }
};