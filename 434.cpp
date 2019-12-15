class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string word;
        int count= 0;
        
        while(ss >> word){
            count++;
        }
        
        return count;
    }

    int _countSegments(string s) {
        int res = 0;
        s.push_back(' ');
        for(int i = 1; i < s.size(); ++i)
          if(s[i] == ' ' && s[i-1] != ' ') ++res;
        return res;
    }
};