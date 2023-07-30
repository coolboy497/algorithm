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
//给定一个非空的整数数组，返回其中出现频率前 k 高的元素
class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>vec;
        for(auto it=m.begin();it!=m.end();it++){
            vec.push_back(pair<int,int>(it->first,it->second));
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(vec[i].first);
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
    vector<int> result = s1.topKFrequent(a,k);
    for_each(result.begin(),result.end(),myprint);
    cout<<endl;
    return 0;
}