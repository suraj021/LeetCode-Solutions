class Solution {
public:
    int nthUglyNumber(int n) {
        if(n== 0 || n==1) return n;
        int a, b, c;
        a= 0; b= 0; c= 0;
        int count= 1;
        int ugly[n+1];
        ugly[0]= 1;
        
        while(count < n){
            int A= ugly[a]*2;
            int B= ugly[b]*3;
            int C= ugly[c]*5;
            
            ugly[count]= min(A, min(B, C));
            
            if(ugly[count]== A){
                a++;
            } 
            if(ugly[count]== B){
                b++;
            } 
            if(ugly[count]== C) {
                c++;
            }
            count++;
        }

        return ugly[n-1];
    }
};