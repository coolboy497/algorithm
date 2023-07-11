#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定两个数组，请你以数组形式返回两数组的交集.
//返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
//（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1==0||len2==0){
            return {};
        }
        vector<int>result;
        map<int,int>m1;
        for(int i=0;i<len1;i++){
            m1[nums1[i]]++;
        }
        for(int j=0;j<len2;j++){
            if(m1[nums2[j]]>0){
                m1[nums2[j]]--;
                result.emplace_back(nums2[j]);
            }
        }
        return result;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>nums1={1,2,2,1};
    vector<int>nums2={2,2,2};
    Solution s;
    vector<int>result = s.intersect(nums1,nums2);
    for_each(result.begin(),result.end(),myprint);
    cout<<endl;
    return 0;
}