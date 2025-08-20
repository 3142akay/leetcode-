class Solution {
public:

int dp[305][305];
    int countSquares(vector<vector<int>>& mat) {
          int result=0;
          memset(dp,0,sizeof(dp));
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

               
                if(mat[i][j]==0||i==0||j==0){
                   dp[i][j]=mat[i][j];
                }

                else if(mat[i][j]==1){
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                }
                result+=dp[i][j];
            }
        }
        return result;
    }
};