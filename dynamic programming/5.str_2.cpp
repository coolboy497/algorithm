#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
// 给定一个字符串str,给定一个字符串类型的数组arr,出现的字符都是小写英文
// arr每一个字符串,代表一张贴纸,你可以把单个字符剪开使用,目的时拼出str来
// 返回需要至少多少张贴纸可以完成这个任务 （每种贴纸可以无数张）

// 例子:str="babac"  arr={"ba","c","abcd"}
// 至少需要两张贴纸 "ba"和"abcd"，因为使用这两张贴纸，把每一个字符单独剪开，含有2个a,2个b,1个c。
// 是可以拼出str的，所以返回2.
class Solution{
public:
    int num(string str,vector<string>&arr){
        if(arr.empty() || str.empty()){
            return 0;
        }
        return subprocess(str,arr)==INT_MAX ? -1 : subprocess(str,arr);
    }
    // 这里str是一个可变量，不需要弄成动态规划的严格表
    // 可以用傻缓存
    int subprocess(string str,vector<string>&arr){
        if(str.size()==0){
            return 0;
        }
        int Min = INT_MAX;
        for(string first : arr){
            string rest = minus(str,first);
            if(rest.length()!=str.length()){
                //Min是由后序贴纸计算出来的
                Min = min(Min,subprocess(rest,arr));
            }
        }
        //如果后序贴纸算的是有效解就加1，无效解就加0
        return Min + (Min == INT_MAX ? 0 : 1);
    }
    string minus(string str,string s){
        unordered_map<char,int>umap;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (char c : alphabet) {
            umap[c] = 0;
        }
        for (char c : str){
            umap[c]++;
        }
        for (char c : s){
            umap[c]--;
        }
        string result="";
        for (auto it = umap.begin();it!=umap.end();it++){
            while(it->second>0){
                result+=it->first;
                it->second--;
            }
        }
        return result;
    }
};
int main(){
    Solution a;
    string str = "babac";
    vector<string>arr{"ba","c","abcd"};
    int num = a.num(str,arr);
    cout<<"num1:"<<num<<endl;
}