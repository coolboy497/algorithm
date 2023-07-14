#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
//给定四个包含整数的数组列表 A , B , C , D ,
//计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len3 = nums3.size();
        int len4 = nums4.size();
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                int sum = nums1[i]+nums2[j];
                map1[sum]++;
            }
        }
        for(int i=0;i<len3;i++){
            for(int j=0;j<len4;j++){
                int sum = nums3[i]+nums4[j];
                map2[sum]++;
            }
        }
        // int len5 = map1.size();
        int count=0;
        for(auto it = map1.begin();it!=map1.end();it++){
            int find_num = 0 - it->first;
            auto result = map2.find(find_num);
            if(result!=map2.end()){
                int temp_count = it->second*result->second;
                count+=temp_count;
            }
        }
        return count;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    vector<int>nums1={1,2};
    vector<int>nums2={-2,-1};
    vector<int>nums3={-1,2};
    vector<int>nums4={0,2};
    Solution s;
    int result = s.fourSumCount(nums1,nums2,nums3,nums4);
    cout<<result<<endl;
    return 0;
}