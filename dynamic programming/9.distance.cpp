#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//给定一个二维数组matrix,一个人必须从左上角出发，最后到达右下角
//沿途只可以向下或者向右走,沿途的数组都累加就是距离累加和
//返回最小距离累加和
class Solution{
public:
    int minpath(vector<vector<int>>&matrix){
        return subprocess(matrix,0,0,matrix.size()-1,matrix[0].size()-1);
    }
    int subprocess(vector<vector<int>>&matrix,int x,int y,int a,int b){
        if(x>a||y>b){
            return INT_MAX;
        }
        if(x==a&&y==b){
            return matrix[x][y];
        }
        int p1 = subprocess(matrix,x+1,y,a,b);
        int p2 = subprocess(matrix,x,y+1,a,b);
        return min(p1,p2) + matrix[x][y];
    }

    int minpath2(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[m-1][n-1] = matrix[m-1][n-1];

        // 初始化最后一行和最后一列
        // 初始化最后一行时，每个位置只能向右移动，所以每个位置的最小路径和都等于当前位置的值加上右侧位置的最小路径和
        for (int j = n-2; j >= 0; j--) {
            dp[m-1][j] = dp[m-1][j+1] + matrix[m-1][j];
        }
        for (int i = m-2; i >= 0; i--) {
            dp[i][n-1] = dp[i+1][n-1] + matrix[i][n-1];
        }

        // 从倒数第二行和倒数第二列开始遍历填表
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + matrix[i][j];
            }
        }

        return dp[0][0];

    }
    //从左上角往右下角填
    int minpath3(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0]=matrix[0][0];
        //第一行
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+matrix[0][j];
        }
        //第一列
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+matrix[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            }
        }
        return dp[m-1][n-1];
    }

    //优化：用一个滚动数组
    int minpath4(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>arr(n);
        arr[0]=matrix[0][0];
        //初始化数组
        for(int j=1;j<n;j++){
            arr[j]=arr[j-1]+matrix[0][j];
        }
        for(int i=1;i<m;i++){
            //第一个位置要单独处理，因为左边没有
            arr[0]+=matrix[i][0];
            for(int j=1;j<n;j++){
                arr[j]=min(arr[j-1],arr[j])+matrix[i][j];
            }
        }
        return arr[n-1];
    }

};
int main(){
    Solution a;
    vector<vector<int>>matrix={{4,7,8,7},{1,2,6,4},{10,3,8,9},{8,1,2,0}};
    int sum = a.minpath(matrix);
    cout<<sum<<endl;
    int sum2 = a.minpath2(matrix);
    cout<<sum2<<endl;
    int sum3 = a.minpath3(matrix);
    cout<<sum3<<endl;
    int sum4 = a.minpath4(matrix);
    cout<<sum4<<endl;
}