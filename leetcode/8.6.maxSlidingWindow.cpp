#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <stack>
#include <ctype.h>
using namespace std;
//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
//你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//返回滑动窗口中的最大值

//超出了时间限制
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         if(nums.size()<k){
//             auto maxPosition = max_element(nums.begin(), nums.end());
//             int max = *maxPosition;
//             return {max};
//         }
//         vector<int>result;
//         int i=0;
//         int j=0;
//         j = i+k-1;
//         while(j<nums.size()){
//             auto maxPosition = max_element(nums.begin()+i, nums.begin()+j+1);
//             int max = *maxPosition;
//             result.push_back(max);
//             i++;
//             j = i+k-1;
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<k){
            auto maxPosition = max_element(nums.begin(), nums.end());
            int max = *maxPosition;
            return {max};
        }
        vector<int>result;
        set<int>s;
        int i=0;
        int j=0;
        j = i+k-1;
        // int max=0;
        while(j<nums.size()){
            // auto maxPosition = max_element(nums.begin()+i, nums.begin()+j+1);
            // max = *maxPosition;
            s.insert(nums.begin()+i, nums.begin()+j+1);
            result.push_back(*s.rbegin());
            s.clear();
            i++;
            j = i+k-1;
        }
        return result;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>a={1,3,-1,-3,5,3,6,7};//(2+1)*3=9
    int k=3;
    Solution s1;
    vector<int> result = s1.maxSlidingWindow(a,k);
    for_each(result.begin(),result.end(),myprint);
    cout<<endl;
    return 0;
}