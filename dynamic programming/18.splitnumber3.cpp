#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//给定一个正数数组arr，请把arr中所有的数分成两个集合，
//如果arr长度为偶数，两个集合包含数的个数要一样多
//如果arr长度为奇数，两个集合包含数的个数必须只差一个
//尽量让两个集合的累加和接近返回
//最接近的情况下，较小集合的累加和
class Solution{
public:
    int way1(vector<int>&arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int target = sum/2;
        int number = arr.size()/2;
        //(1)arr的长度是偶数
        if(arr.size()%2==0){
            return process(arr,0,target,number);
        }
        //(2)arr的长度是奇数
        return max(process(arr,0,target,number),process(arr,0,target,number+1));
    }
    //在arr[index...]可以自由选择，请返回累加和尽量接近rest，但不能超过rest的情况下，最接近的累加和，最后的集合个数等于number
    int process(vector<int>&arr,int index,int rest,int number){
        if(index==arr.size()){
            //当没数可挑时，集合个数已经满足条件了才符合，要不然就是无效的（返回-1）
            return number==0 ? 0 : -1;
        }
        //不使用arr[index]
        int p1 = process(arr,index+1,rest,number);
        //使用arr[index]
        int p2 = -1; 
        if(rest-arr[index]>=0&&process(arr,index+1,rest-arr[index],number-1)!=-1){
            p2 = arr[index]+process(arr,index+1,rest-arr[index],number-1);
        }
        return max(p1,p2);
    }

    // index 0~arr.size()
    // rest 0~target
    // number 0~number
    int way2(vector<int>&arr){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int target = sum/2;
        int number = arr.size()/2;
        vector<vector<vector<int>>>dp(arr.size()+1,vector<vector<int>>(target+1,vector<int>(number+1)));
        for(int i=0;i<=arr.size();i++){
            for(int j=0;j<=target;j++){
                for(int k=0;k<=number;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        for(int j=0;j<=target;j++){
            dp[arr.size()][j][0]=0;
        }
        for(int index = arr.size()-1;index>=0;index-- ){
            for(int k = 0;k<=number;k++){
                for(int rest = 0;rest<=target;rest++){
                    int p1 = dp[index+1][rest][k];
                //使用arr[index]
                    int p2 = -1; 
                    if(rest-arr[index]>=0&&dp[index+1][rest-arr[index]][k-1]!=-1){
                        p2 = arr[index]+dp[index+1][rest-arr[index]][k-1];
                    }
                    dp[index][rest][k] = max(p1,p2);
                }
            }
        }
        
        //(1)arr的长度是偶数
        if(arr.size()%2==0){
            return dp[0][target][number];
        }
        //(2)arr的长度是奇数
        return max(dp[0][target][number],dp[0][target][number+1]);
    }

    // int way3(vector<int>&arr){
  
    // }
};
int main(){
    Solution a;
    vector<int>arr{1,5,6,8,7,10};
    cout<<a.way1(arr)<<endl;
    cout<<a.way2(arr)<<endl;
    // cout<<a.way3(arr)<<endl;
}