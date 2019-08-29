class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= (int)prices.size();
        
        if(n== 0)   return 0;
        
        int lmin[n], rmax[n];
        lmin[0]= prices[0]; rmax[n-1]= prices[n-1];
        
        for(int i= 1; i< n; ++i)
            lmin[i]= min(lmin[i-1], prices[i]);
        for(int i= n-2; i>= 0; --i)
            rmax[i]= max(rmax[i+1], prices[i]);
        
        int maxP= INT_MIN;
        
        for(int i= 0; i< n; ++i){
            maxP= max(maxP, rmax[i]-lmin[i]);
        }
        
        return maxP;
    }
};