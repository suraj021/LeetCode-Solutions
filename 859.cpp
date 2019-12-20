class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if(A.length() != B.length()) return false;
        
        unordered_set<char> s;
        vector<int> diffs;
        
        for(int i= 0; i< A.length(); ++i){
            if(A[i] != B[i])    diffs.push_back(i);
            s.insert(A[i]);
        }
        
        if(A == B){
            if(s.size() == A.length())  return false;
            else    return true;
        }
        
        if(diffs.size() > 2)
            return false;
        
        if( A[diffs[0]] != B[diffs[1]] || A[diffs[1]] != B[diffs[0]] )
            return false;
        
        return true;
        
    }
};