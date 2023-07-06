#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
// 给定一个正整数n，生成一个nxn的螺旋矩阵
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> v(n, vector<int>(n, 0)); 
//         int startx=0,starty=0;
//         int i,j;
//         int loop = n/2;//循环圈数
//         int mid = n/2;//中间位置
//         int count = 1;
//         int offset1=1;
//         while(loop--){
//             for(j=starty;j<n-offset1;j++){
//                 v[startx][j] = count;
//                 count++;
//             }
//             for(i=startx;i<n-offset1;i++){
//                 v[i][j] = count;
//                 count++;
//             }
//             for(;j>starty;j--){
//                 v[i][j] = count;
//                 count++;
//             }
//             for(;i>startx;i--){
//                 v[i][j] = count;
//                 count++;
//             }
//             startx++;
//             starty++;
//             offset1++;
//         }
//         if(n%2){
//             v[mid][mid] = count;
//         }
//         return v;
//     }
// };
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> v(n, vector<int>(n, 0)); 
//         int l=0,r=n-1,t=0,b=n-1;//定义上下左右边
//         int num = n*n;
//         int start = 1;
//         int i;
//         while(start<=num){
//             for(i=l;i<=r;i++){
//                 v[t][i]=start;
//                 start++;
//             }
//             t++;
//             for(i=t;i<=b;i++){
//                 v[i][r]=start;
//                 start++;
//             }
//             r--;
//             for(i=r;i>=l;i--){
//                 v[b][i]=start;
//                 start++;
//             }
//             b--;
//             for(i=b;i>=t;i--){
//                 v[i][l]=start;
//                 start++;
//             }
//             l++;
//         }
//         return v;
//     }
// };
class Solution {
public:
    vector<vector<int>> generateMatrix(int m,int n) {
        vector<vector<int>> v(m, vector<int>(n, 0)); 
        int l=0,r=n-1,t=0,b=m-1;
        int num = m*n;
        int i;
        int start = 1;
        while(start<num){
            for(i=l;i<=r;i++){
                v[t][i]=start;
                start++;
            }
            t++;
            if (t>b){break;}
            for(i=t;i<=b;i++){
                v[i][r]=start;
                start++;
            }
            r--;
            if(l>r){break;}
            for(i=r;i>=l;i--){
                v[b][i]=start;
                start++;
            }
            b--;
            if (t>b){break;}
            for(i=b;i>=t;i--){
                v[i][l]=start;
                start++;
            }
            l++;
            if(l>r){break;}
        }
        return v;
    }
};
int main(){
    int m=3,n=4;
    Solution s1;
    vector<vector<int>> v = s1.generateMatrix(m,n);
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
        for(vector<int>::iterator ot = (*it).begin();ot!=(*it).end();ot++){
            cout<<(*ot)<<" ";
        }
        cout<<endl;
    }
    return 0;
}