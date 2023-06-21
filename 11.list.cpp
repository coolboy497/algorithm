#include<iostream>
#include<list>
using namespace std;
void printList(list <int>&L){
    for(list<int>::iterator it = L.begin();it!=L.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
bool compare(int v1,int v2){
    return v1 > v2;
}
int main(){
    // (1)List容器构造
    // list <int> L;
    // L.push_back(10);
    // L.push_back(20);
    // L.push_back(30);
    // printList(L);
    // list <int> L2(L.begin(),L.end());
    // printList(L2);
    // list <int> L3(L2);
    // printList(L3);
    // list <int> L4(10,10);
    // printList(L4);
    
    //(2)list容器大小操作
    // list <int> l;
    // l.push_back(10);
    // l.push_back(20);
    // l.push_back(30);
    // if(l.empty()){
    //     cout<<"l为空"<<endl;
    // }
    // else{
    //     cout<<"l不为空"<<endl;
    //     cout<<"当前容器元素个数为:"<<l.size()<<endl;
    // }
    // l.resize(10);
    // printList(l);

    //(3)list容器插入和删除
    // list<int> l1;
    // //尾插
    // l1.push_back(10);
    // l1.push_back(20);
    // l1.push_back(30);
    // printList(l1);//10,20,30
    // //头插
    // l1.push_front(100);
    // l1.push_front(200);
    // l1.push_front(100);
    // printList(l1);//100 200 100 10 20 30
    // //尾删
    // l1.pop_back();
    // printList(l1);//100 200 100 10 20
    // //头删
    // l1.pop_front();
    // printList(l1);//200 100 10 20

    // //任意位置插入
    // list<int>::iterator it = l1.begin();
    // l1.insert(++it,50);
    // printList(l1);//200 50 100 10 20
     
    // it = l1.begin();
    // l1.insert(++it,4,10);
    // printList(l1);//200 10 10 10 10 50 100 10 20

    // // 删除
    // l1.remove(10);
    // printList(l1);//200 50 100 20
    
    // (4)list容器数据存取
    // list<int> l1;
    // l1.push_back(10);
    // l1.push_back(20);
    // l1.push_back(30);
    // cout<<"第一个元素为: "<<l1.front()<<endl; //10
    // cout<<"最后一个元素为: "<<l1.back()<<endl; //30

    //(5)list容器反转和排序
    list<int> l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(30);
    l1.reverse();
    printList(l1);//30 10 20
    l1.sort();
    printList(l1);//10 20 30默认是升序
    l1.sort(compare);
    printList(l1); // 30 20 10
    return 0;
}