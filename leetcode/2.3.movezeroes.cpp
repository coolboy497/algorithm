#include <iostream>
#include <vector>
using namespace std;
//将数组中的0移动到数组的末尾，同时保持非零元素的相对顺序
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        for(i=0,j=0;i<nums.size();i++){
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        // cout<<j;
        for(int k=j;k<nums.size();k++)
        {
            nums[k]=0;
        }
    }
};
