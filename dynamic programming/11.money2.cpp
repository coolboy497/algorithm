#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//arr是面值数组，其中的值都是正数且没有重复，再给定一个正数aim
//每个值都认为是一种面值，且认为张数是无限的，返回组成aim的方法数
//例如 arr={1,2},aim=4
//方法如下：1+1+1+1 、1+1+2、2+2
//一共就3种方法，所以返回3
class Solution{
public:
    int coinways(vector<int>&arr,int aim){
        return subprocess(arr,0,aim);
    }
    int subprocess(vector<int>&arr,int index,int rest){
        if(rest<0){
            return 0;
        }
        if(index==arr.size()){
            return rest==0 ? 1 : 0;
        }
        int ways = 0;
        for(int zhang=0;zhang*arr[index]<=rest;zhang++){
            ways+=subprocess(arr,index+1,rest-zhang*arr[index]);
        }
        return ways;
    }

    // index 0~arr.size()
    // rest 0~aim
    int coinways2(vector<int>&arr,int aim){
        vector<vector<int>>dp(arr.size()+1,vector<int>(aim+1));
        dp[arr.size()][0]=1;
        for(int index=arr.size()-1;index>=0;index--){
            for(int rest=aim;rest>=0;rest--){
                int ways = 0;
                for(int zhang=0;zhang*arr[index]<=rest;zhang++){
                    ways+=dp[index+1][rest-zhang*arr[index]];
                }
                dp[index][rest]=ways;
            }
        }
        return dp[0][aim];
    }


    //优化-》不需要循环张数,这里的优化是当前位置的值等于同一行的前一个值加上当前位置下面的值
    //所有内部的循环必须要是从左到右的（*****）
    int coinways3(vector<int>&arr,int aim){
        vector<vector<int>>dp(arr.size()+1,vector<int>(aim+1));
        dp[arr.size()][0]=1;
        for(int index=arr.size()-1;index>=0;index--){
            for(int rest=0;rest<=aim;rest++){
                // int ways = 0;
                // for(int zhang=0;zhang*arr[index]<=rest;zhang++){
                //     ways+=dp[index+1][rest-zhang*arr[index]];
                // }
                // dp[index][rest]=ways;
                dp[index][rest]=dp[index+1][rest];
                if(rest-arr[index]>=0){
                    dp[index][rest]+=dp[index][rest-arr[index]];
                }
            }
        }
        return dp[0][aim];
    }
};
int main(){
    Solution a;
    vector<int>arr{1,2};
    int aim = 4;
    int ways = a.coinways(arr,aim);
    cout<<ways<<endl;
    int ways2 = a.coinways2(arr,aim);
    cout<<ways2<<endl;
    int ways3 = a.coinways3(arr,aim);
    cout<<ways3<<endl;
}