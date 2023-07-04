#include <iostream>
#include <vector>
using namespace std;
// 给定一个正整数num，如果num是一个完全平方数，则返回true,否则返回false
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1){
            return true;
        }
        int l = 0;
        int r = num/2;
        while(l<=r){
            long mid = l+(r-l)/2;
            if(mid*mid>num){
                r = mid-1;
            }
            else if(mid*mid<num){
                l = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
int main(){
    int x = 8;
    Solution s;
    bool result = s.isPerfectSquare(x);
    cout<<result<<endl;
    return 0;
}