#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
// 普通函数
void print01(int val){
    cout<<val<<" ";
}
// 仿函数，函数对像
class myprint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
int main(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    for_each(v.begin(),v.end(),myprint());
    cout<<endl;
    return 0;
}