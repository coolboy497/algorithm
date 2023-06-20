#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
// const_iterator只读迭代器
void printdeque(const deque<int> &v){
   for(deque<int>::const_iterator it = v.begin();it!=v.end();it++){
        cout<<(*it)<<" ";
   }
   cout<<endl;
}
int main(){
    //(1)deque 构造函数
    // deque<int> v;
    // for(int i=0;i<10;i++){
    //     v.push_back(i);
    // }
    // printdeque(v);

    // deque<int> v2;
    // v2 = v;
    // printdeque(v2);

    // deque<int> v3(10,100);
    // printdeque(v3);
    //(2)deque 赋值操作，和vector相同
    //(3)deque 插入和删除
    // deque<int> v;
    // for(int i=0;i<10;i++){
    //     v.push_back(i);
    // }
    // printdeque(v);
    // //插入
    // v.push_front(-1);
    // v.push_back(10);
    // printdeque(v);
    // //删除
    // v.pop_front();
    // v.pop_back();
    // printdeque(v);
    // //位置插入
    // v.insert(v.begin()+3,100);
    // printdeque(v);
    // //位置删除
    // v.erase(v.begin()+3);
    // printdeque(v);
    // //清空
    // v.clear();
    // printdeque(v);
    // (4)deque排序
    deque <int> v;
    for(int i=10;i>0;i--){
        v.push_back(i);
    }
    sort(v.begin(),v.end());//默认从小到大
    printdeque(v);
    return 0;
}