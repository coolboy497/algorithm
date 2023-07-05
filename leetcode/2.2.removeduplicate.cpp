#include <iostream>
#include <vector>
using namespace std;
//删除有序数组中的重复项
//给你一个升序排列的数组nums,请你原地删除重复出现的元素,
//使每个元素只出现一次,返回删除后数组的新长度
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j;
        for(i=0,j=0;i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j=j+1;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
};
int main(){
    int num[3]={1,1,2};
    vector<int> v;
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        v.push_back(num[i]);
    }
    Solution s;
    int len = s.removeDuplicates(v);
    cout<<len<<endl;
    return 0;
}