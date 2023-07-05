#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

    }
};
int main(){
    int nums[5]={-4,-1,0,3,10};
    vector <int> v;
    int target = 7;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        v.push_back(nums[i]);
    }
    Solution s;
    int nice = s.minSubArrayLen(target,v);

    return 0;
}