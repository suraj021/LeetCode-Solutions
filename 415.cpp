class Solution {
public:
    string addStrings(string num1, string num2) {
        int m= num1.length();
        int n= num2.length();
        
        int i, j;
        i= m-1; j= n-1;
        int carry= 0;
        string ans= "";
        
        while(i>= 0 || j>= 0 || carry){
            // cout << carry << " " ;
            int sum= 0;
            sum+= i >= 0 ? num1[i--] - '0' : 0;
            sum+= j >= 0 ? num2[j--] - '0' : 0;
            // cout << carry << endl;
            sum+= carry;
            ans+= to_string(sum%10);
            carry= sum/10;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};