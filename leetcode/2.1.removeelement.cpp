#include <iostream>
#include <vector>
using namespace std;
//给你一个数组 nums 和一个值 val，
//你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度
//双指针法
//快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
//慢指针：指向更新 新数组下标的位置
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j;
        for(i=0,j=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
int main(){
    int num[4]={3,2,2,3};
    int val = 3;
    vector<int> v;
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        v.push_back(num[i]);
    }
    Solution s;
    int len = s.removeElement(v,val);
    cout<<len<<endl;
    return 0;
}