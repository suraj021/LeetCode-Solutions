class Solution {
public:
    int fib(int N) {
        if(N== 0 || N== 1)  return N;
        int a, b, c;
        
        a= 0; b= 1; c= 1;
        N-= 1;
        
        while(N--){
            c= a+b;
            a= b;
            b= c;            
        }
        
        return c;
    }
};