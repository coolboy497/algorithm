#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1(也就是说sum重复出现)。
//如果 可以变为  1，那么这个数就是快乐数。
//如果 n 是快乐数就返回 True ；不是，则返回 False 
void myprint(int val){
    cout<<val<<"";
}
int total_num(int n){
    int sum = 0;
    while(n > 0)
    {
        int bit = n % 10;
        sum += bit * bit;
        n = n / 10;
    }
    return sum;
}
class Solution {
public:
    bool isHappy(int n) {
        map<int,int>m;
        int sum = total_num(n);
        while(sum!=1){
            if(m[sum]==0){
                m[sum]++;
                sum = total_num(sum);
            }
            else{
                return false;
            }
        }
        return true;    
    }
};
int main(){
    int n=2;
    // cout<<n/10<<endl;
    Solution s;
    bool result = s.isHappy(n);
    if(result){
        cout<<n<<"是快乐数!"<<endl;
    }
    else{
        cout<<n<<"不是快乐数!"<<endl;
    }
}