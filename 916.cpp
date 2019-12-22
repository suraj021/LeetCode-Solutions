class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> wcount(26, 0), tmp(26);
        vector<string> ans;
        
        for(string word: B){
            tmp= get_count(word);
            for(int i= 0; i< 26; ++i){
                wcount[i]= max(wcount[i], tmp[i]);
            }
        }
        
        for(int i= 0; i< 26; ++i){
            if(wcount[i] > 0){
                cout << char('a' + i) << " " << wcount[i] << endl;
            }
        }
        
        for(string word: A){
            tmp= get_count(word);
            bool subset= true;
            for(int i= 0; i< 26; ++i){
                if(tmp[i] < wcount[i]){
                    subset= false;
                    break;
                }
            }
            if(subset) ans.push_back(word);
        }
        
        return ans;
    }
    
    vector<int> get_count(string s){
        vector<int> count(26);
        
        for(char c: s){
            count[c-'a']++;
        }
        
        return count;
    }
};