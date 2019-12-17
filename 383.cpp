class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length() < ransomNote.length()) return false;
        if(ransomNote == "") return true;
        
        map<char, int> freq;
        
        for(int i= 0; i< magazine.length(); ++i){
            freq[magazine[i]]++;
            
            if(i < ransomNote.length())
                freq[ransomNote[i]]--;
        }
        
        for(auto f: freq){
            if(f.second < 0)   return false;
        }
        
        return true;
    }
};