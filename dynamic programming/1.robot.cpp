#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//出现重复解的暴力递归才能进行优化

//假设有排成一行的 N 个位置，记为 1~N，N 一定大于或等于 2。
//开始时机器人在其中的 M 位置上(M 一定是 1~N 中的一个)，机器人可以往左走或者往右走，
//如果机器人来到 1 位置， 那么下一步只能往右来到 2 位置;如果机器人来到 N 位置，那么下一步只能往左来到 N-1 位置。
//规定机器人必须走 K 步，最终能来到 P 位置(P 也一定是 1~N 中的一个)的方法有多少种。给定四个参数 N、M、K、P，返回方法数
class Solution{
public:
    int process1(int sum, int cur, int step, int target){
        if(sum==0 || target>sum || target < 0 || cur > sum || cur < 0){
            return 0;
        }
        if(step==0){
            return cur == target ? 1 : 0;
        }
        else if(cur==1){
            return process1(sum,cur+1,step-1,target);
        }
        else if(cur==sum){
            return process1(sum,sum-1,step-1,target);
        }
        return process1(sum,cur+1,step-1,target)+process1(sum,cur-1,step-1,target);
    }

    // cur 1~N
    // step 0~k
    int process2(int sum, int cur, int step, int target){
        if(sum==0 || target>sum || target < 0 || cur > sum || cur < 0){
            return 0;
        }
        // dp就是缓存表
        // dp[cur][step]==-1 ->subprocess2(cur,step)没算过
        // dp[cur][step]！=-1 ->subprocess2(cur,step)算过，直接取值就行
        vector<vector<int>>dp(sum+1,vector<int>(step+1,-1));
        return subprocess2(sum, cur, step, target, dp);
    }
    int subprocess2(int sum, int cur, int step, int target,vector<vector<int>>&dp){
        if(dp[cur][step]!=-1){
            return dp[cur][step];
        }
        // 之前没算过
        int ans = 0;
        if(step==0){
            ans =  (cur == target ? 1 : 0);
        }
        else if(cur==1){
            ans = subprocess2(sum,2,step-1,target,dp);
        }
        else if(cur==sum){
            ans = subprocess2(sum,sum-1,step-1,target,dp);
        }
        else{
            ans = subprocess2(sum,cur+1,step-1,target,dp)+subprocess2(sum,cur-1,step-1,target,dp);
        }
        dp[cur][step]=ans;
        return ans;
    }

    int process3(int sum, int cur, int step, int target){
        if(sum==0 || target>sum || target < 0 || cur > sum || cur < 0){
            return 0;
        }
        vector<vector<int>>dp(sum+1,vector<int>(step+1));
        dp[target][0]=1;
        for(int j=1;j<=step;j++){
            for(int i=1;i<=sum;i++){
                if(i==1){
                    dp[i][j]=dp[i+1][j-1];
                    continue;
                }
                else if(i==sum){
                    dp[i][j]=dp[i-1][j-1];
                    continue;
                }
                dp[i][j]=dp[i+1][j-1]+dp[i-1][j-1];
            }
        }
        return dp[cur][step];
    }
};

int main(){
    Solution a;
    // int ways = a.subprocess(5,2,3,3);
    int ways = a.process1(5,2,3,3);
    int ways2 = a.process2(5,2,3,3);
    int ways3 = a.process3(5,2,3,3);
    cout << "process1:"<< ways <<endl;
    cout << "process2:"<< ways2 <<endl;
    cout << "process3:"<< ways3 <<endl;
    return 0;
}