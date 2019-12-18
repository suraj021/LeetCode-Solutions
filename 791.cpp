class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> mp= makeMap(S);
        
        for(int i= 0; i< T.length(); ++i){
            if(mp[T[i]]){
                for(int j= i+1; j< T.length(); ++j){
                    if(mp[T[j]] && mp[T[i]] > mp[T[j]]){
                        swap(T[i], T[j]);
                    }
                }
            }
        }
                    
        return T;
    }
    
    map<char, int> makeMap(string &s){
        map<char, int> mp;
        
        for(int i= 0; i< s.length(); ++i){
            if(!mp[s[i]]){
                mp[s[i]]= i+1;
            }
        }
        
        return mp;
    }
};