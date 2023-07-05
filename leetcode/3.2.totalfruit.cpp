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
class Solution{
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int len = fruits.size();
        int sublen = 0;
        map <int,int> m;
        for(j=0;j<len;j++){
          m[fruits[j]]++;
          while(m.size()>2){
            auto it = m.find(fruits[i]);
            it->second--;
            if(it->second==0){
              m.erase(it);
            }
            i++;
            }
          sublen = max(sublen,j-i+1);
        }
        return sublen;
    }
};
int main(){
    int nums[9]={1,0,1,4,1,4,1,2,3};
    vector <int> v;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        v.push_back(nums[i]);
    }
    Solution s;
    int sublen = s.totalFruit(v);
    cout<<sublen<<endl;
    return 0;
}