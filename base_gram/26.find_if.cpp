#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
class GreatFive{
public:
    bool operator()(int val){
        return val>5;
    }
};
void test01(){
    // 内置数据类型
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    vector<int>::iterator pos = find_if(v.begin(),v.end(),GreatFive());
    if(pos==v.end()){
        cout<<"不存在满足条件的元素"<<endl;
    }
    else{
        cout<<"存在满足条件的元素"<<(*pos)<<endl;
    }
   
}
class Person{
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    
    string name;
    int age;
};
class GreatThirty{
public:
    bool operator()(const Person &p){
        if(p.age>=30){
            return true;
        }
        else{
            return false;
        }
    }
};
void test02(){
    vector<Person>p;
    Person p1("aaa",20);
    Person p2("ccc",40);
    Person p3("bbb",30);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    vector<Person>::iterator pos = find_if(p.begin(),p.end(),GreatThirty());
    if(pos==p.end()){
        cout<<"不存在满足条件的元素"<<endl;
    }
    else{
        cout<<"存在满足条件的元素"<<" 姓名:"<<pos->name<<" 年龄:"<<pos->age<<endl;
    }
   
}
int main(){
    cout<<"内置数据类型"<<endl;
    test01();
    cout<<"自定义数据类型"<<endl;
    test02();
    return 0;
}