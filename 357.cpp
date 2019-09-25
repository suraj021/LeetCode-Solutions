class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if( n== 0 ) return 1;
        int ans= 10;
        int uniqueDigits= 9;
        int availableNumbers= 9;
        for(int i= 1; i< n && availableNumbers; ++i){
            uniqueDigits= uniqueDigits * availableNumbers;
            ans+= uniqueDigits;
            availableNumbers--;
        }
        
        return ans;
    }
};