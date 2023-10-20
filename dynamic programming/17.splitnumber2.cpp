#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//给定一个正数数组arr，请把arr中所有的数分成两个集合，尽量让两个集合的累加和接近返回
//最接近的情况下，较小集合的累加和
class Solution{
public:
    int way1(vector<int>&arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int target = sum/2;
        int result = process(arr,0,target);
        return min(result,sum-result);
    }
    //在arr[index...]可以自由选择，请返回累加和尽量接近rest，但不能超过rest的情况下，最接近的累加和
    int process(vector<int>&arr,int index,int rest){
        if(index==arr.size()){
            return 0;
        }
        //不使用arr[index]
        int p1 = process(arr,index+1,rest);
        //使用arr[index]
        int p2 = 0;
        if(rest-arr[index]>=0){
            p2 = arr[index]+process(arr,index+1,rest-arr[index]);
        }
        return max(p1,p2);
    }

    // index 0~arr.size()
    // rest 0~target
    int way2(vector<int>&arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int target = sum/2;
        vector<vector<int>>dp(arr.size()+1,vector<int>(target+1));
        for(int index = arr.size()-1;index>=0;index--){
            for(int rest=0;rest<=target;rest++){
                //不使用arr[index]
                int p1 = dp[index+1][rest];
                //使用arr[index]
                int p2 = 0;
                if(rest-arr[index]>=0){
                    p2 = arr[index]+dp[index+1][rest-arr[index]];
                }
                dp[index][rest] =  max(p1,p2);
            }
        }
        return dp[0][target];
    }

    // int way3(vector<int>&arr){
  
    // }
};
int main(){
    Solution a;
    vector<int>arr{1,5,6,8};
    cout<<a.way1(arr)<<endl;
    cout<<a.way2(arr)<<endl;
    // cout<<a.way3(arr)<<endl;
}