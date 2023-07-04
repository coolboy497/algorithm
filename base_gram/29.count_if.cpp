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
    string name;
    int age;
};
class Great18{
public:
    bool operator()(const Person &p){
        return p.age>18;
    }
};
int main(){
    vector<Person>v;
    Person P1("aaa",19);
    Person P2("bbb",18);
    Person P3("ccc",17);
    Person P4("ddd",20);
    v.push_back(P1);
    v.push_back(P2);
    v.push_back(P3);
    v.push_back(P4);
    int num=count_if(v.begin(),v.end(),Great18());
    cout<<"大于18岁的人有"<<num<<"个"<<endl;
    return 0;
}