#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//arr是货币数组，其中的值都是正数。再给定一个正数aim。
//每个值都认为是一张货币，认为值相同的货币没有任何不同，返回组成aim的方法数
//例如 arr={1,2,1,1,2,1,2} aim=4
//方法:1+1+1+1、1+1+2、2+2
//一共就3种方法，所以返回3
class Solution{
public:
    int coinways(vector<int>&arr,int aim){
        return subprocess(arr,0,aim);
    }
    int subprocess(vector<int>&arr,int index,int rest){
     
    }

    // index 0~arr.size()
    // rest 0~aim
    int coinways2(vector<int>&arr,int aim){
        vector<vector<int>>dp(arr.size()+1,vector<int>(aim+1));
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
    // int ways3 = a.coinways3(arr,aim);
    // cout<<ways3<<endl;
}