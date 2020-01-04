class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int untilMax= -1;
        
        for(int i= arr.size()-1; i>= 0; --i){
            int a= arr[i];
            arr[i]= untilMax;
            untilMax= max(untilMax, a);
        }
        
        return arr;
    }
};