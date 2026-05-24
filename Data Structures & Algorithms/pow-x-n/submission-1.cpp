class Solution {
public:
    double popo(double x, long long  n){
            double half = myPow(x,n/2);
            double ans =  half * half;
            if( n %2 == 1){
                ans *= x;
            }

            return ans;
    }
    double myPow(double x, int n) {
        double ans = x  ;
        long long nn = n ;
        if(n == 0  ){
            return 1;
        }if(n == 1){
            return x;
        }else if( x == 1){
            return 1;
        }
        else if( n < 0 ){
            x = 1/x;
            nn = -nn;
        }
        return popo(x,nn);
    }
};

// x = 2  , n =  -1
//  2/2 = 1, 1/2 = 0.5