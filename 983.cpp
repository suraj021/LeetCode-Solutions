class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(days.begin(), days.end());
        int dp[366]= {0};
        
        for(int i= 1; i<= 365; ++i){
            if(travel.find(i) != travel.end()){
                dp[i]= min(dp[i-1]+costs[0], min(dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2]));
            } else {
                dp[i]= dp[i-1];
            }
        }
        
        return dp[365];
    }
};