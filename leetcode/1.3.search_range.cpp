#include <iostream>
#include <vector>
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
//请你找出给定目标值在数组中的开始位置和结束位置。
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

    }
};
int main(){
    int num[6] = {5,7,7,8,8,10};
    int target = 8;
    vector<int>v;
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        v.push_back(num[i]);
    }
    Solution S;
    vector<int> index = S.searchRange(v,target);
    for(auto it =index.begin();it!=index.end();it++){
        cout<<(*it)<<endl;
    }
    // if(index!=-1){
    //     cout<<"所查值的下标为:"<<index<<endl;
    // }
    // else{
    //     cout<<"不存在所查值"<<endl;
    // }
}