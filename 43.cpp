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

    // O(n^2) method trick
    string _multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        for (int i = 0; i < m + n; i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return "0";
    }
    
};