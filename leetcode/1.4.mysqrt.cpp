#include <iostream>
#include <vector>
using namespace std;
// 一个非负整数,计算返回x的算术平方根,舍掉小数
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        long r = x>>1;
        while(l<=r){
            long mid = (l+r)>>1;
            if(mid*mid>x){
                r=mid-1;
            }
            else if(mid*mid<x){
                l = mid+1;
            }
            else{
                return mid;
            }
        }
        return r;
    }
};
int main(){
    int x = 9;
    Solution s;
    int result = s.mySqrt(x);
    cout<<result<<endl;
    return 0;
}