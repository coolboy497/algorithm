#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sublen = nums.size()+1;
        int tempsum = 0;
        while(i<nums.size()&&j<nums.size()){
            tempsum+=nums[i];
            if(tempsum<target){
                i++;
            }
            else{
                sublen = min(sublen,i-j+1);
                tempsum-=nums[j];
                tempsum-=nums[i];
                j++;
            }
        }
        if(sublen == nums.size()+1){
            return 0;
        }
        else{
            return sublen;
        }
    }
};
int main(){
    int nums[6]={2,3,1,2,4,3};
    vector <int> v;
    int target = 7;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        v.push_back(nums[i]);
    }
    Solution s;
    int sublen = s.minSubArrayLen(target,v);
    cout<<sublen<<endl;
    return 0;
}