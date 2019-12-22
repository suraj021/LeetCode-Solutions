class Solution {
public:
    string smallestSubsequence(string text) {
        int lastSeen[26], used[26]= {0};
        string res= "";
        
        for(int i= 0; i< text.length(); ++i) lastSeen[text[i]-'a']= i;
        
        for(int i= 0; i< text.length(); ++i){
            // cout << text[i] << "\n";
            if(used[text[i]-'a']) continue;
            // cout << "\t";
            while(!res.empty() && res.back() > text[i] && lastSeen[res.back()-'a'] > i){
                used[res.back()-'a']= false;
                res.pop_back();
                // cout << res << "\n\t";
            }
            
            used[text[i]-'a']= true;
            res.push_back(text[i]);
            // cout << res << endl;
        }
        
        return res;
    }
};