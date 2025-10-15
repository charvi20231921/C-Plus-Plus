class Solution {
public:
    int solve(int i  , int j , vector<vector<int>>&dp){
        if(i<0 && j<0 ) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = 0;
        if(j>0) left = solve(i , j-1 , dp);
        int up = 0;
        if(i>0) up = solve(i-1 , j , dp);
        return dp[i][j] = left + up;

    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n , vector<int>( m , 0));
        vector<int>prev(m , 0);

        for(int j=0 ; j<m ; ++j){
            prev[j] = 1;
        }
        for(int i=n-2 ; i>=0 ; --i){
            vector<int>temp(m , 0);
            for(int j=m-1 ; j>=0 ; --j){
                if(i==0 && j==0) temp[0] = 1;
                int right = 0;
                int down =0;
                if(j<m-1) right = temp[j+1];
                if(i<n-1) down = prev[j];
                temp[j] = right + down;
            }
            prev = temp;
        }
        return prev[0];
    }
};
