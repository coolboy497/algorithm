#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定两个数组，编写一个函数来计算它们的交集,输出元素唯一
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1==0||len2==0){
            return {};
        }
        set<int>s;
        map<int,int>m1;
        for(int i=0;i<len1;i++){
            m1[nums1[i]]++;
        }
        for(int j=0;j<len2;j++){
            if(m1[nums2[j]]!=0){
                s.insert(nums2[j]);
            }
        }
        vector<int>result;
        result.assign(s.begin(), s.end());
        return result;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>nums1={1,2,2,1};
    vector<int>nums2={2,2};
    Solution s;
    vector<int>result = s.intersection(nums1,nums2);
    for_each(result.begin(),result.end(),myprint);
    cout<<endl;
    return 0;
}