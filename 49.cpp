class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        vector<vector<string>> ans;
        
        for(string word: strs){
            string s= word;
            s= counting_sort(s);
            ump[s].push_back(word);
        }
        
        for(auto it= ump.begin(); it!= ump.end(); ++it){
            ans.push_back(it->second);   
        }
        
        return ans;
    }
    
    // counting sort to increase effeciency
    string counting_sort(string s){
        int f[26]= {0};
        
        for(char c: s){
            f[c-'a']++;
        }
        
        s= "";
        
        for(int i= 0; i< 26; ++i){
            for(int j= 0; j< f[i]; ++j){
                s+= char(i + 'a');
            }
        }
        
        return s;
    }
};