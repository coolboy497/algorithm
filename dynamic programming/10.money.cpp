#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//arr是货币数组，其中的值都是正数。再给定一个正数aim,每个值都认为是一张货币
//即便是值相同的货币也认为每一张都是不同的，返回组成aim的方法数
//例如：arr={1,1,1},aim=2
//arr[0]+arr[1] arr[0]+arr[2] arr[1]+arr[2]  3种方法
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
        int p1 = subprocess(arr,index+1,rest);
        int p2 = subprocess(arr,index+1,rest-arr[index]);
        return p1+p2;
    }

    // rest 0-aim
    // index 0-arr.size

    // 初始写成了rest-arr[index]>0 出错 要写成 rest-arr[index]>=0
    int coinways2(vector<int>&arr,int aim){
        vector<vector<int>>dp(arr.size()+1,vector<int>(aim+1));
        dp[arr.size()][0]=1;
        for(int index=arr.size()-1;index>=0;index--){
            for(int rest=aim;rest>=0;rest--){
                int p1 = dp[index+1][rest];
                int p2 = rest-arr[index]>=0 ? dp[index+1][rest-arr[index]] : 0;
                dp[index][rest] = p1+p2;
            }
        }
        return dp[0][aim];
    }
};
int main(){
    Solution a;
    vector<int>arr{1,1,1};
    int aim = 2;
    int ways = a.coinways(arr,aim);
    cout<<ways<<endl;
    int ways2 = a.coinways2(arr,aim);
    cout<<ways2<<endl;
}