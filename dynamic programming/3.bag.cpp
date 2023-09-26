#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//返回背包容量可装下的最大价值
//weight数组代表物品的重量
//value数组代表物品的价值
//bag就表示背包容量


//1.先看暴力递归有没有重复调用
//2.看有哪些可变参数
class Solution{
public:
    int maxValue1(vector<int>&w,vector<int>&v,int bag){
        if(w.empty()||v.empty()||w.size()!=v.size()){
            return 0;
        }
        return subprocess1(w,v,0,bag);
    }
    //返回最大价值，当前考虑第index号货物
    int subprocess1(vector<int>w,vector<int>v,int index,int bag){
        // if(bag<0){
        //     return 0;
        // }
        if(bag<0){
            return -1;
        }
        if(index==w.size()){
            return 0; 
        }
        int p1 = 0;
        int next = subprocess1(w,v,index+1,bag-w[index]); //因为分支可能存在无效的情况，即容量不满足选择当前背包，因此选择当前背包是不对的
        if(next!=-1){
            p1 = next+v[index];
        }
        // int p1 = subprocess(w,v,index+1,bag-w[index])+v[index]; 
        int p2 = subprocess1(w,v,index+1,bag);
        return max(p1,p2);
    }



    int maxValue2(vector<int>&w,vector<int>&v,int bag){
        if(w.empty()||v.empty()||w.size()!=v.size()){
            return 0;
        }
        int N = w.size();
        vector<vector<int>>dp(N+1,vector<int>(bag+1));
        for(int index=N-1;index>=0;index--){
            for(int rest = 0; rest<=bag; rest++){
                if(rest-w[index]<0){
                    continue;
                }
                dp[index][rest]=max(dp[index+1][rest-w[index]]+v[index],dp[index+1][rest]);
            }
        }

        return dp[0][bag];
    }
    //返回最大价值，当前考虑第index号货物
    //index 0~N
    //bag 0~bag
    int subprocess2(vector<int>w,vector<int>v,int index,int bag, vector<vector<int>>&dp){
        if(bag<0){
            return -1;
        }
        if(index==w.size()){
            return 0; 
        }
        int p1 = 0;
        int next = subprocess2(w,v,index+1,bag-w[index],dp); //因为分支可能存在无效的情况，即容量不满足选择当前背包，因此选择当前背包是不对的
        if(next!=-1){
            p1 = next+v[index];
        }
        int p2 = subprocess2(w,v,index+1,bag,dp);
        return max(p1,p2);
    }
};
int main(){
    Solution a;
    vector<int>w{3,2,4,7,3,1,7};
    vector<int>v{5,6,3,19,12,4,2};
    int bag = 15;
    int maxvalue1 = a.maxValue1(w,v,bag);
    cout<<"maxvalue1:"<<maxvalue1<<endl;
    int maxvalue2 = a.maxValue2(w,v,bag);
    cout<<"maxvalue2:"<<maxvalue2<<endl;
}