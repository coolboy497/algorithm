#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//splitnumber 给定一个数字，分裂成多个数字，后面的数字不能小于前面的，有多少种方法
class Solution{
public:
    int way1(int n){
        if(n<0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return process(1,n);
    }
    //上一个拆出来的数是pre，还剩rest需要去拆，返回拆解的方法数
    int process(int pre,int rest){
        if(rest==0){
            return 1;
        }
        if(pre>rest){
            return 0;
        }
        if(pre==rest){
            return 1;
        }
        //pre<rest
        int ways = 0;
        for(int first=pre;first<=rest;first++){
            ways+=process(first,rest-first);
        }
        return ways;
    }

    //pre 1~n
    //rest 0~n
    int way2(int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int i=0;i<=n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int pre=n-1;pre>=1;pre--){
            // rest要从pre+1开始，因为rest>pre
            for(int rest=pre+1;rest<=n;rest++){
                int ways = 0;
                for(int first=pre;first<=rest;first++){
                    ways+=dp[first][rest-first];
                }
                dp[pre][rest] = ways;
            }
        }
        return dp[1][n];
    }

    //动态规划，当前格子依赖下面的格子和左边的某个格子
    int way3(int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        for(int i=0;i<=n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int pre=n-1;pre>=1;pre--){
            // rest要从pre+1开始，因为rest>pre
            for(int rest=pre+1;rest<=n;rest++){
               dp[pre][rest]=dp[pre+1][rest];
               dp[pre][rest]+=dp[pre][rest-pre];
            }
        }
        return dp[1][n];
    }
};
int main(){
    Solution a;
    cout<<a.way1(27)<<endl;
    cout<<a.way2(27)<<endl;
    cout<<a.way3(27)<<endl;
}