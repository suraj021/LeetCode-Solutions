class Solution {
public:
    string alphabetBoardPath(string target) {
        int x, y;
        string ans= "";

        x= y= 0;
        
        for(char c: target){
            int x1= (c - 'a')/5;
            int y1= (c - 'a')%5;
            
            ans+= string(max(0, x-x1), 'U') + string(max(0, y1-y), 'R') + string(max(0, y-y1), 'L') + string(max(0, x1-x), 'D') + '!';
            
            x= x1; y= y1;
        }
        
        return ans;
    }
};