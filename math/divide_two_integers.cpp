class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==dividend) return 1;
        bool ispos = (dividend<0 == divisor<0);
        long long a=dividend , b=divisor , ans=0 , q=0;
        a = a<0?-a:a;
        b = b<0?-b:b;
        while(a>=b){
            short q=0;
            while(a>=(b<<(q+1))){
                q++;
            }
            ans+=(1<<q);
            a=a-(b<<q);
        }
        if(ans == (1<<31) and ispos){
            return INT_MAX;
        }
        return ispos ? ans : -ans;

    }
};
