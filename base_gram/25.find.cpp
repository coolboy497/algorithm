#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
class Person{
    public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    //重载== 底层find知道如何对比Person数据类型
    bool operator==(const Person &v1){
        if(v1.name==this->name&&v1.age==this->age){
            return true;
        }
        else{
            return false;
        }
    }
    string name;
    int age;
};
int main(){
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person pp("bbb",10);
    vector<Person>::iterator pos = find(v.begin(),v.end(),pp);
    if(pos==v.end()){
        cout<<"不存在查找的成员"<<endl;
    }
    else{
        cout<<"存在 姓名:"<<pos->name<<" 年龄:"<<pos->age<<endl;
    }
    return 0;
}