#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>target){
                r = mid-1;
            }
            else if (nums[mid]<target){
                l = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
int main(){
    int num[6] = {-1,0,3,5,9,12};
    int target = 9;
    vector<int>v;
    for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
        v.push_back(num[i]);
    }
    Solution S;
    int index = S.search(v,target);
    if(index!=-1){
        cout<<"所查值的下标为:"<<index<<endl;
    }
    else{
        cout<<"不存在所查值"<<endl;
    }
}