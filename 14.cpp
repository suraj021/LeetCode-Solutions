class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if( strs.size() == 0 )  return "";
        if( strs.size() == 1 )  return strs[0];
        
        int len= 0;
        
        int minLen= INT_MAX;
        
        for(int i= 0; i< strs.size(); ++i){
            minLen= min(minLen, (int)strs[i].length());
        }
        
        for(int l= 0; l < minLen; ++l){
            bool exists= true;
            char c= strs[0][l];
            for(int i= 1; i< strs.size(); ++i){
                if(strs[i][l] != c) {
                    exists= false;
                    break;
                }
            }
            
            if(!exists) break;
            len= l+1;
        }
        
        return strs[0].substr(0, len);
    }
};