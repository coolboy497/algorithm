#include <iostream>
#include <vector>
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
//请你找出给定目标值在数组中的开始位置和结束位置。
// 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
// 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时找到的左右边界为（0,1）应该返回{-1, -1}
// 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时找到的左右边界为（0,2）应该返回{1,1}
using namespace std;
//寻找右边界，mid=target并不一定是最右的，因此要继续缩进左边值
int getrightborder(vector<int>& nums, int target){
    int l=0;
    int r=nums.size()-1;
    int rightborder = -2;
    while(l<=r){
        int mid = (l+r)/2;//防止溢出
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
int getleftborder(vector<int>& nums, int target){
    int l=0;
    int r=nums.size()-1;
    int leftborder = -2;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(nums[mid]<target){
            l = mid+1;
        }
        else{
            r = mid-1;
            leftborder = r;
        }
    }
    return leftborder;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rightborder = getrightborder(nums,target);
        int leftborder = getleftborder(nums,target);
        vector<int> result;
        if(rightborder==-2||leftborder==-2){
            result.push_back(-1);
            result.push_back(-1);
        }
        else if(rightborder-leftborder>1){
            result.push_back(leftborder+1);
            result.push_back(rightborder-1);
        }
        else {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};
int main(){
    int num[6] = {-1,2,3,7,7,9};
    int target = 3;
    vector<int>v;
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        v.push_back(num[i]);
    }
    Solution S;
    vector<int> index = S.searchRange(v,target);
    for(auto it =index.begin();it!=index.end();it++){
        cout<<(*it)<<endl;
    }
    int rightborder = getrightborder(v,target);
    cout<<rightborder<<endl;
    int leftborder = getleftborder(v,target);
    cout<<leftborder<<endl;
    // if(index!=-1){
    //     cout<<"所查值的下标为:"<<index<<endl;
    // }
    // else{
    //     cout<<"不存在所查值"<<endl;
    // }
}