#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
//两数之和,给定一个整数数组 nums 和一个目标值 target，
//请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len<2){
            return {};
        }
        unordered_map<int,int>umap;
        for(int i=0;i<len;i++){
            auto result = umap.find(target-nums[i]);
            if(result!=umap.end()){
                return{i,result->second};
            }
            umap[nums[i]]=i;
        }
        return {};
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>nums={2,7,11,15};
    int target = 9;
    Solution s;
    vector<int>result = s.twoSum(nums,target);
    for_each(result.begin(),result.end(),myprint);
    return 0;
}