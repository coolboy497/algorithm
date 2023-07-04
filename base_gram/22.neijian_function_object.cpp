#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
void printvector(vector<int> &v){
    for(auto it=v.begin();it!=v.end();it++){
        cout<<(*it)<<endl;
    }
}
int main(){
    //算术仿函数
    negate<int>n;
    cout<<"取反："<<n(50)<<endl;//-50
    plus<int>p;
    cout<<"加法: "<<p(10,20)<<endl;//30
    cout<<endl;
    //关系仿函数（实现关系对比）
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    cout<<"排序前:"<<endl;
    printvector(v);
    // 这里直接使用内置函数对象，可以省去自己写compare（）
    sort(v.begin(),v.end(),greater<int>());
    cout<<"排序后:"<<endl;
    printvector(v);

    //逻辑仿函数
    vector<bool>b;
    b.push_back(true);
    b.push_back(false);
    b.push_back(true);
    b.push_back(false);
    cout<<"逻辑排序前:"<<endl;
    for(auto it = b.begin();it!=b.end();it++){
        cout<<(*it)<<endl;
    }
    // 利用逻辑非 将容器v搬运到容器v2中，并执行取反操作
    vector<bool>b2;
    b2.resize(b.size());
    transform(b.begin(),b.end(),b2.begin(),logical_not<bool>());
    cout<<"逻辑排序后:"<<endl;
    for(auto it = b2.begin();it!=b2.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}