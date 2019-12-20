class Solution {
public:
    string countAndSay(int n) {
        if(n== 1) return "1";
        
        string prev= "1";
        
        while(n-- > 1){
            string newStr="";
            for(int i= 0; i< prev.length();){
                int c= 1;
                int j= i+1;
                // cout << prev[i] << " " << c << endl;
                while(j < prev.length() && prev[j] == prev[i]){
                    c++; j++;
                }
                // cout << c << "\n";
                newStr+= to_string(c) + prev[i];
                i= j;
            }
            prev= newStr;
        }
        
        return prev;
    }
};