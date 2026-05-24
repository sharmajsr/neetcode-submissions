class Solution {
public:
    double myPow(double x, int n) {
        double ans = x  ;
        if(n > 0){
            for(int i =0 ; i <n-1 ;i++){
                ans = ans * x;
            }
        }else{
           for(int i =0 ; i <abs(n-1) ;i++){
                ans = ans / x;
            }
        }
        return ans;
    }
};
