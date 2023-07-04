#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printmyvector(vector<int>& t){
    for(vector<int>::iterator it = t.begin();it!=t.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
int main(){
    //(1)vector 构造函数

    //(2)vector 赋值操作 =和assign
    // vector<int> v;
    // for(int i=0;i<10;i++){
    //     v.push_back(i);
    // }
    // printmyvector(v);

    // vector<int> v2;
    // v2 = v;
    // printmyvector(v2);

    // vector<int> v3;
    // v3.assign(v.begin(),v.end());
    // printmyvector(v3);

    // vector<int> v4;
    // v4.assign(10,100);//赋值为10个100
    // printmyvector(v4);

    //(3)vector容量和大小
    // vector<int> v;
    // for(int i=0;i<10;i++){
    //     v.push_back(i);
    // }
    // printmyvector(v);
    // if(v.empty()){
    //     cout<<"v数组为空"<<endl;
    // }
    // else{
    //     cout<<"v数组不为空"<<endl;
    //     cout<<"v数组的容量为:"<<v.capacity()<<endl;
    //     cout<<"v数组中的元素个数为:"<<v.size()<<endl;
    // }
    // v.resize(15);
    // printmyvector(v);

    //(4)vector插入和删除
    // vector<int> v;
    // // 尾插
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // printmyvector(v);
    // // 尾删
    // v.pop_back();
    // printmyvector(v);
    // // 插入
    // v.insert(v.begin(),100);
    // printmyvector(v);
    // // 删除
    // v.erase(v.begin()+2);
    // printmyvector(v);
    // // 删除
    // v.erase(v.begin()+1,v.end());
    // printmyvector(v);
    // // 清空
    // v.clear();
    // printmyvector(v);

    //(5)vector数据存取
    // vector<int> v;
    // for(int i=0;i<10;i++){
    //     v.push_back(i);
    // }
    // cout<<v.at(0)<<endl;
    // cout<<v[1]<<endl;
    // cout<<v.front()<<endl;
    // cout<<v.back()<<endl;

    //(6)vector容器互换
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    vector<int> v2;
    for(int i=9;i>=0;i--){
        v2.push_back(i);
    }
    printmyvector(v1);
    printmyvector(v2);
    // swap(v1,v2);
    v1.swap(v2);
    printmyvector(v1);
    printmyvector(v2);
    return 0;
}