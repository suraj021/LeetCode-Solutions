class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        int i= 0;

        for(int n: arr1) mp[n]++;
        
        for(int n: arr2){
            while(mp[n]){
                arr1[i]= n;
                mp[n]--;
                i++;
            }
        }
        
        for(auto it: mp){
            if(mp[it.first]){
                while(it.second){
                    arr1[i]= it.first;
                    it.second--;
                    i++;
                }
            }
        }
        
        return arr1;
    }
};