#include <iostream>
#include <set>
using namespace std;
void printset(set<int> &s){
    for(set<int>::iterator it =s.begin();it!=s.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
int main(){
    //（1）set赋值
    // set <int> s;
    // //插入数据
    // s.insert(10);
    // s.insert(30);
    // s.insert(20);
    // s.insert(40);
    // s.insert(20);
    // // set不能插入重复值,插入自动排序
    // printset(s);//10 20 30 40
    // // 拷贝构造
    // set <int>s2(s);
    // printset(s2);//10 20 30 40
    // //赋值
    // set <int>s3;
    // s3 =s;
    // printset(s3);//10 20 30 40

    //（2）set容器大小
    // set <int> s;
    // //插入数据
    // s.insert(10);
    // s.insert(30);
    // s.insert(20);
    // s.insert(40);
    // s.insert(20);

    // set <int> s1;
    // s1.insert(100);
    // s1.insert(300);
    // s1.insert(200);
    // s1.insert(400);
    // if(s.empty()){
    //     cout<<"s为空"<<endl;
    // }
    // else{
    //     cout<<"s不为空"<<endl;
    //     cout<<"容器大小为: "<<s.size()<<endl;
    // }
    // cout<<"交换前:"<<endl;
    // printset(s);
    // printset(s1);

    // s.swap(s1);
    // cout<<"交换后:"<<endl;
    // printset(s);
    // printset(s1);

    //(3)set容器插入和删除
    set <int> s;
    //插入数据
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(40);
    s.insert(20);
    printset(s);//10 20 30 40
    s.erase(s.begin());
    printset(s);//20 30 40
    s.erase(30);
    printset(s);//20 40
    return 0;
}