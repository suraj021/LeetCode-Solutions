class Solution {
public:
    string dayOfTheWeek(int din, int month, int year) {
        string week[]= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int numOfDays[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day= 0;
        
        for(int i= 1971; i< year; ++i){
            if(isLeapYear(i)){
                day+= 366;
            } else {
                day+= 365;
            }
        }
        
        if(isLeapYear(year)) numOfDays[1]= 29;
        
        for(int m= 0; m< month-1; ++m){
            day+= numOfDays[m];
        }
        
        day+= din-1;
                
        return week[(day+5)%7];
        
    }
    
    bool isLeapYear(int year){
        return year%4== 0 && year%100!= 0 || year%400== 0;
    }
};