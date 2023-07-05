#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//非递减顺序排序的整数数组nums,返回每个数字的平方
//组成的新数组，也要求非递减排序
//隐藏条件：最大的数一定是在两边的，所以想到用双指针头尾遍历做
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             nums[i]=nums[i]*nums[i];
//         }
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>new_nums;
        new_nums.resize(nums.size());
        int i,j,k;
        for(i=0,j=nums.size()-1,k=new_nums.size()-1;i<=j;){
            if(nums[i]*nums[i]>nums[j]*nums[j]){
                new_nums[k] = nums[i]*nums[i];
                k--;
                i++;
            }
            else{
                new_nums[k] = nums[j]*nums[j];
                k--;
                j--;
            }
        }
        return new_nums;
    }
};
int main(){
    int nums[5]={-4,-1,0,3,10};
    vector <int> v;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        v.push_back(nums[i]);
    }
    Solution s;
    vector <int> new_nums = s.sortedSquares(v);
    for(auto it = new_nums.begin();it!=new_nums.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}