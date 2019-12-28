class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1== "0" || num2== "0") return "0";
        
        vector<string> mul;
        
        for(int i= num2.size()-1; i>= 0; --i){
            mul.push_back(_multiply(num1, num2[i], num2.size()-i-1));
        }
        
        int maxlen= 0;
        for(int i= 0; i< mul.size(); ++i){
            maxlen= max(maxlen, (int)mul[i].length());
        }
        
        int rem= 0;
        string ans= "";
        
        for(int i= 0; i< maxlen; ++i){
            int sum= 0;
            for(int j= 0; j< mul.size(); ++j){
                if(i < mul[j].size()){
                    sum+= mul[j][i] - '0';
                }
            }
            sum+= rem;
            rem= sum/10;
            ans+= to_string(sum%10);
        }
        
        if(rem) ans+= to_string(rem);
        reverse(ans.begin(), ans.end());

        return ans;
    }
    
    string _multiply(string from, char to, int n){
        string ans= "";
        int rem= 0;
                
        for(int i= from.size()-1; i>= 0; --i){
            int m= (from[i] - '0')*(to - '0') + rem;
            rem= m/10;
            ans+= to_string(m%10);
        }
        
        if(rem) ans+= to_string(rem);
                
        return string(n, '0') + ans;
    }
    
};