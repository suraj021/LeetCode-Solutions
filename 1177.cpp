class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> presum;
        vector<int> tmp(26, 0);
        
        presum.push_back(tmp);
        
        for(char c: s){
            tmp[c-'a']++;
            presum.push_back(tmp);
        }
                
        vector<bool> ans;
        
        for(auto q: queries){
            int lo= q[0], hi= q[1], k= q[2];
            int unmatch= 0;
            for(int i= 0; i< 26; ++i){
                unmatch+= (presum[hi+1][i] - presum[lo][i])%2;
            }
        
            int slen= hi-lo+1;
            
            ans.push_back(unmatch-slen%2 <= 2*k);
        }
        
        return ans;
    }
};