class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows+1);
        int row= 1;
        int cycle= 0;
        
        if(numRows == 1) return s;
        
        for(int i= 0; i< s.length(); ++i){
            v[row].push_back(s[i]);
            
            if(row== numRows){
                cycle= 1;
            }
            if(row == 1){
                cycle= 0;
            }
            
            if(cycle) row--;
            else row++;
        }
        
        s= "";
        
        for(string c: v){
            s+= c;
        }
        
        return s;
    }
};