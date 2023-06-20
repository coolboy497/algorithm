#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myprint(int val){
    cout<<val<<endl;
}
void test01(){
    //创建vector容器,并且通过模板参数指定容器中存放的数据的类型
    vector<int> v;
    //往容器中放数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //每个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
    //v.begin()返回迭代器,这个迭代器指向容器中第一个数据
    //v.end()返回迭代器，指向容器中最后一个元素的下一个位置
    //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();
    //第一种遍历方法
    while (begin!=end)
    {
        cout<<*begin<<endl;
        begin++;
    }
    //第二种遍历方法
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    //第三种遍历方法
    //使用STL提供的标准遍历算法 for_each 头文件algorithm
    for_each(v.begin(),v.end(),myprint);
}
int main(){
    test01();
    return 0 ;
}
