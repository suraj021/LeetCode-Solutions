class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num+1);
        bits[0]= 0; 
        
        if(num== 0) return bits;
        
        bits[1]= 1;
        
        for(int i= 2; i<= num; ++i){
            int j= (int)log2(i);
            j= pow(2, j);
            bits[i]= (i&(i-1))== 0 ? 1 : (bits[j] + bits[i-j]);

        }
        
        return bits;
    }
};