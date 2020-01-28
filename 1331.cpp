class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a(arr);
        map<int, int> rank;
        
        sort(a.begin(), a.end());
        
        for(int i: a){
            rank[i]= (rank[i] == 0) ? rank.size() : rank[i];
        }
        
        for(int i= 0; i< arr.size(); ++i){
            arr[i]= rank[arr[i]];
        }
        
        return arr;
    }
};