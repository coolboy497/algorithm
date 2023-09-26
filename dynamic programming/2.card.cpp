#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
// 【题目】
// 给定一个整型数组 arr，代表数值不同的纸牌排成一条线。玩家 A 和玩家 B 依次拿走每张纸 牌，
// 规定玩家 A 先拿，玩家 B 后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家 A 和 玩
// 家 B 都绝顶聪明。请返回最后获胜者的分数。
// 【举例】
// arr=[1,2,100,4]。
// 开始时，玩家 A 只能拿走 1 或 4。如果玩家 A 拿走 1，则排列变为[2,100,4]，接下来玩家 B
// 可以拿走 2 或 4，然后继续轮到玩家 A。如果开始时玩家 A 拿走 4，则排列变为[1,2,100]，接
// 下 来玩家 B 可以拿走 1 或 100，然后继续轮到玩家 A。玩家 A 作为绝顶聪明的人不会先拿 4，
// 因为 拿 4 之后，玩家 B 将拿走 100。所以玩家 A 会先拿 1，让排列变为[2,100,4]，接下来玩
// 家 B 不管 怎么选，100 都会被玩家 A 拿走。玩家 A 会获胜，分数为 101。所以返回 101。
// arr=[1,100,2]。
// 开始时，玩家 A 不管拿 1 还是 2，玩家 B 作为绝顶聪明的人，都会把 100 拿走。玩家 B 会
// 获胜，分数为 100。所以返回 100。

class Solution{
public:
    //  在arr[left...right]中拿纸牌 先手所能获得的最好分数
    int f1(vector<int>&arr,int left,int right){
        if(arr.empty()){
            return 0;
        }
        if(left==right){
            return arr[left];
        }
        int p1 = arr[left]+g1(arr,left+1,right);
        int p2 = arr[right]+g1(arr,left,right-1);
        return max(p1,p2);
    }
    // B拿后手 ，后手函数
    int g1(vector<int>&arr,int left,int right){
        // 因为是后手，所以left==right时会被别人先拿
        if(left==right){
            return 0;
        }
        // 两种情况，A拿走了left, A拿走了right, 后手只能在剩下的里面挑
        // 因为对手是绝顶聪明的，所以后手只能在两种情况中拿到最小值
        int p1 = f1(arr,left+1,right);
        int p2 = f1(arr,left,right-1);
        return min(p1,p2);
    }

    // 比如0.....7纸牌，则依赖关系为f2(0,7)依赖g2(1,7)和g2(0,6)  g2(1,7)->f2(2,7),f2(1,6)  g2(0,6)->f2(1,6),f2(0,5) 有重复的
    // 直接定义两个数组，一个存f, 一个存g
    int f2(vector<int>&arr,int left,int right,vector<vector<int>>&f,vector<vector<int>>&g){
        if(f[left][right]!=-1){
            return f[left][right]; 
        }
        if(arr.empty()){
            return 0;
        }
        if(left==right){
            return arr[left];
        }
        int p1 = arr[left]+g2(arr,left+1,right,f,g);
        int p2 = arr[right]+g2(arr,left,right-1,f,g);
        f[left][right] = max(p1,p2);
        return max(p1,p2);
    }
    // B拿后手 ，后手函数
    int g2(vector<int>&arr,int left,int right,vector<vector<int>>&f,vector<vector<int>>g){
        if(g[left][right]!=-1){
            return g[left][right];
        }
        // 因为是后手，所以left==right时会被别人先拿
        if(left==right){
            return 0;
        }
        // 两种情况，A拿走了left, A拿走了right, 后手只能在剩下的里面挑
        // 因为对手是绝顶聪明的，所以后手只能在两种情况中拿到最小值
        int p1 = f2(arr,left+1,right,f,g);
        int p2 = f2(arr,left,right-1,f,g);
        g[left][right] = min(p1,p2);
        return min(p1,p2);
    }


    int f3(vector<int>&arr,vector<vector<int>>&f,vector<vector<int>>&g){
        if(arr.empty()){
            return 0;
        }
        int N = arr.size();
        for(int i=0;i<N;i++){
            f[i][i]=arr[i];
            g[i][i]=0;
        }
        for(int startcol = 1; startcol<N; startcol++){
            int L = 0;
            int R = startcol;
            while(R<N){
                f[L][R] = max(arr[L]+g[L+1][R],arr[R]+g[L][R-1]);
                g[L][R] = min(f[L+1][R],f[L][R-1]);
                L++;
                R++;
            }
        }
        return max(f[0][N-1],g[0][N-1]);
    }
};

int main(){
    Solution a;
    vector<int>arr{1,2,100,4};
    vector<vector<int>>f(arr.size(),vector<int>(arr.size(),-1));
    vector<vector<int>>g(arr.size(),vector<int>(arr.size(),-1));
    int score1 = a.f1(arr,0,arr.size()-1);
    int score2 = a.f2(arr,0,arr.size()-1,f,g);
    int score3 = a.f3(arr,f,g);
    cout<<score1<<endl;
    cout<<score2<<endl;
    cout<<score3<<endl;
    return 0;
}