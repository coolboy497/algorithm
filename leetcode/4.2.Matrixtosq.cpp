#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
class Solution1 {
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
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> seq;
        int rows = matrix.size(); // 获取行数
        int cols = matrix[0].size(); // 获取列数
        int nums = rows*cols;
        int l=0,r=cols-1,t=0,b=rows-1;
        int i;
        while(nums>1){
            for(i=l;i<=r;i++){
                seq.push_back(matrix[t][i]);
                nums--;
            }
            t++;
            for(i=t;i<=b;i++){
                seq.push_back(matrix[i][r]);
                nums--;
            }
            r--;
            for(i=r;i>=l;i--){
                seq.push_back(matrix[b][i]);
                nums--;
            }
            b--;
            for(i=b;i>=t;i--){
                seq.push_back(matrix[i][l]);
                nums--;
            }
            l++;
        }
        return seq;
    }
};
void myprint(int val){
    cout<<val<<endl;
}
int main(){
    int m=3,n=4;
    Solution1 s1;
    Solution s;
    vector<vector<int>> v = s1.generateMatrix(m,n);
    vector<int> vsq = s.spiralOrder(v);
    for_each(vsq.begin(),vsq.end(),myprint);
    return 0;
}