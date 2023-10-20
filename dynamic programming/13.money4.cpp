#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//arr是面值数组，其中的值都是正数且没有重复。再给定一个正数aim。每个值都认为是一种面值，且认为张数是无限的。
//返回组成aim的最少货币数
class Solution{
public:
    int minCoins(vector<int>&arr,int aim){
        return process(arr,0,aim);
    }
    //arr[index...]面值，每种面值张数自由选择，搞出rest正好怎么多钱，返回最小张数（递归函数的含义一定要清楚）
    int process(vector<int>&arr,int index,int rest){
        if(rest < 0){
            return INT_MAX;
        }
        if(index==arr.size()){
            return rest==0 ? 0 : INT_MAX;
        }
        int ans = INT_MAX;
        for(int zhang = 0; zhang*arr[index]<=rest;zhang++){
            int next = process(arr,index+1,rest-zhang*arr[index]);
            if(next!=INT_MAX){
                ans = min(ans,next+zhang);
            }
        }
        return ans;
    }

    //index 0~arr.size()
    //rest 0~aim
    int minCoins2(vector<int>&arr,int aim){
        int N = arr.size();
        vector<vector<int>>dp(N+1,vector<int>(aim+1));
        dp[N][0]=0;
        for(int j=1;j<=aim;j++){
            dp[N][j]=INT_MAX;
        }
        for(int index=N-1;index>=0;index--){
            for(int rest=0;rest<=aim;rest++){
                int ans = INT_MAX;
                for(int zhang = 0; zhang*arr[index]<=rest;zhang++){
                    int next = rest-zhang*arr[index]<0 ? INT_MAX : dp[index+1][rest-zhang*arr[index]];
                    if(next!=INT_MAX){
                        ans = min(ans,next+zhang);
                    }
                }
                dp[index][rest]=ans;
            }
        }
        return dp[0][aim];
    }

    int minCoins3(vector<int>&arr,int aim){
        int N = arr.size();
        vector<vector<int>>dp(N+1,vector<int>(aim+1));
        dp[N][0]=0;
        for(int j=1;j<=aim;j++){
            dp[N][j]=INT_MAX;
        }
        for(int index=N-1;index>=0;index--){
            for(int rest=0;rest<=aim;rest++){
                // int ans = INT_MAX;
                // for(int zhang = 0; zhang*arr[index]<=rest;zhang++){
                //     int next = rest-zhang*arr[index]<0 ? INT_MAX : dp[index+1][rest-zhang*arr[index]];
                //     if(next!=INT_MAX){
                //         ans = min(ans,next+zhang);
                //     }
                // }
                // dp[index][rest]=ans;
                dp[index][rest]=dp[index+1][rest];
                if(rest-arr[index]>=0 && dp[index][rest-arr[index]]!=INT_MAX){
                    dp[index][rest]=min(dp[index][rest],dp[index][rest-arr[index]]+1);
                }

            }
        }
        return dp[0][aim];
    }
};
int main(){
    Solution a;
    vector<int>arr{1,2,3,5,8,4,6};
    int aim = 25;
    int num = a.minCoins(arr,aim);
    cout<<num<<endl;
    int num2 = a.minCoins2(arr,aim);
    cout<<num2<<endl;
    int num3 = a.minCoins3(arr,aim);
    cout<<num3<<endl;
}