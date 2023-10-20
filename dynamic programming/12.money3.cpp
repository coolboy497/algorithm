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
        unordered_map<int,int>umap;
        for(int i=0;i<arr.size();i++){
            umap[arr[i]]++;
        }
        sort(arr.begin(), arr.end());  //先做排序，排序后利用unique函数去重
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        return subprocess(arr,0,aim,umap);
    }
    //umap每种面值及其对应的张数
    int subprocess(vector<int>&arr,int index,int rest,unordered_map<int,int>&umap){
        if(rest<0){
            return 0;
        }
        if(index==arr.size()){
            return rest==0 ? 1 : 0;
        }
        int ways = 0;
        for(int zhang=0;zhang*arr[index]<=rest&&zhang<=umap[arr[index]];zhang++){
            ways+=subprocess(arr,index+1,rest-zhang*arr[index],umap);
        }
        return ways;
    }

    // index 0~arr.size()
    // rest 0~aim
    int coinways2(vector<int>&arr,int aim){
        unordered_map<int,int>umap;
        for(int i=0;i<arr.size();i++){
            umap[arr[i]]++;
        }
        sort(arr.begin(), arr.end());  //先做排序，排序后利用unique函数去重
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        vector<vector<int>>dp(arr.size()+1,vector<int>(aim+1));
        dp[arr.size()][0]=1;
        for(int index=arr.size()-1;index>=0;index--){
            for(int rest=0;rest<=aim;rest++){
                int ways = 0;
                for(int zhang=0;zhang*arr[index]<=rest&&zhang<=umap[arr[index]];zhang++){
                    ways+=dp[index+1][rest-zhang*arr[index]];
                }
                dp[index][rest]=ways;
            }
        }
        return dp[0][aim];
    }

};
int main(){
    Solution a;
    vector<int>arr{1,2,1,1,2,1,2};
    vector<int>arr1{1,2,1,1,2,1,2};
    int aim = 4;
    int ways = a.coinways(arr,aim);
    cout<<ways<<endl;
    int ways2 = a.coinways2(arr1,aim);
    cout<<ways2<<endl;
    // int ways3 = a.coinways3(arr,aim);
    // cout<<ways3<<endl;
}