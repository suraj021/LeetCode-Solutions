class Solution {
public:
    bool checkValidString(string s) {
        int cmin= 0; // min number of open parenthesis that MUST be matched
        int cmax= 0; // max number of open parenthesis that COULD be matched
        
        for(char c: s){
            if(c == '('){
                cmin++; cmax++;
            } else if(c == ')'){
                cmax--; cmin= max(cmin-1, 0);
            } else {
                cmax++; cmin= max(cmin-1, 0);
            }
            
            cout << cmin << " " << cmax << endl;
            
            if(cmax < 0)    return false;
        }
        
        return cmin == 0;
    }
};