#include <iostream>
#include <map>
using namespace std;
class Person{
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};
class mycompare {
public:
    bool operator()(const Person &v1,const Person &v2){
        return v1.age>v2.age;
    }
    // bool operator()(const pair<Person,int> &v1,const pair<Person,int> &v2){
    //     return v1.second > v2.second;
    // }
};
int main(){
    map<Person,int,mycompare> m;
    Person p1("tom",18);
    Person p2("john",16);
    Person p3("jey",19);
    Person p4("gee",21);
    pair<Person,int>m1(p1,99);
    pair<Person,int>m2(p2,87);
    pair<Person,int>m3(p3,92);
    pair<Person,int>m4(p4,95);
    m.insert(m1);
    m.insert(m2);
    m.insert(m3);
    m.insert(m4);
    for(auto it = m.begin();it!=m.end();it++){
        cout<<"姓名: "<<it->first.name<<" 年龄: "<<it->first.age<<" 分数: "<<it->second<<endl;
    }
    return 0;
}