#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
//使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//i,j进行遍历，left、right进行移动
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        int left,right;
        for(int i=0;i<nums.size();i++){
            // 剪枝
            if(nums[i]>target&&nums[i]>0){
                break;
            }
            // 去重
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                // 剪枝
                if(nums[i]+nums[j]>target&&nums[j]>0){
                    break;
                }
                // 去重
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                left = j+1;
                right = nums.size()-1;
                while (left<right)
                {
                    //nums[i]+nums[j]+nums[left]+nums[right]可能会溢出
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]>target){
                        right--;
                    }
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right]<target){
                        left++;
                    }
                    else{
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
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
            
        }
        return result;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>nums={2,2,2,2,2};
    int target = 8;
    // for_each(nums.begin(),nums.end(),myprint);
    // cout<<endl;
    Solution s;
    vector<vector<int>> result = s.fourSum(nums,target);
    for(auto it = result.begin();it!=result.end();it++)
    {
        for(auto k = (*it).begin();k!=(*it).end();k++){
            cout<<(*k)<<" ";
        }
        cout<<endl;
    }
    return 0;
}