class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int mindiff= INT_MAX;

        sort(arr.begin(), arr.end());
        
        for(int i= 1; i< arr.size(); ++i){
            mindiff= min(mindiff, abs(arr[i]-arr[i-1]));
        }
        
        for(int i= 1; i< arr.size(); ++i){
            if(abs(arr[i]-arr[i-1]) == mindiff){
                ans.push_back(vector<int>{arr[i-1], arr[i]});
            }
        }
        
        return ans;
    }
};