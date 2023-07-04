#include <iostream>
#include <vector>
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
//请你找出给定目标值在数组中的开始位置和结束位置。
using namespace std;
//寻找右边界，mid=target并不一定是最右的，因此要继续缩进左边值
int getrightborder(vector<int>& nums, int target){
    int l=0;
    int r=nums.size()-1;
    int rightborder = -1;
    while(l<=r){
        int mid = l+(l+r)/2;//防止溢出
        if(nums[mid]>target){
            r=mid-1;
        }
        else{
            l = mid+1;
            rightborder = l;
        }
    }
    return rightborder;
}
// int getleftborder(vector<int>& nums, int target){
//     int l=0;
//     int r=nums.size()-1;
//     int leftborder = -1;
//     while(l<=r)
//     {
//         int mid = l+(l+r)/2;
//         if(nums[mid]<target){
//             l = mid+1;
//         }
//         else{
//             r = mid-1;
//             leftborder = r;
//         }
//     }
//     return leftborder;
// }
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//     }
// };
int main(){
    int num[6] = {5,7,7,8,8,10};
    int target = 7;
    vector<int>v;
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        v.push_back(num[i]);
    }
    // Solution S;
    // vector<int> index = S.searchRange(v,target);
    // for(auto it =index.begin();it!=index.end();it++){
    //     cout<<(*it)<<endl;
    // }
    int rightborder = getrightborder(v,target);
    cout<<rightborder<<endl;
    // int leftborder = getleftborder(v,target);
    // cout<<leftborder<<endl;
    // if(index!=-1){
    //     cout<<"所查值的下标为:"<<index<<endl;
    // }
    // else{
    //     cout<<"不存在所查值"<<endl;
    // }
}