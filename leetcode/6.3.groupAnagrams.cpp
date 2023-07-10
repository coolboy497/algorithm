#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//将字符串中各个字母的频次作为key
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        vector<vector<string>> v;
        if(strs.size()==0||strs.size()==1){
            v.emplace_back(strs);
            return v;
        }
        for(int i=0;i<strs.size();i++){
            string key = string(26,'0');
            for(auto c:strs[i]){
                key[c-'a']++;
            }
            m[key].emplace_back(strs[i]);
        }   
        for(auto c:m){
            v.emplace_back(c.second);
        }
        return v;
    }
};
int main(){
    vector<string> v={"eat","tea","tan","ate","nat","bat"};
    Solution s;
    vector<vector<string>>result=s.groupAnagrams(v);
    for(auto it = result.begin();it!=result.end();it++){
        for(auto k = (*it).begin();k!=(*it).end();k++){
            cout<<(*k)<<endl;
        }
        cout<<endl;
    }
    return 0;
}