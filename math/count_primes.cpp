class Solution {
public:
    int countPrimes(int n) {
        vector<bool>ans(n+1,true);
        int c=0;
        ans[0]=false;
        ans[1]=false;
        for(int i=2;i<n;++i){
            if(ans[i]){
                c++;
                for(int j=2*i;j<n;j=j+i){
                    ans[j]=false;
                }
            }
            
        }return c;



        
    }
};
