class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int mindiff= INT_MAX;
        int n= timePoints.size();
        
        sort(timePoints.begin(), timePoints.end());
        
        for(int i= 0; i< n; ++i){
            int diff= abs(timeDiff(timePoints[(i-1+n)%n], timePoints[i]));
            diff= min(diff, 1440-diff);
            mindiff= min(mindiff, diff);
        }
        
        return mindiff;
    }
    
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};