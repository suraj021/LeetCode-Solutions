class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz= (int)height.size();
        int i, j;
        i= 0; j= sz-1;
        
        int water= 0;
        
        while(i<j){
            int h= min(height[i], height[j]);
            water= max(water, (j-i)*h);
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        
        return water;
    }
};