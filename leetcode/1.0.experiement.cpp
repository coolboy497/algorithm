#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    // int backtraverse(vector<int>&nums,int start,int end){
    //     if(start>end){
    //       return 0;
    //     }
    //     int p1 = nums[start]+backtraverse(nums,start+2,end);
    //     int p2 = backtraverse(nums,start+1,end);
    //     return max(p1,p2);
    // }
    // start 0~nums.size()-1
    // end  nums.size()-2~nums.size()-1
    int dp2(vector<int>&nums,vector<int>&dp){
        for(int i=nums.size()-2;i>=0;i--){
            int p1 = nums[i]+dp[i+2];
            int p2 = dp[i+1];
            dp[i] = max(p1,p2);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int>nums1(nums.begin()+1,nums.end());
        vector<int>nums2(nums.begin()+2,nums.end()-1);
        vector<int>dp(nums1.size()+1);
        vector<int>dp1(nums2.size()+1);
        return max(nums[0]+dp2(nums2,dp1),dp2(nums1,dp));

        // return max(nums[0]+backtraverse(nums,2,nums.size()-2),backtraverse(nums,1,nums.size()-1));
    }
};
int main(){
    Solution s1;
    //vector<vector<int>>points = {{1,2},{3,4},{5,6},{7,8}};
    // int s = 332;
    vector<int>nums{1,2,3,1};
    int a = s1.rob(nums);
    // vector<int>dp(nums.size()+1);
    // vector<int>dp1(nums.size()+1);
    // int a = nums[0]+s1.dp2(nums,dp,2,nums.size()-2);
    // int b = s1.dp2(nums,dp1,1,nums.size()-1);
    // return max(nums[0]+dp2(nums,dp,2,nums.size()-2),dp2(nums,dp1,1,nums.size()-1));
    // int a=s1.rob(nums);
    cout<<a;
    // cout<<b;
}