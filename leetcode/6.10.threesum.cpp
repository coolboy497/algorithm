#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
//使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组
//i进行遍历,left、right进行移动
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int left,right,i;
        int pre_left,pre_right;
        for(i=0;i<nums.size();i++){
            if (nums[i] > 0) {
                return result;
            }
            //*************去重*********************//
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            left=i+1;
            right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                }
                else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    // 对b和c去重
                    while(right>left&&nums[right]==nums[right-1]){
                            right--;
                    }
                    while(right>left&&nums[left]==nums[left+1]){
                            left++;
                    }
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>nums={-2,0,0,2,2};
    sort(nums.begin(),nums.end());
    for_each(nums.begin(),nums.end(),myprint);
    cout<<endl;
    Solution s;
    vector<vector<int>> result = s.threeSum(nums);
    for(auto it = result.begin();it!=result.end();it++){
        for(auto k = (*it).begin();k!=(*it).end();k++){
            cout<<(*k)<<" ";
        }
        cout<<endl;
    }
    return 0;
}