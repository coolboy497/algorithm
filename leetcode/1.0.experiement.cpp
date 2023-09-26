#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //dp[i,j]表示到达第i,j位置时的不同路径
        //递推关系:dp[i,j]=dp[i-1,j]+dp[i,j-1] (无障碍物)
        // 
        //初始化:dp[0,j]=1;dp[i,0]=1;
        //遇到障碍物，后面的初始化为0;
        //遍历顺序：先行后列
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> >dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==0){
                dp[0][j]=1;
            }
            else{
                for(int k=j;k<n;k++){
                    dp[0][k]=0;
                }
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==0){
                dp[i][0]=1;
            }
            else{
                for(int k=i;k<m;k++){
                    dp[k][0]=0;
                }
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i-1][j]==0&&obstacleGrid[i][j-1]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else{
                    if(obstacleGrid[i-1][j]==0){
                        dp[i][j]=dp[i][j-1];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
int main(){
    Solution s1;
    //vector<vector<int>>points = {{1,2},{3,4},{5,6},{7,8}};
    // int s = 332;
    vector<vector<int>>obstacleGrid = {{1,0}};
    int a=s1.uniquePathsWithObstacles(obstacleGrid);
    cout<<a;
}