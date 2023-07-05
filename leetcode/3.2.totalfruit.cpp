#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
//fruits[i]是第i棵树上的水果种类
//只有两个篮子，每个篮子只能装单一类型的水果
//给一个整数数组fruits,返回可以收集的水果的最大数目
//（子数组中只能有两种不同的类型，值最大）
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int len = fruits.size();
        int sublen = 0;
        // int temp = 0;
        map <int,int> m;
        while(i<len&&j<len){
          if(m.size()<2){
            if(m.count(fruits[i])==0){
              m.insert(make_pair(fruits[i],1));
            }
            else{
              m[fruits[i]]++;
            }
            // temp++;
            i++;
          }
          else{
            if(m.count(fruits[i])==0){
              sublen = max(sublen,i-j+1);
              // j++;
              m.erase(fruits[j]);
              j++;
              i++;
              // temp = 0;
            }
            else{
              m[fruits[i]]++;
              // temp++;
              i++;
            }
          }
        }
        sublen = max(sublen,i-j);
        return sublen;
    }
};
int main(){
    int nums[5]={1,2,3,2,2};
    vector <int> v;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        v.push_back(nums[i]);
    }
    Solution s;
    int sublen = s.totalFruit(v);
    cout<<sublen<<endl;
    return 0;
}