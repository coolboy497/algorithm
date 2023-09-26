#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
// 规定1和A对应、2和B对应、3和C对应....
// 那么一个数字字符串比如“111”就可以转化为：“AAA”、“KA” 和 “AK”
// 给定一个只有数字字符组成的字符串str,返回有多少种转化结果
class Solution{
public:
    int num(string s){
        if(s.empty()){
            return 0;
        }
        return subprocess(s,0);
    }
    // s[0....i-1]的转化结果无需过问
    // s[i...]有多少中转化结果
    int subprocess(string s, int i){
        if(i==s.size()){//i等于了s的长度,说明把s作为了一个整体进行转化，是一种方案
            return 1;
        }
        if(s[i]=='0'){ //当i位置单独面对一个0字符时，说明之前做的决策不对，因为只有1-26才能进行转化
            return 0;
        }
        // i位置是一个满足1-26间的字符
        // 有两种选择方案，一种将现位置单独进行考虑，第二种将现位置和下一个位置一起进行考虑
        int ways = subprocess(s,i+1); //i单转
        if(i+1<s.size()&&(s[i]-'0')*10+(s[i+1]-'0')<27){
            ways+= subprocess(s,i+2); //i和i+1一起转
        }
        return ways;
    }


    int num2(string s){
        if(s.empty()){
            return 0;
        }
        vector<int>dp(s.size()+1);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='0'){
                int ways = dp[i+1]; //i单转
                if(i+1<s.size()&&(s[i]-'0')*10+(s[i+1]-'0')<27){
                    ways+= dp[i+2]; //i和i+1一起转
                }
                dp[i]=ways;
            }
        }
        return dp[0];
    }
   
};
int main(){
    Solution a;
    string s = "7210231231232031203123";
    int num = a.num(s);
    cout << "num1:" <<num <<endl;

    int num2 = a.num2(s);
    cout << "num2:" <<num2 <<endl;
}