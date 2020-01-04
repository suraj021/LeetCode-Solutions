class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans= 0;
        
        for(int n: nums){
            cout << numOfDigits(n) << endl;
            ans+= numOfDigits(n)%2 ? 0 : 1;
        }
        
        return ans;
    }
    
    int numOfDigits(int n){
        int c= 0;
        
        while(n > 0){
            c++;
            n/= 10;
        }
        
        return c;
    }
};