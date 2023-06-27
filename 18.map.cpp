#include <iostream>
#include <map>
using namespace std;
void printmap(map<int,int> &m){
    for(auto it = m.begin();it!=m.end();it++){
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
    }
    cout<<endl;
}
int main(){
    //(1)map容器默认构造
    // map <int,int>m;
    // m.insert(pair<int,int>(1,10));
    // m.insert(pair<int,int>(2,20));
    // m.insert(pair<int,int>(3,30));
    // m.insert(pair<int,int>(4,40));
    // printmap(m);
    // // 拷贝构造
    // map <int,int>m2(m);
    // printmap(m2);
    // // 赋值构造
    // map <int,int>m3;
    // m3 = m2;
    // printmap(m3);
    //(2)map容器插入和删除
    map <int,int> m;
    // 插入
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m.insert(map<int,int>::value_type(3,30));
    printmap(m);
    return 0;
}